#include QMK_KEYBOARD_H

enum dz60rgb_layers {
	_QWERTY,
	_FN,
	_RGB
};

enum dz60rgb_keycodes {
	REBOOT = SAFE_RANGE,
	MAS_RUP,
	MAS_RDN,
	MAS_GUP,
	MAS_GDN,
	MAS_BUP,
	MAS_BDN,
	MAS_CRM,
	MAS_PRP,
	MAS_RED,
	MAS_GRN,
	MAS_BLU,
	MAS_CYN,
	MAS_MGT,
	MAS_YEL,
	MAS_KEY,
	MAS_WHT,
};

const int8_t step_size = 16;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_ANSI(
		KC_ESCAPE, KC_1,  KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
		KC_TAB,    KC_Q,  KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
		KC_LGUI,   KC_A,  KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT,     KC_ENTER,
		KC_LSFT,   KC_Z,  KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSHIFT,
		KC_LCTRL,  TT(1), KC_LALT,           KC_SPC,              KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT
							),
	[_FN] = LAYOUT_ANSI(
		KC_GRAVE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
		KC_TRNS, KC_PSCREEN, KC_SCROLLLOCK, KC_PAUSE, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_INSERT, KC_HOME, KC_PGUP, KC_VOLD, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_DELETE, KC_END, KC_PGDOWN, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
		TG(2), KC_TRNS, KC_LOCK, KC_LEAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
		),
	[_RGB] = LAYOUT_ANSI(
		MAS_KEY, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NUMLOCK, KC_KP_SLASH, KC_KP_ASTERISK,    KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, RGB_MOD, RGB_RMOD, KC_TRNS, MAS_MGT, MAS_BLU, MAS_WHT,   KC_KP_7,    KC_KP_8,       KC_KP_9,     KC_KP_MINUS, KC_TRNS, KC_TRNS, KC_TRNS,
		RGB_VAI, MAS_RUP, MAS_GUP,  MAS_BUP, MAS_RED, MAS_PRP, MAS_CYN,   KC_KP_4,    KC_KP_5,       KC_KP_6,      KC_KP_PLUS, KC_TRNS,     KC_TRNS,
		RGB_VAD, MAS_RDN, MAS_GDN,  MAS_BDN, MAS_YEL, MAS_GRN, MAS_CRM,   KC_KP_1,    KC_KP_2,       KC_KP_3,                  KC_TRNS,     KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS,                                        KC_KP_0,    KC_KP_DOT,     KC_TRNS,                  KC_TRNS,     KC_TRNS
		),
	/*
		 [_LAYER] = LAYOUT(
		13,      12,      11,       10,      9,       8,       7,       6,       5,       4,       3,       2,       1,       0,      \
		27,      26,      25,       24,      23,      22,      21,      20,      19,      18,      17,      16,      15,      14,     \
		40,      39,      38,       37,      36,      35,      34,      33,      32,      31,      30,      29,      28,              \
		53,      52,      51,       50,      49,      48,      47,      46,      45,      44,      43,               42,      41,     \
		62,      61,      60,                         59,                        58,      57,               56,      55,      54      \
	),
	*/
};

void rgb_matrix_layer_helper (uint8_t red, uint8_t green, uint8_t blue) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    rgb_matrix_set_color( i, red, green, blue );
  }
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;

	// Sequences go here
	SEQ_ONE_KEY(KC_L) {
		SEND_STRING(SS_LCTRL(SS_LGUI(SS_LALT(SS_LSFT("l")))));
	} else
	SEQ_ONE_KEY(KC_S) {
		SEND_STRING(SS_LCTRL(SS_LGUI(SS_LALT(SS_LSFT("s")))));
	} else
	SEQ_TWO_KEYS(KC_B, KC_F) {
		SEND_STRING(SS_LCTRL(SS_LGUI(SS_LALT(SS_LSFT("bf")))));
	} else
	SEQ_TWO_KEYS(KC_B, KC_C) {
		SEND_STRING(SS_LCTRL(SS_LGUI(SS_LALT(SS_LSFT("bc")))));
	} else
	SEQ_TWO_KEYS(KC_B, KC_S) {
		SEND_STRING(SS_LCTRL(SS_LGUI(SS_LALT(SS_LSFT("bs")))));
	} else
	SEQ_TWO_KEYS(KC_I, KC_T) {
		SEND_STRING(SS_LCTRL(SS_LGUI(SS_LALT(SS_LSFT("it")))));
	} else
	SEQ_TWO_KEYS(KC_W, KC_S) {
		SEND_STRING(SS_LCTRL(SS_LGUI(SS_LALT(SS_LSFT("ws")))));
	} else
	SEQ_TWO_KEYS(KC_W, KC_O) {
		SEND_STRING(SS_LCTRL(SS_LGUI(SS_LALT(SS_LSFT("wo")))));
	}
	// And stop here
    leader_end();
  }
}

