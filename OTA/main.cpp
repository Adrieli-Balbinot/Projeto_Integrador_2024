#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ArduinoOTA.h>

const char *ssid = "";
const char *passoword = "";

void setup()
{
    Serial.begin(9600);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, passoword);

    while (WiFi.waitForConnectResult() != WL_CONNECTED)
    {
        Serial.println("Conexão falhou! Rebooting");
        WiFi.begin(ssid, passoword);
        delay(500);
    }

    ArduinoOTA.onStart([]()
                       { Serial.println("Start"); });

    ArduinoOTA.onEnd([](){
        Serial.println("End");
    });

    ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
        Serial.printf("Progress: ", (progress / (total /100)));
    });


    ArduinoOTA.onError([](ota_error_t error) {
        Serial.printf("Error[%u]: ", error);
        if(error == OTA_AUTH_ERROR) Serial.println("Auth failed");
        else if(error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
        else if (error == OTA_CONNECT_ERROR) Serial.println("Connected Failed");
        else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    });
    ArduinoOTA.begin();
    Serial.println("Pronto");
    Serial.print("IP:");
    Serial.println(WiFi.localIP());
}

void loop() {
    ArduinoOTA.handle();
}
