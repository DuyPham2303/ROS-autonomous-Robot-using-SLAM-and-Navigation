#include "Arduino.h"
#include "Motor.h"


Motor::Motor(int PWM_pin, int plus_1, int minus, int en_a, int en_b) {
  pinMode(PWM_pin,OUTPUT);
  pinMode(plus,OUTPUT);
  pinMode(minus,OUTPUT);
  pinMode(en_a,INPUT_PULLUP);
  pinMode(en_b,INPUT_PULLUP);
  Motor::PWM_pin = PWM_pin;
  Motor::plus = plus_1;
  Motor::minus = minus;
  Motor::en_a = en_a;
  Motor::en_b = en_b;
}

void Motor::rotate(int value) {
  if(value>=0){
    //Max Voltage with 16V battery with 12V required
    //(12/16)*255 ~=190
//    Serial.println("called");
//    Serial.println(plus);
    int out = map(value, 0, 100, 0, 255);
    analogWrite(PWM_pin,out);
    digitalWrite(plus,LOW);
    digitalWrite(minus,HIGH);
  }else{
    //Max Voltage with 16V battery with 12V required
    //(12/16)*255 ~=190
    int out = map(value, 0, -100, 0, 255);
    analogWrite(PWM_pin,out);
    digitalWrite(plus,HIGH);
    digitalWrite(minus,LOW);
  }
}
