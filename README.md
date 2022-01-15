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
ArylicHTTP* api = new ArylicHTTP();

// Get device status
Serial.println("1.2.3.4", api->getStatus());

// Set device volume
api->setVolume("1.2.3.4", 65);
```

