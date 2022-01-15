#include "ArylicHTTP.h"


ArylicHTTP::ArylicHTTP() {
  
}

String ArylicHTTP::get(String ip, String cmd) {
    String uri = "http://" + ip;
    uri += "/httpapi.asp?command=";
    uri += cmd;

    HTTPClient http;
    http.begin(uri.c_str());
    int httpCode = http.GET();
    String body = http.getString();
    http.end();
    return body;
}

String ArylicHTTP::getStatus(String ip) {
  return get(ip, "getStatusEx");
}

String ArylicHTTP::getPlayerStatus(String ip) {
  return get(ip, "getPlayerStatus");
}

void ArylicHTTP::playbackPause(String ip) {
  get(ip, "setPlayerCmd:pause");
}

void ArylicHTTP::playbackResume(String ip) {
  get(ip, "setPlayerCmd:resume");
}

void ArylicHTTP::playbackPrev(String ip) {
  get(ip, "setPlayerCmd:prev");
}

void ArylicHTTP::playbackNext(String ip) {
  get(ip, "setPlayerCmd:next");
}

void ArylicHTTP::seekTo(String ip, int seconds) {
  String cmd = "setPlayerCmd:seek:" + String(seconds);
  get(ip, cmd);
}

void ArylicHTTP::setVolume(String ip, int vol) {
  String cmd = "setPlayerCmd:vol:" + String(vol);
  get(ip, cmd);
}

void ArylicHTTP::enableMute(String ip, boolean mute) {
  String cmd = "setPlayerCmd:mute:" + String(mute);
  get(ip, cmd);
}
