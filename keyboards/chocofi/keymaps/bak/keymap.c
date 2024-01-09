#include QMK_KEYBOARD_H
#include <stdio.h>

enum Layer {
    QWERTY = 0,
    SYMBOLS_NUMBERS,
    NAVIGATION,
    GAME_0,
    GAME_1,
};

// COLEMAK HOME ROW MODS
// left side
#define KC_A_ LALT_T(KC_A)
#define KC_R_ LGUI_T(KC_R)
#define KC_S_ LCTL_T(KC_S)
#define KC_T_ LSFT_T(KC_T)
// right side
#define KC_N_ RSFT_T(KC_N)
#define KC_E_ RCTL_T(KC_E)
#define KC_I_ RGUI_T(KC_I)
#define KC_O_ LALT_T(KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A_,   KC_S_,   KC_D_,   KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                   KC_WM,   KC_BSP_, KC_SPC_,          KC_ENT_, KC_SPC_, KC_TAB_
    ),
    [SYMBOLS_NUMBERS] = LAYOUT_split_3x5_3(
        KC_0,    KC_1,    KC_2,    KC_3,    KC_4,                               KC_5,    KC_6,    KC_7,    KC_8,    KC_9,
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        KC_TILD, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,                            KC_BSLS, KC_QUOT, KC_DQUO, KC_LCBR, KC_RCBR,
                                   KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS
    ),
};
