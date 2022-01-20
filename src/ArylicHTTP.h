#ifndef ArylicHTTP_H
#define ArylicHTTP_H

#include <Arduino.h>
#include <HTTPClient.h>

class ArylicHTTP {

  private:
    String target;
    String get(String cmd);

  public:
    ArylicHTTP(String ip);
    String getStatus();
    String getPlayerStatus();
    void playbackPause();
    void playbackResume();
    void playbackTogglePlay();
    void playbackPrev();
    void playbackNext();
    void seekTo(int seconds);
    void setVolume(int vol);
    String setVolumeStepUp();
    String setVolumeStepDown();
    void enableMute(boolean mute);
    void playURL(String url);
    void shutdown(int seconds);
    void groupLeave();
    void groupJoin(String master);
    void setInput(String mode);
    void preset(int preset);
};

#endif
