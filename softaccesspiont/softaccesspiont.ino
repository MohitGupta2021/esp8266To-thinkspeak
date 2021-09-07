#include <ESP8266WiFi.h>

#define wifi_ssid "excitel-2.4G"
#define wifi_password "12345678**"
#define ap_ssid "open esp8266"
#define ap_password "12345678"

void setup()
{
  Serial.begin(115200);
  Serial.println();
  WiFi.softAP(ap_ssid,ap_password);
  WiFi.begin("excitel-2.4G","12345678**");
  Serial.begin('connecting to');
  Serial.println(WiFi.localIP());
  while(WiFi.status() !=WL_CONNECTED){
    Serial.print('.');
    delay(100);
  }
  Serial.println('soft ip');
  Serial.print(WiFi.softAPIP());
  
  }
 

void loop() {}
