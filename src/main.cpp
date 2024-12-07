#include <WebServer.h>
#include <WiFi.h>
#include "stens_moisture_sensor.h"

const char* ssid = "ZYXEL-522";
const char* password = "birkannsten!";

WebServer server(80);
StensMoistureSensor sms("prototyp");

void handle_root() {
  String out = sms.getHTML();
  server.send(200, "text/html", out);
}

void handle_json() {
  String out = sms.getJson();
  server.send(200, "application/json", out);
}


void setup() {
  pinMode(32, INPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  digitalWrite(25, HIGH);
  digitalWrite(26, HIGH);
  digitalWrite(27, HIGH);
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.on("/", handle_root);
  server.on("/json", handle_json);
  server.begin();
}

void loop() {
  server.handleClient();
  
  Serial.println(sms.getRaw());
  delay(500);
}

