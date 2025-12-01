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
    _BS,
    _GM,
    _NV,
    _CH,
    _MS,

    _CAPS, // for lighting layers only, do not assign keymap!
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BS] = { ENCODER_CCW_CW(MS_WHLL, MS_WHLR), ENCODER_CCW_CW(MS_WHLD, MS_WHLU) },
    [_GM] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(MS_WHLD, MS_WHLU) },
    [_NV] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(_______, _______) },
    [_CH] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_MS] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * keyboard layout
 * ┌────┬────┬────┬────┬────┬────┐                    ┌────┬────┬────┬────┬────┬────┐
 * │ESC │ 1! │ 2@ │ 3# │ 4$ │ 5% │                    │ 6^ │ 7& │ 8* │ 9( │ 0) │ __ │
 * ├────┼────┼────┼────┼────┼────┤                    ├────┼────┼────┼────┼────┼────┤
 * │TAB │ Q  │ W  │ E  │ R  │ T  │                    │ Y  │ U  │ I  │ O  │ P  │ \| │
 * ├────┼────┼────┼────┼────┼────┤                    ├────┼────┼────┼────┼────┼────┤
 * │_CH │ A  │ S  │ D  │ F  │ G  │                    │ H  │ J  │ K  │ L  │ ;: │ '" │
 * ├────┼────┼────┼────┼────┼────┤                    ├────┼────┼────┼────┼────┼────┤
 * │LSFT│ Z  │ X  │ C  │ V  │ B  │   ┌────┐  ┌────┐   │ N  │ M  │ ,< │ .> │ /? │RSFT│
 * └────┴──┬─┴──┬─┴──┬─┴──┬─┴──┬─┴──┐│ENCL│  │ENCL│┌──┴─┬──┴─┬──┴─┬──┴─┬──┴─┬──┴────┘
 *         │LALT│LCTL│ESC │SPC │DEL │└────┘  └────┘│LALT│LCTL│____│SPC │ESC │
 *         └────┴────┴────┴────┴────┘              └────┴────┴────┴────┴────┘
 */

/// [TEMPLATE]
// [<LAYER>] = LAYOUT(
// _______,  _______,  _______,  _______,  _______,  _______,                  _______,  _______,  _______,  _______,  _______,  _______,
// _______,  _______,  _______,  _______,  _______,  _______,                  _______,  _______,  _______,  _______,  _______,  _______,
// _______,  _______,  _______,  _______,  _______,  _______,                  _______,  _______,  _______,  _______,  _______,  _______,
// _______,  _______,  _______,  _______,  _______,  _______,                  _______,  _______,  _______,  _______,  _______,  _______,
//      _______,  _______,  _______,  _______,  _______,     _______,  _______,     _______,  _______,  _______,  _______,  _______
// ),

// base layer
[_BS] = LAYOUT(
    KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
    MO(_CH),  QUAK_A,   QUAK_S,   QUAK_D,   QUAK_F,   KC_G,                     KC_H,     QUAK_J,   QUAK_K,   QUAK_L,   QUAK__,   KC_QUOT,
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,                     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
         KC_LALT,  KC_LCTL,  KC_ESC,  KC_SPC,   KC_DEL,       DF(_GM),  _______,     KC_BSPC,  KC_ENT,   MO(_NV),  _______,  KC_RGUI
),

// gaming layer
[_GM] = LAYOUT(
    KC_ESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,
    KC_TAB,   KC_T,     KC_Q,     KC_W,     KC_E,     KC_R,                     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSLS,
    KC_LCTL,  KC_LSFT,  KC_A,     KC_S,     KC_D,     KC_F,                     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
    KC_G,     KC_B,     KC_Z,     KC_X,     KC_C,     KC_V,                     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
         KC_LALT,  KC_LCTL,  KC_ESC,  KC_SPC,   KC_DEL,       DF(_BS),  _______,     KC_BSPC,  KC_ENT,   MO(_NV),  _______,  KC_RGUI
),

// navigation layer
[_NV] = LAYOUT(
    KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
    _______,  _______,  KC_HOME,  KC_UP,    KC_END,   KC_PGUP,                  _______,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MSTP,  KC_F12,
    _______,  _______,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_PGDN,                  _______,  KC_LCTL,  KC_LSFT,  KC_LALT,  KC_LGUI,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                  _______,  _______,  _______,  _______,  _______,  _______,
         _______,  _______,  _______,  _______,  _______,     KC_MUTE,  _______,     _______,  _______,  _______,  _______,  QK_BOOT
),

// div
[_CH] = LAYOUT(
    KC_GRV,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
    _______,  _______,  _______,  _______,  _______,  _______,                  _______,  _______,  _______,  _______,  _______,  KC_F12,
    _______,  _______,  KC_LALT,  KC_LSFT,  KC_LCTL,  _______,                  _______,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_BSLS,
    _______,  _______,  _______,  _______,  _______,  _______,                  _______,  _______,  _______,  _______,  _______,  _______,
         QK_BOOT,  _______,  _______,  KC_CAPS,  _______,     _______,  _______,     _______,  _______,  _______,  _______,  _______
),

// mouse layer
[_MS] = LAYOUT(
    _______,  _______,  _______,  _______,  _______,  _______,                  _______,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                  _______,  _______,  MS_UP,    _______,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                  MS_BTN1,  MS_LEFT,  MS_DOWN,  MS_RGHT,  _______,  _______,
    _______,  _______,  _______,  _______,  _______,  _______,                  _______,  MS_BTN2,  _______,  _______,  _______,  _______,
         _______,  _______,  _______,  _______,  _______,     _______,  _______,     _______,  _______,  _______,  _______,  _______
),
};

/* Indicator LED Configuraton */
const rgblight_segment_t PROGMEM rgb_layer_BASE[] = RGBLIGHT_LAYER_SEGMENTS({0, 1,  27, 255,  70});
const rgblight_segment_t PROGMEM rgb_layer_GAME[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, 197, 255,  70});
const rgblight_segment_t PROGMEM rgb_layer_CAPS[] = RGBLIGHT_LAYER_SEGMENTS({0, 1,   0,   0,  70});

const rgblight_segment_t * const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    rgb_layer_BASE,
    rgb_layer_GAME,
    rgb_layer_CAPS
);

void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(2, led_state.caps_lock);

    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _BS));
    rgblight_set_layer_state(1, layer_state_cmp(state, _GM));

    return state;
}

