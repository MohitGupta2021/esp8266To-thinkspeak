

// station mode
#include<ESP8266WiFi.h>
void connectToWiFi(){
 WiFi.mode(WIFI_STA);
 WiFi.begin("excitel-2.4G","12345678**");
 while(WiFi.status() !=WL_CONNECTED)
 {
  Serial.print('.');
  delay(200);
 }
 Serial.print("IP ADDRESSS");
 Serial.println(WiFi.localIP());
 Serial.print("Mac adresss");
 Serial.print(WiFi.macAddress());
 
  
}
void setup() {
 Serial.begin(115200);
 connectToWiFi();
 
 // Initialize the LED_BUILTIN pin as an output
}

void loop() {
                        // Wait for two seconds
}
