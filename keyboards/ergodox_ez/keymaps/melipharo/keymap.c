#include QMK_KEYBOARD_H

// The layers that we are defining for this keyboards.
#define BASE 0
#define FN_NUM 1
#define MEDIA 2
#define SYSLEDS 3
//KC_NO - NA

// A 'transparent' key code (that falls back to the layers below it).
#define ___ KC_TRNS // KC_TRANSPARENT


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // base layer
    [BASE] = LAYOUT_ergodox_pretty(
        KC_EQL,         KC_1,                KC_2,       KC_3,       KC_4,       KC_5,       KC_NO,                      KC_INS,             KC_6,       KC_7,       KC_8,       KC_9,           KC_0,                   KC_MINS,
        KC_DEL,         KC_Q,                KC_W,       KC_E,       KC_R,       KC_T,       TG(FN_NUM),                 TG(FN_NUM),         KC_Y,       KC_U,       KC_I,       KC_O,           KC_P,                   KC_BSLS,
        KC_BSPC,        KC_A,                KC_S,       KC_D,       KC_F,       KC_G,                                                       KC_H,       KC_J,       KC_K,       KC_L,           KC_SCLN,                KC_ENT,
        KC_LSFT,        KC_Z,                KC_X,       KC_C,       KC_V,       KC_B,       LSA(KC_1),                  LSA(KC_2),          KC_N,       KC_M,       KC_COMM,    KC_DOT,         LT(SYSLEDS, KC_SLSH),   KC_RSFT,
        KC_LCTRL,       LT(FN_NUM, KC_GRV),  KC_QUOT,    KC_LEFT,    KC_RGHT,                                                                            KC_UP,      KC_DOWN,    KC_LBRC,        LT(FN_NUM, KC_RBRC),    LT(MEDIA, KC_NO),
                                                                                KC_LALT,  KC_ESC,                      KC_PAUS,    LALT_T(KC_APP),
                                                                                                    KC_HOME,           KC_PGUP,
                                                                                KC_SPC,   KC_TAB,   KC_END,            KC_PGDN,    KC_LGUI,    KC_ENT
        ),

    // fn and nums layer
    [FN_NUM] = LAYOUT_ergodox_pretty(
        ___,          KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      ___,                        ___,        KC_F6,      KC_F7,      KC_F8,      KC_F9,          KC_F10,         KC_F11,
        ___,            KC_EXLM,    KC_AT,      KC_LCBR,    KC_RCBR,    KC_PIPE,    ___,                        ___,        KC_UP,      KC_7,       KC_8,       KC_9,           KC_ASTR,        KC_F12,
        ___,            KC_HASH,    KC_DLR,     KC_LPRN,    KC_RPRN,    KC_GRV,                                             KC_DOWN,    KC_4,       KC_5,       KC_6,           KC_PLUS,        ___,
        ___,            KC_PERC,    KC_CIRC,    KC_LBRC,    KC_RBRC,    KC_TILD,    ___,                        ___,        KC_AMPR,    KC_1,       KC_2,       KC_3,           KC_BSLS,        ___,
        ___,            ___,        ___,        ___,        ___,                                                                        KC_0,       KC_DOT,     ___,            KC_EQL,         ___,
                                                                            ___,    ___,                             ___,    ___,
                                                                                    ___,                             ___,
                                                                    ___,    ___,    ___,                             ___,    ___,   ___
        ),

    // mouse layer
    [MEDIA] = LAYOUT_ergodox_pretty(
        ___, ___, ___,      ___,        ___,        ___, ___,                       ___,    ___,        ___,        KC_PSCR,    KC_SLCK,    KC_NLCK,    ___,
        ___, ___, ___,      KC_MS_U,    ___,        ___, ___,                       ___,    ___,        ___,        ___,        ___,        ___,        RESET,
        ___, ___, KC_MS_L,  KC_MS_D,    KC_MS_R,    ___,                                    ___,        ___,        ___,        ___,        ___,        KC_MPLY,
        ___, ___, ___,      ___,        ___,        ___, ___,                       ___,    ___,        ___,        KC_MPRV,    KC_MNXT,    ___,        ___,
        ___, ___, ___,      KC_BTN1,    KC_BTN2,                                            KC_VOLU,    KC_VOLD,    KC_MUTE,    ___,        ___,
                                                            ___,    ___,                ___,    ___,
                                                                    ___,                ___,
                                                    ___,    ___,    ___,                ___,    ___,    KC_WBAK
        ),

    // std LEDs level
    [SYSLEDS] = LAYOUT_ergodox_pretty(
        ___, ___, ___, ___, ___, ___, ___,                       ___, ___, ___, ___, ___, ___,          ___,
        ___, ___, ___, ___, ___, ___, ___,                       ___, ___, ___, ___, ___, ___,          ___,
        ___, ___, ___, ___, ___, ___,                                 ___, ___, ___, ___, ___,          ___,
        ___, ___, ___, ___, ___, ___, ___,                       ___, ___, ___, ___, ___, MO(SYSLEDS),  ___,
        ___, ___, ___, ___, ___,                                      ___, ___, ___, ___, ___,
                                   ___, ___,                ___, ___,
                                        ___,                ___,
                              ___, ___, ___,                ___, ___, ___
    )
};

