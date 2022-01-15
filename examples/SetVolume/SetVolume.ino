#include <ArylicHTTP.h>

#define WIFI_SSID "network.name"
#define WIFI_PASS "<password>"

#define ARYLIC_IP "10.3.106.120"

void setup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while(WiFi.status() != WL_CONNECTED) {
    delay(1);
  }

  ArylicHTTP* api = new ArylicHTTP();
  api->setVolume(ARYLIC_IP, 75);
}

void loop() {}

