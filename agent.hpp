#pragma once

//代理程序，与服务器通讯，负责状态汇报，指令下发

typedef enum {
  AM_NONE = 0,
  AM_HEART_BEAT, //心跳，上行
  AM_CONNECT, //连接，上行
  AM_INFO, //系统信息，下行，上行
  AM_STATUS, //系统状态，下行，上行
  AM_ERROR, //系统错误

  AM_UPDATE, //更新
  AM_REBOOT, //重启，下行

  //WiFi管理
  AM_WIFI_CONNECT = 10, //连接WiFi，下行，上行
  AM_WIFI_STATUS, //WiFi状态，下行，上行
  AM_WIFI_CONFIG, //配置WiFi，IP地址等
  AM_WIFI_SCAN, //扫描WiFi热点

  //文件系统
  AM_FS_FORMAT = 20, //格式化，下行，上行
  AM_FS_LIST, //列表，下行，上行
  AM_FS_EXISTS, //是否存在，下行，上行
  AM_FS_REMOVE, //删除，下行，上行
  AM_FS_RENAME, //重命名，下行，上行
  AM_FS_MKDIR, //创建目录，下行，上行

  AM_FILE_INFO,  //文件信息，下行，上行
  AM_FILE_WRITE, //写入文件，下行，上行
  AM_FILE_READ, //读取文件，下行，上行

  //元件管理
  AM_ELEMENT_LIST = 30,
  AM_ELEMENT_WRITE,
  AM_ELEMENT_READ,
  AM_ELEMENT_REMOVE,

  //设备管理
  AM_DEVICE_LIST = 40,
  AM_DEVICE_WRITE,
  AM_DEVICE_READ,
  AM_DEVICE_REMOVE,
  AM_DEVICE_STATUS,
  AM_DEVICE_SET,
  AM_DEVICE_GET,
  AM_DEVICE_START,
  AM_DEVICE_STOP,

  //采集器  
  AM_SCAN_LIST = 50,
  AM_SCAN_WRITE,
  AM_SCAN_READ,
  AM_SCAN_REMOVE,
  AM_SCAN_STATUS,
  AM_SCAN_EXEC,
  AM_SCAN_START,
  AM_SCAN_STOP,
  
  //命令管理
  AM_COMMAND_LIST = 60,
  AM_COMMAND_WRITE,
  AM_COMMAND_READ,
  AM_COMMAND_REMOVE,
  AM_COMMAND_EXEC,
  
  //定时任务
  AM_JOB_LIST = 70,
  AM_JOB_WRITE,
  AM_JOB_READ,
  AM_JOB_REMOVE,
  AM_JOB_STATUS,
  AM_JOB_EXEC,
  AM_JOB_START,
  AM_JOB_STOP,

  //响应器
  AM_REACTOR_LIST = 80,
  AM_REACTOR_WRITE,
  AM_REACTOR_READ,
  AM_REACTOR_REMOVE,
  AM_REACTOR_STATUS,
  AM_REACTOR_EXEC,
  AM_REACTOR_START,
  AM_REACTOR_STOP,

  //报警器
  AM_ALARM_LIST = 90,
  AM_ALARM_WRITE,
  AM_ALARM_READ,
  AM_ALARM_REMOVE,
  AM_ALARM_STATUS,
  AM_ALARM_RESET,
  AM_ALARM_START,
  AM_ALARM_STOP,

  //项目管理
  AM_PROJECT_WRITE = 100,
  AM_PROJECT_READ,
  AM_PROJECT_CLEAR,
  AM_PROJECT_STATUS,
  AM_PROJECT_SET,
  AM_PROJECT_GET,
  AM_PROJECT_START,
  AM_PROJECT_STOP,
  AM_PROJECT_RELOAD,







} AGENT_MSG_E;

class AgentMessage{
  uint8 type;
  uint32 length;
  char* payload;

  char* encode();
  int decode(char* buf);
};

class Agent {

};