// The current set of active layers (as a bitmask).
// There is a global 'layer_state' variable but it is set after the call
// to layer_state_set_user().
static uint32_t current_layer_state = 0;
uint32_t layer_state_set_user(uint32_t state);

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// The state of the LEDs requested by the system, as a bitmask.
static uint8_t sys_led_state = 0;

// Use these masks to read the system LEDs state.
static const uint8_t sys_led_mask_num_lock = 1 << USB_LED_NUM_LOCK;
static const uint8_t sys_led_mask_caps_lock = 1 << USB_LED_CAPS_LOCK;
static const uint8_t sys_led_mask_scroll_lock = 1 << USB_LED_SCROLL_LOCK;

// Value to use to switch LEDs on. The default value of 255 is far too bright.
static const uint8_t max_led_value = 20;

void led_1_on(void) {
    ergodox_right_led_1_on();
    ergodox_right_led_1_set(max_led_value);
}

void led_2_on(void) {
    ergodox_right_led_2_on();
    ergodox_right_led_2_set(max_led_value);
}

void led_3_on(void) {
    ergodox_right_led_3_on();
    ergodox_right_led_3_set(max_led_value);
}

void led_1_off(void) {
    ergodox_right_led_1_off();
}

void led_2_off(void) {
    ergodox_right_led_2_off();
}

void led_3_off(void) {
    ergodox_right_led_3_off();
}

// Whether the given layer (one of the constant defined at the top) is active.
#define LAYER_ON(layer) (current_layer_state & (1<<layer))

// Called when the computer wants to change the state of the keyboard LEDs.
void led_set_user(uint8_t usb_led) {
    sys_led_state = usb_led;
    if (LAYER_ON(SYSLEDS)) {
        if (sys_led_state & sys_led_mask_num_lock) {
            led_1_on();
        } else {
            led_1_off();
        }
        if (sys_led_state & sys_led_mask_caps_lock) {
            led_2_on();
        } else {
            led_2_off();
        }
        if (sys_led_state & sys_led_mask_scroll_lock) {
            led_3_on();
        } else {
            led_3_off();
        }
    }
}

// Called every time the layer changed
uint32_t layer_state_set_user(uint32_t state) {
  current_layer_state = state;

  if (LAYER_ON(SYSLEDS)) {
    led_set_user(sys_led_state);
    return state;
  }

  if (LAYER_ON(FN_NUM)) {
    led_1_on();
  } else {
    led_1_off();
  }

  if (LAYER_ON(MEDIA)) {
    led_2_on();
  } else {
    led_2_off();
  }

  return state;
};
