#include <ArylicHTTP.h>

#define WIFI_SSID "network.name"
#define WIFI_PASS "<password>"

#define ARYLIC_M "192.168.1.200"
#define ARYLIC_S "192.168.1.201"

void setup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while(WiFi.status() != WL_CONNECTED) {
    delay(1);
  }

  ArylicHTTP* apiM = new ArylicHTTP(ARYLIC_M);
  ArylicHTTP* apiS = new ArylicHTTP(ARYLIC_S);

  apiM->groupLeave();
  apiS->groupLeave();

  delay(100);
  
  apiS->groupJoin(ARYLIC_M);

  delay(250);

  apiM->setVolume(65);
  apiS->setVolume(40);

  delay(100);

  apiM->preset(1);
}

void loop() {}

