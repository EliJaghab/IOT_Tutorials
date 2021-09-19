/*
    HTTP over TLS (HTTPS) example sketch

    This example demonstrates how to use
    WiFiClientSecure class to access HTTPS API.
    We fetch and display the status of
    esp32/Arduino project continuous integration
    build.

    Limitations:
      only RSA certificates
      no support of Perfect Forward Secrecy (PFS)
      TLSv1.2 is supported since version 2.4.0-rc1

    Created by Ivan Grokhotkov, 2015 and modified by Paul Schragger and Eli Jaghab, 2021
    This example is in public domain.
*/

#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>

#ifndef STASSID
const char* ssid = "your wifi name";
const char* password =  "your wifi password";
#endif

const char* host = "api.openweathermap.org";
const int httpsPort = 443;

// Use web browser to view and copy
// SHA1 fingerprint of the certificate
const char fingerprint[] PROGMEM = "5F F1 60 31 09 04 3E F2 90 D2 B0 8A 50 38 04 E8 37 9F BC 76";
StaticJsonDocument<1024> doc;

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Connected at ");
  Serial.println(WiFi.localIP());

  // Use WiFiClientSecure class to create TLS connection
  WiFiClientSecure client;
  Serial.print("Connecting to ");
  Serial.println(host);

  //Serial.printf("Using fingerprint '%s'\n", fingerprint);
  //client.setFingerprint(fingerprint);
  client.setInsecure();

  if (!client.connect(host, httpsPort)) {
    Serial.println("Connection Failed");
    return;
  }

  String url = "/data/2.5/weather?q=Bryn Mawr&appid=XXXXX&units=imperial";
  Serial.print("Requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: ESP32\r\n" +
               "Connection: close\r\n\r\n");

  Serial.println("Request Sent");
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("Headers Received");
      break;
    }
  }
  //String line = client.readString();
  //Serial.println(line);
  DeserializationError error = deserializeJson(doc, client.readString());

  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }

  JsonObject weather_0 = doc["weather"][0];
  const char* weather_0_description = weather_0["description"]; // "clear sky"

  JsonObject main = doc["main"];
  float main_temp_min = main["temp_min"]; // 77.07
  float main_temp_max = main["temp_max"]; // 85.66
  int main_humidity = main["humidity"]; // 52
  
  JsonObject wind = doc["wind"];
  float wind_speed = wind["speed"]; // 1.01

  JsonObject sys = doc["sys"];
  const char* name = doc["name"]; // "Bryn Mawr"

  Serial.println("The weather in " + String(name) + " today is " + String(weather_0_description) + " with a low of " + String(main_temp_min) + "F and a high of " + String(main_temp_max) + "F");
  Serial.println("The humidity is " + String(main_humidity) + "% with wind speeds of " + String(wind_speed) + "mph");
}

void loop() {
}
