

/*
* 物联小白 入口文件
* jason@zgwit.com
*
*/
#include "application.hpp"

#include <WiFi.h>

void setup(){

  WiFi.begin();

  Serial.begin(115200);
  
  App.Begin();
}

void loop() {
  Modbus.loop();
  Cron.loop();
  Wheel.loop();
  

}
