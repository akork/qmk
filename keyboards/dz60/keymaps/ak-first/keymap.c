// -*- compile-command: "make dz60:ak-first:dfu" -*-


// option + f12 terminal

#include QMK_KEYBOARD_H

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// static bool isCmdSetByMeta = false;

enum custom_keycodes {
					  TEST = SAFE_RANGE,
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
                      LSFT,
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
      SYM_LR,
      RU_SYM_LR,
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
	
static uint16_t timer, rcmd_timer, lctl_timer, lsft_timer, rsft_timer, osl_sym_timer, osl_edi_timer, osl_num_timer;
static const uint16_t timer_threshold = 250;
static const uint16_t oneshot_threshold = 700, joker_threshold = 2000;  
static uint8_t rgblight_mode_current = RGBLIGHT_MODE_KNIGHT + 1;
static uint8_t osl_sym_pressed = 0;
static uint8_t osl_edi_pressed = 0;
static uint8_t em_forced = 0;
static uint8_t 
	osl_num_pressed;
static uint8_t osl_sym_another_pressed = 0;
static uint8_t osl_edi_another_pressed = 0;
static uint8_t 
	osl_num_another_pressed;

static uint16_t oneshot_timer, rt_spc_timer, endl_joker_timer, esc_promise_timer;
static uint8_t oneshot_down = 0, oneshot_fired = 0;
static uint8_t
    caps = 0,
	comma_advance = 0,
 	rt_spc = 0,
	endl_joker = 0,
	ru_off = 0,
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

static __attribute__ ((noinline)) void process_record_noinline(keyrecord_t *record) {
	process_record(record);
}

void matrix_scan_user(void) {
	if (biton32(layer_state) == REF_LR) {
		if ((!oneshot_down && oneshot_fired) ||
			(!oneshot_down && timer_elapsed(oneshot_timer) > oneshot_threshold)) {
			layer_off(REF_LR);
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
			ru_off = 0;
		}
	}
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
		/* rgblight_enable_noeeprom(); */
		if (((3UL << BRA_LR) & layer_state)) {
			/* if (comma_advance == 1) { */
			/* 	if (keycode == COM_SPC) { */
			/* 		register_code(_RT); */
			/* 		unregister_code(_RT); */
			/* 	} */
			/* 	comma_advance = 0; */
			/* } */
			
			/* if ((osl_bra_pressed == 0 && timer_elapsed(osl_bra_timer) > oneshot_threshold) || */
			/* 	(osl_bra_pressed == 0 && osl_bra_another_pressed == 1)) { */
			/* 	layer_off(BRA_LR); */
			/* 	if (1UL << RU_LR & layer_state) */
			/* 		layer_off(RU_BRA_LR); */
			/* 	process_record_noinline(record); */
			/* 	return 0; */
			/* } */
			
			if (keycode != OSL_BRA)
			    oneshot_fired = 1;
			/* if (keycode == COM_SPC) */
			/* osl_bra_another_pressed = 0; */

			/* if (biton32(default_layer_state) == RU_LR) { */
			/* 	switch (keycode) { */
			/* 	case _LBR: */
			/* 		send_string("~"); */
			/* 		return 0; */
			/* 	case _RBR: */
			/* 		send_string("`"); */
			/* 		return 0; */
			/* 	case BRACKS: */
			/* 		send_string("~`" SS_TAP(X_LEFT)); */
			/* 		return 0; */
			/* 	case COM_SPC: */
			/* 		send_string("? "); */
			/* 		return 0; */
			/* 	} */
			/* } */
		}
		if (SYM_LR == biton32(layer_state)) {
			if ((osl_sym_pressed == 0 && timer_elapsed(osl_sym_timer) > oneshot_threshold) ||
				(osl_sym_pressed == 0 && osl_sym_another_pressed == 1)) {
				layer_off(SYM_LR); 
				if (1UL << RU_LR & layer_state)
					layer_off(RU_SYM_LR);
				process_record_noinline(record);
				return 0;
			}
			if (keycode != OSL_SYM)
				osl_sym_another_pressed = 1;
			}
		if (NUM_LR == biton32(layer_state)) {
			if ((osl_num_pressed == 0 && timer_elapsed(osl_num_timer) > oneshot_threshold) ||
				(osl_num_pressed == 0 && osl_num_another_pressed == 1)) {
				layer_off(NUM_LR);
			    process_record_noinline(record);
				return 0;
			}
			if (keycode != OSL_NUM)
				osl_num_another_pressed = 1;
		}
		if (EDI_LR == biton32(layer_state) && !em_forced) {
			if ((osl_edi_pressed == 0 && timer_elapsed(osl_edi_timer) > oneshot_threshold) ||
				(osl_edi_pressed == 0 && osl_edi_another_pressed == 1)) {
				layer_off(EDI_LR);
				process_record_noinline(record);
				return 0;
			}
			if (keycode != OSL_EDI)
				osl_edi_another_pressed = 1;
			
		}
		if (biton32(layer_state) == REF_LR) {
			/* if ((!oneshot_down && timer_elapsed(oneshot_timer) > oneshot_threshold) || */
			/* 	(!oneshot_down && oneshot_fired)) { */
			/* 	layer_off(REF_LR); */
			/* 	process_record_noinline(record); */
			/* 	return 0; */
			/* } */
			if (keycode != OSL_REF)
				oneshot_fired = 1;
		}
		if (IDE_LR == biton32(layer_state)) {
			if ((!oneshot_down && timer_elapsed(oneshot_timer) > oneshot_threshold) ||
				(!oneshot_down && oneshot_fired)) {
				layer_off(IDE_LR);
				process_record_noinline(record);
				return 0;
			}
			if (keycode != OSL_IDE)
				oneshot_fired = 1;
		}
 		if (rt_spc == 1 && timer_elapsed(rt_spc_timer) < joker_threshold) {
			if (keycode == MACMETA) {
				send_string(SS_TAP(X_BSPACE) ", ");
				rt_spc = 0;
				return 0;
			}
		} else {
			rt_spc = 0;
		}
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
		if (em_forced == 1) {
			if (keycode == _BSP ||
				keycode == G(_C) ||
				keycode == G(_X) ||
				keycode == G(_V) ||
				keycode == G(_SLS) ||
				keycode == C(A(_BSL))
				) {
				em_forced = 0;
				unregister_code(KC_LSHIFT);

				if (keycode == G(_V))
					send_string(SS_TAP(X_BSPACE));
			
				return true;
			}
			if (keycode == G(_BSP)) {
				unregister_code(KC_LSHIFT);
				send_string(SS_LCTRL("xx"));
				register_code(KC_LSHIFT);
				return 0;
			}
		}
	}

