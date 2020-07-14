# HTTP IR Controller
## Hardware
- [ESPr IR](https://www.switch-science.com/catalog/2740/)
- [USB FTDI](https://www.switch-science.com/catalog/2782/)

## How to use
- get your wifi ssid and password
- run commands bellow

```bash
WIFI_SSID=YOUR_SSID WIFI_PASSWD=YOUR_WIFI_PASSWD make write-conf
```

- run program. this causes write wifi ssid & passwd to EEPROM

- get your ir code
    - sample code is [here](https://github.com/SWITCHSCIENCE/samplecodes/tree/master/ESPr-IR/ESPrIR_dumper)- and deploy it to ESPr
    - get your own IR code

- paste ir code to the main.ino

- build & deploy

```bash
make all
```

## Reference
- [ESPr IR 赤外線リモコン データ受信機](https://github.com/SWITCHSCIENCE/samplecodes/tree/master/ESPr-IR/ESPrIR_dumper)
- [ESPr IR 赤外線リモコン データ送信機](https://github.com/SWITCHSCIENCE/samplecodes/tree/master/ESPr-IR/ESPrIR_sender)