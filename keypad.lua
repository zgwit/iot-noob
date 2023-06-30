--- 模块功能：按键处理
-- @module keypad
-- @author 杰神
-- @license GPLv3
-- @copyright zgwit
-- @release 2023.06.30

module(..., package.seeall)


-- TODO 定义按键表，按键码




-- 按键消息处理函数
local function keyMsg(msg)
    -- 保存按键名
    -- msg.key_matrix_row：行索引
    -- msg.key_matrix_col：列索引
    log.info("keyMsg", msg.key_matrix_row, msg.key_matrix_col, msg.pressed)
    sys.publish("KEYPAD", msg.key_matrix_row, msg.key_matrix_col, msg.pressed)

    if msg.pressed == false and msg.key_matrix_col == 3 then
        --modbus_send(1, 3, 0, 16)
    end
end

rtos.on(rtos.MSG_KEYPAD, keyMsg)
rtos.init_module(rtos.MOD_KEYPAD, 0, 0x3c, 0x0F)

