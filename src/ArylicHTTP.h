#ifndef ArylicHTTP_H
#define ArylicHTTP_H

#include <Arduino.h>
#include <HTTPClient.h>

class ArylicHTTP {

  private:
    String get(String ip, String cmd);

  public:
    ArylicHTTP();
    String getStatus(String ip);
    String getPlayerStatus(String ip);
    void playbackPause(String ip);
    void playbackResume(String ip);
    void playbackPrev(String ip);
    void playbackNext(String ip);
    void seekTo(String ip, int seconds);
    void setVolume(String ip, int vol);
    void enableMute(String ip, boolean mute);
	void playURL(String ip, String url);
	void shutdown(String ip, int seconds);
	void groupLeave(String ip);
	void groupJoin(String ip, String master);
	void setInput(String ip, String mode);
	void preset(String ip, int preset);
};

#endif
