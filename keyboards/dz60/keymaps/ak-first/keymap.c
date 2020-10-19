// -*- compile-command: "make dz60:ak-first:dfu" -*-


// option + f12 terminal

#include QMK_KEYBOARD_H

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// static bool isCmdSetByMeta = false;

enum custom_keycodes {
					  TEST = SAFE_RANGE,
                      SURPAR,
					  STICKY_SEL,
					  PHONY,
					  NEXT,
					  NCOMMA,
					  NCOLON,
					  C_ENT,
					  COUT,
					  CIN,
					  NAMESPACE,
					  PLUSPLUS,
					  MOD_SWITCH,
					  JOKER,
					  JOIN_L,
					  DUP,
					  L_SEL,
					  L_DEL,
					  W_SEL,
					  PGDN,
					  EQL_EQL,
					  EQL_SPC,
					  ENDL_JOKER,
					  RT_SPC,
					  RT2_SPC,
					  ADVANCE,
					  SEARCH,
					  CAPS,
					  CAPSSPS,
					  LEADER,
					  PYBLOCK,
					  CBLOCK,
					  BSP,
					  SSHIFT,
					  YANK,
					  KILL,
					  OSL_NUM,
					  OSL_EDI,
					  OSL_SYM,
					  OSL_BRA,
					  OSL_IDE,
					  OSL_REF,
					  LGUI,
                      MAC,
                      WIN,
                      MACMETA,
                      RCMD,
                      LCMD,
                      LALT,
                      RALT,
                      LCTL,
                      RSFT,
                      _VIMRC,
                      CC_PLS,
                      CC_MIN,
                      CX_CC,
                      CXCS,
                      CXCS_CXE,
                      CXCS_CZ,
                      CXCS_CXCC,
                      LSWITCH,
                      CMDTAB,
                      SCMDTAB,
                      CMDTAB2,
                      ALTTAB,
                      SALTTAB,
                      ALTQUO,
                      LBR_RBR_LFT,
                      GQ,
                      CX_CX,
                      CX_G,
                      CX_Z,
                      CX_F,
                      CX_CF,
                      CX_O,
                      CX_B,
                      CX_K,
                      CX_0,
                      CX_1,
                      CX_3,
                      M0_CK,
                      CXCJ_0,
                      CXCJ_B,
                      CXCJ_CC,
                      CXCJ_D,
                      CXCJ_CD,
                      CXCJ_SD,
                      CXCJ_MD,
                      CXCJ_T,
                      CXCJ_CT,
                      CXCJ_MT,
                      CX_P,
                      CX_CP,
                      CX_LBRC,
                      CX_RBRC,
                      COM_MIN,
                      COM_SPC,
                      COM_SPC_RU,
                      EENTER,
                      EEENTER,
                      PARENS,
                      PARENS_ENDL,
                      BRACES,
                      BL_BRACES,
                      BRACKS,
                      BRACKS_RU,
                      ABRACKS,
					  QUOTES,
					  CCS, // complete current statement
					  CCSNL,
					  SCLSPC,  // semicolon space
					  ENDSPC,
					  ENDL,
					  H_A,
					  H_B,
					  H_C,
					  H_D,

};

// -layers enum
enum {
      EN_LR,
      RU_LR,
      MACOS_LR,
      NUM_LR,
      EDI_LR,
      SEL_LR,
      SEL2_LR,
      SYM_LR,
      RU_SYM_LR,
	  NEXT_LR,
	  BRA_LR,
      RU_BRA_LR,
      IDE_LR,
	  REF_LR,
};

#define _LSFT KC_LSFT
#define _LCTL KC_LCTL
#define _LGUI KC_LGUI
#define _LALT KC_LALT

#define TR KC_TRNS

#define _U KC_U
#define _1 KC_1
#define _2 KC_2
#define _3 KC_3
#define _4 KC_4
#define _5 KC_5
#define _6 KC_6
#define _7 KC_7
#define _8 KC_8
#define _9 KC_9
#define _0 KC_0
#define _A KC_A
#define _B KC_B
#define _C KC_C
#define _D KC_D
#define _E KC_E
#define _F KC_F
#define _G KC_G
#define _H KC_H
#define _I KC_I
#define _J KC_J
#define _K KC_K
#define _L KC_L
#define _M KC_M
#define _N KC_N
#define _O KC_O
#define _P KC_P
#define _Q KC_Q
#define _R KC_R
#define _S KC_S
#define _T KC_T
#define _U KC_U
#define _V KC_V
#define _W KC_W
#define _X KC_X
#define _Y KC_Y
#define _Z KC_Z

#define _F1 KC_F1
#define _F2 KC_F2
#define _F3 KC_F3
#define _F4 KC_F4
#define _F5 KC_F5
#define _F6 KC_F6
#define _F7 KC_F7
#define _F8 KC_F8
#define _F9 KC_F9
#define _F10 KC_F10
#define _F11 KC_F11
#define _F12 KC_F12
#define _F13 KC_F13
#define _F14 KC_F14
#define _F15 KC_F15
#define _F16 KC_F16
#define _F17 KC_F17
#define _F18 KC_F18
#define _F19 KC_F19
#define _F20 KC_F20

