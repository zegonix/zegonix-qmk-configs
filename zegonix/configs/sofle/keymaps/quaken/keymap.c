#include QMK_KEYBOARD_H

#define QUAK_A (MT(MOD_LGUI, KC_A))
#define QUAK_S (MT(MOD_LALT, KC_S))
#define QUAK_D (MT(MOD_LSFT, KC_D))
#define QUAK_F (MT(MOD_LCTL, KC_F))
#define QUAK_J (MT(MOD_LCTL, KC_J))
#define QUAK_K (MT(MOD_LSFT, KC_K))
#define QUAK_L (MT(MOD_LALT, KC_L))
#define QUAK__ (MT(MOD_LGUI, KC_SCLN))

enum sofle_layers {
    _BASE,
    _GAME,
    _NAV,
    _CHAR,
    _MOUS,
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] = { ENCODER_CCW_CW(KC_WH_L, KC_WH_R), ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
    [_GAME] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_WH_D, KC_WH_U) },
    [_NAV]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(_______, _______) },
    [_CHAR] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_MOUS] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Keyboard Layout
 * .-----------------------------------------------------.                      .-----------------------------------------------------.
 * |   ESC  |    1   |    2   |    3   |    4   |    5   |                      |    6   |    7   |    8   |    9   |    0   | BSPACE |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
 * |   TAB  |    Q   |    W   |    E   |    R   |    T   |                      |    Y   |    U   |    I   |    O   |    P   |    \   |
 * |--------+--------+--------+--------+--------+--------|                      |--------+--------+--------+--------+--------+--------|
 * | LSHIFT |    A   |    S   |    D   |    F   |    G   |                      |    H   |    J   |    K   |    L   |    ;   |    '   |
 * |--------+--------+--------+--------+--------+--------+--------.    .--------+--------+--------+--------+--------+--------+--------|
 * | LSHIFT |    Z   |    X   |    C   |    V   |    B   |   ENC  |    |   ENC  |    N   |    M   |    ,   |    .   |    /   | RSHIFT |
 * '--------+--------+--------+--------+--------+--------+--------'    '--------+--------+--------+--------+--------+--------+--------'
 *          | THUMB5 | THUMB4 | THUMB3 | THUMB2 | THUMB1 |                      |   ESC  |    1   |    2   |    3   |    4   |
 *          '--------------------------------------------'                      '--------------------------------------------'
 * 
 */

// QWERTY LAYER
[_BASE] = LAYOUT(
KC_ESC,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                             KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_BSPC,
KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,                             KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSLS,
MO(_CHAR), QUAK_A,    QUAK_S,    QUAK_D,    QUAK_F,    KC_G,                             KC_H,      QUAK_J,    QUAK_K,    QUAK_L,    QUAK__,    KC_QUOT,
KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_MUTE,    DF(_GAME), KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_RSFT,
           KC_LALT,   KC_LCTL,   MO(_MOUS), KC_SPC,    KC_DEL,                           KC_BSPC,   KC_ENT,    MO(_NAV),  KC_RALT,   KC_LGUI
),

// GAME LAYER
[_GAME] = LAYOUT(
KC_ESC,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,                             KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_BSPC,
KC_TAB,    KC_G,      KC_Q,      KC_W,      KC_E,      KC_R,                             KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSLS,
KC_LCTL,   KC_LSFT,   KC_A,      KC_S,      KC_D,      KC_F,                             KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_QUOT,
KC_T,      KC_I,      KC_Z,      KC_X,      KC_C,      KC_V,      KC_MUTE,    DF(_BASE), KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_RSFT,
           KC_B,      KC_LALT,   KC_I,      KC_SPC,    KC_M,                             KC_BSPC,   KC_ENT,    MO(_NAV),  KC_RALT,   KC_LGUI
),

// NAVIGATION LAYER
[_NAV] = LAYOUT(
KC_GRV,    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,                            KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,
_______,   _______,   KC_HOME,   KC_UP,     KC_END,    KC_PGUP,                          _______,   KC_MPRV,   KC_MPLY,   KC_MNXT,   KC_MSTP,   KC_F12,
_______,   _______,   KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_PGDN,                          _______,   KC_LCTL,   KC_LSFT,   KC_LALT,   KC_LGUI,   KC_BSLS,
_______,   _______,   KC_LBRC,   KC_RBRC,   KC_MINS,   KC_EQL,    _______,    _______,   _______,   _______,   _______,   _______,   _______,   _______,
           _______,   _______,   KC_CAPS,   _______,   _______,                          _______,   _______,   _______,   _______,   _______
),

// SPECIAL CHARACTER LAYER
[_CHAR] = LAYOUT(
_______,   _______,   _______,   _______,   _______,   _______,                          _______,   _______,   _______,   _______,   _______,   _______,
_______,   _______,   _______,   _______,   _______,   _______,                          _______,   _______,   _______,   _______,   _______,   _______,
_______,   KC_LGUI,   KC_LALT,   KC_LSFT,   KC_LCTL,   _______,                          _______,   KC_MINS,   KC_EQL,    KC_LBRC,   KC_RBRC,   _______,
_______,   _______,   _______,   _______,   _______,   _______,   _______,    _______,   _______,   _______,   _______,   _______,   _______,   _______,
           QK_BOOT,   _______,   _______,   KC_CAPS,   _______,                          _______,   _______,   _______,   _______,   _______
),

// MOUSE KEYS LAYER
[_MOUS] = LAYOUT(
_______,   _______,   _______,   _______,   _______,   _______,                          _______,   _______,   _______,   _______,   _______,   _______,
_______,   _______,   _______,   _______,   _______,   _______,                          KC_WH_U,   KC_BTN1,   KC_MS_U,   KC_BTN2,   _______,   _______,
_______,   KC_LGUI,   KC_LALT,   KC_LSFT,   KC_LCTL,   _______,                          KC_WH_D,   KC_MS_L,   KC_MS_D,   KC_MS_R,   _______,   _______,
_______,   _______,   _______,   _______,   _______,   _______,   _______,    _______,   _______,   _______,   _______,   _______,   _______,   _______,
           _______,   _______,   _______,   _______,   _______,                          _______,   _______,   _______,   _______,   _______
)

};

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("BASE"), false);
            break;
        case _GAME:
            oled_write_ln_P(PSTR("GAME"), false);
            break;
        default:
            oled_write_P(PSTR("ERROR"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif
