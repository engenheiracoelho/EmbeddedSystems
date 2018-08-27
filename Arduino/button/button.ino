#define in1 2
#define in2 3
#define out1 8
#define out2 9
  
void setup() {
  pinMode(in1, INPUT);
  pinMode(in2, INPUT);
  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);   
}

void loop(){
  digitalWrite(out1, digitalRead(in1));    
  digitalWrite(out2, digitalRead(in2));
}
