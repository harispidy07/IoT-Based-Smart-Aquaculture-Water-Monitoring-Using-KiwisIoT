#include <ESP8266WiFi.h>
#include <KiwisIoT.h>
#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_ADS1X15.h>

// WiFi Credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

// KiwisIoT Topic ID
const char* topic = "YOUR_TOPIC_ID";

// Sensor Pin
#define TEMP_PIN D4

// Temperature Sensor
OneWire oneWire(TEMP_PIN);
DallasTemperature tempSensor(&oneWire);

// ADS1115
Adafruit_ADS1115 ads;

// KiwisIoT
KiwisIoT kiwisiot(ssid, pass, topic);

unsigned long previousMillis = 0;

void setup() {

  Serial.begin(115200);

  Wire.begin(D2, D1);

  tempSensor.begin();

  if (!ads.begin(0x48)) {
    Serial.println("ADS1115 Not Found!");
    while (true) {
      delay(1000);
    }
  }

  ads.setGain(GAIN_ONE);

  kiwisiot.begin();

  Serial.println("Smart Aquaculture Monitoring Started");
}

void loop() {

  kiwisiot.run();

  if (millis() - previousMillis >= 5000) {

    previousMillis = millis();

    // Temperature Reading
    tempSensor.requestTemperatures();

    float temperature =
      tempSensor.getTempCByIndex(0);

    // pH Sensor Reading
    int16_t phRaw = ads.readADC_SingleEnded(0);

    // Turbidity Sensor Reading
    int16_t turbidityRaw =
      ads.readADC_SingleEnded(1);

    Serial.println("\n--- WATER QUALITY DATA ---");

    if (temperature != DEVICE_DISCONNECTED_C) {

      Serial.print("Temperature: ");
      Serial.println(temperature);

      kiwisiot.send("0", String(temperature, 2));

    } else {

      Serial.println("Temperature Sensor Error");

    }

    Serial.print("pH ADC Reading: ");
    Serial.println(phRaw);

    Serial.print("Turbidity ADC Reading: ");
    Serial.println(turbidityRaw);

    // Send data to KiwisIoT
    kiwisiot.send("1", String(phRaw));
    kiwisiot.send("2", String(turbidityRaw));

  }
}