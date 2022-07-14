//------------------------------------------------------------------
//Thingspeak:
// #include <ESP8266WiFi.h>
#include <Arduino.h>
#include <WiFi.h>
#include <math.h>
#include <Adafruit_GFX.h>
#include "ThingSpeak.h"
#include "i2cArduino.h"

//RELAY PINS
#define RP2 2
#define RP4 4
#define RP12 12
#define RP15 15

unsigned long myChannelNumber = 1757836;
const char * myWriteAPIKey = "PRMQ9ELIDYEHYWPA";
//
const char* ssid = "agrotech-lab-1";
const char* password="1Afuna2Gezer";


//soil moisture sensor consts - sensor with added 1M ohm resistor - BY PIN LAYOUT
const int dry35 =  2950;// value for dry sensor
const int wet35 = 1000;
const int dry32 = 2100;// value for dry sensor
const int wet32 = 540;
const int dry27 = 2970;// value for dry sensor
const int wet27 = 1090;
const int dry13 = 2950;// value for dry sensor
const int wet13 = 1040;
const char* server = "api.thingspeak.com";

WiFiClient client;

#include <Wire.h>

//------------------------------------------------------------------

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println();
  Serial.print("Connecting to AP");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(200);
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println();
//--------------------------------------
//Thingspeak and wifi:
  WiFi.disconnect();
  delay(10);
  WiFi.begin(ssid, password);

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  ThingSpeak.begin(client);
 
  WiFi.begin(ssid, password);
  
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("NodeMcu connected to wifi...");
  Serial.println(ssid);
  Serial.println();
  //------------------------------------------------------------------
  //relay setup
  pinMode(RP2,OUTPUT);
  pinMode(RP4,OUTPUT);
  pinMode(RP12,OUTPUT);
  pinMode(RP15,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  //soil sensors
  int sensorVal35 = analogRead(35);
  int sensorVal32 = analogRead(32);
  int sensorVal27 = analogRead(27);
  int sensorVal13 = analogRead(13);

  //SH - Soil Humidity
  int SH35 = map(sensorVal35, wet35, dry35, 100, 0); 
  Serial.print("Soil moisture in pepper plant is "); Serial.print(SH35);
  Serial.println("%");  
  delay(100);
  int SH32 = map(sensorVal32, wet32, dry32, 100, 0); 
  Serial.print("Soil moisture in tomato plant is "); Serial.print(SH32);
  Serial.println("%");  
  delay(100);
  int SH27 = map(sensorVal27, wet27, dry27, 100, 0); 
  Serial.print("Soil moisture in corn plant is "); Serial.print(SH27);
  Serial.println("%");  
  delay(100);
  int SH13 = map(sensorVal13, wet13, dry13, 100, 0); 
  Serial.print("Soil moisture in pepper plant is "); Serial.print(SH13);
  Serial.println("%");  
  delay(100);

  //sensor35 - relay 15 control
  if (SH35<41){//if soil moisture 35 is below 41% *Data taken from the internet
    digitalWrite(RP15, LOW);//open the valve 
  }
  if (SH35>41){//if soil moisture 35 is bigger then 41%
    digitalWrite(RP15, HIGH);//shut the valve off, or keep it shut
  }
  //sensor32 - relay 2 control
  if (SH32<41){//if soil 32 moisture is below 41% *Data taken from the internet
    digitalWrite(RP2, LOW);//open the valve 
  }
  if (SH32>41){//if soil moisture 32 is bigger then 41%
    digitalWrite(RP2, HIGH);//shut the valve off, or keep it shut
  }
  //sensor27 - relay 12 control
  if (SH27<41){//if soil moisture 27 is below 41% *Data taken from the internet
    digitalWrite(RP12, LOW);//open the valve 
  }
  if (SH27>41){//if soil moisture 27 is bigger then 41%
    digitalWrite(RP12, HIGH);//shut the valve off, or keep it shut
  }
  //sensor13 - relay 4 control
  if (SH13<41){//if soil moisture 0 is below 41% *Data taken from the internet
    digitalWrite(RP4, LOW);//open the valve 
  }
  if (SH13>41){//if soil moisture 0 is bigger then 41%
    digitalWrite(RP4, HIGH);//shut the valve off, or keep it shut
  }
//------------------------------------------------------------------------------------
  //Thingspeak:
  ThingSpeak.setField(1,SH35); // soil moisture 35
  ThingSpeak.setField(2,SH32); // soil moisture 32
  ThingSpeak.setField(3,SH27); // soil moisture 27
  ThingSpeak.setField(4,SH13); // soil moisture 13
  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  Serial.println("uploaded to Thingspeak server....");
  
  client.stop();
  
  Serial.println("Waiting to upload next reading...");
  Serial.println();
  delay(1000);
  // thingspeak free needs minimum 15 sec delay between updates 
  
}
