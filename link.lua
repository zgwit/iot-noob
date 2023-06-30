--- 模块功能：链接管理
-- @module link
-- @author 杰神
-- @license GPLv3
-- @copyright zgwit
-- @release 2023.06.30
module(..., package.seeall)

local TAG = "LINK"

local types = {}

function register(id, factory)
    types[id] = factory
end


local links = {}

Link = {}

function Link:new(id, args)
    local obj = args or {}
    setmetatable(obj, self)
    self.__index = self
    links[id] = obj
    return obj
end

-- 打开连接
function Link:open()

end

