#include QMK_KEYBOARD_H

#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2

enum unicode_names {
    BANG,
    SNEK,
    HRT,
    FLEX,
    PRTY,
    KISS,
    THUP,
    CHLI,
    MOON,
    OCTO,
    THNK,
    BRN,
    EGL,
    DODO,
    DRGN,
    CAMP,
    GME,
    SMRK,
    MNY,
    OFCE,
    SAD,
};

const uint32_t PROGMEM unicode_map[] = {
    [BANG]  = 0x203D,  // ‽
    [SNEK]  = 0x1F40D, // 🐍
    [HRT] = 0x2665, // ♥
    [FLEX] = 0x1F4AA, // 💪
    [PRTY] = 0x1F389, // 🎉
    [KISS] = 0x1F618, // 😘
    [THUP] = 0x1F44D, // 👍
    [CHLI] = 0x1F336, // 🌶
    [MOON] = 0x1F31D, // 🌝
    [OCTO] = 0x1F419, // 🐙
    [THNK] = 0x1F914, // 🤔
    [BRN] = 0x1F9E0, 
    [EGL] = 0x1F985,
    [DODO] = 0x1F9A4,
    [DRGN] = 0x1F409,
    [CAMP] = 0x1F3D5, // 🏕
    [GME] = 0x1F579, // 🕹
    [SMRK] = 0x1F60F, // 😏
    [MNY] = 0x1F4B8, // 💸
    [OFCE] = 0x1F975,
    [SAD] = 0x1F622, // 😢
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
		[_LAYER0] = LAYOUT_65_ansi_blocker( /* Base */
			KC_GESC,       KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,   KC_HOME,
		    KC_TAB,        KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLASH, KC_PGUP,
			KC_ESC,        KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,    KC_PGDN,
		    KC_LSFT,       KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  KC_N,    KC_M,  KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,           KC_UP,     KC_END,
		    KC_LCTL,       KC_LGUI,  KC_LALT,                KC_SPC,                MO(1),             MO(2),    KC_LEFT,           KC_DOWN,   KC_RIGHT
        ),

		[_LAYER1] = LAYOUT_65_ansi_blocker( /* FN */
			KC_GESC,       KC_F1,    KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  KC_DEL,   KC_PSCR,
		    _______,       RGB_TOG,  RGB_MOD, RGB_HUI,RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______,  _______, KC_PAUS, KC_INS,   _______,
			_______,       RGB_SPI,  RGB_SPD, _______,_______, _______, _______, _______, _______, _______, _______,  _______,          KC_MPLY,  _______,
		    KC_RSFT,       _______,  _______, _______,_______, _______, _______, _______, _______, _______, _______,  _______,          KC_VOLU,  _______,
		    KC_RCTL,       KC_RGUI,  KC_RALT,                  _______,                   _______,          _______,  KC_MPRV,          KC_VOLD,  KC_MNXT),

		[_LAYER2] = LAYOUT_65_ansi_blocker( /* FN2 */
			_______,       X(BANG),  _______, X(SMRK),X(MNY),  _______, _______,  _______, _______, _______, _______,  _______, _______, _______,  X(SNEK),
		    _______,       _______,  _______, X(EGL), _______, X(THUP), _______,  _______, _______, X(OFCE), X(PRTY),  _______, _______, _______,  X(OCTO),
			_______,       _______,  X(SAD),  X(DODO),X(FLEX), X(GME),  X(HRT),   _______, X(KISS), _______, _______,  _______,          _______,  _______,
		    _______,       X(CAMP),  X(DRGN), X(CHLI),_______, X(BRN), _______,  _______, _______, _______, X(THNK),  _______,           _______,  _______,
		    _______,       _______,  _______,                  _______,                    _______,          _______,  _______,          _______,  UC_MOD),
};

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index <= led_max && index != NO_LED &&
                keymap_key_to_keycode(layer, (keypos_t){col,row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, RGB_GREEN);
                }
            }
        }
    }
}

