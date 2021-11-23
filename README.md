- [物联小白](#%E7%89%A9%E8%81%94%E5%B0%8F%E7%99%BD)
- [项目配置](#%E9%A1%B9%E7%9B%AE%E9%85%8D%E7%BD%AE)
- [上位机通讯协议](#%E4%B8%8A%E4%BD%8D%E6%9C%BA%E9%80%9A%E8%AE%AF%E5%8D%8F%E8%AE%AE)
  * [包结构](#%E5%8C%85%E7%BB%93%E6%9E%84)
  * [消息类型](#%E6%B6%88%E6%81%AF%E7%B1%BB%E5%9E%8B)
  * [消息状态](#%E6%B6%88%E6%81%AF%E7%8A%B6%E6%80%81)



# 物联小白

项目以ESP32C3为基础，使用ArduinoIDE作为开发环境，有几点原因：
1. ESP32便宜，性能高，内存和Flash也很大
2. Arduino对硬件进行了封装，项目专注于上层逻辑即可
3. 



# 项目配置
系统通过加载和解析配置文件完成初始化，同样远端可以通过修改配置文件来实现系统配置。配置文件使用常用的JSON数据格式，虽然效率低，但是比较通过，能够方便与APP和后台对接。鉴于ESP32的RAM和ROM都很小，不便于处理较大的JSON文件，我们将部分内容进行拆分，避免内存占用突增。

| 配置 | 文件路径 | 内容 |
|----|----|----|
| 项目 | project.json | name, version, enable |
| 变量 | variables.json | name, type, label, unit, default |
| 命令 | commands.json | name, label, args, execute:[target, variable, value] |
| 报警 | alarms.json | variable, compare, value, value2?, timeout, resetInterval, resetTimes |
| 策略 | reactors.json | variable, compare, value, value2?, commands:[target, command, value?] |
| 定时任务 | jobs.json | type, interval, crontab, commands:[同上] | 
| 设备 | devices/${id}.json | name, slave, element |
| 设备采集 | devices/${id}/collectors.json | type, interval, crontab, code, address, length |
| 设备定时任务 | devices/${id}/jobs.json | type, interval, crontab, commands:[command, value?] |
| 元件 | elements/${id}.json | name, slave, version, url,  |
| 元件变量 | elements/${id}/variables.json | name, label, unit, default |
| 元件点位 | elements/${id}/sheets.json | name, label, unit, default, code, address, type, le, precision, readable, writable |
| 元件命令 | elements/${id}/commands.json | name, variable, value |
| 元件采集 | elements/${id}/collectors.json | type, interval, crontab, code, address, length |
| 元件报警 | elements/${id}/alarms.json | variable, compare, value, value2?, timeout, resetInterval, resetTimes |
| 元件定时任务 | elements/${id}/jobs.json | type, interval, crontab, commands:[command, value?] |


# 通讯协议（NOOB）

物联小白与上位机（服务器）通讯原计划使用MQTT协议，但MQTT并不是一个好的物联网协议（1.总线不安全，2.topic冗余，3.不适合高并发），所以根据以往项目经验重新设计了一个二进制和JSON结合的协议，暂时定名为NOOB。NOOB协议使用1个字节作为包头，包体最长支持30KB（但是建议在1KB以内，因为有些网络有限制数据包体积）。数据内容支持加密传输，默认AES（AES有硬件加速，ESP32、STM32、服务器CPU都支持）。


## 包结构

包头 1字节

|消息类型|设备状态|数据加密|包体标识|
|----|----|----|----|
|4bit|2bit|1bit|1bit|

包体 2~32676

|长包标识|内容长度|[扩展长度]|内容|
|----|----|----|----|
|1bit|7bit|[8bit]|1~32676 byte|

*长包标识为1时，使用扩展长度表示长度大于127的包*


## 消息类型

| 序号 | 类型 | 方向 | 类型 | 内容 |
|----|----|----|----|----|
| 0 | NONE | - | - | - |
| 1 | CONNECT | 上行 | 鉴权 | json |
| 2 | HEARTBEAT | 上行 | 心跳 |-|
| 3 | QUERY | 下行 | 查询 |json|
| 4 | STATUS | 上行 | 状态 |json|
| 5 | UPDATE | 下行 | 修改 |json|
| 6 | CONTROL | 下行 | 控制 |json|
| 7 | EVENT | 上行 | 事件 |json|
| 8 | ALARM | 上行 | 报警 |json|
| 9 | LOG | 上行 | 日志 |string|
| 10 | APP | 下行 | 应用管理 |json|
| 11 | FS | 下行 | 文件管理 |json|
| 12 | SYSTEM | 下行 | 系统设置 |json|
| 13 | DATA | 双向 | 数据 |binary|
| 14 | FINISH | 下行 | 结束 | - |
| 15 | DISCONNECT | 双向 | 断开 |[string]|

## 消息状态

| 序号 | 类型 | 说明 |
|----|----|----|
| 0 | NORMAL | - |
| 1 | BUSY | 忙 |
| 2 | ERROR | 错误 |
| 3 | UNSUPPORTED | 不支持 |

