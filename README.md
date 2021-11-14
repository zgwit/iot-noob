# 物联小白

项目以ESP32C3为基础，使用ArduinoIDE 2.0作为开发环境，几点原因：
1. ESP32便宜，性能高，内存和Flash大
2. Arduino对硬件进行了封装，无需关心过多底层的东西，专注于上层逻辑即可



## 配置文件

### 项目配置 project.json
```json
{
    "name": "示例项目",
    "version": "1.0",
    "enable": true
}
```

### 变量 var/[name].json
```json
{
    "type": "uint8",
    "label": "数量",
    "default": 1,
    "unit": "个"
}
```


### 命令 cmd/[name].json
```json
{
    "label": "名称",
    "args": 0,
    "task": [
        {
            "type":"set",
            "variable": "count",
            "value": 1
        },
        {
            "type":"expression",
            "variable": "count",
            "value": "$1"
        },
        {
            "type":"command",
            "variable": "recovery",
            "value": "$1"
        }
    ]
}
```


### 设备 dev/[name].json
```json
{
    "slave": 1,
    "element": "元件名（ID）",
    "enable": true
}
```



### 采集器 dev/[name]/scan/xxx.json
```json
{
    "slave": 1,
    "element": "元件名（ID）",
    "enable": true
}
```


### 元件库 elem/[name].json
```json
{
    "name": "元件名称",
    "collectors": [],
    "validators": [],
    "slave": {
        "default": 1,
        "address": 0
    },
    "map": [
        {
            "name": "var1",
            "label": "变量",
            "code": 3,
            "address": 0,
            "type": "uint16",
            "le": false,
            "precision": 0,
            "default": 0,
            "readable": true,
            "writable": true
        }
    ]
}
```

