

/*
* 物联小白 入口文件
* jason@zgwit.com
*
*/
#include "application.hpp"

void setup(){

}

void loop() {
  Modbus.loop();
  Cron.loop();
  Wheel.loop();
  

}
