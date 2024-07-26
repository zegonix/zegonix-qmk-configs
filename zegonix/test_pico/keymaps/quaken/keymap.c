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

enum layer_names {
    _BASE,
    _GAME,
    _NAV,
    _DIV,
    _MOUS,

    _CAPS, // for lighting layers only, do not assign keymap!
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
// _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,     _______,   _______,   _______,
// _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,     _______,   _______,   _______,
// _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,
// _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,                         _______,                _______,
// _______,   _______,   _______,   _______,              _______,              _______,                         _______,   _______,   _______,   _______,     _______,   _______,   _______
// ),

// base layer
[_BASE] = LAYOUT(
KC_ESC,    KC_1,
KC_TAB,    KC_Q
),

// gaming layer
[_GAME] = LAYOUT(
KC_ESC,    KC_1,
KC_TAB,    KC_Q
),

// navigation layer
[_NAV] = LAYOUT(
KC_GRV,    KC_F1,
_______,   _______
),

// div
[_DIV] = LAYOUT(
KC_GRV,    KC_F1,
_______,   _______
),

// mouse layer
[_MOUS] = LAYOUT(
_______,   _______,
_______,   _______
),
};

/* Indicator LED Configuraton */
const rgblight_segment_t PROGMEM rgb_layer_BASE[] = RGBLIGHT_LAYER_SEGMENTS({1, 1, HSV_YELLOW});
const rgblight_segment_t PROGMEM rgb_layer_GAME[] = RGBLIGHT_LAYER_SEGMENTS({1, 1, HSV_SPRINGGREEN});
const rgblight_segment_t PROGMEM rgb_layer_NAV[] = RGBLIGHT_LAYER_SEGMENTS({11, 2, HSV_PURPLE});
const rgblight_segment_t PROGMEM rgb_layer_DIV[] = RGBLIGHT_LAYER_SEGMENTS({11, 2, HSV_PURPLE});
const rgblight_segment_t PROGMEM rgb_layer_MOUS[] = RGBLIGHT_LAYER_SEGMENTS({11, 2, HSV_PURPLE});
const rgblight_segment_t PROGMEM rgb_layer_CAPS[] = RGBLIGHT_LAYER_SEGMENTS({1, 1, HSV_WHITE});

const rgblight_segment_t * const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    [_BASE] = rgb_layer_BASE,
    [_GAME] = rgb_layer_GAME,
    [_NAV]  = rgb_layer_NAV,
    [_DIV]  = rgb_layer_DIV,
    [_MOUS] = rgb_layer_MOUS,
    [_CAPS] = rgb_layer_CAPS
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(_CAPS, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(_BASE, layer_state_cmp(state, _BASE));
    rgblight_set_layer_state(_GAME, layer_state_cmp(state, _GAME));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(_NAV, layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(_DIV, layer_state_cmp(state, _DIV));
    rgblight_set_layer_state(_MOUS, layer_state_cmp(state, _MOUS));
    return state;
}