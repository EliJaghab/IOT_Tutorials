
#include "DHTesp.h"
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>

#ifndef STASSID
const char* ssid = "your-wifi";
const char* password = "your-pass";
#endif

const char* mqtt_server = "your-ip";

WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

DHTesp dht;
#define DHTpin 5

void setup() {
  Serial.begin(115200);
  pinMode(DHTpin, INPUT);
  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)\tHeatIndex (C)\t(F)");

  dht.setup(DHTpin, DHTesp::DHT11);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);

}

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();


}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");
      // Subscribe
      client.subscribe("esp32/output");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long now = millis();
  if (now - lastMsg > 5000) {
    lastMsg = now;

  
    float temperature = dht.getTemperature();
    char tempString[8];
    dtostrf(temperature, 1, 2, tempString);
    Serial.println(tempString);
    temperature = dht.toFahrenheit(temperature);   
    client.publish("temperature", tempString);
    
    float humidity = dht.getHumidity();
    char humString[8];
    dtostrf(humidity, 1, 2, humString);
    Serial.println(humString);
    client.publish("humidity", humString);
  }
}
