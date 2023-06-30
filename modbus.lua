module(..., package.seeall)

local TAG = "MODBUS"

local modbus = {}
modbus.__index = modbus

function create(link, timeout)
    local o = {link = link, timeout = timeout or 500}
    setmetatable(o, modbus)
    return o
end

-- 读指令 code 1 2 3 4
function modbus:read(slave, code, addr, len)
    local data = pack.pack("b2>H2", slave, code, addr, len)
    local crc = pack.pack('<H', crypto.crc16("MODBUS", data))
    local msg = data .. crc
    self.link.write(msg)
    local ret = self.link.read(self.timeout)
    if ret == "" or ret == nil then return false end
    return string.sub(ret, 4) -- 删掉：从站，功能码，字数
    -- return unpack(string.sub(ret, 4), mappers)
end

-- 写入 1->5 3->6，仅支持单值写入
function modbus:write(slave, code, addr, data)
    if code == 1 then
        code = 5
        if data then
            data = 0xFF00
        else
            data = 0x0000
        end
    elseif code == 3 then
        if #data > 2 then
            code = 16 -- 写多个寄存器
        else
            code = 6 -- 写单个寄存器
        end
    end

    local data = pack.pack("b2>H", slave, code, addr) .. data
    local crc = pack.pack('<H', crypto.crc16("MODBUS", data))
    self.link.write(msg)
    local ret = self.link.read(self.timeout)
    if ret == "" or ret == nil then return false end
    -- 判断成功与否
    local _, s, c = pack.unpack(ret, "b2")
    if c > 0x80 then
        log.info(TAG, "error")
        return false
    end
    return true
end

function modbus:poll(slave, poller)
    local data = self.read(slave, poller.code, poller.addr, poller.length)
    if not data then return false end
    return parse(poller.code, data, poller.mappers)
end

function modbus:put(slave, name, value, pollers)
    local ret, code, addr, data = lookup(name, value, pollers)
    if not ret then return false end
    return self.write(slave, code, addr, data)
end


-- 数据类型
local unpackTypes = {
    --    bit = '',
    float = 'f',
    double = 'd',
    -- local NUMBER = 'n'
    int8 = 'c',
    uint8 = 'b',
    int16 = 'h',
    uint16 = 'H',
    int32 = 'i',
    uint32 = 'I',
    int64 = 'l',
    uint64 = 'L'
}

-- 解析数据
function parse(code, data, mappers)
    local result = {}
    if code == 1 or code == 2 then
        -- 取线圈或触点
        for i, m in ipairs(mappers) do
            local str = string.sub(data, m.offset / 8)
            local val = pack.unpack(str, "b")
            local pos = m.offset % 8
            result[m.name] = bit.isset(val, pos)
        end
    elseif code == 3 or code == 4 then
        -- 取寄存器
        for i, m in ipairs(mappers) do
            -- {offset = 0, be = true, type = "uint16", name = "temp", rate = 0.1， adjust = 0}
            local str = string.sub(data, m.offset * 2)
            -- 拼接格式
            local fmt = (m.be and '>' or '<') .. unpackTypes[m.type]
            local _, v = pack.unpack(str, fmt)
            -- 倍率
            if m.rate ~= 0 and m.rate ~= 1 then v = v * m.rate end
            -- 校准
            if m.adjust ~= 0 then v = v + m.adjust end

            result[m.name] = v
        end
    else
        log.info(TAG, "unpack unsupport code")
        ---
    end

    return result
end

-- 定位数据 
function lookup(name, value, pollers)
    for i, p in ipairs(pollers) do
        if p.code == 1 then
            -- 写线圈
            for i, m in ipairs(p.mappers) do
                if m.name == name then
                    return true, p.code, p.addr + m.offset, value
                end
            end
        elseif p.code == 3 then
            -- 写寄存器
            for i, m in ipairs(p.mappers) do
                if m.name == name then
                    -- if m.adjust ~= 0 then value = value - m.adjust end
                    if m.rate ~= 0 and m.rate ~= 1 then
                        value = value / m.rate
                    end
                    local fmt = (m.be and '>' or '<') .. unpackTypes[m.type]
                    return true, p.code, p.addr + m.offset,
                           pack.pack(fmt, value)
                end
            end
        end
    end
    return false
end
