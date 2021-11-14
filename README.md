# 物联小白

项目以ESP32C3为基础，使用ArduinoIDE 2.0作为开发环境，几点原因：
1. ESP32便宜，性能高，内存和Flash大
2. Arduino对硬件进行了封装，无需关心过多底层的东西，专注于上层逻辑即可


## 配置文件
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


