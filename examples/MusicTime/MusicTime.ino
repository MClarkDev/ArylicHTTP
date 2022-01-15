#include <ArylicHTTP.h>

#define WIFI_SSID "network.name"
#define WIFI_PASS "<password>"

#define ARYLIC_DEV_M "10.3.106.120"
#define ARYLIC_DEV_S "10.3.106.121"

void setup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while(WiFi.status() != WL_CONNECTED) {
    delay(1);
  }

  ArylicHTTP* api = new ArylicHTTP();

  api->groupLeave(ARYLIC_DEV_M);

  delay(250);
  
  api->groupLeave(ARYLIC_DEV_S);
  
  delay(100);
  
  api->groupJoin(ARYLIC_DEV_S, ARYLIC_DEV_M);

  delay(250);

  api->setVolume(ARYLIC_DEV_M, 65);
  api->setVolume(ARYLIC_DEV_S, 40);

  delay(100);

  api->preset(ARYLIC_DEV_M, 1);
}

void loop() {}
