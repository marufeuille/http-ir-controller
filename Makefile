ARDUINO := /Applications/Arduino.app/Contents/MacOS/Arduino
BUILD_DIR := build
BOARD := esp8266:esp8266:generic
PORT := /dev/tty.usbserial-D306EKAY
BAUD := 115200

.PHONY: all

all:
	$(ARDUINO) --pref build.path=$(BUILD_DIR) --board $(BOARD) --port $(PORT) --upload main.ino

write-conf:
	mkdir -p ./tmp
	cat template/save_config.ino | sed 's/^\/\/REPLACE_SSID/  strcpy(buf.ssid, \"$(WIFI_SSID)\");/' | sed 's/^\/\/REPLACE_PASSWD/  strcpy(buf.pass, \"$(WIFI_PASSWD)\");/' > ./tmp/save_config.ino 
	$(ARDUINO) --pref build.path=$(BUILD_DIR) --board $(BOARD) --port $(PORT) --upload ./tmp/save_config.ino