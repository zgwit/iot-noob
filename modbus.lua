module(..., package.seeall)


local modbus = {}
modbus.__index = modbus


function create(link, timeout)
    local o = {
        link = link,
        timeout = timeout or 500,
    }
    setmetatable(o, modbus)
    return o
end






-- 读指令 code 1 2 3 4
function modbus:read(slave, code, addr, len, fmt)
    local data = pack.pack("b2>h2", slave, code, addr, len)
    local crc = pack.pack('<h', crypto.crc16("MODBUS", data))
    local msg = data .. crc
    self.link.write(msg)
    local ret = self.link.read(self.timeout)
    if ret == "" or ret == nil then
        return false
    end
    local buf = string.sub(ret, 4) --删掉：从站，功能码，字数
    -- 使用unpack解析数据？？？
    local values = {pack.unpack(buf, fmt)}
    table.remove(values, 1)
    return values
end


-- 写入 1->5 3->6 
function modbus:write(slave, code, addr, data)
    local data = pack.pack("b2>h", slave, code, addr)..data
    local crc = pack.pack('<h', crypto.crc16("MODBUS", data))
    self.link.write(msg)
    local ret = self.link.read(self.timeout)
    if ret == "" or ret == nil then
        return false
    end
    
    -- 判断成功与否
    if ret[2] > 0x80 then
        return false
    end
    return true
end

function modbus:unpack(data, mapper)
    
end