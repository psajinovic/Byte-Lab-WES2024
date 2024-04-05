# ESP32 Wi-Fi

## Content

**1. Wi-Fi Station mode**
  Example for ESP32 in STATION MODE.
**2. Wi-Fi Access Point mode**
  Example for ESP32 in AP MODE.

  ## How to run each project?
- Position yourself in the root of the project you want to run.
- Set up required environmental variables using the `. $HOME/esp/esp-idf/export.sh` command. (You only have to run this once).
- Run the `idf.py build` command to build the project.
- Run the `idf.py flash /dev/ttyUSB0` command to flash the project. Make sure to use the appropriate USB path.
:exclamation:  If the Byte Lab Development Kit is used, `TCH_IRQ switch` on the peripheral module must be `OFF`.
- Run the `idf.py monitor /dev/ttyUSB0` command to monitor the programs output.
