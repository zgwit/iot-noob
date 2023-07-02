--- 模块功能：链接管理
-- @module link
-- @author 杰神
-- @license GPLv3
-- @copyright zgwit
-- @release 2023.06.30
module(..., package.seeall)

local TAG = "LINK"

--[[
Link {
    open(): bool
    close(): void
    write(data): bool
    read(timeout): string
}
]]

-- 构造器
local factories = {
    serial = require("links.serial").Serial.new,
    tcpclient = require("links.tcpclient").TcpClient.new,
}

local links = {}
