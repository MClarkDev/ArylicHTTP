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
   String cmd = "getStatusEx";
  return get(ip, cmd);
}

String ArylicHTTP::getPlayerStatus(String ip) {
  String cmd = "getPlayerStatus";
  return get(ip, cmd);
}

void ArylicHTTP::playbackPause(String ip) {
  String cmd = "setPlayerCmd:pause";
  get(ip, cmd);
}

void ArylicHTTP::playbackResume(String ip) {
  String cmd = "setPlayerCmd:resume";
  get(ip, cmd);
}

void ArylicHTTP::playbackPrev(String ip) {
  String cmd = "setPlayerCmd:prev";
  get(ip, cmd);
}

void ArylicHTTP::playbackNext(String ip) {
  String cmd = "setPlayerCmd:next";
  get(ip, cmd);
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

void ArylicHTTP::playURL(String ip, String url) {
  String cmd = "setPlayerCmd:play:" + url;
  get(ip, cmd);
}

void ArylicHTTP::shutdown(String ip, int seconds) {
  String cmd = "setShutdown:" + String(seconds);
  get(ip, cmd);
}

void ArylicHTTP::groupLeave(String ip) {
  String cmd = "multiroom:Ungroup";
  get(ip, cmd);
}

void ArylicHTTP::groupJoin(String ip, String master) {
  String cmd = "ConnectMasterAp:JoinGroupMaster:eth" + master + ":wifi0.0.0.0";
  get(ip, cmd);
}

void ArylicHTTP::setInput(String ip, String mode) {
  String cmd = "setPlayerCmd:switchmode:" + mode;
  get(ip, cmd);
}

void ArylicHTTP::preset(String ip, int preset) {
  String cmd = "MCUKeyShortClick:" + String(preset);
  get(ip, cmd);
}
