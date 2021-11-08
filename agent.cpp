#include <ArxContainer.h>
#include <ArduinoJson.h>


void parse() {
  DynamicJsonDocument doc(1024);
  deserializeJson(doc, json);
  const char* command = doc["cmd"];
  handlers.containsKey(command);


}


arx::map<string, handler> handlers;
  
void init() {
  handlers["info"] = handle_info;
}

void handle_info(JsonDocument &doc) {
  
}
