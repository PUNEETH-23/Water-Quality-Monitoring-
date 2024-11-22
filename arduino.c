#define PH_PIN A0
#define TURBIDITY_PIN A1
#define TDS_PIN A2

void setup() {
  Serial.begin(9600);
}

void loop() {
  float phValue = analogRead(PH_PIN);
  float turbidityValue = analogRead(TURBIDITY_PIN);
  float tdsValue = analogRead(TDS_PIN);
 
  // Send data to NodeMCU
  Serial.print(phValue*7/350);
  Serial.print(",");
  Serial.print(60-(turbidityValue*5/1023));
  Serial.print(",");
  Serial.println(1023-tdsValue);

  delay(1000); // Delay for 1 second
}
