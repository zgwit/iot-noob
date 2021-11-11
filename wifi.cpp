
#include "fs.hpp"
#include <ArduinoJson.h>
#include <WiFi.h>

bool WiFi_Init()
{
    DynamicJsonDocument doc(1024);

    File file = FileSystem.open("wifi.json");
    if (!file)
    {
        Serial.println(F("Failed to read wifi file"));
        return false;
    }

    DeserializationError error = deserializeJson(doc, file);
    file.close();

    if (error)
    {
        Serial.println(F("Failed to read file, using default configuration"));
        return false;
    }
    const char* ssid = doc["ssid"];
    const char* password = doc["password"];

    WiFi.begin(ssid, password);

    return true;
}

void WiFi_Set(const char *ssid, const char *password)
{
}