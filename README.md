# ArylicHTTP

A simple ESP32 library for interfacing with Arylic audio devices.

## Installation

Download the repository, and extract the ZIP to `~/Documents/Arduino/libraries/`

Include the libary in your project using

```
#include "ArylicHTTP.h"
```

## Usage

Once the device has been connected to WiFi, usage of the library is quite simple.

```
ArylicHTTP* device = new ArylicHTTP("192.168.1.200");

// Get device status
Serial.println(device->getStatus());
Serial.println(device->getPlayerStatus());

// Play / Pause
device->playbackPause();
device->playbackResume();

// Next / Prev
device->playbackNext();
device->playbackPrev();

// Media Control
device->seekTo(seconds);
device->playURL("http://url");
device->preset(4);
device->setInput(mode);

// Set device volume
device->setVolume(65);
device->setVolumeStepUp();
device->setVolumeSetpDown();
device->enableMute(true);

// Grouping
device->groupLeave();
device->groupJoin(master);

// Misc
device->shutdown(delay);
```

