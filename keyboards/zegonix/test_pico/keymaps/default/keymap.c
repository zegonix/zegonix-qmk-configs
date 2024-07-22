/* 
 * KEYMAP KEYMAP KEYMAP, QUAK!
 */
#include QMK_KEYBOARD_H

#define QUAK_A (MT(MOD_LGUI, KC_A))
#define QUAK_S (MT(MOD_LALT, KC_S))
#define QUAK_D (MT(MOD_LSFT, KC_D))
#define QUAK_F (MT(MOD_LCTL, KC_F))
#define QUAK_J (MT(MOD_LCTL, KC_J))
#define QUAK_K (MT(MOD_LSFT, KC_K))
#define QUAK_L (MT(MOD_LALT, KC_L))
#define QUAK__ (MT(MOD_LGUI, KC_SCLN))

enum envoy_layers {
    _BASE,
    _GAME,
    _NAV,
    _DIV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * keyboard layout
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐  ┌───┬───┬───┐
 * │00 │01 │02 │03 │04 │05 │06 │07 │08 │09 │0A │0B │2D │0C     │  │0D │0E │0F │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤  ├───┼───┼───┤
 * │10   │11 │12 │13 │14 │15 │16 │17 │18 │19 │1A │1B │3D │1C   │  │1D │1E │1F │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤  └───┴───┴───┘
 * │20    │21 │22 │23 │24 │25 │26 │27 │28 │29 │2A │2B │2C      │  : = :
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤  :...┌───┐
 * │30      │31 │32 │33 │34 │35 │36 │37 │38 │39 │3A │3C        │  : ] │3E │
 * ├────┬───┴┬──┴─┬─┴──┬┴───┴───┴─┬─┴───┴──┬┴───┼───┴┬────┬────┤  ┌───┼───┼───┐
 * │40  │41  │42  │43  │45        │47      │49  │4A  │ 4B │4C  │  │4D │4E │4F │
 * └────┴────┴────┴────┴──────────┴────────┴────┴────┴────┴────┘  └───┴───┴───┘
 */

/// [TEMPLATE]
// [<LAYER>] = LAYOUT(
// _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,        _______,   _______,   _______,
// _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,        _______,   _______,   _______,
// _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,        _______,
// _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,        _______,   _______,
// _______,   _______,   _______,   _______,              _______,              _______,              _______,   _______,   _______,   _______,        _______,   _______,   _______
// ),

// base layer
[_BASE] = LAYOUT(
KC_ESC,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_MINS,   KC_BSPC,        KC_INS,    KC_HOME,   KC_PGUP,
KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_LBRC,   KC_BSLS,        KC_DEL,    KC_END,    KC_PGDN,
MO(_DIV),  QUAK_A,    QUAK_S,    QUAK_D,    QUAK_F,    KC_G,      KC_H,      QUAK_J,    QUAK_K,    QUAK_L,    QUAK__,    KC_QUOT,   KC_ENT,         KC_EQL,
KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,              KC_RSFT,        KC_RBRC,   KC_UP,
KC_LCTL,   KC_LGUI,   KC_LALT,   KC_DEL,               KC_SPC,               KC_BSPC,              MO(_NAV),  KC_LCTL,   KC_LGUI,   KC_LALT,        KC_LEFT,   KC_DOWN,   KC_RGHT
),

// gaming layer
[_GAME] = LAYOUT(
KC_ESC,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_MINS,   KC_BSPC,        KC_INS,    KC_HOME,   KC_PGUP,
KC_TAB,    KC_Q,      KC_W,      KC_E,      KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_LBRC,   KC_BSLS,        KC_DEL,    KC_END,    KC_PGDN,
MO(_DIV),  KC_A,      KC_S,      KC_D,      KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_QUOT,   KC_ENT,         KC_EQL,
KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,              KC_RSFT,        KC_RBRC,   KC_UP,
KC_LCTL,   KC_LGUI,   KC_LALT,   KC_M,                 KC_SPC,               KC_BSPC,              MO(_NAV),  KC_LCTL,   KC_LGUI,   KC_LALT,        KC_LEFT,   KC_DOWN,   KC_RGHT
),

// navigation layer
[_NAV] = LAYOUT(
KC_GRV,    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    _______,        QK_BOOT,   _______,   _______,
_______,   _______,   KC_HOME,   KC_UP,     KC_END,    KC_PGUP,   _______,   KC_MPRV,   KC_MPLY,   KC_MNXT,   _______,   _______,   _______,        _______,   _______,   _______,
_______,   _______,   KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_PGDN,   _______,   KC_LCTL,   KC_LSFT,   KC_LALT,   KC_LGUI,   _______,   _______,        KC_F12,
_______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,        _______,   _______,
_______,   _______,   _______,   _______,              _______,              _______,              _______,   _______,   _______,   _______,        _______,   _______,   _______
),

// div
[_DIV] = LAYOUT(
KC_GRV,    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    _______,        _______,   _______,   _______,
_______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,        _______,   _______,   _______,
_______,   _______,   KC_LALT,   KC_LSFT,   KC_LCTL,   _______,   _______,   KC_DEL,    _______,   _______,   _______,   _______,   _______,        KC_F12,
_______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,        _______,   _______,
_______,   _______,   _______,   _______,              KC_CAPS,              _______,              _______,   _______,   _______,   _______,        _______,   _______,   _______
),
};
