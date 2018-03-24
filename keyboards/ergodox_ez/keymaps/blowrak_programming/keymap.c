#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE  0 // default layer
#define SHFT  1 // shifted layer
#define SYMB  2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   $    |   &  |   [  |   {  |   }  |   (  | =    |           |   *  |   )  |   +  |   ]  |   !  |   #  |  BACKS |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   ;  |   ,  |   .  |   P  |   Y  |  Tab |           | Entr |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc    |   A  |   O  |   E  |   U  |   I  |------|           |------|   H  |   D  |   T  |   N  |   S  |   \    |
 * |--------+------+------+------+------+------| Ctrl |           | Back |------+------+------+------+------+--------|
 * | L1     |   '  |   Q  |   J  |   K  |   B  |      |           |      |   X  |   M  |   W  |   V  |   Z  | L1     |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  L2  |  Win |  Alt | Left | Right|                                       |   @  | Down |   [  |   ]  |  L2  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_DLR,         KC_AMPR,      KC_LBRC,  KC_LCBR,  KC_RCBR,   KC_LPRN,   KC_EQL,
        KC_DELT,        KC_SCLN,      KC_COMM,  KC_DOT,   KC_P,      KC_Y,      KC_TAB,
        KC_ESC,         KC_A,         KC_O,     KC_E,     KC_U,      KC_I,
        MO(1),          KC_QUOT,      KC_Q,     KC_J,     KC_K,      KC_B,      KC_LCTRL,
        MO(2),          KC_LGUI,      KC_LALT,  KC_LEFT,  KC_RGHT,
                                              ALT_T(KC_APP),  KC_LGUI,
                                                              KC_HOME,
                                               KC_SPC,KC_BSPC,KC_END,
        // right hand
             KC_ASTR,     KC_RPRN,    KC_PLUS,    KC_RBRC,   KC_EXLM,     KC_HASH,    KC_BSPC,
             KC_ENT,      KC_F,       KC_G,       KC_C,      KC_R,        KC_L,       KC_SLSH,
                          KC_H,       KC_D,       KC_T,      KC_N,        KC_S,       KC_BSLS,
             KC_BSPC,     KC_X,       KC_M,       KC_W,      KC_V,        KC_Z,       MO(1),
                          KC_AT,      KC_DOWN,    KC_LBRC,   KC_RBRC,     MO(2),
             KC_LALT,        CTL_T(KC_ESC),
             KC_PGUP,
             KC_PGDN,KC_TAB, KC_ENT
    ),
  /* Keymap 1: Shifted layer
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |   ~    |   %  |   1  |   2  |   3  |   4  | 5    |           |   6  |   7  |   8  |   9  |   0  |   `  |  BACKS |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * | Del    |   :  |   <  |   >  |   P  |   Y  |  Tab |           | Entr |   F  |   G  |   C  |   R  |   L  |   ?    |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * | Esc    |   A  |   O  |   E  |   U  |   I  |------|           |------|   H  |   D  |   T  |   N  |   S  |   |    |
   * |--------+------+------+------+------+------| Ctrl |           | Back |------+------+------+------+------+--------|
   * | L1     |   "  |   Q  |   J  |   K  |   B  |      |           |      |   X  |   M  |   W  |   V  |   Z  | L1     |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |  L2  |  Win |  Alt | Left | Right|                                       |   ^  | Down |   [  |   ]  |  L2  |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
   *                                 ,------|------|------|       |------+--------+------.
   *                                 |      |      | Home |       | PgUp |        |      |
   *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
   *                                 |      |ace   | End  |       | PgDn |        |      |
   *                                 `--------------------'       `----------------------'
   */
  // If it accepts an argument (i.e, is a function), it doesn't need KC_.
  // Otherwise, it needs KC_*
  [SHFT] = LAYOUT_ergodox(  // layer 0 : default
          // left hand
          KC_TILD,        KC_PERC,      KC_1,     KC_2,     KC_3,      KC_4,      KC_5,
          KC_DELT,        KC_COLN,      KC_LT,    KC_GT,    S(KC_P),   S(KC_Y),   S(KC_TAB),
          S(KC_ESC),      S(KC_A),      S(KC_O),  S(KC_E),  S(KC_U),   S(KC_I),
          MO(1),          KC_DQT,       S(KC_Q),  S(KC_J),  S(KC_K),   S(KC_B),   S(KC_LCTRL),
          MO(2),          KC_LGUI,      S(KC_LALT),  S(KC_LEFT),  S(KC_RGHT),
                                                ALT_T(KC_APP),  KC_LGUI,
                                                                S(KC_HOME),
                                                 S(KC_SPC),S(KC_BSPC),S(KC_END),
          // right hand
               KC_6,        KC_7,       KC_8,       KC_9,      KC_0,        KC_GRV,     S(KC_BSPC),
               S(KC_ENT),   S(KC_F),    S(KC_G),    S(KC_C),   S(KC_R),     S(KC_L),    KC_QUES,
                            S(KC_H),    S(KC_D),    S(KC_T),   S(KC_N),     S(KC_S),    KC_PIPE,
               S(KC_BSPC),  S(KC_X),    S(KC_M),    S(KC_W),   S(KC_V),     S(KC_Z),    MO(1),
                            KC_CIRC,    S(KC_DOWN), S(KC_UP),  KC_RBRC,     MO(2),
               S(KC_LALT),        CTL_T(KC_ESC),
               S(KC_PGUP),
               S(KC_PGDN), S(KC_TAB), S(KC_ENT)
      ),

/* Keymap 2: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |      |  F1  |  F2  |  F3  |  F4  |  F5  |           |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |   F12  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |      | MsUp |      |      |      |           |      |      | PGUP |   UP  | PGDN|     |         |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |  MsL | MsDwn| MsR  |      |------|           |------|      | RIGHT| DOWN | LEFT |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      | HOME |      |  END |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      | LClk | RClk |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SHFT] = LAYOUT_ergodox(
       // left hand
       KC_TRNS, KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_F6,   KC_F7,   KC_F8,  KC_F9,   KC_F10,   KC_F11,   KC_F12,
       KC_TRNS, KC_TRNS, KC_PGUP,KC_UP,   KC_PGDN,  KC_TRNS,  KC_TRNS,
                KC_DOWN, KC_LEFT,KC_DOWN, KC_RGHT,  KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS, KC_HOME,KC_TRNS, KC_END,   KC_TRNS,  KC_TRNS,
                         KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
