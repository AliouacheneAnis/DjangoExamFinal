/*
  Titre      : Controler moteur a l'aide de deux bouton 
  Auteur     : Anis Aliouachene
  Date       : 12/12/2022
  Version    : 0.0.1
*/

/*
  Rui Santos
  Complete project details at Complete project details at https://RandomNerdTutorials.com/esp32-http-post-ifttt-thingspeak-arduino/ 

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_AHTX0.h>


Adafruit_AHTX0 aht;


const char* ssid = "Ste-adele";
const char* password = "allo1234";

// Domain Name with full URL Path for HTTP POST Request
const char* serverName = "http://127.0.0.1:8000/postbme/";


unsigned long lastTime = 0;
unsigned long timerDelay = 10000;
float Temperature, Humidity; 
String IDcapteur = "1"; 
int IDdata = 5 ; 

void setup() {
  Serial.begin(9600);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
 
  
  if (aht.begin()) {
    Serial.println("Found AHT20");
  } else {
    Serial.println("Didn't find AHT20");
  }  
  
}

void loop() {

  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);

  //Send an HTTP POST request every 10 seconds
  if ((millis() - lastTime) > timerDelay) {
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      WiFiClient client;
      HTTPClient http;
    
      // Your Domain name with URL path or IP address with path
      http.begin(client, serverName);

      // If you need an HTTP request with a content type: application/json, use the following:
      http.addHeader("Content-Type", "application/json");
      // JSON data to send with HTTP POST
      String httpRequestData = "{\'Capteur\': [\'" + IDcapteur + "\'],\'IDdatabme\': [\'" + String(IDdata) + "\'],\'tmp\': [\'" + String(temp.temperature) + "\'],\'hum\': [\'" + String(humidity.relative_humidity)  + "\']}";           
      // Send HTTP POST request
      Serial.println(httpRequestData);
      int httpResponseCode = http.POST(httpRequestData); // send data 

      IDdata += 1; 

      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
        
      // Free resources
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}