#define BLYNK_TEMPLATE_ID "TMPL3FLUYq7lt"
#define BLYNK_TEMPLATE_NAME "EL1"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "lWA9uS9-w1FIrDfd0t39ddqpk86SfXuc";
char ssid[] = "SSID";
char pass[] = "***PASSWORD***";

BlynkTimer timer;

void setup() {
  Serial.begin(9600); // For communication with Arduino
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');
    float phValue = data.substring(0, data.indexOf(',')).toInt();
    float turbidityValue = data.substring(data.indexOf(',') + 1, data.lastIndexOf(',')).toInt();
    float tdsValue = data.substring(data.lastIndexOf(',') + 1).toInt();
    float quality = 33.33 * ((phValue - 6.5) / 2 + (5 - turbidityValue) / 5 + (500 - tdsValue) / 450);

    Blynk.virtualWrite(V2, phValue);
    Blynk.virtualWrite(V0, turbidityValue);
    Blynk.virtualWrite(V3, tdsValue);
    Blynk.virtualWrite(V1, turbidityValue);
  }

  Blynk.run();
}
