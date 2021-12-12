

# 物联小白

项目以ESP32C3为基础，使用ArduinoIDE作为开发环境，有几点原因：
1. ESP32便宜，性能高，内存和Flash也很大
2. Arduino对硬件进行了封装，项目专注于上层逻辑即可
3. 



# 应用配置
系统通过加载和解析配置文件完成初始化，同样远端可以通过修改配置文件来实现系统配置。配置文件使用常用的JSON数据格式，虽然效率低，但是比较通过，能够方便与APP和后台对接。鉴于ESP32的RAM和ROM都很小，不便于处理较大的JSON文件，我们将部分内容进行拆分，避免内存占用突增。

| 配置 | 文件路径 | 内容 |
|----|----|----|
| 应用 | app.json | name, version, enable, devices, variables, command, alarms, jobs, reactors, aggregators|
| 变量 | variables/${id}.json | name, type, label, unit, value |
| 命令 | commands/${id}.json | name, label, argc, instructions:[device, point, value, arg] |
| 报警 | alarms/${id}.json | compares, dailyRanges, weekRange, delay, reset:{interval, times} |
| 策略 | reactors/${id}.json | variable, compares, invokes:[command, argv] |
| 定时任务 | jobs/${id}.json | type, daily, week, crontab, invokes:[command, argv] | 
| 设备 | devices/${id}.json | id, name, slave, element, points, variables, collectors, calculators, command, alarms, jobs |
| 聚合器 | aggregators/${id}.json | device, query, group, variable, as |
| 设备采集 | devices/${id}/collectors.json | type, interval, crontab, code, address, length |
| 设备变量 | devices/${id}/variables.json | name, label, unit, value |
| 设备点位 | devices/${id}/points.json | name, label, unit, value, code, address, type, le, precision |
| 设备命令 | devices/${id}/commands.json | name, point, instructions:[point, value, arg] |
| 设备报警 | devices/${id}/alarms.json |  compares, delay, reset:{interval, times} |
| 设备定时任务 | devices/${id}/jobs.json | type, interval, crontab, invokes:[command, argv] |


