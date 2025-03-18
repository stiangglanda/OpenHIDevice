# OpenHIDevice

A compact, programmable input peripheral that combines customizable buttons with mouse functionality, built on the ESP32 platform.

## Overview

OpenHIDevice is an open-source hardware project that creates a versatile input device combining the functionality of programmable buttons (similar to a Stream Deck) with mouse cursor control capabilities. Built around the ESP32 microcontroller, this device offers a space-efficient alternative to having multiple input peripherals.

https://github.com/user-attachments/assets/15c544cc-acb0-47aa-90a2-82ebc2b00d73

## Features

- **Programmable Buttons**: Bind custom functions, macros, or shortcuts to physical buttons
- **Mouse Functionality**: Control cursor movement from the same device
- **Compact Design**: Smaller footprint than commercial alternatives
- **ESP32 Powered**: Leverages the capabilities of the ESP32 microcontroller
- **Open Source**: Hardware designs and firmware are fully customizable
- **Cross-platform**: Compatible with Windows, macOS, and Linux

## Hardware Requirements

- ESP32 microcontroller
- Pushbuttons/mechanical switches
- Joy Stick for cursor control
- Micro USB cable (for power and programming)

## Installation

### Installing the Firmware

1. Clone this repository:
```bash
git clone https://github.com/stiangglanda/OpenHIDevice.git
cd OpenHIDevice
```

2. Open the project in PlatformIO

3. Build and upload to your ESP32:
```bash
pio run -t upload
```

## Future Improvements

- Wireless connectivity option
- Custom configuration app
- OLED display for button labels
- Expanded gesture controls
- Battery power option
- PCB
