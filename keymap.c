#include QMK_KEYBOARD_H

extern uint8_t is_master;

enum layer_number {
  _QWERTY = 0,
  _NUM_SYM,
  _FUNC,
  _NAV,
  _MOUSE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |   Q  |  W   |  E   |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |lsft A|lctl S|lalt D|lgui F|   G  |-------.    ,-------|   H  |rgui J|ralt K|rctl L|rsft ;|      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      | L1   | / L3    /       \L4    \  |   L2  |      |      |
     *                   |      |      |      |/ Space /         \Enter \ | Backsp|      |      |
     *                   `----------------------------'           '------''--------------------'
     */
  [_QWERTY] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F20,
    KC_TRNS, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_TRNS,
    KC_TRNS,LSFT_T(KC_A),LCTL_T(KC_S),LALT_T(KC_D),LGUI_T(KC_F),KC_G,                     KC_H,RGUI_T(KC_J),RALT_T(KC_K),RCTL_T(KC_L),RSFT_T(KC_SCLN),KC_TRNS,
    KC_TRNS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_TRNS,              KC_TRNS,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_TRNS,
    KC_TRNS, KC_TRNS, MO(_NUM_SYM), LT(_NAV,KC_SPC),                                     LT(_MOUSE,KC_ENT), LT(_FUNC,KC_BSPC), KC_TRNS, KC_TRNS),
  [_NUM_SYM] = LAYOUT( // numbers and symbols
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_QUOT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_BSLS, KC_GRV,  KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
  [_FUNC] = LAYOUT( // functions
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
    KC_TRNS, KC_TAB,  KC_TRNS, KC_VOLD, KC_VOLU, KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F11,  KC_TRNS,
    KC_TRNS, KC_MUTE, KC_MPLY, KC_MNXT, KC_MPRV, KC_DEL,  KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F12,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TAB, KC_ESC,                                                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
  [_NAV] = LAYOUT( // navigation
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_PGUP, KC_END,  KC_HOME, KC_PGDN, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
  [_MOUSE] = LAYOUT( // mouse
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                 KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2, KC_BTN3,                                 KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

