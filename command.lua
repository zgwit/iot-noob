module(..., package.seeall)

function reply(msg, data)
    local body = data or {}
    body.cmd = msg.cmd -- 回复命令
    body.sn = msg.sn -- 回复序号，方便对应
    return body
end


function reboot(msg)
    local ret = rtos.reboot()
    return reply(msg, {ret = ret})
end

require "files"

-- 遍历目录
function list(msg)
    local data = files.list(msg.dir, msg.skip, msg.limit)
    return reply(msg, {ret = 1, data = data})
end

-- 重命名
function rename(msg)
    local ret = files.rename(msg.path, msg.new)
    return reply(msg, {ret = ret})
end

-- 删除
function remove(msg)
    local ret = files.remove(msg.path)
    return reply(msg, {ret = ret})
end

-- 删除目录
function removeDir(msg)
    local ret = files.removeDir(msg.path)
    return reply(msg, {ret = ret})
end

-- 创建目录
function makeDir(msg)
    local ret = files.makeDir(msg.path)
    return reply(msg, {ret = ret})
end

-- 文件存在
function exists(msg)
    local ret = files.exists(msg.path)
    return reply(msg, {ret = ret})
end

-- 读取文件
function read(msg)
    local ret = files.read(msg.path)
    return reply(msg, {ret = ret})
end

-- 读取文件（部分内容）
function readPart(msg)
    local ret = files.readPart(msg.path, msg.offset, msg.length)
    return reply(msg, {ret = ret})
end

-- 写入文件
function write(msg)
    local ret = files.write(msg.path, msg.data)
    return reply(msg, {ret = ret})
end

-- 写入文件
function writeAppend(msg)
    local ret = files.writeAppend(msg.path, msg.data)
    return reply(msg, {ret = ret})
end

-- 写入文件（掉电保护）
function writeSafe(msg)
    local ret = files.writeSafe(msg.path, msg.data)
    return reply(msg, {ret = ret})
end