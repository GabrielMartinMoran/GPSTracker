#!/bin/bash
puerto=/dev/ttyUSB0
firmwarePath=firmware.bin
esptool.py --chip esp32 --port $puerto erase_flash
esptool.py --chip esp32 --port $puerto write_flash -z 0x1000 $firmwarePath
