module(..., package.seeall)


require "files"

-- 配置文件根目录
local root = "/noob/"
if not files.exists(root) then
    files.makeDir(root) -- 自动创建
end

-- 加载配置文件
function load(cfg)
    local fn = root .. cfg .. ".json"
    if not files.exists(cfg) then return false end
    local data = files.read(fn)
    if #data > 0 then return true, json.decode(data) end
    return false
end

-- 写入配置文件
function store(cfg, data)
    local fn = root .. cfg .. ".json"
    return files.write(fn, json.encode(data))
end


-- 删除配置文件
function remove(cfg)
    local fn = root .. cfg .. ".json"
    return files.remove(fn)
end
