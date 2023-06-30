module(..., package.seeall)

require "config"

local TAG = "RS485"
local CFG = "rs485"

local UART_ID = 1 -- 某些板为2，3
local RS485_EN = pio.P0_0 -- 某些板为pio.P0_23

cfg = {
    -- 波特率
    baud = 9600,
    -- 字长
    bits = 8,
    -- 校验，0 none 无校验, 1 odd 奇校验, 2 even 偶校验
    parity = 0,
    -- 结束符 1, 2, 0.5=>0xf0, 1.5=>0xf1
    stop = 1,
    -- 读超时
    -- timeout = 2000
}

-- 加载配置
local ok, res = config.load(CFG)
if ok then
    cfg = res
else
    config.store(CFG, cfg) -- 生成默认文件
end

-- 配置并且打开串口
uart.setup(UART_ID, cfg.baud, cfg.bits, cfg.parity, cfg.stop, nil, 1)

-- RS485使能（收发电平翻转）
uart.set_rs485_oe(UART_ID, RS485_EN, 1, 1, 1)

-- 读取数据
function read(timeout)
    local data = sys.waitUntil("RS485_DATA", timeout)
    return data
end
-- read = uart.read

-- 写数据
write = uart.write

-- 监听读取数据
uart.on(UART_ID, "receive", function() sys.publish("RS485_READ") end)

-- 读数据接口
sys.taskInit(function()
    local buf = ""
    while true do
        local s = uart.read(UART_ID, 1)
        if s == "" then
            -- 等待485帧间隔
            if not sys.waitUntil("RS485_READ", 35000 / config.baud) then
                if buf:len() > 0 then
                    sys.publish("RS485_DATA", buf)
                    buf = ""
                end
            else
                -- TODO 有没有必要？？
                buf = buf .. s    
            end
        else
            buf = buf .. s
        end
    end
end)

