# ESP32 Basics

## Content

1. **GPIO**
   Example of how to use GPIO on ESP32 by controlling the LED.
3. **FreeRTOS: Thread**
   FreeRTOS thread example.
4. **FreeRTOS: Mutex**
   Mutex usage example in FreeRTOS.
5. **FreeRTOS: Software timer**
   FreeRTOS timer example. 
6. **WiFi**
   SoftAp and Wifi station example. 

## How to run each project?
- Position yourself in the root of the project you want to run.
- Set up required environmental variables using the `. $HOME/esp/esp-idf/export.sh` command. (You only have to run this once).
- Run the `idf.py build` command to build the project.
- Run the `idf.py flash -p /dev/ttyUSB0` command to flash the project. Make sure to use the appropriate USB path. <br  />:exclamation:  If the Byte Lab Development Kit is used, `TCH_IRQ switch` on the peripheral module must be `OFF`.
- Run the `idf.py monitor /dev/ttyUSB0` command to monitor the programs output.

## Configuration

The project is configured for Byte Lab Development Kit. If you want to use it on a custom board, make sure to use the appropriate GPIO pin (for driving the LED) in **2_gpio** and **6_freertos_timer** projects.