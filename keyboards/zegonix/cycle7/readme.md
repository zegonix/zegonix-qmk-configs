# Description

Configuration for my custom PCB for TKD's Cycle7 with (weird) split spacebar design.

* Keyboard Maintainer: [zegonix](https://github.com/zegonix)
* Hardware Supported: [custom-cycle7-pcb](https://github.com/zegonix/custom-cycle7-pcb)
* Hardware Availability: the pcb is open source, order it yourself

# Building and flashing firmware
To build and flash the firmware, set up the qmk tool and use the compile and flash commands:

```
qmk config user.keyboard=zegonix-qmk/cycle7
qmk config user.keymap=quaken
qmk compile
qmk flash
```

Alternatively you can use the QMK root level Makefile:

```
make zegonix/cycle7:quaken             // build firmware
make zegonix/cycle7:quaken:dfu-utils   // build and flash firmware
```

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with the [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

# Bootloader

Enter the bootloader in 2 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix, which is be Escape key, while connecting the keyboard. *This variant was not tested*
* **Physical reset button**: Short the two Pins of J2 (usually a pair of tweezers works well) and press the reset button (only button on the backside)
* **Keycode in layout**: Press the key mapped to `QK_BOOT`.
