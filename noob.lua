module(..., package.seeall)
-- 连接云平台

require "misc"
require "mqtt"

local TAG = "NOOB"
local CFG = "noob.json"

-- TODO 添加备份服务器
local imei = misc.getImei()
log.info(TAG, "imei", imei)

cfg = {
    clientId = imei, -- 默认使用IMEI号
    username = "", -- TODO 账号密码规则
    password = "",
    server = "mqtt.iot-noob.com",
    port = 1883
}

function Load()
    if not io.exists(CFG) then return end
    local data = io.readFile(CFG)
    if #data > 0 then cfg = json.decode(data) end
end

-- 加载配置
Load()

-- MQTT Broker 参数配置
local ready = false

function IsReady() return ready end

-- 客户端
local client

-- 数据发送的消息队列
local _msgQueue = {}

-- 要订阅的主题
local topics = {["down/gateway/" .. imei .. "/#"] = 0}

local commandTopic = "up/gateway/" .. imei .. "/command"

--- 发布消息
function Publish(topic, payload, cb)
    log.info(TAG, "publish", topic, payload)
    table.insert(_msgQueue, {t = topic, p = payload, q = 0, c = cb})
    sys.publish("APP_SOCKET_SEND_DATA") -- 终止接收等待，处理发送
end

-- 订阅消息 TODO 添加callback
function Subscribe(topic, qos)
    topics[topic] = qos
    if ready then return client:subscribe({[topic] = qos}) end
end

local function send_messages()
    while #_msgQueue > 0 do
        local msg = table.remove(_msgQueue, 1)
        local ok = client:publish(msg.t, msg.p, msg.q)
        if msg.c then msg.c(ok) end
        if not ok then return end
    end
    return true
end

local function receive_messages()
    local ok, data
    while true do
        -- 接收到数据
        ok, data = client:receive(60000, "APP_SOCKET_SEND_DATA")
        if ok then
            log.info(TAG, "message", data.topic, data.payload)

            local ts = string.split(data.topic, "/")
            if ts[1] == "down" then
                if ts[2] == "gateway" then
                    if ts[4] == "command" then
                        handleGateway(ts[4], data.payload)
                    end
                elseif ts[2] == "property" then
                    -- TODO 数据怎么回传
                end
            end
        else
            break
        end
    end

    return ok or data == "timeout" or data == "APP_SOCKET_SEND_DATA"
end

-- 启动NOOB客户端任务
sys.taskInit(function()
    local retry = 0
    while true do
        if not socket.isReady() then
            retry = 0
            -- 等待网络环境准备就绪，超时时间是5分钟
            sys.waitUntil("IP_READY_IND", 300000)
        end

        if socket.isReady() then

            client = mqtt.client(cfg.clientId, 600, cfg.username, cfg.password)
            -- 阻塞执行MQTT CONNECT动作，直至成功
            if client:connect(cfg.server, cfg.port, "tcp") then
                retry = 0
                ready = true

                -- 订阅主题
                client:subscribe(topics)

                -- 循环处理接收和发送的数据
                while true do
                    if not receive_messages(client) then
                        log.error(TAG, "receive error")
                        break
                    end
                    if not send_messages(client) then
                        log.error(TAG, "send error")
                        break
                    end
                end

                ready = false
            else
                retry = retry + 1
            end

            -- 断开MQTT连接
            client:disconnect()
            if retry >= 5 then
                link.shut()
                retry = 0
            end
            sys.wait(5000)
        else
            -- 飞行模式20秒，重置网络
            net.switchFly(true)
            sys.wait(20000)
            net.switchFly(false)
        end
    end
end)

local function handleCommand(payload)
    log.info(TAG, "handleCommand", payload)
    local msg = json.decode(payload)

    if msg.cmd == "set-broker" then
        -- 设置服务器
        io.writeFile(CFG, payload, "w")
        Publish("up/gateway" .. imei .. "/command",
                json.encode({cmd = msg.cmd, mid = msg.mid, ret = "ok"}))
    elseif msg == "debug" then
        -- 数据透传
    elseif msg == "product" then
        -- 下载产品
    elseif msg == "device" then
        -- 下载设备
    elseif msg == "connect" then
        -- 下载连接配置
    end
end
