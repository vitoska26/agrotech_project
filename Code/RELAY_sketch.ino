#include <Arduino.h>

#define RELAY_PIN2 2
#define RELAY_PIN15 15

void setup() {
  // put your setup code here, to run once:
  pinMode(RELAY_PIN2,OUTPUT);
  pinMode(RELAY_PIN15 ,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RELAY_PIN2, HIGH);
  digitalWrite(RELAY_PIN15, HIGH);
  delay(1000);
  digitalWrite(RELAY_PIN2, LOW);
  digitalWrite(RELAY_PIN15, LOW);
  delay(1000);
}
