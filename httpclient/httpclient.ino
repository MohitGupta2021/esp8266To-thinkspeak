#include<ESP8266WiFi.h>
#include<WiFiClient.h>
#include<ESP8266HTTPClient.h>


void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
connectToWifi();

}

void loop() {
  // put your main code here, to run repeatedly:

}
void connectToWifi(){
  WiFi.mode(WIFI_STA);
  WiFi.begin("excitel-2.4G","12345678**");
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print('.');
    delay(100);
  }
  Serial.print("ip address");
  Serial.print("\t",WiFi.localIP());
  Serial.print("Mac address");
  Serial.print(WiFi.macAddress());
}
