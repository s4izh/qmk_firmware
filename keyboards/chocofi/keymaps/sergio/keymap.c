#include QMK_KEYBOARD_H
#include <stdio.h>

enum Layer {
    /* QWERTY = 0, */
    DVORAK = 0,
    SYM_NUM,
    NAV,
    FUNC_NUM,
    GAME_0,
    GAME_1,

    NUM_LAYERS
};

// COLEMAK HOME ROW MODS
// left side
/* #define KC_A_ LALT_T(KC_A) */
/* #define KC_R_ LGUI_T(KC_R) */
/* #define KC_S_ LCTL_T(KC_S) */
/* #define KC_T_ LSFT_T(KC_T) */
// right side
/* #define KC_N_ RSFT_T(KC_N) */
/* #define KC_E_ RCTL_T(KC_E) */
/* #define KC_I_ RGUI_T(KC_I) */
/* #define KC_O_ LALT_T(KC_O) */

#define KC_A_ KC_A
#define KC_S_ KC_S
#define KC_D_ KC_D
#define KC_F_ KC_F
#define KC_G_ KC_G

// Layer toggles
/* #define KC_WM   LT(WNDWMGR, WM_EXPOSEE) */
/* #define KC_BSP_ LT(MOD_ARR, KC_BSPC) */
/* #define KC_TAB_ LT(FUN_NUM, KC_TAB) */
/* #define KC_D_   LT(SYMBOLS, KC_D) */
/* #define KC_NAV  LT(NAVIGAT, KC_NO) */
#define KC_WM   LGUI_T(KC_TAB)
#define KC_BSP_ LCTL_T(KC_BSPC)

#define KC_SPC_SHIFT KC_LEFT_SHIFT(KC_SPC)

#define MY_MOD(key) LGUI_T(key)
#define MY_LCTL(key) LCTL_T(key)
#define MY_SHIFT(key) LSFT_T(key)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* [QWERTY] = LAYOUT_split_3x5_3( */
    /*     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, */
    /*     KC_A_,   KC_S_,   KC_D_,   KC_F_,   KC_G_,                              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, */
    /*     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, */
    /*                                KC_WM,   KC_SPC, KC_LCTL,            KC_ENT, KC_BSP_, MO(SYM_NUM) */

    [DVORAK] = LAYOUT_split_3x5_3(
        KC_QUOT, KC_COMM, KC_DOT , KC_P         , KC_Y   ,                       KC_F   , KC_G   , KC_C   , KC_R   , KC_L   ,
        KC_A   , KC_O   , KC_E   , MY_MOD(KC_U)    , KC_I   ,                    KC_D   , KC_H   , KC_T   , KC_N   , KC_S   ,
        KC_SCLN, KC_Q   , KC_J   , KC_K         , KC_X   ,                       KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   ,
                 KC_WM, MY_SHIFT(KC_SPC),    MY_LCTL(KC_TAB),                    MY_LCTL(KC_ENT), MY_SHIFT(KC_BSPC), MO(SYM_NUM)
    ),
    [SYM_NUM] = LAYOUT_split_3x5_3(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
        KC_TILD, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,                            KC_BSLS, KC_QUOT, KC_DQUO, KC_LCBR, KC_RCBR,
                                   KC_TRNS, KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [NAV] = LAYOUT_split_3x5_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                   KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [FUNC_NUM] = LAYOUT_split_3x5_3(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
        KC_F11,  KC_F12,  KC_F13,  KC_F14,  KC_F15,                             KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,
        KC_F21,  KC_F22,  KC_F23,  KC_F24,  KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                   KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [GAME_0] = LAYOUT_split_3x5_3(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                   KC_LGUI, KC_BSPC, KC_SPC,            KC_ENT, KC_SPC, KC_TAB
    ),
};
