// -*- compile-command: "make dz60:ak-first:dfu" -*-


// option + f12 terminal

#include QMK_KEYBOARD_H

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

// static bool isCmdSetByMeta = false;

enum custom_keycodes {
					  TEST = SAFE_RANGE,
					  ENDL_SPC,
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
					  OSLSM,
					  OSLEM,
					  OSLBM,
					  OSLTM,
					  OSLNM,
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
                      EENTER,
                      EEENTER,
                      PARENS,
                      BRACES,
                      MBRACES,
                      BRACKS,
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
      ENL,
      RUL,
      OSMETAL,
      NMETAL,
      EMETAL,
      SEL_LAYER,
      SMETAL,
      RU_SMETAL,
      TABMETAL,
      BMETAL,
      SEARCHL,
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
#define _SCLN KC_SCLN
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

#define SS_RGUI(string) SS_DOWN(X_RGUI) string SS_UP(X_RGUI)
	
uint32_t default_layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
  case RUL:
    rgblight_enable_noeeprom();
    /* rgblight_setrgb (0xFF,  0x00, 0x00); */
    break;
  default: //  for any other layers, or the default layer
    /* rgblight_setrgb (0x00,  0x00, 0xFF); */
    rgblight_disable_noeeprom();
    break;
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
  if (layer == OSMETAL) {
    unregister_mods(MOD_LGUI);
    unregister_mods(MOD_LALT);
  }
};

static uint16_t timer, rcmd_timer, lctl_timer, lsft_timer, rsft_timer, oslsm_timer, oslem_timer, oslbm_timer, osltm_timer, oslnm_timer;
static const uint16_t timer_threshold = 250;
static const uint16_t oneshot_threshold = 1000;
static uint8_t rgblight_mode_current = RGBLIGHT_MODE_KNIGHT + 1;
static uint8_t oslsm_pressed = 0;
static uint8_t oslem_pressed = 0;
static uint8_t em_forced = 0;
static uint8_t oslbm_pressed = 0;
static uint8_t osltm_pressed = 0,
	oslnm_pressed;
static uint8_t oslsm_another_pressed = 0;
static uint8_t oslem_another_pressed = 0;
static uint8_t oslbm_another_pressed = 0;
static uint8_t osltm_another_pressed = 0,
	oslnm_another_pressed;
static uint8_t
    caps = 0,
	comma_advance = 0
	/* smeta_advance = 0 */
	;


void increase_timer(void) {
  uint8_t layer = biton32(layer_state);
  if (layer == OSMETAL) timer += 2 * timer_threshold;
}

