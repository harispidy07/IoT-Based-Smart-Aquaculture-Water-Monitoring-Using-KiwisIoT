# IoT-Based Smart Aquaculture Water Monitoring Using KiwisIoT

## Project Overview

This project monitors important water quality parameters in aquaculture systems using an ESP8266 NodeMCU, DS18B20 temperature sensor, pH sensor, turbidity sensor, and ADS1115 ADC module. It collects sensor readings and sends them to the KiwisIoT platform for remote water quality monitoring.

## Hardware Components

- ESP8266 NodeMCU
- DS18B20 Temperature Sensor
- pH Sensor Module
- Turbidity Sensor
- ADS1115 ADC Module
- Jumper Wires
- Power Supply

## Software Requirements

- Arduino IDE
- ESP8266 Board Package
- KiwisIoT Arduino Library
- OneWire Library
- DallasTemperature Library
- Adafruit ADS1X15 Library

## Circuit Connections

| Component                      | ESP8266 Pin / ADS1115 |
| ------------------------------ | --------------------- |
| DS18B20 Data                   | D4                    |
| ADS1115 SDA                    | D2                    |
| ADS1115 SCL                    | D1                    |
| ADS1115 VDD                    | 3.3V                  |
| ADS1115 GND                    | GND                   |
| pH Sensor Analog Output        | A0 (ADS1115)          |
| Turbidity Sensor Analog Output | A1 (ADS1115)          |

Connect the DS18B20 data line with an appropriate pull-up resistor. Connect the ADS1115 to the ESP8266 using the I2C interface.

## Working Principle

The DS18B20 measures water temperature, while the pH and turbidity sensors monitor water quality parameters. The ADS1115 reads the analog signals from the pH and turbidity sensors. The ESP8266 collects the readings every 5 seconds and transmits them to the KiwisIoT platform for remote monitoring.

## KiwisIoT Dashboard

| Channel   | Data                         |
| --------- | ---------------------------- |
| Channel 0 | Water Temperature (°C)       |
| Channel 1 | pH Sensor ADC Reading        |
| Channel 2 | Turbidity Sensor ADC Reading |

**Note:** The pH and turbidity readings are transmitted as raw ADC values. Calibration and suitable conversion formulas are required to obtain actual pH and turbidity measurements.

## Configuration

Update your Wi-Fi credentials and KiwisIoT Topic ID in the code:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";
const char* topic = "YOUR_TOPIC_ID";
```

Upload the code to the NodeMCU ESP8266 and monitor the aquaculture water quality readings through the KiwisIoT dashboard.

## Applications

- Smart aquaculture monitoring
- Fish farming water quality management
- Water temperature monitoring
- pH and turbidity monitoring
- Remote aquaculture management

## Project Reference

**Hackster.io Project:**  
[https://www.hackster.io/harispidy07/iot-based-smart-aquaculture-water-monitoring-using-kiwisiot-759966](https://www.hackster.io/harispidy07/iot-based-smart-aquaculture-water-monitoring-using-kiwisiot-759966)

**KiwisIoT Platform:**  
[https://kiwisiot.com/](https://kiwisiot.com/)

**KiwisIoT GitHub Repository:**  
[https://github.com/Kiwistron/KiwisIoT-Projects](https://github.com/Kiwistron/KiwisIoT-Projects)

## Author

**Hariprasath S**

GitHub: [https://github.com/harispidy07](https://github.com/harispidy07)

---

_Built using ESP8266, water quality sensors, ADS1115, and KiwisIoT for smart aquaculture monitoring._
