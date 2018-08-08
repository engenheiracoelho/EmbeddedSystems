// ECO Function - return ASCII

void setup() {
  Serial.begin(9600);
}

void loop() {
    if (Serial.available()) {
      int byte_received = Serial.read();
      Serial.print(byte_received,DEC);
    }
}
