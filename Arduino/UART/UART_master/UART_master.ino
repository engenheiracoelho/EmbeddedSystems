#define baud_rate 9600

void setup() {
  Serial.begin(baud_rate);
  int num = 0
}

// MASTER mode - Don't use the print function!
void loop() {
  Serial.write(num);
  delay(2000);
  num = 1;
  Serial.write(num);
  delay(2000);
}
