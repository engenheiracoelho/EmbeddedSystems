int val;
int digital_value;
int accumulated;
int average;
  
void setup() {
    pinMode(A0, INPUT);
    Serial.begin(9600);
}

int RMS(int repeat){
    for(int i=0; i<=repeat; i++){
       digital_value = analogRead(A0);   
       accumulated = digital_value*digital_value; 
    }
    average = accumulated/repeat;
    return sqrt(average);
}

/*
the row above should convert the digital manipulated value to a voltage/ analogic signal again acording to the following rule:
5v - 1024        1024 x voltage = average x 5
voltage - average    voltage(Vo) = averagex 5/1024
*/
float to_analog(int value){
  return (value*(5.0/1023.0));
}

void loop(){
    val = RMS(30);
    Serial.print("Digital: ");
    Serial.println(val);
    Serial.print("Analog: ");
    Serial.println(to_analog(val));
    delay(1000);
}
