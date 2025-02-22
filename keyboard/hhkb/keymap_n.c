//#define DEFAULT_LAYER_IS_JP
//#define FOR_CLASSIC_ENV

/*
 * HHKB Layout
 */
#include "keymap_common.h"
/*
 * for rn42 control
 */
#if PRODUCT_ID == 0x4242
#include "rn42_task.h"
#endif

enum layer_id {
#ifndef DEFAULT_LAYER_IS_JP
    L_US = 0,
    L_JP,
#else
    L_JP = 0,
    L_US,
#endif
#ifdef RN42_H
    L_USBT,
#endif
    L_NL,
    L_FN,
};

#ifdef KEYMAP_SECTION_ENABLE
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] __attribute__ ((section (".keymap.keymaps"))) = {
#else
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
#endif
    /* US Layer */
    [L_US] = \
    KEYMAP( ESC,   1,   2,   3,   4,   5,   6,   7,   8,   9,   0,MINS, EQL,BSLS, GRV,   \
            TAB,   Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,LBRC,RBRC,BSPC,        \
           LCTL,   A,   S,   D,   F,   G,   H,   J,   K,   L,SCLN,QUOT, ENT,             \
           LSFT,   Z,   X,   C,   V,   B,   N,   M,COMM, DOT,SLSH,RSFT, FN0,             \
                LALT, FN2,           SPC,                FN3,RALT),
    /* JP Layer (FN1 references US Layer) */
    [L_JP] = \
    KEYMAP( ESC,   1, FN1,   3,   4,   5, FN1, FN1, FN1, FN1, FN1, FN1, FN1,JYEN,FN1,    \
            TAB,   Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,RBRC,BSLS,BSPC,        \
           LCTL,   A,   S,   D,   F,   G,   H,   J,   K,   L, FN1, FN1, ENT,             \
           LSFT,   Z,   X,   C,   V,   B,   N,   M,COMM, DOT,SLSH,RSFT, FN0,             \
                LALT, FN4,           SPC,                FN5,RALT),
#ifdef RN42_H
    /* USBT Layer */
    [L_USBT] = \
    KEYMAP( ESC,   1,   2,   3,   4,   5,   6,   7,   8,   9,   0,MINS, EQL,BSLS, GRV,   \
            TAB,   Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,LBRC,RBRC,BSPC,        \
           LCTL,   A,   S,   D,   F,   G,   H,   J,   K,   L,SCLN,QUOT, ENT,             \
           LSFT,   Z,   X,   C,   V,   B,   N,   M,COMM, DOT,SLSH,RSFT, FN0,             \
                LALT,FN10,           SPC,               FN11,RALT),
#endif
    /* Number Lock Layer */
    [L_NL] = \
    KEYMAP(TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   7,   8,   9,PSLS,TRNS,TRNS,TRNS,TRNS,   \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   4,   5,   6,PAST,TRNS,TRNS,TRNS,        \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   1,   2,   3,PMNS,TRNS,TRNS,             \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,   0,COMM, DOT,PPLS,TRNS, FN0,             \
                TRNS,TRNS,          TRNS,               TRNS,TRNS),
#ifndef RN42_H
    /* Fn Layer*/
    [L_FN] = \
    KEYMAP(TRNS,  F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9, F10, F11, F12, INS, DEL,   \
           CAPS, FN6, FN7, FN8,TRNS,TRNS,TRNS,TRNS,PSCR,SLCK,PAUS,  UP,TRNS,TRNS,        \
           TRNS,VOLD,VOLU,MUTE,TRNS,TRNS,PAST,PSLS,HOME,PGUP,LEFT,RGHT,PENT,             \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PPLS,PMNS, END,PGDN,DOWN,TRNS,TRNS,             \
                TRNS,TRNS,          TRNS,               TRNS,TRNS),
#else
    /* Fn Layer*/
    [L_FN] = \
    KEYMAP(TRNS,  F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9, F10, F11, F12, INS, DEL,   \
           CAPS, FN6, FN7, FN8, FN9,TRNS,TRNS,TRNS,PSCR,SLCK,PAUS,  UP,TRNS,TRNS,        \
           TRNS,VOLD,VOLU,MUTE,TRNS,TRNS,PAST,PSLS,HOME,PGUP,LEFT,RGHT,PENT,             \
           TRNS,TRNS,TRNS,TRNS,TRNS,TRNS,PPLS,PMNS, END,PGDN,DOWN,TRNS,TRNS,             \
                TRNS,TRNS,          TRNS,               TRNS,TRNS),
#endif
};

