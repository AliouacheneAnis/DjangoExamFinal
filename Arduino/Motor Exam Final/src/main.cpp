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


const char* ssid = "Ste-adele";
const char* password = "allo1234";

// Domain Name with full URL Path for HTTP POST Request
const char* serverName = "http://127.0.0.1:8000/postmotor/";

const int PIN1 = 4, PIN2 = 5; 
int val1 , val2 , val1precedent = 0, Val2Precedent = 0; 
String IDcapteur = "2"; 
int IDdata = 3; 
String Btn1, Btn2; 

void setup() {

  Serial.begin(9600);
  pinMode(PIN1, INPUT);
	pinMode(PIN2, INPUT);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
 
}

void loop() {

  val1 = digitalRead(PIN1);
  val2 = digitalRead(PIN2);

  //Send an HTTP POST request every 10 seconds
  if (val1 != val1precedent || val2 != Val2Precedent) {

    if (val1 == 1)
    {
      Btn1 = "ON";
    }else
    {
      Btn1 = "OFF"; 
    }
    
     if (val2 == 1)
     {
      Btn2 = "ON";
     }else
     {
       Btn2 = "OFF";
     }
     
     
    //Check WiFi connection status
    if(WiFi.status()== WL_CONNECTED){
      WiFiClient client;
      HTTPClient http;
    
      // Your Domain name with URL path or IP address with path
      http.begin(client, serverName);
      
      // If you need an HTTP request with a content type: application/json, use the following:
      http.addHeader("Content-Type", "application/json");
      // JSON data to send with HTTP POST
      String httpRequestData = "{\'Capteur2\': [\'" + IDcapteur + "\'],\'IDdatamotor\': [\'" + String(IDdata) + "\'],\'btn1\': [\'" +  Btn1 + "\'],\'btn2\': [\'" + Btn2  + "\']}";           
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
    
    val1precedent = val1; 
    Val2Precedent = val2; 
  }
}