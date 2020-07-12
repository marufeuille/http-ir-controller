ARDUINO := /Applications/Arduino.app/Contents/MacOS/Arduino
BUILD_DIR := build
BOARD := esp8266:esp8266:generic
PORT := /dev/cu.SLAB_USBtoUART
BAUD := 115200
SKETCH = $(basename "$$PWD").ino
DEFINES := "-DWIFI_SSID=\"$$WIFI_SSID\" -DWIFI_PASSWD=\"$$WIFI_PASSWD\""

.PHONY: all

all:
	$(ARDUINO) --pref build.defines=$(DEFINES) --pref build.path=$(BUILD_DIR) --board $(BOARD) --port $(PORT) --upload $(SKETCH)