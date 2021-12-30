/*
 * HHKB Layout
 */
#include "keymap_common.h"
#include "rn42_task.h"

enum layer_id {
    L_WIN = 0,
    L_IOS,
    L_NP,
    L_FN,
};

#ifdef KEYMAP_SECTION_ENABLE
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
#endif
    /* WIN Layer */
    [L_WIN] = \
    KEYMAP( ESC,   1,   2,   3,   4,   5,   6,   7,   8,   9,   0,MINS, EQL,BSLS, GRV,   \
            TAB,   Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,LBRC,RBRC,BSPC,        \
           LCTL,   A,   S,   D,   F,   G,   H,   J,   K,   L,SCLN,QUOT, ENT,             \
           LSFT,   Z,   X,   C,   V,   B,   N,   M,COMM, DOT,SLSH,RSFT, FN0,             \
                LALT, FN4,           SPC,                FN5,RALT),
    /* IOS Layer */
    [L_IOS] = \
    KEYMAP( ESC,   1,   2,   3,   4,   5,   6,   7,   8,   9,   0,MINS, EQL,BSLS, GRV,   \
            TAB,   Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,LBRC,RBRC,BSPC,        \
           LCTL,   A,   S,   D,   F,   G,   H,   J,   K,   L,SCLN,QUOT, ENT,             \
           LSFT,   Z,   X,   C,   V,   B,   N,   M,COMM, DOT,SLSH,RSFT, FN0,             \
                LALT, FN6,           SPC,                FN7,RALT),
    /* Number Pad Layer */
    [L_NP] = \
    KEYMAP( ESC,  NO,  NO,  NO,  NO,  NO,  NO,   7,   8,   9,PSLS,  NO,  NO,  NO, NO,    \
            TAB,  NO,  NO,  NO,  NO,  NO,  NO,   4,   5,   6,PAST,  NO,  NO,BSPC,        \
           LCTL,  NO,  NO,  NO,  NO,  NO,  NO,   1,   2,   3,PMNS,  NO, ENT,             \
           LSFT,  NO,  NO,  NO,  NO,  NO,  NO,   0,COMM, DOT,PPLS,RSFT, FN0,             \
                LALT,LGUI,           SPC,               RGUI,RALT),
    /* Fn Layer*/
    [L_FN] = \
    KEYMAP(TRNS,  F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9, F10, F11, F12, INS, DEL,   \
           CAPS, FN1, FN2, FN3,TRNS,TRNS,TRNS,TRNS,PSCR,SLCK,PAUS,  UP,TRNS,TRNS,        \
           TRNS,VOLD,VOLU,MUTE,TRNS,TRNS,PAST,PSLS,HOME,PGUP,LEFT,RGHT,PENT,             \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PPLS,PMNS, END,PGDN,DOWN,TRNS,TRNS,             \
                TRNS,TRNS,          TRNS,               TRNS,TRNS),
};

/* id for user defined functions */
enum function_id {
    USB_WIN,
    BT_IOS,
};

/*
 * Fn action definition
 */
#ifdef KEYMAP_SECTION_ENABLE
const action_t fn_actions[] __attribute__ ((section (".keymap.fn_actions"))) = {
#else
const action_t fn_actions[] PROGMEM = {
#endif
    [0]  = ACTION_LAYER_MOMENTARY(L_FN),
    [1]  = ACTION_FUNCTION(USB_WIN),  
    [2]  = ACTION_FUNCTION(BT_IOS), 
    [3]  = ACTION_DEFAULT_LAYER_SET(L_NP),
    [4]  = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_F13),
    [5]  = ACTION_MODS_TAP_KEY(MOD_RGUI, KC_F14),
    [6]  = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_CAPS),
    [7]  = ACTION_MODS_TAP_KEY(MOD_RGUI, KC_CAPS),
};

/*
 * user defined action function
 */
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case USB_WIN:
            rn42_force_usb(true);
            default_layer_set(1UL<<L_WIN);
            break;
        case BT_IOS:
            rn42_force_usb(false);
            default_layer_set(1UL<<L_IOS);
            break;
    }
}
