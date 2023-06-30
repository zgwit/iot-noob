module(..., package.seeall)

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
end

-- 写入 1->5 3->6 
function modbus:write(slave, code, addr, data)
    local data = pack.pack("b2>H", slave, code, addr) .. data
    local crc = pack.pack('<H', crypto.crc16("MODBUS", data))
    self.link.write(msg)
    local ret = self.link.read(self.timeout)
    if ret == "" or ret == nil then return false end

    -- 判断成功与否
    if ret[2] > 0x80 then return false end
    return true
end

-- 数据类型
local types = {
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
function modbus:unpack(code, data, mappers)
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
            local fmt = (m.be and '>' or '<') .. types[m.type]
            local _, v = pack.unpack(str, fmt)
            -- 倍率
            if m.rate ~= 0 and m.rate ~= 1 then v = v * m.rate end
            -- 校准
            if m.adjust ~= 0 then v = v + m.adjust end

            result[m.name] = v
        end
    else
        ---
    end

    return result
end