static __attribute__ ((noinline)) void process_record_noinline(keyrecord_t *record) {
	process_record(record);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
		if (BMETAL == biton32(layer_state)) {
			if (comma_advance == 1) {
				if (keycode == COM_SPC) {
					register_code(_RT);
					unregister_code(_RT);
				}
				comma_advance = 0;
			}
			if ((oslbm_pressed == 0 && timer_elapsed(oslbm_timer) > oneshot_threshold) ||
				(oslbm_pressed == 0 && oslbm_another_pressed == 1)) {
				layer_off(BMETAL);
				process_record_noinline(record);
				return 0;
			}
			if (keycode != OSLBM)
				oslbm_another_pressed = 1;
			if (keycode == COM_SPC)
				oslbm_another_pressed = 0;
		}
		if (SMETAL == biton32(layer_state)) {
			if ((oslsm_pressed == 0 && timer_elapsed(oslsm_timer) > oneshot_threshold) ||
				(oslsm_pressed == 0 && oslsm_another_pressed == 1)) {
				layer_off(SMETAL); 
			    process_record_noinline(record);
				return 0;
			}
			if (keycode != OSLSM)
				oslsm_another_pressed = 1;
		}
		if (NMETAL == biton32(layer_state)) {
			if ((oslnm_pressed == 0 && timer_elapsed(oslnm_timer) > oneshot_threshold) ||
				(oslnm_pressed == 0 && oslnm_another_pressed == 1)) {
				layer_off(NMETAL);
			    process_record_noinline(record);
				return 0;
			}
			if (keycode != OSLNM)
				oslnm_another_pressed = 1;
		}
		if (EMETAL == biton32(layer_state) && !em_forced) {
			if ((oslem_pressed == 0 && timer_elapsed(oslem_timer) > oneshot_threshold) ||
				(oslem_pressed == 0 && oslem_another_pressed == 1)) {
				layer_off(EMETAL);
				process_record_noinline(record);
				return 0;
			}
			if (keycode != OSLEM)
				oslem_another_pressed = 1;
		}
	
		if (caps == 1) {
			if (keycode == _SPC) {
				caps = 0;
				unregister_code(KC_LSHIFT);
				return 0;
			} else if (keycode == MACMETA) {
				caps = 0;
				unregister_code(KC_LSHIFT);
				return 0;
			}
		}
		if (em_forced == 1 && (
				keycode == _BSP ||
				keycode == G(_C) ||
				keycode == G(_X) ||
				keycode == G(_V) ||
				keycode == G(_SLS)
				)) {
			/* layer_off(EMETAL); */
			em_forced = 0;
			unregister_code(KC_LSHIFT);
			return true;
		} 
	}
	
  if (TABMETAL == biton32(layer_state)) {
  	  if ((osltm_pressed == 0) && record->event.pressed &&
  		  timer_elapsed(osltm_timer) > oneshot_threshold) {
  		  layer_off(TABMETAL);
  	  }
  	  if (osltm_pressed == 0 && keycode != OSLTM &&
  		  osltm_another_pressed == 1) {
  		  layer_off(TABMETAL);
  	  }
  	  if (keycode != OSLTM)
  		  osltm_another_pressed = 1;
  } // END: OSL TABMETAL
  
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
  case OSLTM:
	  if (record->event.pressed) {
		  osltm_timer = timer_read();
		  osltm_pressed = 1;
		  osltm_another_pressed = 0;
		  layer_on(TABMETAL);
	  } else {
		  osltm_pressed = 0;
		  if (osltm_another_pressed)
			  layer_off(TABMETAL);
	  }
	  return false;
  case OSLEM:
	  if (record->event.pressed) {
		  oslem_timer = timer_read();
		  oslem_pressed = 1;
		  oslem_another_pressed = 0;
		  layer_on(EMETAL);
	  } else {
		  oslem_pressed = 0;
		  if (oslem_another_pressed && !em_forced)
			  layer_off(EMETAL);
	  }
	  return false;
  case OSLSM:
	  if (record->event.pressed) {
		  oslsm_timer = timer_read();
		  oslsm_pressed = 1;
		  oslsm_another_pressed = 0;
		  layer_on(SMETAL);
	  } else {
		  oslsm_pressed = 0;
		  }
	  return false;
  case OSLNM:
	  if (record->event.pressed) {
		  oslnm_timer = timer_read();
		  oslnm_pressed = 1;
		  oslnm_another_pressed = 0;
		  layer_on(NMETAL);
	  } else {
		  oslnm_pressed = 0;
		  }
	  return false;
  case OSLBM:
	  if (record->event.pressed) {
		  oslbm_timer = timer_read();
		  oslbm_pressed = 1;
		  oslbm_another_pressed = 0;
		  layer_on(BMETAL);
	  } else {
		  oslbm_pressed = 0;
		  if (oslbm_another_pressed)
			  layer_off(BMETAL);
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
  case SEARCH:
	  if (record->event.pressed) {
		  layer_on(SEARCHL);
		  send_string(SS_RGUI("f"));
	  } else { }
	  return false;
  case ADVANCE:
	  if (record->event.pressed) {
		  comma_advance = 1;
		  oslbm_another_pressed = 0;
	  } else { }
	  return false;
  case CAPSSPS:
	  if (record->event.pressed) {
		  unregister_code(KC_LSHIFT);
		  layer_off(SEARCHL);
	  } else { }
	  return false;
  case LGUI:
	  if (record->event.pressed) {
		  timer = timer_read();
		  register_code(KC_LGUI);
	  } else {
		  if (timer_elapsed(timer) < timer_threshold) {
			  layer_off(EMETAL);
			  em_forced = 0;
			  unregister_code(KC_LGUI);
			  unregister_code(KC_LSHIFT);
			  send_string(SS_LCTRL("g"));
		  } else {
			  unregister_code(KC_LGUI);
		  }
	  }
	  return false;
  case BSP:
	  if (record->event.pressed) {
		  unregister_code(KC_LSHIFT);
		  register_code(KC_BSPACE);
		  unregister_code(KC_BSPACE);
	  }
	  return false;
  case SSHIFT:
	  if (record->event.pressed) {
		  register_code(KC_LSHIFT);
		  layer_on(EMETAL);
		  em_forced = 1;
	  }
	  return false;
  case KILL:
	  if (record->event.pressed) {
		  unregister_code(KC_LSHIFT);
		  layer_off(EMETAL);
		  em_forced = 0;
		  send_string(SS_LGUI("x"));
	  }
	  return false;
  case YANK:
	  if (record->event.pressed) {
		  unregister_code(KC_LSHIFT);
		  layer_off(EMETAL);
		  em_forced = 0;
		  send_string(SS_LGUI("c"));
	  }
	  return false;
  case TEST:
	rgblight_mode_noeeprom(rgblight_mode_current++); // sets mode to Fast breathing without saving
	return false;
  case MACMETA:
    if (record->event.pressed) {
      timer = timer_read();
      layer_on(OSMETAL);
    } else {
      layer_off(OSMETAL);
      if (timer_elapsed(timer) < timer_threshold) {
        register_code(KC_ENTER);
        unregister_code(KC_ENTER);
      }
      unregister_code(KC_LGUI);
      unregister_code(KC_LALT);
      /* clear_mods(); */
    }
    return false;
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
  switch(keycode) {
  case CMDTAB:
    if (record->event.pressed) {
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
  default:
	  unregister_cmd_after_cmdtab();
  } // END: CMD-TAB like keycodes
  
  // RCMD & RALT doing smth usefull on single press:
  switch(keycode) {
  case RCMD: // CXCJ_K_C[
    if (record->event.pressed) {
      rcmd_timer = timer_read();
      /* layer_on(RCMDL); */
      register_code(KC_RGUI);
    } else {
      unregister_code(KC_RGUI);
      /* layer_off(RCMDL); */
      if (timer_elapsed(rcmd_timer) < timer_threshold) {
        register_code(KC_LCTRL);
        register_code(KC_X);
        unregister_code(KC_X);
        register_code(KC_J);
        unregister_code(KC_J);
        unregister_code(KC_LCTRL);

        register_code(KC_K);
        unregister_code(KC_K);

        register_code(KC_LCTRL);
        register_code(KC_LBRC);
        unregister_code(KC_LBRC);
        unregister_code(KC_LCTRL);
      }
    }
    return false;
  case RALT: // CX_CJ_T_C[
    if (record->event.pressed) {
      rcmd_timer = timer_read();
      /* layer_on(RCMDL); */
      register_code(KC_RALT);
    } else {
      unregister_code(KC_RALT);
      /* layer_off(RCMDL); */
      if (timer_elapsed(rcmd_timer) < timer_threshold) {
        register_code(KC_LCTRL);
        register_code(KC_X);
        unregister_code(KC_X);
        register_code(KC_J);
        unregister_code(KC_J);
        unregister_code(KC_LCTRL);

        register_code(KC_F);
        unregister_code(KC_F);

        register_code(KC_LCTRL);
        register_code(KC_LBRC);
        unregister_code(KC_LBRC);
        unregister_code(KC_LCTRL);
      }
    }
    return false;
  } // end RCMD RALT

  // layers manipulating events (language switch here):
  if (record->event.pressed) {
    switch(keycode) {
    case MAC:
      register_code(KC_A);
      unregister_code(KC_A);
      default_layer_set(1UL<<ENL);
      return false;
    case LSWITCH:
      SEND_STRING(SS_LGUI(" "));
      if (biton32(default_layer_state) == 0) {
        default_layer_set(1UL<<RUL);
      } else {
        default_layer_set(1UL<<ENL);
      }
      return false;
    }
  }

  // just macros:
  if (record->event.pressed) {
    switch (keycode) {
	case ENDL_SPC:
	  send_string(SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) " ");
	  return false;
	case RT_SPC:
	  send_string(SS_TAP(X_RIGHT) " ");
 	  return false;
	case RT2_SPC:
	  send_string(SS_TAP(X_RIGHT) SS_TAP(X_RIGHT) " ");
 	  return false;
	case ENDL:
		SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI));
		oslsm_another_pressed = 0;
		oslsm_timer = timer_read();
      return false;
    case SCLSPC:
		SEND_STRING("; ");
		return false;
    case ENDSPC:
		SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) " ");
		return false;
    case CCS:
		SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) ";");
		return false;
    case PYBLOCK:
		SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) ":" SS_TAP(X_ENTER));
		return false;
    case CBLOCK:
		SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_RIGHT) SS_UP(X_LGUI) " ");
	case MBRACES:
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
    case CXCS_CXE:
      SEND_STRING(SS_LCTRL("xsx") "e");
      return false;
    case CXCS_CZ:
      SEND_STRING(SS_LCTRL("xsz"));
      return false;
    case CXCS_CXCC:
      SEND_STRING(SS_LCTRL("xsxc"));
      return false;
    case CX_CX:
		SEND_STRING(SS_LCTRL("x") SS_LCTRL("x"));
      return false;
    case CX_G:
      SEND_STRING(SS_LCTRL("x") "g");
      return false;
    case CX_Z:
      SEND_STRING(SS_LCTRL("x") "z");
      return false;
    case CX_F:
      SEND_STRING(SS_LCTRL("x") "f");
      return false;
    case CX_CC:
      SEND_STRING(SS_LCTRL("xc"));
      return false;
    case CX_CF:
      SEND_STRING(SS_LCTRL("xf"));
      return false;
    case CX_O:
      SEND_STRING(SS_LCTRL("x") "o");
      return false;
	case CX_B:
      SEND_STRING(SS_LCTRL("x") "b");
      return false;
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
    case CXCJ_SD:
      SEND_STRING(SS_LCTRL("xj") "D");
      return false;
    case CXCJ_MD:
      SEND_STRING(SS_LCTRL("xj") SS_LALT("d"));
      return false;
    case CXCJ_T:
      SEND_STRING(SS_LCTRL("xj") "t");
      return false;
    case CXCJ_CT:
      SEND_STRING(SS_LCTRL("xjt"));
      return false;
    case CXCJ_MT:
      SEND_STRING(SS_LCTRL("xj") SS_LALT("t"));
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
    case GQ:
      register_code(KC_LGUI);
      register_code(KC_Q);
      unregister_code(KC_Q);
      return false;
    }
    return true;
  }

