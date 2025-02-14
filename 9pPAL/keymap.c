#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_NO,          KC_Q,           KC_W,           KC_E,           KC_R,           MT(MOD_LALT, KC_T),                                MT(MOD_RCTL, KC_Y),KC_U,           KC_I,           KC_O,           KC_P,           KC_NO,          
    KC_NO,          KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           MT(MOD_RGUI, KC_SCLN),KC_NO,          
    KC_NO,          MT(MOD_LSFT, KC_Z),KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         MT(MOD_RSFT, KC_SLASH),KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_LEFT_GUI,    LT(1,KC_SPACE),                                 LT(2,KC_BSPC),  LT(4,KC_ENTER), KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                                    KC_NO,          KC_NO,                                          KC_NO,          KC_NO
  ),
  [1] = LAYOUT_voyager(
    KC_NO,          LALT(LSFT(KC_RIGHT)),LGUI(LSFT(KC_4)),LGUI(LCTL(LSFT(KC_4))),LGUI(KC_SPACE), KC_NO,                                          LGUI(LSFT(KC_J)),LCTL(KC_W),     KC_NO,          LALT(KC_D),     KC_NO,          KC_NO,          
    KC_NO,          ST_MACRO_0,     ST_MACRO_1,     ST_MACRO_2,     LCTL(KC_C),     LCTL(KC_RBRC),                                  KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_NO,          KC_NO,          
    KC_NO,          LALT(LGUI(KC_W)),KC_NO,          ST_MACRO_3,     LALT(LGUI(KC_C)),LGUI(LSFT(KC_SLASH)),                                LGUI(LSFT(KC_SPACE)),LALT(KC_B),     KC_NO,          LALT(KC_F),     KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 MO(3),          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_NO,          KC_ESCAPE,      KC_NO,          KC_QUOTE,       KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_DQUO,        KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_1,           KC_2,           KC_3,           KC_4,           KC_MINUS,                                       KC_PLUS,        KC_9,           KC_8,           KC_7,           KC_6,           KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_5,           KC_UNDS,                                        KC_EQUAL,       KC_0,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          MO(3),                                          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          RGB_TOG,        KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_LCBR,        KC_LBRC,        KC_LPRN,        KC_GRAVE,       KC_TILD,                                        KC_BSLS,        KC_PIPE,        KC_RPRN,        KC_RBRC,        KC_RCBR,        KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          LCTL(LSFT(KC_TAB)),LCTL(KC_A),     KC_NO,                                          KC_NO,          LCTL(KC_E),     LCTL(KC_TAB),   KC_NO,          QK_BOOT,        KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_NO,          KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_NO,          
    KC_NO,          KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_NO,                                          KC_NO,          KC_F9,          KC_F8,          KC_F7,          KC_F6,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_F5,          KC_NO,                                          KC_NO,          KC_F10,         KC_NO,          KC_NO,          KC_NO,          KC_NO,          
    KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const uint16_t PROGMEM combo0[] = { KC_F, KC_J, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_TAB),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT(MOD_LSFT, KC_Z):
            return TAPPING_TERM -50;
        case KC_LEFT_GUI:
            return TAPPING_TERM -50;
        case LT(1,KC_SPACE):
            return TAPPING_TERM -20;
        case MT(MOD_RGUI, KC_SCLN):
            return TAPPING_TERM -50;
        case MT(MOD_RSFT, KC_SLASH):
            return TAPPING_TERM -50;
        case LT(2,KC_BSPC):
            return TAPPING_TERM -20;
        case LT(4,KC_ENTER):
            return TAPPING_TERM -20;
        default:
            return TAPPING_TERM;
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_GRAVE) SS_DELAY(100) SS_TAP(X_LEFT));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SLASH) SS_DELAY(100) SS_TAP(X_B) SS_DELAY(100) SS_TAP(X_L) SS_DELAY(100) SS_TAP(X_K));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SLASH) SS_DELAY(100) SS_TAP(X_LBRC) SS_DELAY(100) SS_TAP(X_LBRC));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SLASH) SS_DELAY(100) SS_TAP(X_G) SS_DELAY(100) SS_TAP(X_R) SS_DELAY(100) SS_TAP(X_P));
    }
    break;

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}



