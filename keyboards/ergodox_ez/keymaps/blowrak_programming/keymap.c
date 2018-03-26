#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_swedish.h"

#define BASE  0 // default layer
#define SHFT  1 // shifted layer
#define NAVI  2 // navigation keys
#define NAVI_TWO 3
#define GAME  4

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
 * |   $    |   &  |   [  |   {  |   }  |   (  | =    |           |   *  |   )  |   +  |   ]  |   !  |   #  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Alt+Tab|   ;  |   ,  |   .  |   P  |   Y  |  Tab |           | Win  |   F  |   G  |   C  |   R  |   L  |   /    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc    |   A  |   O  |   E  |   U  |   I  |------|           |------|   H  |   D  |   T  |   N  |   S  |   \    |
 * |--------+------+------+------+------+------| Ctrl |           | Ctrl |------+------+------+------+------+--------|
 * | L1     |   '  |   Q  |   J  |   K  |   B  |      |           |      |   X  |   M  |   W  |   V  |   Z  | L1     |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  L2  |  L3 | Shift | Alt  | Win  |                                       |   @  |   Å  |   Ä  |   Ö  |  L2  |
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
        KC_DLR,         NO_AMPR,      NO_LBRC,  NO_LCBR,  NO_RCBR,   NO_LPRN,   NO_EQL,
        LALT(KC_TAB),   NO_SCLN,      KC_COMM,  KC_DOT,   KC_P,      KC_Y,      KC_TAB,
        KC_ESC,         KC_A,         KC_O,     KC_E,     KC_U,      KC_I,
        MO(SHFT),       NO_APOS,      KC_Q,     KC_J,     KC_K,      KC_B,      KC_LCTRL,
        MO(NAVI),       MO(NAVI_TWO), KC_LSFT,  KC_LALT,  KC_LGUI,
                                              ALT_T(KC_APP),  KC_LGUI,
                                                              KC_HOME,
                                               KC_SPC,KC_BSPC,KC_END,
        // right hand
             NO_ASTR,     NO_RPRN,    NO_PLUS,    NO_RBRC,   KC_EXLM,     KC_HASH,    NO_MINS,
             KC_LGUI,      KC_F,       KC_G,       KC_C,      KC_R,        KC_L,       NO_SLSH,
                          KC_H,       KC_D,       KC_T,      KC_N,        KC_S,       KC_BSLS,
             KC_RCTL,     KC_X,       KC_M,       KC_W,      KC_V,        KC_Z,       MO(SHFT),
                          NO_AT,      NO_AA,      NO_AE,     NO_OSLH,     MO(NAVI),
             KC_RALT,        CTL_T(KC_ESC),
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
   *   |  L2  |  Win |  Alt | Left | Right|                                       |   ^  |   Å  |   Ä  |   Ö  |  L2  |
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
  [SHFT] = LAYOUT_ergodox(  // layer 1 : shifted
          // left hand
          KC_TILD,        KC_PERC,      KC_1,     KC_2,     KC_3,      KC_4,      KC_5,
          LALT(KC_TAB),   NO_COLN,      KC_LT,    KC_GT,    S(KC_P),   S(KC_Y),   S(KC_TAB),
          S(KC_ESC),      S(KC_A),      S(KC_O),  S(KC_E),  S(KC_U),   S(KC_I),
          KC_TRNS,        NO_QUO2,      S(KC_Q),  S(KC_J),  S(KC_K),   S(KC_B),   S(KC_LCTRL),
          KC_TRNS,        KC_TRNS,      KC_LSFT,  S(KC_LALT),  S(KC_LGUI),
                                                ALT_T(KC_APP),  KC_LGUI,
                                                                S(KC_HOME),
                                                 S(KC_SPC),S(KC_BSPC),S(KC_END),
          // right hand
               KC_6,        KC_7,       KC_8,       KC_9,      KC_0,        NO_GRV,     NO_UNDS,
               S(KC_ENT),   S(KC_F),    S(KC_G),    S(KC_C),   S(KC_R),     S(KC_L),    NO_QUES,
                            S(KC_H),    S(KC_D),    S(KC_T),   S(KC_N),     S(KC_S),    NO_PIPE,
               S(KC_BSPC),  S(KC_X),    S(KC_M),    S(KC_W),   S(KC_V),     S(KC_Z),    MO(1),
                            NO_CIRC,    S(NO_AA),   S(NO_AE),  S(NO_OSLH),  MO(2),
               S(KC_LALT),        CTL_T(KC_ESC),
               S(KC_PGUP),
               S(KC_PGDN), S(KC_TAB), S(KC_ENT)
      ),

