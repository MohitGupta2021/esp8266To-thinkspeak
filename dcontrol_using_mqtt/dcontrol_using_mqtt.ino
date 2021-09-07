#include<ESP8266WiFi.h>
#include<PubSubClient.h>
#define ssid "excitel-2.4G"
#define password "12345678**"

const char* mqtt_server ="169.254.26.86";
WiFiClient espClient;
PubSubClient client(espClient);

  
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
void callback(String topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();
if(topic=="led/pi"){
  Serial.println("changing room light to ");
  if(messageTemp=="On"){
  digitalWrite(LED_BUILTIN,HIGH);
  Serial.println("on");
}
else if(messageTemp=="off"){
  digitalWrite(LED_BUILTIN,LOW);
  Serial.println("off");
}
}
Serial.println();
}
void reconnect(){
  while(!client.connected())
{
    Serial.print("attempt to reconnect");
    if(client.connect("ESP8266Client"))
    {
      Serial.println("connected to ");
      client.subscribe("led/pi");

    }
    else{
      Serial.print("fialed, rc=");
      Serial.print(client.state());
      Serial.println("try again in 5 seconds");
      delay(5000);
    }
  }
}
 void setup(){
  pinMode(LED_BUILTIN,OUTPUT);
  Serial.begin(115200);
  conncectToWiFi();
  client.setServer(mqtt_server,1883);
  client.setCallback(callback);
 }
 void loop(){
  
  if (!client.connected()) {
    reconnect();
  }
  if(!client.loop())
    client.connect("ESP8266Client");
 }