/* id for user defined functions */
enum function_id {
    US2JP = 1,
#ifdef RN42_H
    BT_US,
    USB_US,
    USB_JP,
#endif
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
    [1]  = ACTION_FUNCTION(US2JP),
    [2]  = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_LANG2),
    [3]  = ACTION_MODS_TAP_KEY(MOD_RGUI, KC_LANG1),
#ifndef FOR_CLASSIC_ENV
    [4]  = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_LANG2),
    [5]  = ACTION_MODS_TAP_KEY(MOD_RGUI, KC_LANG1),
#else
    [4]  = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_MHEN),
    [5]  = ACTION_MODS_TAP_KEY(MOD_RGUI, KC_HENK),
#endif
    [6]  = ACTION_DEFAULT_LAYER_SET(L_NL),
#ifndef RN42_H
    [7]  = ACTION_DEFAULT_LAYER_SET(L_US),
    [8]  = ACTION_DEFAULT_LAYER_SET(L_JP),
#else
    [7]  = ACTION_FUNCTION(USB_US), 
    [8]  = ACTION_FUNCTION(USB_JP),  
    [9]  = ACTION_FUNCTION(BT_US), 
    [10] = ACTION_MODS_TAP_KEY(MOD_LGUI, KC_CAPS),
    [11] = ACTION_MODS_TAP_KEY(MOD_RGUI, KC_CAPS),
#endif
};

/*
 * user defined action function
 */
const uint8_t us2jp_table[] = {
/*  US_KC,  US_SFT, JP_KC,  JP_SFT */
    KC_2,   1,      KC_LBRC,0,      // @
    KC_6,   1,      KC_EQL, 0,      // ^
    KC_7,   1,      KC_6,   1,      // &
    KC_8,   1,      KC_QUOT,1,      // *
    KC_9,   1,      KC_8,   1,      // (
    KC_0,   1,      KC_9,   1,      // )
    KC_MINS,1,      KC_RO,  1,      // _
    KC_EQL, 0,      KC_MINS,1,      // =
    KC_EQL, 1,      KC_SCLN,1,      // +
    KC_SCLN,1,      KC_QUOT,0,      // :
    KC_QUOT,0,      KC_7,   1,      // '
    KC_QUOT,1,      KC_2,   1,      // "
    KC_GRV, 0,      KC_LBRC,1,      // `
    KC_GRV, 1,      KC_EQL, 1,      // ~
    0
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    uint8_t src_shift, pseudo_shift;
    uint8_t src_keycode, pseudo_keycode;
    const uint8_t *p_us2jp_table;
    switch (id) {
        case US2JP:
            src_keycode = keymap_key_to_keycode(L_US, record->event.key);  
            src_shift = keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT));
            if (record->event.pressed) {
                if (IS_COMMAND()) { /* when magic commands entered, keycode does not converted */
                    register_code(src_keycode); 
                    return; 
                }
                p_us2jp_table = us2jp_table;
                while (*p_us2jp_table) {
                    if ((*p_us2jp_table == src_keycode) && *(p_us2jp_table + 1) == (src_shift ? 1 : 0)) {
                        pseudo_keycode = *(p_us2jp_table + 2);
                        pseudo_shift = *(p_us2jp_table + 3);
                        if (src_shift) {
                            if (pseudo_shift) {
                                register_code(pseudo_keycode);
                                del_key(pseudo_keycode);
                                return;
                            }
                            else {
                                del_mods(src_shift);
                                send_keyboard_report();
                                register_code(pseudo_keycode);
                                del_key(pseudo_keycode);
                                add_mods(src_shift);
                                return;
                            }
                        }
                        else {
                            if (pseudo_shift) {
                                add_mods(MOD_BIT(KC_LSFT));
                                send_keyboard_report();
                                register_code(pseudo_keycode);
                                del_key(pseudo_keycode);
                                del_mods(MOD_BIT(KC_LSFT));
                                return;
                            }
                            else {
                                register_code(pseudo_keycode);
                                del_key(pseudo_keycode);
                                return;
                            }
                        }
                    }
                    p_us2jp_table += 4;
                }
                register_code(src_keycode);
            }
            else {
                unregister_code(src_keycode);
            }
            break;
#ifdef RN42_H
        case BT_US:
            rn42_force_usb(false);
            default_layer_set(1UL<<L_USBT);
            break;
        case USB_US:
            rn42_force_usb(true);
            default_layer_set(1UL<<L_US);
            break;
        case USB_JP:
            rn42_force_usb(true);
            default_layer_set(1UL<<L_JP);
            break;
#endif
    }
}
