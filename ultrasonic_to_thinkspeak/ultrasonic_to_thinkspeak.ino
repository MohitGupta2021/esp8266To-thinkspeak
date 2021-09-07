
//field 1 we send distance in inches 
#include<ESP8266WiFi.h>
#include<WiFiClient.h>
#include<ESP8266HTTPClient.h>

WiFiClient client;
HTTPClient http;
String url;
String api="RJK0LWSP09MB1PZX";
String Field_no="1";
int httpcode;


  

//trig green d1=GPIO5

//echo blue d2=gpio 4

const int trigPin = 5;
const int echoPin = 4;

//define sound velocity in cm/uS
#define SOUND_VELOCITY 0.034
#define CM_TO_INCH 0.393701

long duration;
float distanceCm;
float distanceInch;

void setup() {
  Serial.begin(115200); // Starts the serial communication
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);
  conncectToWiFi();// Sets the echoPin as an Input
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance
  distanceCm = duration * SOUND_VELOCITY/2;
  
  // Convert to inches
  distanceInch = distanceCm * CM_TO_INCH;
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);
  Serial.print("Distance (inch): ");
  Serial.println(distanceInch);
  sendGetRequest(distanceInch);
  delay(20000);
  
  
  delay(1000);
}
void sendGetRequest(double data){
  url="http://api.thingspeak.com/update?api_key=";
  url=url+api;
  url=url+"&field";
  url=url+Field_no;
  url=url+"=";
  url=url+data;
  http.begin(client,url);
  Serial.println("waiting for response");
    httpcode=http.GET();
    if(httpcode>0){
      Serial.print(115200);
      Serial.println("-data sent successfully");
    }
      else{
        Serial.println("error sending");
      }
      http.end();
      
    }
  
void conncectToWiFi(){
   WiFi.mode(WIFI_STA); // nodemcu as station
  WiFi.begin("excitel-2.4G","12345678**");
  Serial.print("connecting to wifi");
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.print('.');
    delay(200);
  }
  Serial.print("IP Address:");
  Serial.println(WiFi.localIP());
  Serial.print("MacAddress:");
  Serial.println(WiFi.macAddress());
}