#define _RT KC_RGHT
#define _LT KC_LEFT
#define _UP KC_UP
#define _DN KC_DOWN
#define _VUP KC__VOLUP
#define _VDN KC__VOLDOWN

#define _CSL KC_BSLS
#define _COM KC_COMM
#define _MIN KC_MINS
#define _TAB KC_TAB
#define _TB KC_TAB
#define _CAP KC_CAPS
#define _LBR KC_LBRC
#define _RBR KC_RBRC
#define _NO KC_NO
#define _BSP KC_BSPC
#define _ESC KC_ESC
#define _BSL KC_BSLS
#define _SPC KC_SPC
#define _DOT KC_DOT
#define _SLS KC_SLSH
#define _QUO KC_QUOT
#define _ENT KC_ENT
#define _DOW KC_DOWN
#define _UP KC_UP
#define _EQL KC_EQL
#define _SCL KC_SCLN
#define _GRV KC_GRV
#define CTA(x) LCTL(LALT(x))
#define ALT(x) LALT(x)
#define CTL(x) LCTL(x)
#define GUI(x) LGUI(x)
#define GUA(x) LGUI(LALT(x))
#define ALG(x) LALT(LGUI(x))
#define GACS(x) LGUI(LALT(LCTL(LSFT(x))))
#define _PGUP KC_PGUP
#define _PGDN KC_PGDN
#define _HOME KC_HOME
#define _END KC_END
#define _DEL KC_DELETE
#define GR(x) RGUI(x)

#define SS_RGUI(string) SS_DOWN(X_RGUI) string SS_UP(X_RGUI)

static uint16_t timer, rcmd_timer;
static const uint16_t timer_threshold = 250;
static const uint16_t oneshot_threshold = 700, oneshot_next_threshold = 1500, joker_threshold = 2000;
static uint8_t rgblight_mode_current = RGBLIGHT_MODE_KNIGHT + 1;
static uint8_t em_forced = 0;

static uint16_t oneshot_timer, oneshot_next_timer, rt_spc_timer, endl_joker_timer, esc_promise_timer;
static uint8_t oneshot_down = 0, oneshot_fired = 0,
	oneshot_next_down = 0, oneshot_next_fired = 0;
static uint8_t
    caps = 0,
	comma_advance = 0,
 	rt_spc = 0,
	endl_joker = 0,
	ru_off = 0,
	sel_off = 0,
	mod = 0;



void keyboard_post_init_user(void) {
  // Call the post init code.

	/* rgblight_disable(); */
	rgblight_disable();
	rgblight_mode_noeeprom(rgblight_mode_current + 7); // sets mode to Fast breathing without saving

	/* rgblight_enable_noeeprom(); // enables Rgb, without saving settings */
	/* rgblight_sethsv_noeeprom(250, 200, 100); // sets the color to teal/cyan without saving */
	/* rgblight_mode_noeeprom(rgblight_mode_current); // sets mode to Fast breathing without saving */
	/* rgblight_disable_noeeprom(); */
}

uint32_t layer_state_set_user(uint32_t state) {
	/* rgblight_enable_noeeprom(); */
	/* if () */

	if (1UL << RU_LR & state) {
		rgblight_enable_noeeprom();
		/* rgblight_setrgb(0, 16, 0); //green */
	} else {
		rgblight_disable_noeeprom();
		/* rgblight_setrgb(16, 0, 0); //green */
		/* rgblight_disable_noeeprom(); */
	}
	return state;
}

void unregister_cmd_after_cmdtab(void) {
  uint8_t layer = biton32(layer_state);
  /* bool isCmdOn = get_mods() & MOD_BIT(KC_LGUI); */
  /* if (layer != META && isCmdSetByMeta && isCmdOn) { */
  /*   unregister_mods(MOD_LGUI); */
  /*   isCmdSetByMeta = false; */
  /* } */
  if (layer == MACOS_LR) {
    unregister_mods(MOD_LGUI);
    unregister_mods(MOD_LALT);
  }
};

void increase_timer(void) {
  uint8_t layer = biton32(layer_state);
  if (layer == MACOS_LR) timer += 2 * timer_threshold;
}

/* static __attribute__ ((noinline)) void process_record_noinline(keyrecord_t *record) { */
/* 	process_record(record); */
/* } */

static __attribute__ ((noinline)) void oneshot_check(int LR, uint8_t layer_mask) {
	if ((layer_mask << LR) & layer_state) {
		if ((!oneshot_down && oneshot_fired) ||
			(!oneshot_down && timer_elapsed(oneshot_timer) > oneshot_threshold)) {
			layer_off(LR);
		}
	}
}

static __attribute__ ((noinline))
void oneshot_fired_check(uint16_t keycode, int LR, uint8_t layer_mask, int TRIG) {
	if ((layer_mask << LR) & layer_state)
			if (keycode != TRIG)
				oneshot_fired = 1;
}

