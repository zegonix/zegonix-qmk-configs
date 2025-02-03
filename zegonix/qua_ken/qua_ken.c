
#include "gpio.h"

void keyboard_pre_init_kb(void) {
    // set pulldown on handedness pin
    gpio_set_pin_input_low(A2);
}
