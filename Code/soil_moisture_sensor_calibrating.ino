//the code shows the bit readings from the sensor every 1 milli-second.
//first watch the serial monitor while the sensor is completly dry, wait a minute and decide on an average value - that's the dry value
//then put the sensor in a glass of water (not fully submerged), that's the 100% wet value, decide on an average value like before.
//right these values own, these would be the "wet##" and "dry##" consts for this specific sensor in the project's code. 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(13));//pick any analog pin you want
  delay(100);//wait 1 milli-second
}
