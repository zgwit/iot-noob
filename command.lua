module(..., package.seeall)

require "noob"

local function reply(msg, data)
    local body = data or {}
    body.cmd = msg.cmd
    body.mid = msg.mid

    local topic = "up/gateway" .. imei .. "/command"
    local payload = json.encode(body)
    noob.Publish(topic, payload)
end

function set_noob(msg)
    io.writeFile(noob.CFG, json.encode(msg.data), "w")
    reply(msg, {ret = "ok"})
    noob.Close()
end

function get_noob(msg)
    reply(msg, {ret = noob.cfg})
end