void matrix_scan_user(void) {
	oneshot_check(NUM_LR, 1);
	oneshot_check(IDE_LR, 1);
	oneshot_check(REF_LR, 1);
	oneshot_check(EDI_LR, 1);
	/* if (biton32(layer_state) == EDI_LR && !em_forced) { */
		/* if ((!oneshot_down && oneshot_fired) || */
			/* (!oneshot_down && timer_elapsed(oneshot_timer) > oneshot_threshold)) { */
			/* layer_off(EDI_LR); */
		/* } */
	/* } */
	if (biton32(layer_state) == NEXT_LR) {
		if ((!oneshot_next_down && oneshot_next_fired) ||
			(!oneshot_next_down && timer_elapsed(oneshot_next_timer) > oneshot_next_threshold)) {
			layer_off(NEXT_LR);
		}
	}
	if (((3UL << SYM_LR) & layer_state)) {
		if ((!oneshot_down && oneshot_fired) ||
			(!oneshot_down && timer_elapsed(oneshot_timer) > oneshot_threshold)) {
			layer_off(SYM_LR);
			if (1UL << RU_LR & layer_state)
				layer_off(RU_SYM_LR);
		}
	}
	if (((3UL << BRA_LR) & layer_state)) {
		if ((!oneshot_down && oneshot_fired) ||
			(!oneshot_down && timer_elapsed(oneshot_timer) > oneshot_threshold)) {
			layer_off(BRA_LR);
			if (1UL << RU_LR & layer_state)
				layer_off(RU_BRA_LR);
		}
	}
	if (ru_off) {
		if (1UL << RU_LR & layer_state) {
			send_string(SS_LGUI(" "));
			layer_off(RU_LR);
			layer_off(RU_BRA_LR);
			layer_off(RU_SYM_LR);
			ru_off = 0;
		}
	}
	if (sel_off) {
		if (1UL << SEL_LR & layer_state) {
			layer_off(SEL2_LR);
			layer_off(SEL_LR);
			layer_off(EDI_LR);
			sel_off = 0;
		}
	}
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
		uint8_t layer = layer_switch_get_layer(record->event.key); // from which layer keycode flew in
		oneshot_fired_check(keycode, NUM_LR, 1, OSL_NUM);
		oneshot_fired_check(keycode, IDE_LR, 1, OSL_IDE);
		oneshot_fired_check(keycode, REF_LR, 1, OSL_REF);
		oneshot_fired_check(keycode, BRA_LR, 3, OSL_BRA);
		oneshot_fired_check(keycode, SYM_LR, 3, OSL_SYM);
		if ((1UL << SEL2_LR) & layer_state && layer == SEL2_LR)
			sel_off = 1;
		oneshot_fired_check(keycode, EDI_LR, 1, OSL_EDI);

		/* if (EDI_LR == biton32(layer_state) && !em_forced) { */
			/* if (keycode != OSL_EDI) */
			    /* oneshot_fired = 1; */
		/* } */

        /* RT_SPC */
		if (rt_spc == 1 && timer_elapsed(rt_spc_timer) < joker_threshold) {
			/* if (keycode == MACMETA) { */
			/* 	send_string(SS_TAP(X_BSPACE)); */
			/* 	rt_spc = 0; */
			/* 	return 1 ; */
			/* } */
		} else {
			rt_spc = 0;
		}
		/* ENDL_JOKER */
        if (endl_joker == 1 && timer_elapsed(endl_joker_timer) < joker_threshold) {
			if (keycode == OSL_BRA) {
				send_string(SS_TAP(X_BSPACE) ",");
				endl_joker = 0;
				return 0;
			} else if (keycode == _L) {
				send_string(SS_TAP(X_BSPACE) " ");
				keycode = BL_BRACES;
				endl_joker = 0;
			} else if (keycode == _T) {
				send_string(SS_TAP(X_BSPACE) ":" SS_TAP(X_ENTER));
				endl_joker = 0;
				return 0;
			} else if (keycode == _G) {
				send_string(SS_TAP(X_BSPACE) ": ");
				endl_joker = 0;
				return 0;
			} else if (keycode == _H) {
				send_string(SS_TAP(X_BSPACE) " {}" SS_TAP(X_LEFT) SS_TAP(X_ENTER));
				if (!mod)
					send_string(SS_TAP(X_UP) SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) SS_TAP(X_ENTER) SS_TAP(X_TAB));
				endl_joker = 0; {

				}
				return 0;
			}
		} else {
			endl_joker = 0;
		}

		if (caps == 1) {
			if (keycode == CAPS ||
				keycode == _ESC ||
				keycode == MACMETA) {
				caps = 0;
				unregister_code(KC_LSHIFT);
				return 0;
			}

			if ((keycode >= OSL_NUM &&
				 keycode <= OSL_REF) ||
				keycode == _SPC) {
				caps = 0;
				unregister_code(KC_LSHIFT);
			}
		}
	}

    /* lang switch */
	if (record->event.pressed) {
		if (keycode == _ENT ||
			keycode == G(_ENT) ||
			keycode == MACMETA) {
			if (1UL << RU_LR & layer_state)
				ru_off = 1;
		}

		if (keycode == LSWITCH) {
			if (1UL << RU_LR & layer_state) {
				ru_off = 1;
			} else {
				send_string(SS_LGUI(" "));
				layer_on(RU_LR);
			}
			return 0;
		}
	}

	/* if (record->event.pressed) { */
		/* if (keycode != MACMETA) increase_timer(); */
		/* if (keycode != LCTL) */
			/* lctl_timer += 2 * timer_threshold; */
		/* if (keycode != LSFT) */
			/* lsft_timer += 2 * timer_threshold; */
		/* if (keycode != RSFT) */
			/* rsft_timer += 2 * timer_threshold; */
	/* } */

	switch(keycode) {
	case NEXT:
		/* layer_off(SYM_LR); */
		/* layer_off(SYM_RU_LR); */
		if (record->event.pressed) {
			send_string(SS_TAP(X_RIGHT));
			oneshot_next_timer = timer_read();
			oneshot_next_down = 1;
			oneshot_next_fired = 0;
			layer_on(NEXT_LR);
		} else {
			oneshot_next_down = 0;
		}
		return 0;
	case STICKY_SEL:
		if (record->event.pressed) {
			/* register_code(KC_LSHIFT); */
			layer_on(SEL_LR);
			layer_on(SEL2_LR);
		} else {
		}
		return 0;
	case OSL_REF:
		if (record->event.pressed) {
			oneshot_timer = timer_read();
			oneshot_down = 1;
			oneshot_fired = 0;
			layer_on(REF_LR);
		} else {
			oneshot_down = 0;
		}
		return 0;
	case OSL_IDE:
		if (record->event.pressed) {
			oneshot_timer = timer_read();
			oneshot_down = 1;
			oneshot_fired = 0;
		  layer_on(IDE_LR);
	  } else {
		  oneshot_down = 0;
	  }
	  return false;
  case OSL_EDI:
		if (record->event.pressed) {
			oneshot_timer = timer_read();
			oneshot_down = 1;
			oneshot_fired = 0;
		  layer_on(EDI_LR);
	  } else {
		  oneshot_down = 0;
	  }
	  return false;
  case OSL_SYM:
	  if (record->event.pressed) {
		  oneshot_timer = timer_read();
		  oneshot_down = 1;
		  oneshot_fired = 0;
		  layer_on(SYM_LR);
		  if (1UL << RU_LR & layer_state)
			  layer_on(RU_SYM_LR);
	  } else {
		  oneshot_down = 0;
	  }
	  return false;
  case OSL_NUM:
		if (record->event.pressed) {
			oneshot_timer = timer_read();
			oneshot_down = 1;
			oneshot_fired = 0;
		  layer_on(NUM_LR);
	  } else {
		  oneshot_down = 0;
	  }
	  return false;
  case OSL_BRA:
	  if (record->event.pressed) {
		  oneshot_timer = timer_read();
		  oneshot_down = 1;
		  oneshot_fired = 0;
		  layer_on(BRA_LR);
		  if (1UL << RU_LR & layer_state)
			  layer_on(RU_BRA_LR);
	  } else {
		  oneshot_down = 0;
	  }
	  return false;
  case CAPS:
	  if (record->event.pressed) {
		  register_code(KC_LSHIFT);
		  caps = 1;
	  } else { }
	  return false;
  case LEADER:
	  if (record->event.pressed) {
		  send_string(SS_LCTRL(SS_RGUI("x")));
	  } else { }
	  return false;
  case JOKER:
	  if (record->event.pressed) {
		  esc_promise_timer = timer_read();
		  register_code(_LGUI);
	  } else {
		  unregister_code(_LGUI);
	  }
	  return 0;
  case ADVANCE:
	  if (record->event.pressed) {
		  comma_advance = 1;
		  oneshot_fired = 0;
	  } else { }
	  return false;
  case LGUI:
	  if (record->event.pressed) {
		  timer = timer_read();
		  register_code(KC_LGUI);
	  } else {
		  if (timer_elapsed(timer) < timer_threshold) {
			  layer_off(EDI_LR);
			  em_forced = 0;
			  unregister_code(KC_LGUI);
			  unregister_code(KC_LSHIFT);
			  send_string(SS_LCTRL("g"));
		  } else {
			  unregister_code(KC_LGUI);
		  }
	  }
	  return false;
  case SSHIFT:
	  if (record->event.pressed) {
		  register_code(KC_LSHIFT);
		  layer_on(EDI_LR);
		  em_forced = 1;
	  }
	  return false;
  case TEST:
	rgblight_mode_noeeprom(rgblight_mode_current++); // sets mode to Fast breathing without saving
	return false;
  case MACMETA:
    if (record->event.pressed) {
      timer = timer_read();
      layer_on(MACOS_LR);
    } else {
      layer_off(MACOS_LR);
      if (timer_elapsed(timer) < timer_threshold) {
        register_code(KC_ENTER);
        unregister_code(KC_ENTER);
      }
      unregister_code(KC_LGUI);
      unregister_code(KC_LALT);
      /* clear_mods(); */
    }
    return 0;
} // end WINMETA MACMETA
  // CMD-TAB like keycodes
  if (biton32(layer_state) == MACOS_LR) {
	  if (record->event.pressed) {
		  switch(keycode) {
		  case G(A(_C)):
		  	  register_code(KC_RGUI);
		  	  register_code(KC_LALT);
		  	  register_code(KC_C);
		  	  unregister_code(KC_C);
		  	  unregister_code(KC_LALT);
		  	  unregister_code(KC_RGUI);
		  	  return 0;
		  /* case G(A(S(_C))): */
		  /* 	  register_code(KC_RGUI); */
		  /* 	  register_code(KC_LALT); */
		  /* 	  register_code(KC_LSHIFT); */
		  /* 	  register_code(KC_C); */
		  /* 	  unregister_code(KC_C); */
		  /* 	  register_code(KC_LSHIFT); */
		  /* 	  unregister_code(KC_LALT); */
		  /* 	  unregister_code(KC_RGUI); */
		  /* 	  return 0; */
		  case CMDTAB:
			  if (record->event.pressed) {
				  if (get_mods() & MOD_BIT(KC_LSHIFT)) {
					  del_mods(MOD_BIT(KC_LSHIFT));
				  }
				  del_mods(MOD_BIT(KC_LGUI));
				  register_code(KC_LGUI);
				  register_code(KC_TAB);
				  unregister_code(KC_TAB);
			  }
			  return false;
		  case CMDTAB2:
			  if (record->event.pressed) {
				  register_code(KC_LGUI);
				  register_code(KC_TAB);
				  unregister_code(KC_TAB);
				  unregister_code(KC_LGUI);
				  register_code(KC_LGUI);
				  register_code(KC_TAB);
				  unregister_code(KC_TAB);
				  register_code(KC_TAB);
				  unregister_code(KC_TAB);
				  unregister_code(KC_LGUI);
			  }
			  return false;
		  case SCMDTAB:
			  if (record->event.pressed) {
				  register_code(KC_LGUI);
				  register_code(KC_LSHIFT);
				  register_code(KC_TAB);
				  unregister_code(KC_TAB);
				  unregister_code(KC_LSHIFT);
			  }
			  return false;
		  case ALTTAB:
			  if (record->event.pressed) {
				  register_code(KC_LALT);
				  register_code(KC_TAB);
				  unregister_code(KC_TAB);
			  }
			  return false;
		  case SALTTAB:
			  if (record->event.pressed) {
				  register_code(KC_LALT);
				  register_code(KC_LSHIFT);
				  register_code(KC_TAB);
				  unregister_code(KC_TAB);
				  unregister_code(KC_LSHIFT);
			  }
			  return false;
		  case GQ:
			  register_code(KC_LGUI);
			  register_code(KC_Q);
			  unregister_code(KC_Q);
			  return false;
		  default:
			  unregister_cmd_after_cmdtab();
		  } // END: CMD-TAB like keycodes
	  }
  }

  // RCMD & RALT doing smth usefull on single press:
  switch(keycode) {
  case RCMD:
    if (record->event.pressed) {
      rcmd_timer = timer_read();
      register_code(KC_RGUI);
    } else {
      unregister_code(KC_RGUI);
      if (timer_elapsed(rcmd_timer) < timer_threshold)
		  send_string(SS_LCTRL("x") "k" SS_LCTRL("["));
    }
    return false;
  case RALT:
	  if (record->event.pressed) {
		  rcmd_timer = timer_read();
		  register_code(KC_RALT);
	  } else {
		  unregister_code(KC_RALT);
		  if (timer_elapsed(rcmd_timer) < timer_threshold)
			  send_string(SS_LCTRL("x") "f" SS_LCTRL("["));
	  }
	  return false;
  case _UP:
	  if (record->event.pressed) {
		  if (timer_elapsed(esc_promise_timer) < oneshot_threshold) {
			  unregister_code(_LGUI);
			  send_string(SS_TAP(X_ESCAPE));
		  }
	  }
	  return 1;
  case _DN:
	  if (record->event.pressed) {
		  if (timer_elapsed(esc_promise_timer) < oneshot_threshold) {
			  unregister_code(_LGUI);
			  send_string(SS_TAP(X_ESCAPE));
		  }
	  }
	  return 1;
}

  if (record->event.pressed) {
	  switch(keycode) {
	  case PHONY:
		  return 0;
	  case NCOMMA:
		  send_string(", ");
		  return 0;
	  case NCOLON:
		  send_string(": ");
		  return 0;
	  case C_ENT:
		  send_string(SS_LCTRL(SS_TAP(X_ENTER)) SS_TAP(X_ENTER));
		  return 0;
	  case COUT:
		  send_string(" << ");
		  return 0;
	  case CIN:
		  send_string(" >> ");
		  return 0;
	  case NAMESPACE:
		  send_string("::");
		  return 0;
	  case PLUSPLUS:
		  send_string("++");
		  return 0;
	  }
  }

  /* :main */
  if (record->event.pressed) {
	  switch(keycode) {
      case SURPAR:
          send_string(SS_LGUI("x") "()" SS_TAP(X_LEFT) SS_LGUI("v"));
          return 0;
	  case MOD_SWITCH:
		  mod ^= 1;
		  return 0;
	  case EQL_EQL:
		  send_string("== ");
		  return 0;
	  case EQL_SPC:
		  send_string("= ");
		  return 0;
	  case ENDL_JOKER:
		  send_string(SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) ";");
		  endl_joker = 1;
		  endl_joker_timer = timer_read();
		  return false;
	  case RT_SPC:
		  send_string(SS_TAP(X_RIGHT) " ");
		  rt_spc = 1;
		  rt_spc_timer = timer_read();
		  return false;
	  case RT2_SPC:
		  send_string(SS_TAP(X_RIGHT) SS_TAP(X_RIGHT) " ");
		  return false;
	  case SCLSPC:
		  SEND_STRING("; ");
		  return false;
	  case CCS:
		  SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) ";");
		  return false;
	  case PYBLOCK:
		  SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) ":" SS_TAP(X_ENTER));
		  return false;
	  case CBLOCK:
		  SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) " ");
	  case BL_BRACES:
		  SEND_STRING("{}" SS_TAP(X_LEFT) SS_TAP(X_ENTER) SS_TAP(X_UP) SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) SS_TAP(X_ENTER) SS_TAP(X_TAB));
		  return false;
	  case BRACES:
		  SEND_STRING("{}" SS_TAP(X_LEFT));
		  return false;
	  case PARENS:
		  SEND_STRING("()" SS_TAP(X_LEFT));
		  return false;
	  case PARENS_ENDL:
		  SEND_STRING("(" SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) ")");
		  return false;
	  case BRACKS:
		  SEND_STRING("[]" SS_TAP(X_LEFT));
		  return false;
	  case ABRACKS:
		  SEND_STRING("<>" SS_TAP(X_LEFT));
		  return false;
	  case BRACKS_RU:
		  SEND_STRING("~`" SS_TAP(X_LEFT));
		  return false;
	  case QUOTES:
		  SEND_STRING("\"\"" SS_TAP(X_LEFT));
		  return false;
	  case ALTQUO:
		  SEND_STRING(SS_LALT("`"));
		  return false;
	  case CC_PLS:
		  SEND_STRING(SS_LCTRL("c") "+");
		  return false;
	  case CC_MIN:
		  SEND_STRING(SS_LCTRL("c") "-");
		  return false;
	  case CXCS:
		  SEND_STRING(SS_LCTRL("xs"));
		  return false;
	  case CX_CF:
		  SEND_STRING(SS_LCTRL("xf"));
	 	  return false;
	  case CX_O:
		  SEND_STRING(SS_LCTRL("x") "o");
		  return false;
	  case CX_B:
		  SEND_STRING(SS_LCTRL("x") "b");
		  return  false;
	  case CX_K:
		  SEND_STRING(SS_LCTRL("x") "k");
		  return false;
	  case CX_0:
		  SEND_STRING(SS_LCTRL("x") "0");
		  return false;
	  case CX_1:
		  SEND_STRING(SS_LCTRL("x") "1");
		  return false;
	  case CX_3:
		  SEND_STRING(SS_LCTRL("x") "3");
		  return false;
	  case M0_CK:
		  SEND_STRING(SS_LALT("0") SS_LCTRL("k"));
		  return false;
	  case CXCJ_0:
		  SEND_STRING(SS_LCTRL("xj") "0");
		  return false;
	  case CXCJ_B:
		  SEND_STRING(SS_LCTRL("xj") "b");
		  return false;
	  case CXCJ_CC:
		  SEND_STRING(SS_LCTRL("xjc"));
		  return false;
	  case CXCJ_D:
		  SEND_STRING(SS_LCTRL("xj") "d");
		  return false;
	  case CXCJ_CD:
		  SEND_STRING(SS_LCTRL("xjd"));
		  return false;
	  case CX_P:
		  SEND_STRING(SS_LCTRL("x") "p");
		  return false;
	  case CX_CP:
		  SEND_STRING(SS_LCTRL("xp"));
		  return false;
	  case CX_RBRC:
		  SEND_STRING(SS_LCTRL("x")"}");
		  return false;
	  case CX_LBRC:
		  SEND_STRING(SS_LCTRL("x")"{");
		  return false;
	  case COM_SPC:
		  SEND_STRING(", ");
		  return false;
	  case COM_SPC_RU:
		  send_string("? ");
		  return 0;
	  }

  }

  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{

	//%% karabiner:
	/* (non_us_backslash,1,       2,       3,       4,       5,       6,       7,       8,       9,       0,       hyphen, equal_sign,,       delete_or_backspace, */
	/* tab,              q,       w,       e,       r,       t,                y,       u,       i,       o,       p,       open_bracket,close_bracket,return_or_enter, */
	/* caps_lock,        a,       s,       d,       f,       g,                h,       j,       k,       l,       semicolon,quote,           backslash, */
	/* left_shift,grave_accent_and_tilde,z,x,c,     v,       b,                n,       m,       comma,   period,  slash,   right_shift,,     , */
	/* ,                          ,        ,                 ,       ,         ,        ,                 ,                 ,        ,        ) */

	LAYOUT_all //%% plain:en
	(_F2,              _LGUI,   _ESC,    S(_MIN), OSL_IDE, S(_5),   _______, S(_EQL), _B,      _Y,    OSL_BRA,   _J,      G(S(_4)),_NO,     S(_F10),
	 STICKY_SEL, OSM(MOD_LSFT), OSL_SYM, _O,      _DOT,    NEXT,             _MIN,    _G,      _C,      _R,      _F,      _K,      _SLS,    S(A(_F10)),
	 OSL_NUM,          _P,      _A,      _E,      _I,      _BSP,             _L,      _H,      _T,      _N,      _S,      OSL_REF,          G(A(_ENT)),
	 _LSFT,    _A,     _J,      _Q,      S(_2),   _U,      _TAB,             _D,      _M,      _W,      _V,      _X,      _Z,      C(A(_Y)),_UP,
	 _LCTL,                     _LGUI,   RALT,             _SPC,   OSL_EDI,  MACMETA, RCMD,             _VDN,             _VUP,    MACMETA, _SPC),

	LAYOUT_all //%% plain:ru
	(_______,          _______, _______, _______, _______, _______, _______, _______, _COM,    _______, _______, _______, _______, _______, _______,
	 _______,          _______, _______, _J,      _SLS,    _M,               _Q,      _U,      _Z,      _H,      _A,      _P,      _RBR,    _O,
	 _______,          _G,      _F,      _T,      _B,      _BSP,             _K,      _R,      _N,      _Y,      _C,      _W,               _LBR,
	 _DOT, _______,    _QUO,    _I,      _SCL,    _E,      _______,          _L,      _V,      _D,      _X,      _S,      _LBR,    _______, _______,
	 _______,                   _______, _______,          _______, _______, _______,          _______, _______,          _______, _______, _______),

	LAYOUT_all //%% mod:os
	(MOD_SWITCH,       _______, _F17,    _F18,    _______, _______, _______, _______, G(_W),   G(_LBR), G(A(_W)),G(_W),   G(_Z),   _______, _______,
	 WIN,              _______, C(_G),   _ESC,    _F15,    _______,       G(A(S(_C))),A(_TAB),C(S(_TAB)),C(_TAB),A(S(_TAB)),G(_RBR), _______, _______,
	 _______,          G(_X),   G(_V),   G(_C), GACS(_SPC),A(_BSP),         CMDTAB2, CMDTAB,  SCMDTAB,G(A(_C)), G(A(S(_C))),GQ,             _______,
	 _______, _______, G(_A),   _______, _______, _______, _______,          _______, G(_GRV), _______, _______, _______, _______, _______, RGB_TOG,
	 _______,                   _______, _______,          _______, _______, _______,          _______, _______,          _______, _______, _______),

	LAYOUT_all //%% oneshot:num
	(_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	 _______,          _______, _______, _______, COUT,    CIN,              NAMESPACE,COUT,   _0,      _9,      CIN, _______, _______, _______,
	 _______,          _______, _______, _______, NAMESPACE,_______,         _6,      _1,      _2,      _3,      _4,      _5,               _______,
	 _______, _______, _______, _______, _______, _______, _______,          _7,      _8,      _______, CC_PLS,  CC_MIN,  _______, _______, _______,
	 _______,                   _______, _______,          SCLSPC, _______, CCS,               _______, _______,          _______, _______, _______),

	LAYOUT_all //%% oneshot:edi
	(TEST,             _______, RALT(_N),RALT(_P),G(_UP),  G(_DN),  _______, G(_LBR), C(G(_DN)),C(_DN), C(_UP),  C(G(_UP)),_ESC,   _______, _______,
	 _______,          G(_X),   JOKER,   G(_Z),   G(_BSP), G(_O),            C(A(G(_5))),_PGDN,A(_LT),  A(_RT),  _PGUP,   HYPR(_P),_______, _______,
	 G(S(_D)),         SURPAR,  G(_V),   G(_C),   G(_SLS), _______,          _LT,     _DN,     _UP,     _RT,   G(_RT),  _DEL,             G(_UP),
	 G(_X),   _______, CC_PLS,  CC_MIN,  A(_U), C(A(_BSL)),_______,          C(G(_DN)),G(_LT), A(S(_LBR)),A(S(_RBR)),C(G(_UP)),C(_K),A(_BSL), _______,
	 _______,                   _______, _______,          _BSP,    _______, _______,          _______, _______,          _______, _______, _______),

	LAYOUT_all //%% sticky:sel
	(_______,          _______, _______, _______, _______, _______, _______, G(_LBR), G(_RBR), _______, _______, _______, _______, _______, _______,
	 _______,          _______, _______, _______, _______, CX_CX,            _______, S(_PGDN),S(A(_LT)),S(A(_RT)),S(_PGUP),_______,_______,_______,
	 _______,          _______, _______, _______, _______, _______,          S(_LT),  S(_DN),  S(_UP),  S(_RT), S(G(_RT)),  _______,        _______,
	 _______, _______, _______, _______, _______, _______, _______,          _______, S(G(_LT)),_______,_______, _______, _______, _______, _______,
	 _______,                   _______, _______,          _______, _______, _______,          _______, _______,          _______, _______, _______),

	LAYOUT_all //%% sticky:sel2
	(_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	 _______,          G(_X),   _______, PHONY,   _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,
	 _______,          SURPAR,  G(_V),   G(_C),   _______, G(_X),            _______, _______, _______, _______, _______, _______,          _______,
	 _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,
	 _______,                   _______, _______,          _BSP,    _______, _______,          _______, _______,          _______, _______, _______),

	LAYOUT_all //%% oneshot:sym
	(_______,          _______, _______, _______, _______, _______, _______, _LBR,    S(_GRV), _QUO,    _GRV,    _RBR,    _______, _______, _______,
	 _______,          _______, CCS,     G(_F),   _BSL,    S(_BSL),          S(_6),   S(_SCL), QUOTES,  S(_QUO), S(_DOT), _BSL,    _______, _______,
	 _______,          S(_2),   _______, _______, LSWITCH, S(_1),            BRACKS,  PARENS,  S(_7),   S(_EQL), S(_4),   S(_3),            _______,
	 _______, _______, _______, _______, _______, _______, _______,          G(S(_G)),G(_G),   C(_W),   S(_8),   S(_SLS), _______, _______, _______,
	 _______,                   _______, _______,          RT_SPC,  NEXT,    ENDL_JOKER,       _______, _______,          _______, _______, _______),

	
	LAYOUT_all //%% oneshot:sym_ru
	(_______,          _______, _______, _______, _______, _______, _______, _______, _______, S(_GRV), _GRV,    _______, _______, _______, _______,
	 _______,          _______, _______,G(_ENT),  _______, _______,          S(_6),   S(_COM), _EQL,    S(_QUO), S(_DOT), _SLS,    _______, _______,
	 _______,          _______, _______, _______, LSWITCH, _______,          S(_1),   S(_6),   S(_8),   S(_EQL), S(_4),   S(_3),            _______,
	 _______, _______, _______, _______, _______, _______, _______,          LCTL(_R),CTA(_S), LCTL(_W),_______, S(_8),   _______, _______, _______,
	 _______,                   _______, _______,          _______, _______, _______,          _______, _______,          _______, _______, _______),

	LAYOUT_all //%% oneshot:next
	(_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	 _______,          _______, _______, _______, _______, _______,          _______, NCOLON,  NCOMMA,  _______, _______, _______, _______, _______,
	 _______,          _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,          _______,
	 _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,
	 _______,                   _______, _______,          _______, _______, _______,          _______, _______,          _______, _______, _______),

	LAYOUT_all //%% oneshot:bra
	(_______,          _______,PARENS_ENDL,S(_LBR),BRACES, S(_RBR), _______, _LBR,    G(S(_O)),G(_V),   _COM,    PYBLOCK, _______, _______, _______,
	 _______,          S(_0),   S(_9),   ABRACKS, S(_COM), S(_DOT),          S(_6),   G(_P),   _MIN,    S(_QUO), PYBLOCK, PYBLOCK, _______, _______,
	 C_ENT,            _RBR,    _LBR,    C(_ENT), S(_ENT), A(_ENT),          G(S(_O)),G(S(_P)),_______, S(_EQL), S(_4),   S(_3),           _______,
	 _______, _______, _______, _______, _______, C(_ENT), _______,          LCTL(_R),CTA(_S), LCTL(_W),S(_8)   ,S(_SLS), _______, _______, _______,
	 _______,                   _______, _______,          COM_SPC, C(_ENT), G(_ENT),          _______, _______,          _______, _______, _______),

	LAYOUT_all //%% oneshot:bra_ru
	(_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, S(_SLS), _______, _______, _______, _______,
	 _______,          _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,
	 _______,          _______, S(_GRV),BRACKS_RU,_______, _GRV,             _______, _______, _______, _______, _______, _______,          _______,
	 _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,
	 _______,                   _______, _______,        COM_SPC_RU,_______, _______,          _______, _______,          _______, _______, _______),

	LAYOUT_all //%% oneshot:ide
	(_______,          _______, _______, _______, _SCL,    _______, _______, _______, G(S(_W)),G(_P),   G(S(_E)),CX_3,    CX_RBRC, _______, CXCJ_0,
	 _______,          _______, _______, _______, _______, S(_F6),           CX_G, G(C(S(_J))),HYPR(_O),CX_1,    G(S(_J)),HYPR(_G),_______, CX_LBRC,
	 _______,          _______, _______, _______, _______, A(S(_1)),         A(S(_SCL)),C(S(_6)),S(_F10), C(_ENT),G(_S),  S(A(_F10)),       G(_F2),
	 _______, _______, _______, _______, _______, _______, _______,          G(_L),C(A(S(_5))),CXCJ_CD,CXCJ_CC,  CXCJ_SD, CX_CC,   _______, _______,
	 _______,                   _______, _______,          SCLSPC,  SCLSPC,  CCS,              _______, _______,          _______, RGB_HUI, RGB_HUD),

	LAYOUT_all //%% oneshot:ref
	(_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	 _______,          _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,
	 _______,          G(_U),   G(A(_B)),_F2,     _F12,    S(_F12),          _C,      _______, _______, _______, _______, EQL_EQL,          _______,
	 _______, _______, _______, _______, _______, C(_MIN), _______,          _______, _______, _______, _______, _______, _______, _______, _______,
	 _______,                   _______, _______,          EQL_SPC, _EQL,    _______,          _______, _______,          _______, _______, _______),
};

enum function_id {
                  SHIFT_ESC,
};

const uint16_t PROGMEM fn_actions[] = {
                                       [0]  = ACTION_FUNCTION(SHIFT_ESC),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  static uint8_t shift_esc_shift_mask;
  switch (id) {
  case SHIFT_ESC:
    shift_esc_shift_mask = get_mods()&MODS_CTRL_MASK;
    if (record->event.pressed) {
      if (shift_esc_shift_mask) {
        add_key(KC_GRV);
        send_keyboard_report();
      } else {
        add_key(KC_ESC);
        send_keyboard_report();
      }
    } else {
      if (shift_esc_shift_mask) {
        del_key(KC_GRV);
        send_keyboard_report();
      } else {
        del_key(KC_ESC);
        send_keyboard_report();
      }
    }
    break;
  }
}
