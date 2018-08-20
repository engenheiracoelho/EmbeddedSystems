/* Usando Round Robin sem interrupções implementar um
sistema com um LED e um botão. O sistema deve piscar 
o LED a cada 2 segundos e ao botão ser pressionado 
envia uma mensagem pela serial. */

#define in1 2
#define out1 8
int estado=0;
int counter=0;

void setup() {
  pinMode(in1, INPUT);
  pinMode(out1, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int readPin = digitalRead(in1);
  delay(1);
  if(digitalRead(in1) != readPin){
    Serial.println("Botão pressionado");
  }else{
    if(counter==2000){
      estado = !estado;
      counter=0;
      digitalWrite(out1,estado);
    }else{
      counter++;
      delay(1);
    }
  }
}
