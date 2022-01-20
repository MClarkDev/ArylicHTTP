/**
 * ArylicHTTP, 0.0.2
 *
 * A simple ESP32 library for interfacing with Arylic audio devices.
 *
 * MClarkDev.com, 2022
 */

#include "ArylicHTTP.h"

ArylicHTTP::ArylicHTTP(String ip) {
  target = ip;
}

String ArylicHTTP::get(String cmd) {
  String uri = "http://" + target;
  uri += "/httpapi.asp?command=" + cmd;

  HTTPClient http;
  http.begin(uri.c_str());
  http.GET();
  String body = http.getString();
  http.end();
  return body;
}

String ArylicHTTP::getStatus() {
  return get("getStatusEx");
}

String ArylicHTTP::getPlayerStatus() {
  return get("getPlayerStatus");
}

void ArylicHTTP::playbackPause() {
  get("setPlayerCmd:pause");
}

void ArylicHTTP::playbackResume() {
  get("setPlayerCmd:resume");
}

void ArylicHTTP::playbackTogglePlay() {
  get("setPlayerCmd:onepause");
}

void ArylicHTTP::playbackPrev() {
  get("setPlayerCmd:prev");
}

void ArylicHTTP::playbackNext() {
  get("setPlayerCmd:next");
}

void ArylicHTTP::seekTo(int seconds) {
  get("setPlayerCmd:seek:" + String(seconds));
}

void ArylicHTTP::setVolume(int vol) {
  get("setPlayerCmd:vol:" + String(vol));
}

String ArylicHTTP::setVolumeStepUp() {
  return get("setPlayerCmd:Vol%2B%2B");
}

String ArylicHTTP::setVolumeStepDown() {
  return get("setPlayerCmd:Vol--");
}

void ArylicHTTP::enableMute(boolean mute) {
  get("setPlayerCmd:mute:" + String(mute));
}

void ArylicHTTP::playURL(String url) {
  get("setPlayerCmd:play:" + url);
}

void ArylicHTTP::shutdown(int seconds) {
  get("setShutdown:" + String(seconds));
}

void ArylicHTTP::groupLeave() {
  get("multiroom:Ungroup");
}

void ArylicHTTP::groupJoin(String master) {
  get("ConnectMasterAp:JoinGroupMaster:eth" + master + ":wifi0.0.0.0");
}

void ArylicHTTP::setInput(String mode) {
  get("setPlayerCmd:switchmode:" + mode);
}

void ArylicHTTP::preset(int preset) {
  get("MCUKeyShortClick:" + String(preset));
}
