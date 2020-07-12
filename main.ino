#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#ifdef WIFI_SSID
const char *WIFI_SSID = WIFI_SSID;
#else
const char *WIFI_SSID = "MYWIFI_SSID";
#endif

#ifdef WIFI_PASSWD
const char *WIFI_PASSWD = WIFI_PASSWD;
#else
const char *WIFI_PASSWD = "MYWIFI_PASSWD";
#endif

#define WIFI_PWD "ishii5261"

#define N 2000 // 最大5000程度が目安 in ESP-WROOM-02
#define IRPIN 5

ESP8266WebServer server(80);

// HTML
#define HTML_HEADER "<!doctype html>"\
  "<html><head><meta charset=\"UTF-8\"/>"\
  "<meta name=\"viewport\" content=\"width=device-width\"/>"\
  "</head><body>"
#define HTML_FOOTER "</body></html>"

void setup() {
  
  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PWD);

  // Wait until WiFi is connected
  Serial.println("");
  while(WiFi.status() != WL_CONNECTED){
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Setup WebServer Handlers
  server.on("/", [](){
    String html = HTML_HEADER "<h1>NodeMCU!</h1>" HTML_FOOTER;
    server.send(200, "text/html", html);
  });

  server.on("/led/on", [](){
    String html = HTML_HEADER "<h1>LED ON</h1>" HTML_FOOTER;
    server.send(200, "text/html", html);
  });

  server.on("/led/off", [](){
    String html = HTML_HEADER "<h1>LED OFF</h1>" HTML_FOOTER;
    server.send(200, "text/html", html);
  });

  server.begin();
}

void loop() {
  server.handleClient();
}