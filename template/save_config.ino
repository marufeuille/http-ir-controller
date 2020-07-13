#include <EEPROM.h>

struct CONFIG {
  char ssid[32];
  char pass[32];
};

void setup() {
  Serial.begin(115200);
  while (!Serial);
  Serial.println("");

  EEPROM.begin(100);

  CONFIG buf;
  EEPROM.get<CONFIG>(0, buf);
  Serial.println(buf.ssid);
  Serial.println(buf.pass);

//REPLACE_SSID
//REPLACE_PASSWD

  EEPROM.put<CONFIG>(0, buf);
  EEPROM.commit();

  Serial.println("Done");

  EEPROM.get<CONFIG>(0, buf);
  Serial.println(buf.ssid);
  Serial.println(buf.pass);
}

void loop() {
}