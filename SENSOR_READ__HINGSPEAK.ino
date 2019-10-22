#include <ESP8266WiFi.h>;

#include <WiFiClient.h>;

#include <ThingSpeak.h>;

const char* ssid = "ELEMENTZ"; //Your Network SSID

const char* password = "4716006699"; //Your Network Password

int val;

int ALCOHOL_SENSOR = A0; 


WiFiClient client;

unsigned long myChannelNumber = 889174; //Your Channel Number (Without Brackets)

const char * myWriteAPIKey = "FS98RPKUE3KUHKVP"; //Your Write API Key

void setup()

{

Serial.begin(9600);

delay(10);

// Connect to WiFi network

WiFi.begin(ssid, password);



ThingSpeak.begin(client);

}



void loop()

{

val = analogRead(ALCOHOL_SENSOR); //Read Analog values and Store in val variable

Serial.print(val); //Print on Serial Monitor

delay(1000);

ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey); //Update in ThingSpeak



delay(100);

}
