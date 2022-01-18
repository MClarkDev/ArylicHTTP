#include <ArylicHTTP.h>

#define WIFI_SSID "network.name"
#define WIFI_PASS "<password>"

#define ARYLIC_IP "192.168.1.200"

void setup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while(WiFi.status() != WL_CONNECTED) {
    delay(1);
  }

  ArylicHTTP* api = new ArylicHTTP(ARYLIC_IP);
  api->setVolume(75);
}

void loop() {}