/*   if (SMETAL == biton32(layer_state) && keycode != OSLSM && oslsm_another_pressed == 1) { */
/*     action_t action = store_or_get_action(record->event.pressed, record->event.key); */
/*     dprint("ACTION: "); debug_action(action); */
/* #ifndef NO_ACTION_LAYER */
/*     dprint(" layer_state: "); layer_debug(); */
/*     dprint(" default_layer_state: "); default_layer_debug(); */
/* #endif */
/*     dprintln(); */

/*     process_action(record, action); */

/* *   }  */
 
  return true;
}

void matrix_scan_user(void) {
	
}

void keyboard_post_init_user(void) {
  // Call the post init code.
  rgblight_enable_noeeprom(); // enables Rgb, without saving settings
  /* rgblight_sethsv_noeeprom(250, 200, 100); // sets the color to teal/cyan without saving */
  rgblight_mode_noeeprom(rgblight_mode_current); // sets mode to Fast breathing without saving
  rgblight_disable_noeeprom();
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = 
{

	
	LAYOUT_all
	(_F2,              LGUI,    _ESC,    S(_MIN), OSLTM,   S(_5),   _______, S(_EQL), _B,      _MIN,    OSLBM,    G(S(_4)),G(S(_3)),_NO,     S(_F10),
	 SSHIFT,           CAPS,    OSLSM,   _O,      _DOT,    LEADER,           _Y,      _G,      _C,      _R,      _F,      _K,      _SLS,    S(A(_F10)),
	 OSLNM,            _P,      _A,      _E,      _I,      _BSP,             _L,      _H,      _T,      _N,      _S,      _EQL,              _TAB,
	 _LSFT,    _A,     _MIN,    _Z,      _J,      _U,      _TAB,             _D,      _M,      _W,      _V,      _X,      _Q,      C(A(_Y)),_UP,
	 _LCTL,                     _LALT,   RALT,             _SPC,   OSLEM,    MACMETA, RCMD,             _VDN,             _VUP,    MACMETA, _SPC),

	LAYOUT // -ru_l
	(_______,          _______, _______, _______, _______, _______, _RBR,    _______, _COM,    _______, S(_SLS), _______, _______, _______, _______,
	 SSHIFT,           CAPS,    OSLSM,   _J,      _SLS,    _M,               _Q,      _U,      _Z,      _H,      _A,      _P,      _O,      _O,
	 _______,          _G,      _F,      _T,      _B,      _BSP,             _K,      _R,      _N,      _Y,      _C,      _W,               _LBR,
	 _DOT, _______,    _QUO,    _I,      _SCLN,   _E,      _S,               _L,      _V,      _D,      _X,      _A,               _______, _______,
	 _______,                   _______, _______,          _______, _______, _______,          _______, _______,          _______, _______, _______),
 
	LAYOUT // -os_layer
	(DF(1),            _______, _F17,    _F18,    _______, _______, _______, _______, G(_LBR), C(S(_TAB)),C(_TAB),G(_W),  G(_Z),   _______, _______,
	 WIN,              _______, C(_G),   _ESC,    _F15,    _______,          G(_R),   G(_GRV), SCMDTAB, CMDTAB,  SALTTAB, G(_RBR),  _______,_______,
	 _______,          _______, CX_P,    CX_CP, GACS(_SPC),G(S(_P)),         G(S(_P)),G(_L),   G(_C),   G(_V),   G(_X),   GQ,               _______,
	 _______, _______, _______, _______, _______, _______, _______,          _______, G(_C),   _______, _______, _______,          _______, RGB_TOG,
	 _______,                   _______, _______,          _______, _______, _______,          _______, _______,          _______, _______, _______),

	LAYOUT // -nmeta_l
	(_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	 _______,          _______, _______, _______, _______, _______,          _______, _______, _0,      _9,      _______, _______, _______, _______,
	 _______,          _______, _______, _______, _______, _______,          _6,      _1,      _2,      _3,      _4,      _5,               _______,
	 _______, _______, _______, _______, _______, _______, _______,          _7,      _8,      _______, CC_PLS,  CC_MIN,  _______, _______,
	 _______,                   _______, _______,          _______, _______, _______,          _______, _______,          _______, _______, _______),

	LAYOUT // _editing_layer
	(_______,          _______, _______, _______, _______, _______, _______, _BSP,    _______, C(G(_DN)),C(G(_UP)),C(_K), _______, _______, _______,
	 LGUI,             C(S(_K)),_LGUI,   G(_Z),   G(_BSP), G(S(_D)),         C(A(G(_5))),_PGDN,_DN,     _UP,     _PGUP,   _______, _______, _______,
	 G(S(_D)),         G(_X),   G(_V),   G(_C),   G(_SLS), _______,          G(_LT),  A(_LT),  _RT,     A(_RT),  G(_RT),  _DEL,             _SPC,
	 G(_X),   _______, CC_PLS,  CC_MIN,  A(_U), C(M(_BSL)),_______,          A(_W),   _LT,     G(_BSP), CTA(_Y), C(_K),            A(_BSL), _______, 
	 _______,                   _______, _______,          _BSP,    _BSP,    _______,          _______, _______,          _______, _______, _______),

	LAYOUT // _selection_layer
	(_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	 _______,          _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,
	 _______,          G(_X),   _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,          _______,
	 _______, _______, _______, _______, _______, CX_CX,   _______,          _______, _______, _______, _______, _______,          _______, _______,
	 _______,                   _______, _______,          _______, _______, _______,          _______, _______,          _______, _______, _______),

	LAYOUT // _symbols_layer
	(_______,          _______, _______, _______, _______, _______, _______, _LBR,    S(_GRV), _QUO,    _GRV,    _RBR,    _______, _______, _______,
	 _______,          _______, CCS,     ENDL,    _BSL,    S(_BSL),          S(_6),   S(_COM), QUOTES,  S(_QUO), S(_DOT), _BSL,    _______, _______,
	 _______,          S(_2),   _______, _______, LSWITCH, S(_1),            _SLS,    S(_SCLN),S(_7),   S(_EQL), S(_4),   S(_3),            _______,
	 _______, _______, _______, _______, _______, _______, _______,          C(A(_R)),C(A(_S)),C(_W),   S(_8),   S(_SLS),          _______, _______,
	 _______,                   _______, _______,          RT_SPC,  RT2_SPC, ENDL_SPC,         _______, _______,          _______, _______, _______),
   
	LAYOUT // -rusmeta_l
	(_______,          _______, _______, _______, _______, _______, _______, _______, _______, S(_GRV), _GRV,    _______,  _______, _______, _______,
	 _______,          _______, _______,G(_ENT),  _______, _______,          S(_6),   S(_COM), _EQL,    S(_QUO), S(_DOT), _SLS,     _______, _______,
	 _______,          _______, _______, _______, LSWITCH, _______,          S(_1),   S(_6),   S(_8),   S(_EQL), S(_4),   S(_3),            _______,
	 _______, _______, _______, _______, _______, _______, _______,          LCTL(_R),CTA(_S), LCTL(_W),_______, S(_7),            _______, _______,
	 _______,                   _______, _______,          _______, _______, _______,          _______, _______,          _______, _______, _______),

	LAYOUT // -tmetal_l
	(_______,          _______, _______, _______, _SCLN,   _______, _______, _______, CX_K,    CX_CF,   CX_B,    CX_3,    CX_RBRC, _______, CXCJ_0,
	 _______,          _______, _______, _______, _______, S(_F6),           CX_Z,    CX_G,    CX_O,    CX_1,    CX_0,    CX_0,    _______, CX_LBRC,
	 _______,          _______, _______, _______, _______, A(S(_1)),         A(S(_SCLN)),A(_X),S(_F10), CX_Z,    CXCS,    S(A(_F10)),       G(_F2),
	 _______, _______, _______, _______, _______, _______, _______,          C(A(S(_5))),CXCJ_D,CXCJ_CD,CXCJ_CC, CXCJ_SD, CX_CC,   _______,
	 _______,                   _______, _______,          SCLSPC,  ENDSPC,  CCS,              _______, _______,          _______, RGB_HUI, RGB_HUD),

	LAYOUT // -bmeta_l
	(_______,          _______, _______, S(_LBR), BRACES,  S(_RBR), _______, _LBR,    _______, MBRACES, _COM,    _RBR,    _______, _______, _______,
	 _______,          _______, S(_9),   PARENS,   S(_0),  MBRACES,          S(_6),   S(_COM), _MIN,   S(_QUO), S(_DOT), S(_7),   _______,  _______,
	 _______,          C(_ENT), _LBR,    BRACKS,  ADVANCE, _RBR,             G(_ENT), G(_ENT), _______,  S(_EQL), S(_4),   S(_3),           _______,
	 _______, _______, _______, _______, _______, _______, _______,          LCTL(_R),CTA(_S), LCTL(_W),S(_8)   ,S(_SLS),          _______, _______,
	 _______,                   _______, _______,          COM_SPC, ENDSPC,  G(_ENT),          _______, _______,          _______, _______, _______),

	LAYOUT // -search_l
	(_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	 _______,          _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,
	 _______,          _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,          _______,
	 _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
	 _______,                   _______, _______,          _______, _______, G(_G),          _______, _______,          _______, _______, _______),

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