typedef union {
	uint32_t raw;
	struct {
		bool isOn;
		uint8_t red;
		uint8_t green;
		uint8_t blue;
	};
} user_config_t;

user_config_t user_config;

void keyboard_post_init_user(void) {
	user_config.raw = eeconfig_read_user();
}

void eeconfig_init_user(void) {
	user_config.raw = 0;
	user_config.isOn = true;
	user_config.red = 255;
	user_config.green = 0;
	user_config.blue = 0;

	eeconfig_update_user(user_config.raw);
}

bool triggerSave = false;

void rgb_matrix_indicators_user(void) {

	if (!g_suspend_state && rgb_matrix_config.enable) {
		if (user_config.isOn) {
			switch (biton32(layer_state)) {
				case _QWERTY: {
					rgb_matrix_layer_helper(user_config.red, user_config.green, user_config.blue);
					if (triggerSave) {
						eeconfig_update_user(user_config.raw);
						triggerSave = false;
					}
				}
				break;
				case _RGB: {
					uint8_t rup = user_config.red + step_size > 255 ? 255 : user_config.red + step_size;
					uint8_t rdn = user_config.red - step_size < 0   ?   0 : user_config.red - step_size;
					uint8_t gup = user_config.green + step_size > 255 ? 255 : user_config.green + step_size;
					uint8_t gdn = user_config.green - step_size < 0   ?   0 : user_config.green - step_size;
					uint8_t bup = user_config.blue + step_size > 255 ? 255 : user_config.blue + step_size;
					uint8_t bdn = user_config.blue - step_size < 0   ?   0 : user_config.blue - step_size;

					//Top row as color indicator
					//red
					uint16_t value = user_config.red * 4;
					rgb_matrix_set_color(12, value > 255 ? 255 : value, 0, 0);
					value = value - 255 < 0 ? 0 : value - 255;
					rgb_matrix_set_color(11, value > 255 ? 255 : value, 0, 0);
					value = value - 255 < 0 ? 0 : value - 255;
					rgb_matrix_set_color(10, value > 255 ? 255 : value, 0, 0);
					value = value - 255 < 0 ? 0 : value - 255;
					rgb_matrix_set_color(9 , value > 255 ? 255 : value, 0, 0);

					//green
					value = user_config.green * 4;
					rgb_matrix_set_color(8, 0, value > 255 ? 255 : value, 0); 
					value = value - 255 < 0 ? 0 : value - 255;
					rgb_matrix_set_color(7, 0, value > 255 ? 255 : value, 0); 
					value = value - 255 < 0 ? 0 : value - 255;
					rgb_matrix_set_color(6, 0, value > 255 ? 255 : value, 0); 
					value = value - 255 < 0 ? 0 : value - 255;
					rgb_matrix_set_color(5, 0, value > 255 ? 255 : value, 0);

					//blue
					value = user_config.blue * 4;
					rgb_matrix_set_color(4, 0, 0, value > 255 ? 255 : value); 
					value = value - 255 < 0 ? 0 : value - 255;
					rgb_matrix_set_color(3, 0, 0, value > 255 ? 255 : value); 
					value = value - 255 < 0 ? 0 : value - 255;
					rgb_matrix_set_color(2, 0, 0, value > 255 ? 255 : value); 
					value = value - 255 < 0 ? 0 : value - 255;
					rgb_matrix_set_color(1, 0, 0, value > 255 ? 255 : value);

					rgb_matrix_set_color(0, user_config.red, user_config.green, user_config.blue);

					for (int8_t a = 13; a < 63; a = a + 1) {
						if (a == 13) rgb_matrix_set_color(a,   0x00,    0x00,      0x00  ); //MAS_KEY
						else if (a == 39) rgb_matrix_set_color(a,   rup,       0,        0    ); //RED UP
						else if (a == 52) rgb_matrix_set_color(a,   rdn,       0,        0    ); //RED DOWN
						else if (a == 38) rgb_matrix_set_color(a,    0,       gup,       0    ); //GREEN UP
						else if (a == 51) rgb_matrix_set_color(a,    0,       gdn,       0    ); //GREEN DOWN
						else if (a == 37) rgb_matrix_set_color(a,    0,        0,       bup   ); //BLUE UP
						else if (a == 50) rgb_matrix_set_color(a,    0,        0,       bdn   ); //BLUE DOWN
						else if (a == 23) rgb_matrix_set_color(a,   0xF0,    0x00,      0xFF  ); //MAS_MGT
						else if (a == 22) rgb_matrix_set_color(a,   0x00,    0x02,      0xFF  ); //MAS_BLU
						else if (a == 21) rgb_matrix_set_color(a,   0xFF,    0xFF,      0xFF  ); //MAS_WHT
						else if (a == 36) rgb_matrix_set_color(a,   0xFF,    0x00,      0x00  ); //MAS_RED
						else if (a == 35) rgb_matrix_set_color(a,   0x81,    0x3C,      0xFF  ); //MAS_PRP
						else if (a == 34) rgb_matrix_set_color(a,   0x00,    0xFF,      0xF7  ); //MAS_CYN
						else if (a == 49) rgb_matrix_set_color(a,   0xFF,    0xDA,      0x00  ); //MAS_YEL
						else if (a == 48) rgb_matrix_set_color(a,   0x00,    0xFF,      0x01  ); //MAS_GRN
						else if (a == 47) rgb_matrix_set_color(a,   0xFF,    0xA5,      0x18  ); //MAS_CRM
						else rgb_matrix_set_color(a, user_config.red, user_config.green, user_config.blue);
					}
				}
				break;
				case _FN: {
					rgb_matrix_layer_helper(user_config.red, user_config.green, user_config.blue);
					for (int i = 1; i < 13; i++) {
						rgb_matrix_set_color(i, 255, 79, 0); 
					}
					rgb_matrix_set_color(34, 0, 168, 255); 
					rgb_matrix_set_color(33, 0, 168, 255); 
					rgb_matrix_set_color(32, 0, 168, 255); 
					rgb_matrix_set_color(31, 0, 168, 255); 
				}
				break;
			}
		} else {
			rgb_matrix_layer_helper(0,0,0);
		}
	}
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
	switch(keycode) {
    case MAS_RUP:
		if (record->event.pressed) {
			user_config.red = user_config.red + step_size > 255 ? 255 : user_config.red + step_size;
			triggerSave = true;
		}

		return false;
    case MAS_RDN:
		if (record->event.pressed) {
			user_config.red = user_config.red - step_size < 0 ? 0 : user_config.red - step_size;
			triggerSave = true;
		}
		
		return false;
    case MAS_GUP:
		if (record->event.pressed) {
			user_config.green = user_config.green + step_size > 255 ? 255 : user_config.green + step_size;
			triggerSave = true;
		}

		return false;
    case MAS_GDN:
		if (record->event.pressed) {
			user_config.green = user_config.green - step_size < 0 ? 0 : user_config.green - step_size;
			triggerSave = true;
		}
		
		return false;
    case MAS_BUP:
		if (record->event.pressed) {
			user_config.blue = user_config.blue + step_size > 255 ? 255 : user_config.blue + step_size;
			triggerSave = true;
		}

		return false;
    case MAS_BDN:
		if (record->event.pressed) {
			user_config.blue = user_config.blue - step_size < 0 ? 0 : user_config.blue - step_size;
			triggerSave = true;
		}
		
		return false;
	case MAS_CRM:
		if (record->event.pressed) {
			rgb_matrix_sethsv(32, 160, 255);
			triggerSave = true;
		}

		return false;
	case MAS_PRP:
		if (record->event.pressed) {
			rgb_matrix_sethsv(192, 112, 255);
			triggerSave = true;
		}

		return false;

	case MAS_RED:
		if (record->event.pressed) {
			rgb_matrix_sethsv(0, 255, 255);
			triggerSave = true;
		}

		return false;

	case MAS_GRN:
		if (record->event.pressed) {
			rgb_matrix_sethsv(88, 255, 255);
			triggerSave = true;
		}

		return false;

	case MAS_BLU:
		if (record->event.pressed) {
			rgb_matrix_sethsv(168, 255, 255);
			triggerSave = true;
		}

		return false;

	case MAS_CYN:
		if (record->event.pressed) {
			rgb_matrix_sethsv(128, 255, 255);
			triggerSave = true;
		}

		return false;

	case MAS_MGT:
		if (record->event.pressed) {
			rgb_matrix_sethsv(216, 255, 255);
			triggerSave = true;
		}

		return false;

	case MAS_YEL:
		if (record->event.pressed) {
			rgb_matrix_sethsv(40, 255, 255);
			triggerSave = true;
		}

		return false;

	case MAS_KEY:
		if (record->event.pressed) {
			user_config.isOn = !user_config.isOn;
			triggerSave = true;
		}

		return false;

	case MAS_WHT:
		if (record->event.pressed) {
			user_config.red   = 255;
			user_config.green = 255;
			user_config.blue  = 255;
			triggerSave = true;
		}

		return false;

	default:
		return true;
	}
}