	if (record->event.pressed) {
		if (keycode == _ENT ||
			keycode == G(_ENT) ||
			keycode == MACMETA) {
			if (1UL << RU_LR & layer_state)
				ru_off = 1;
		}
  
		if (keycode == LSWITCH) {
			send_string(SS_LGUI(" "));
			if (1UL << RU_LR & layer_state) {
				layer_off(RU_LR);
			} else {
				layer_on(RU_LR);
			}
			return 0;
		}
	}

	/* unregiterCmdAfterCMDTAB(); */
	if (record->event.pressed) {
		if (keycode != MACMETA) increase_timer();
		if (keycode != LCTL)
			lctl_timer += 2 * timer_threshold;
		if (keycode != LSFT)
      lsft_timer += 2 * timer_threshold;
    if (keycode != RSFT)
      rsft_timer += 2 * timer_threshold;
  }

  switch(keycode) {
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
		  osl_edi_timer = timer_read();
		  osl_edi_pressed = 1;
		  osl_edi_another_pressed = 0;
		  layer_on(EDI_LR);
	  } else {
		  osl_edi_pressed = 0;
		  if (osl_edi_another_pressed && !em_forced)
			  layer_off(EDI_LR);
	  }
	  return false;
  case OSL_SYM:
	  if (record->event.pressed) {
		  osl_sym_timer = timer_read();
		  osl_sym_pressed = 1;
		  osl_sym_another_pressed = 0;
		  layer_on(SYM_LR);
	  } else {
		  osl_sym_pressed = 0;
		  }
	  return false;
  case OSL_NUM:
	  if (record->event.pressed) {
		  osl_num_timer = timer_read();
		  osl_num_pressed = 1;
		  osl_num_another_pressed = 0;
		  layer_on(NUM_LR);
	  } else {
		  osl_num_pressed = 0;
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
  case LSFT:
	  if (record->event.pressed) {
		  register_code(KC_LSFT);
		  lsft_timer = timer_read();
	  } else {
		  unregister_code(KC_LSFT);
		  if (timer_elapsed(lsft_timer) < timer_threshold) {
			  SEND_STRING(" ");
		  }
	  }
	  return false;
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
  
  if (record->event.pressed) {
	  switch(keycode) {
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

	LAYOUT_all
	(_F2,              LSWITCH, _ESC,    S(_MIN), OSL_IDE, S(_5),   _______, S(_EQL), _B,      _Y,    OSL_BRA,   _J,      G(S(_4)),_NO,     S(_F10),
	 SSHIFT,           CAPS,    OSL_SYM, _O,      _DOT,    LEADER,           _MIN,    _G,      _C,      _R,      _F,      _K,      _SLS,    S(A(_F10)),
	 OSL_NUM,          _P,      _A,      _E,      _I,      _BSP,             _L,      _H,      _T,      _N,      _S,      OSL_REF,           _ENT,
	 _LSFT,    _A,     _J,      _Q,      _Q,      _U,      _TAB,             _D,      _M,      _W,      _V,      _X,      _Z,      C(A(_Y)),_UP,
	 _LCTL,                     _LGUI,   RALT,             _SPC,   OSL_EDI,  MACMETA, RCMD,             _VDN,             _VUP,    MACMETA, _SPC),

	LAYOUT // -ru_l
	(_______,          _______, _______, _______, _______, _______, _______, _______, _COM,    _______, _______, _______, _______, _______, _______,
	 _______,          _______, _______, _J,      _SLS,    _M,               _Q,      _U,      _Z,      _H,      _A,      _P,      _RBR,    _O,
	 _______,          _G,      _F,      _T,      _B,      _BSP,             _K,      _R,      _N,      _Y,      _C,      _W,               _LBR,
	 _DOT, _______,    _QUO,    _I,      _SCL,    _E,      _S,               _L,      _V,      _D,      _X,      _A,               _______, _______,
	 _______,                   _______, _______,          _______, _______, _______,          _______, _______,          _______, _______, _______),

	LAYOUT // _os_layer
	(MOD_SWITCH,       _______, _F17,    _F18,    _______, _______, _______, _______, G(_W),   G(_LBR), C(_TAB), G(_W),   G(_Z),   _______, _______,
	 WIN,              _______, C(_G),   _ESC,    _F15,    _______,       G(A(S(_C))),G(S(_P)),C(S(_TAB)),C(_TAB),G(_GRV),G(_RBR), _______, _______,
	 _______,          G(_X),   G(_V),   G(_C), GACS(_SPC),G(S(_P)),         A(G(_C)),CMDTAB,  SCMDTAB,G(A(_C)), G(A(S(_C))),GQ,             _______,
	 _______, _______, G(_A),   _______, _______, _______, _______,          _______, G(_W),   _______, _______, _______,          _______, RGB_TOG,
	 _______,                   _______, _______,          _______, _______, _______,          _______, _______,          _______, _______, _______),

	LAYOUT // _numbers_layer
	(_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	 _______,          _______, _______, _______, COUT,    CIN,              NAMESPACE,COUT,   _0,      _9,      CIN, _______, _______, _______,
	 _______,          _______, _______, _______, NAMESPACE,_______,         _6,      _1,      _2,      _3,      _4,      _5,               _______,
	 _______, _______, _______, _______, _______, _______, _______,          _7,      _8,      _______, CC_PLS,  CC_MIN,  _______, _______,
	 _______,                   _______, _______,          SCLSPC, _______, CCS,               _______, _______,          _______, _______, _______),

	LAYOUT_all // _editing_layer
	(TEST,             _______, RALT(_N),RALT(_P),G(_UP),  G(_DN),  _______, G(_LBR),    G(_RBR), C(G(_DN)),C(G(_UP)),_ESC,_______, _______, _______,
	 _______,          G(_X),   JOKER,   G(_Z),   G(_BSP), G(_O),            C(A(G(_5))),_PGDN,_DN,     _UP,     _PGUP,   GACS(_P),_______, _______,
	 G(S(_D)),         G(_BSP), G(_V),   G(_C),   G(_SLS), _______,          G(_LT),  A(_LT),  _RT,     A(_RT),  G(_RT),  _DEL,             G(_UP),
	 G(_X),   _______, CC_PLS,  CC_MIN,  A(_U), C(A(_BSL)),_______,          A(_W),   _LT, A(S(_LBR)),A(S(_RBR)),C(_K),   G(_BSP), A(_BSL), _______, 
	 _______,                   _______, _______,          _BSP,    _BSP,    _______,          _______, _______,          _______, _______, _______),

	LAYOUT // _selection_layer
	(_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	 _______,          _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,
	 _______,          G(_X),   _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,          _______,
	 _______, _______, _______, _______, _______, CX_CX,   _______,          _______, _______, _______, _______, _______,          _______, _______,
	 _______,                   _______, _______,          _______, _______, _______,          _______, _______,          _______, _______, _______),

	LAYOUT // _symbols_layer
	(_______,          _______, _______, _______, _______, _______, _______, _LBR,    S(_GRV), _QUO,    _GRV,    _RBR,    _______, _______, _______,
	 _______,          _______, CCS,     ENDL,    _BSL,    S(_BSL),          S(_6),   S(_SCL), QUOTES,  S(_QUO), S(_DOT), _BSL,    _______, _______,
	 _______,          S(_2),   _______, _______, LSWITCH, S(_1),            _SLS,    PARENS,  S(_7),   S(_EQL), S(_4),   S(_3),            _______,
	 _______, _______, _______, _______, _______, _______, _______,          C(A(_R)),C(A(_S)),C(_W),   S(_8),   S(_SLS),          _______, _______,
	 _______,                   _______, _______,          RT_SPC,  RT2_SPC, ENDL_JOKER,         _______, _______,          _______, _______, _______),
   
	LAYOUT // _ru_symbols_layer
	(_______,          _______, _______, _______, _______, _______, _______, _______, _______, S(_GRV), _GRV,    _______,  _______, _______, _______,
	 _______,          _______, _______,G(_ENT),  _______, _______,          S(_6),   S(_COM), _EQL,    S(_QUO), S(_DOT), _SLS,     _______, _______,
	 _______,          _______, _______, _______, LSWITCH, _______,          S(_1),   S(_6),   S(_8),   S(_EQL), S(_4),   S(_3),            _______,
	 _______, _______, _______, _______, _______, _______, _______,          LCTL(_R),CTA(_S), LCTL(_W),_______, S(_8),            _______, _______,
	 _______,                   _______, _______,          _______, _______, _______,          _______, _______,          _______, _______, _______),

	LAYOUT // _brackets_layer
	(_______,          _______, _______, S(_LBR), BRACES,  S(_RBR), _______, _LBR,    _______, CBLOCK,  _COM,    PYBLOCK, _______, _______, _______,
	 _______,          S(_0),   S(_9),   ABRACKS, S(_COM), S(_DOT),          S(_6),   G(_P),   _MIN,    S(_QUO), PYBLOCK, PYBLOCK, _______, _______,
	 C_ENT,            _RBR,    _LBR,    BRACKS,  G(_ENT), S(_ENT),          G(_P),   G(S(_P)),_______, S(_EQL), S(_4),   S(_3),           _______,
	 _______, _______, _______, _______, _______, C(_ENT), _______,          LCTL(_R),CTA(_S), LCTL(_W),S(_8)   ,S(_SLS),          _______, _______,
	 _______,                   _______, _______,          COM_SPC, C(_ENT), G(_ENT),          _______, _______,          _______, _______, _______),

	LAYOUT // _ru_brackets_layer
	(_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, S(_SLS), _______, _______, _______, _______,
	 _______,          _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,
	 _______,          _______, S(_GRV),BRACKS_RU,_______, _GRV,             _______, _______, _______, _______, _______, _______,          _______,
	 _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
	 _______,                   _______, _______,        COM_SPC_RU,_______, _______,          _______, _______,          _______, _______, _______),

	LAYOUT // _ide_layer
	(_______,          _______, _______, _______, _SCL,    _______, _______, _______, CX_K,    G(_P),   G(S(_E)),CX_3,    CX_RBRC, _______, CXCJ_0,
	 _______,          _______, _______, _______, _______, S(_F6),           CX_G,    G(_L),   CX_O,    CX_1,    GACS(_G),CX_0,    _______, CX_LBRC,
	 _______,          _______, _______, _______, _______, A(S(_1)),         A(S(_SCL)),G(S(_P)),S(_F10), CX_Z,    G(_S),   S(A(_F10)),       G(_F2),
	 _______, _______, _______, _______, _______, _______, _______,          G(_L),C(A(S(_5))),CXCJ_CD,CXCJ_CC, CXCJ_SD, CX_CC,   _______,
	 _______,                   _______, _______,          SCLSPC,  SCLSPC,  CCS,              _______, _______,          _______, RGB_HUI, RGB_HUD),

	LAYOUT // _refactoring_layer
	(_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	 _______,          _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,
	 _______,          G(_X),   _______, _______, _______, _A,               _C,      _______, _______, _______, _______, EQL_EQL,          _______,
	 _______, _______, _______, _______, _______, CX_CX,   _______,          _______, _______, _______, _______, _______,          _______, _______,
	 _______,                   _______, _______,          EQL_SPC, _______, _______,          _______, _______,          _______, _______, _______),

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
