# Description

My custom configuration for the `Optica60`.


## Bootloader Shenanigans

Unfortunately the Optica60 comes with a random bootloader which is not compatible with QMK.
Therefore a debugger (JLink worked great for me) needs to be connected (soldered onto the MCU) to flash the `STM32duino Bootloader`.
Connect `SWDIO`, `SWDCLK`, `VDD` & `GND` to the debugger and flash the bootloader binary.

> *NOTE:* The Optica60 uses 16 MHz crystal (instead of 8 MHz like everyone else), so the `config.h` in the STM32duino source code needs to adjusted accordingly.
> My compiled binary is located at `./bootloader-binary/generic-none_bootloader.bin`.

Flash the binary to the address `0x0800_0000` and power cycle the board.
It should now register as USB device named `Leaflabs Maple DFU interface`.
You should now be able to program the QMK firmware via `DFU` or just `qmk flash`.




