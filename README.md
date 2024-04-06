# WES 2024

## Content

1. **Basic Introductin**
   Usage of GPIOs.
2. **FreeRTOS**
   Basic FreeRTOS concepts.
3. **WiFi**
   Connectivity.
4. **GUI**
   Graphical User Interface.

## Requirements
- ESP-IDF v5.0.x

## Getting started with the repository
- Clone the project with `git clone`.
- Run `git submodule update --init --recursive` to update submodules (LVGL).
- Before running the GUI examples, you must position yourself in the `components/lvgl_esp32_drivers` directory and run `git apply ../lvgl_esp32_drivers_8-3.patch`.
- Before running the GUI examples, copy `sdkconfig.defaults` over `sdkconfig` (`cp sdkconfig.defaults sdkconfig`)


## Building, flashing and monitoring
- Set up required environmental variables. 
   - Windows users: Open the ESP terminal and position yourself in the root of the example you want to run.
   - Linux users: Position yourself in the root of the example you want to run and execute `. $HOME/esp/esp-idf/export.sh` command.
- Build the project.
   - Run the `idf.py build` command.
- Flash the project.
   - Windows users: Run the `idf.py -p COMx flash` command.
   - Linux users: Run the `idf.py -p /dev/ttyUSBx flash` command.
   - :exclamation:  If the Byte Lab Development Kit is used, `TCH_IRQ switch` on the peripheral module must be `OFF`.
- Monitor the programs output:
   - Windows users: Run the `idf.py -p COMx monitor` command.
   - Linux users: Run the `idf.py -p /dev/ttyUSBx monitor` command.

## Configuration

The project is configured for Byte Lab Development Kit. If you want to use it on a custom board, make sure to modify the appropriate GPIO pins.