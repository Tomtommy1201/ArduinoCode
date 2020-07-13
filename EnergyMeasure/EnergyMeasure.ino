//#include <ESP8266WiFi.h>
//#include <ESP8266WebServer.h>
#include <stdio.h>
#include <string.h>
#include <SoftwareSerial.h>

#ifndef STASSID
#define STASSID "type-your-ssid"
#define STAPSK  "type-your-password"
#endif


const char* ssid = STASSID;
const char* password = STAPSK;
SoftwareSerial mySerial(10,11);
//ESP8266WebServer server(80);

const int led = 13;

void handleRoot() {
  digitalWrite(led, 1);
//  server.send(200, "text/plain", "hello from esp8266!");
  digitalWrite(led, 0);
}
/*
void handleNotFound() {
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
//  message += "URI: ";
//  message += server.uri();
//  message += "\nMethod: ";
//  message += (server.method() == HTTP_GET) ? "GET" : "POST";
 // message += "\nArguments: ";
//  message += server.args();
//  message += "\n";
//  for (uint8_t i = 0; i < server.args(); i++) {
//    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
//  }
//  server.send(404, "text/plain", message);
//  digitalWrite(led, 0);
}
*/
void setup(void) {
  //LED Pin Setting
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  //Serial Setting
  mySerial.begin(9600);
  Serial.begin(9600);
//  WiFi.mode(WIFI_STA);
  //begin WiFi Connecting
//  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
//  while (WiFi.status() != WL_CONNECTED) {
//    delay(500);
//    Serial.print(".");
//  }
  
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
//  Serial.println(WiFi.localIP());

 
//  server.on("/", handleRoot);

//  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
//  server.handleClient();
}
