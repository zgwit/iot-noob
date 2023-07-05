--- 模块功能：系统
-- @module system
-- @author 杰神
-- @license GPLv3
-- @copyright zgwit
-- @release 2023.07.03
-- 系统信息
function info()
    return {
        version = rtos.get_version(),
        hardware = rtos.get_hardware(),
        -- project = PROJECT,
        -- VERSION = VERSION,
        -- PRODUCT_KEY = PRODUCT_KEY
    }
end

function network()
    return {
        imsi = misc.getImsi(),
        iccid = misc.getIccid(),
        mcc = misc.getMcc(),
        mnc = misc.getMnc(),
        status = misc.getStatus(),
        number = misc.getNumber()
    }
end

-- 系统使用情况
function usage()
    return {
        cpu = rtos.get_env_usage(),
        -- 内存
        memory = {
            free = 1360 - collectgarbage("count"),
            total = 1360 -- Air724内存
        },
        -- 内部
        storage = {
            free = rtos.get_fs_free_size(0, 1),
            total = rtos.get_fs_total_size(0, 1)
        },
        -- SD卡
        sdcard = {
            free = rtos.get_fs_free_size(1, 1),
            total = rtos.get_fs_total_size(1, 1)
        }
    }
end

