#define pin 6

int dutycycle_register;
int timer_clock_register;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(pin, OUTPUT);
}

void set_duty_cycle(int value){
    dutycycle_register = value;
}
 
void set_pwm_frequency(int divisor){
    timer_clock_register = divisor;
}

// the loop function runs over and over again forever
void loop(){
  set_pwm_frequency(1);
  set_duty_cycle(128);
  analogWrite(pin, timer_clock_register);
  delay(dutycycle_register);
  set_pwm_frequency(30);
  set_duty_cycle(5000);
  analogWrite(pin, timer_clock_register);
  delay(dutycycle_register/2);
}