/* Keymap 2: Navigation
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |      |  F1  |  F2  |  F3  |  F4  |  F5  |           |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |   F12  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |  EPRM   |      |      | MsUp |      |      |      |           |      |      | PGUP |   UP  | PGDN|     |         |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |  MsL | MsDwn| MsR  |      |------|           |------|      | RIGHT| DOWN | LEFT |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      | HOME |      |  END |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      | LClk | RClk |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | SCRL |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[NAVI] = LAYOUT_ergodox(
       // left hand
       VRSN, KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
       EPRM, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                       TO(GAME),KC_SLCK,
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
/* Keymap 3: Navigation faster
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |      |  F1  |  F2  |  F3  |  F4  |  F5  |           |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |   F12  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |  EPRM   |      |      | MsUp |      |      |      |           |      |      | PGUP |   UP  | PGDN|     |         |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |  MsL | MsDwn| MsR  |      |------|           |------|      | RIGHT| DOWN | LEFT |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      |      |      |      |           |      |      | HOME |      |  END |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      | LClk | RClk |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | SCRL |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[NAVI_TWO] = LAYOUT_ergodox(
       // left hand
       VRSN, KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,
       EPRM, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                       KC_TRNS,KC_SLCK,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_F6,   KC_F7,   KC_F8,  KC_F9,   KC_F10,   KC_F11,   KC_F12,
       KC_TRNS, KC_TRNS, KC_PGUP,LALT(KC_UP),   KC_PGDN,  KC_TRNS,  KC_TRNS,
                KC_TRNS, LALT(KC_LEFT),LALT(KC_DOWN), LALT(KC_RGHT),  KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS, KC_HOME,KC_TRNS, KC_END,   KC_TRNS,  KC_TRNS,
                         KC_TRNS,KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 4: Game
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |    Esc  |      |   1  |   2  |   3  |   4  |   5  |           |   6  |   7  |   8  |   9  |   10 |   11 |    12  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |  Tab    |   Q  |  W   |   E  |  R   |  T   |      |           |      |   Y   |  U  |  I   |  O   |   P  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   A  |  S   |   D  |  F   |  G   |------|           |------|   H  |   J  |  K   |  L   |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   Shift |   Z  |  X   |   C  |  V   |  B   |      |           |      |   N  |   M  |  ,   |  .   |  -   |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  Ctrl |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      | L0   |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |  Spc |  Ctrl|------|       |------| Backs|  Entr|
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[GAME] = LAYOUT_ergodox(
       // left hand
       KC_ESC, KC_NO,  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,
       KC_TAB,  KC_Q,  KC_W, KC_R, KC_S, KC_T, KC_NO,
       KC_NO,   KC_A,  KC_S, KC_D, KC_F, KC_G,
       KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO,
       KC_LCTRL,KC_NO, KC_NO, KC_NO, KC_NO,
                                       KC_NO,TO(0),
                                               KC_NO,
                               KC_SPC,KC_LCTRL,KC_NO,
       // right hand
       KC_6,    KC_7,   KC_8,   KC_9,   KC_0,   KC_NO,   KC_NO,
       KC_NO,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,    KC_NO,
                KC_H,   KC_J,   KC_K,   KC_L,   KC_NO,   KC_NO,
       KC_NO,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_MINS, KC_NO,
                         KC_LEFT,KC_UP, KC_DOWN,  KC_RGHT,  KC_NO,
       KC_NO, KC_NO,
       KC_NO,
       KC_NO, KC_BSPC, KC_ENT
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(NAVI)                // FN1 - Momentary Layer 1 (Symbols)
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
  }
  return true;
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};
