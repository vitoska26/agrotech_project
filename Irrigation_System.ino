
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
#define RP15 15

//ThingSpeak channel info
unsigned long myChannelNumber = 1757836;
const char * myWriteAPIKey = "PRMQ9ELIDYEHYWPA";
//wifi 
const char* ssid = "agrotech-lab-1";
const char* password="1Afuna2Gezer";

//soil moisture sensor consts - numbered BY PIN LAYOUT
const int dry35 = 2000;// value for dry sensor
const int wet35 = 350;
const int dry32 = 2100;// value for dry sensor
const int wet32 = 550;
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
  pinMode(RP15,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  //soil sensors readings
  int sensorVal35 = analogRead(35);
  int sensorVal32 = analogRead(32);
  //SH - Soil Humidity (Moisture)
  int SH35 = map(sensorVal35, wet35, dry35, 100, 0); 
  Serial.print("Soil moisture in corn plant is "); Serial.print(SH35);
  Serial.println("%");  
  delay(100);
  int SH32 = map(sensorVal32, wet32, dry32, 100, 0); 
  Serial.print("Soil moisture in #2 pepper plant is "); Serial.print(SH32);
  Serial.println("%");  
  delay(100);

  //sensor35 - relay 15 control
  if (SH35<41){//if soil moisture 35 is below 41% *Data taken from the internet
    digitalWrite(RP15, LOW);//open the valve 
  }
  if (SH35>=41){//if soil moisture 35 is bigger or equal to 41%
    digitalWrite(RP15, HIGH);//shut the valve off, or keep it shut
  }
  //sensor32 - relay 2 control
  if (SH32<41){//if soil 32 moisture is below 41% *Data taken from the internet
    digitalWrite(RP2, LOW);//open the valve 
  }
  
  if (SH32>=41){//if soil moisture 32 is bigger or equal to 41%
    digitalWrite(RP2, HIGH);//shut the valve off, or keep it shut
  }
//------------------------------------------------------------------------------------
  //Thingspeak:
  //upload soil moisture capacity in each plant to to the appropriate channel
  //ThingSpeak.setField(1,SH35); // soil moisture in #1 pepper plant
  //ThingSpeak.setField(2,SH32); // soil moisture in tomato plant
  ThingSpeak.setField(3,SH35); // soil moisture in corn plant
  ThingSpeak.setField(4,SH32); // soil moisture in #2 pepper plant

  ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  Serial.println("uploaded to Thingspeak server....");
  
  client.stop();
  
  Serial.println("Waiting to upload next reading...");
  Serial.println();
  delay(1000);
  // thingspeak free needs minimum 15 sec delay between updates 
  
}
