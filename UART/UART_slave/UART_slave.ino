#define baud_rate 9600
#define led 8

int byte_received = 0;
  
void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(baud_rate);

}

// SLAVE mode
void loop() {
   if (Serial.available() > 0 ) {
      byte_received = Serial.read();
      Serial.println(byte_received);
   }
   digitalWrite(led, byte_received);
}
