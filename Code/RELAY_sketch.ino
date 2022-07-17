#include <Arduino.h>
//this code is for understanding the very simple mechanism of the relay
//connect your relay to an analog pin
#define RELAY_PIN2 2
#define RELAY_PIN15 15

void setup() {
  // put your setup code here, to run once:
  //set the pins to react to an incoming electrical current 
  pinMode(RELAY_PIN2,OUTPUT);
  pinMode(RELAY_PIN15 ,OUTPUT);

}
//using this simple commands, you can implament the command in any condition you want
//in our project the condition is the soil's moisture capacity in %
void loop() {
  // put your main code here, to run repeatedly:
  //HIGH-the relay keeps the circuit open - NO POWER
  digitalWrite(RELAY_PIN2, HIGH);
  digitalWrite(RELAY_PIN15, HIGH);
  delay(1000);//wait for 1 second
  //LOW-the relay closes the circuit - POWER!
  digitalWrite(RELAY_PIN2, LOW);
  digitalWrite(RELAY_PIN15, LOW);
  delay(1000);//wait for 1 second
}
