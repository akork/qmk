
#include QMK_KEYBOARD_H

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

enum custom_keycodes {
		      _VIMRC = SAFE_RANGE,
                      CC_PLS,
                      CC_MIN,
		      CXCS,
		      CXCS_CXE,
		      CXCS_CZ,
		      LSWITCH
};

enum {
      LSFT = 1,
      ENTMETA,
      RUENTMETA,
      RSFT,
      NMETA,
      QMETA,
      HMETA, // 7
      LCMETA,
      RCMETA,
      META, // 10
      TABMETA,
      RU,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
    case _VIMRC:
      SEND_STRING(
":syn on|"
"colo ron|"
"set cul fdm=marker is ai si et sta sw=4|"
"filet plugin indent on|"
"noremap c j|"
"noremap r k|"
"noremap t l|"
"noremap m h\n"

); // this is our macro
      return false;
      break;
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
    
    case LSWITCH:
      layer_on(12);
      SEND_STRING((SS_LALT("x")));
      return false;
    }
  }
  return true;
};

#define _LS_ KC_LSFT
#define _RS_ KC_RSFT
#define _LC_ KC_LCTL
#define _RC_ KC_RCTL
#define _LG_ KC_LGUI
#define _RG_ KC_RGUI
#define _LA_ KC_LALT
#define _RA_ KC_RALT

#define _LS__ MT(MOD_LSFT, KC_TAB)
#define _ENT_ LT(ENTMETA, KC_ENT)
#define _RUENT_ LT(RUENTMETA, KC_ENT)
#define _RS__ LT(RSFT, KC_TAB)
#define _NM__ LT(NMETA, KC_SCLN)
#define _QM__ LT(QMETA, KC_Q)
#define _HM__ LT(HMETA, KC_H)
#define _LC__ LT(LCMETA, KC_ESC)
#define _RC__ LT(RCMETA, KC_ESC)
#define _SPC__ LT(META, KC_SPC)
#define _TAB__ LT(TABMETA, KC_TAB)

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

#define _RT KC_RGHT
#define _LT KC_LEFT
#define _UP KC_UP
#define _DN KC_DOWN

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
#define GACS(x) LGUI(LALT(LCTL(LSHFT(x))))
#define _PGUP KC_PGUP
#define _PGDN KC_PGDN







#define _UND S(KC_MINS)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = 
  {
   LAYOUT
   (_ESC,             S(_1),   _UND,    _COM,    _TAB__,  S(_5),   _CAP,    S(_7),   _MIN,    S(_9),   S(_0),   _LBR,    _RBR,    _NO,     _BSP,
    _LS_,             _Y,      _ENT_,   _O,      _DOT,    _U,               _Z,      _G,      _C,      _R,      _F,      _RS_,    _SLS,    _BSL,
    _NM__,            _I,      _A,      _E,      _QM__,   _L,               _D,      _HM__,   _T,      _N,      _S,      _B,               _QUO,
    _LC__,   _NO,     _BSL,    S(_5),   _J,      _K,      _QUO,             _P,      _M,      _W,      _V,      _X,               _RC__,   _NO,
    _LC_,                      _LG_,    _LA_,             _SPC,    _SPC__,   _SPC,             _RG_,    _SPC,             _NO,     _DOW,    _UP),

   LAYOUT // -lshift = 1
   (TR,               TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,
    TR,               TR,      TR,      TR,      TR,      TR,               TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,
    TR,               TR,      TR,      TR,      TR,      TR,               TR,      TR,      TR,      TR,      TR,      TR,               TR,
    TR,      TR,      TR,      TR,      TR,      TR,      TR,               TR,      TR,      TR,      TR,      TR,               TR,      TR,
    TR,                        TR,      TR,               TR,      TR,      TR,               TR,      TR,               TR,      TR,      TR),

   LAYOUT // -ENTMETA_
   (TR,               TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      S(_GRV), _GRV,   TR,       TR,      TR,      TR,
    TR,               TR,      TR,     GUI(_ENT),TR,      TR,               S(_6),   S(_COM), _EQL,    S(_QUO), S(_DOT), _SLS,   TR,      TR,
    TR,               TR,      TR,      TR,      TR,      TR,               S(_1),   S(_SCLN),S(_8),   S(_EQL), S(_4),   S(_3),            TR,
    TR,      TR,      TR,      TR,      TR,      TR,      TR,               LCTL(_R),CTA(_S), LCTL(_W),LCTL(_S),TR,               TR,      TR,
    TR,                        TR,      TR,               TR,      TR,      TR,               TR,      TR,               TR,      TR,      TR),

   LAYOUT // -RUENTMETA_
   (TR,               TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      S(_GRV), _GRV,   TR,       TR,      TR,      TR,
    TR,               TR,      TR,     GUI(_ENT),TR,      TR,               S(_6),   S(_COM), _EQL,    S(_QUO), S(_DOT), _SLS,   TR,      TR,
    TR,               TR,      TR,      TR,      TR,      TR,               S(_1),   _A,      S(_8),   S(_EQL), S(_4),   S(_3),            TR,
    TR,      TR,      TR,      TR,      TR,      TR,      TR,               LCTL(_R),CTA(_S), LCTL(_W),TR,      TR,               TR,      TR,
    TR,                        TR,      TR,               TR,      TR,      TR,               TR,      TR,               TR,      TR,      TR),

   LAYOUT // -
   (TR,               TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,
    TR,               TR,      TR,      TR,      TR,      TR,               TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,
    TR,               TR,      TR,      TR,      TR,      TR,               TR,      TR,      TR,      TR,      TR,      TR,               TR,
    TR,      TR,      TR,      TR,      TR,      TR,      TR,               TR,      TR,      TR,      TR,      TR,               TR,      TR,
    TR,                        TR,      TR,               TR,      TR,      TR,               TR,      TR,               TR,      TR,      TR),

   LAYOUT // -NMETA = 5
   (TR,               TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      _VIMRC,
    TR,               TR,      TR,      TR,      TR,      TR,               TR,      TR,      _0,      _9,      TR,      TR,      TR,      TR,
    TR,               TR,      TR,      TR,      TR,      TR,               _6,      _1,      _2,      _3,      _4,      _5,               TR,
    TR,      TR,      TR,      TR,      TR,      TR,      TR,               _7,      _8,      TR,      CC_PLS,  CC_MIN,  TR,      TR,
    TR,                        TR,      TR,               TR,      TR,      TR,               TR,      TR,               TR,      TR,      TR),

   LAYOUT // -QMETA
   (TR,               TR,      TR,      TR,      TR,      TR,      TR,      TR,     ALT(_BSP),TR,      TR,      TR,      TR,      TR,      TR,
    TR,               TR,      TR,      CTL(_G), TR,      TR,               TR,      _PGDN,   _DN,     _UP,     _PGUP,   TR,      TR,      TR,
    TR,               TR,      TR,      TR,      TR,      TR,               GUI(_LT),_BSP,    _RT,     ALT(_RT),GUI(_RT),TR,               TR,
    TR,      TR,      TR,      TR,      TR,      TR,      TR,               ALT(_LT),_LT,     ALT(_W), CTA(_Y),TR,                TR,      TR,
    TR,                        TR,      TR,               TR,      TR,      TR,               TR,      TR,               TR,      TR,      TR),

   LAYOUT // -HMETA
   (TR,               TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,
    TR,               TR,      TR,      TR,      TR,      TR,               TR,      TR,      _ESC,    TR,      TR,      TR,      TR,      TR,
    TR,               TR,      TR,      TR,      LSWITCH, TR,               TR,      TR,      TR,      TR,      TR,      TR,               TR,
    TR,      TR,      TR,      TR,      TR,      TR,      TR,               TR,      TR,      CXCS,    CXCS_CXE,CXCS_CZ, TR,      TR,
    TR,                        TR,      TR,               TR,      TR,      TR,               TR,      TR,               TR,      TR,      TR),

   LAYOUT // -LCMETA
   (TR,               TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,
    TR,               TR,      TR,      TR,      TR,      TR,               TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,
    TR,               TR,      TR,      TR,      TR,      TR,               TR,      TR,      TR,      TR,      TR,      TR,               TR,
    TR,      TR,      TR,      TR,      TR,      TR,      TR,               TR,      TR,      TR,      TR,      TR,               TR,      TR,
    TR,                        TR,      TR,               TR,      TR,      TR,               TR,      TR,               TR,      TR,      TR),

   LAYOUT // -RCMETA
   (TR,               TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,
    TR,               TR,      TR,      TR,      TR,      TR,               TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,
    TR,               TR,      TR,      TR,      TR,      TR,               TR,      TR,      TR,      TR,      TR,      TR,               TR,
    TR,      TR,      TR,      TR,      TR,      TR,      TR,               TR,      TR,      TR,      TR,      TR,               TR,      TR,
    TR,                        TR,      TR,               TR,      TR,      TR,               TR,      TR,               TR,      TR,      TR),

   LAYOUT // -SPC (META) = 10
   (TR,               TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,
    TR,               TR,     GUI(_ENT),TR,      KC_F15,  TR,               TR,      TR,      CTL(S(_TAB)),CTL(_TAB),TR, TR,      TR,      TR,
    TR,               TR,      TR,      TR,      GACS(_SPC),TR,             TR,      GUA(_DN),TR,      GUI(_TB),GUI(_L),TR,               TR,
    TR,      TR,      TR,      TR,      TR,      TR,      TR,            S(GUI(_TB)),TR,      TR,      TR,      TR,               TR,      TR,
    TR,                        TR,      TR,               TR,      TR,      TR,               TR,      TR,               TR,      TR,      TR),

   LAYOUT // -TAB (4META)
   (TR,               TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,
    TR,               TR,      TR,      TR,      TR,      TR,               TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,
    TR,               TR,      TR,      TR,      TR,      TR,               TR,      ALT(_X), ALT(_X), TR,      TR,      TR,               TR,
    TR,      TR,      TR,      TR,      TR,      TR,      TR,               TR,      TR,      TR,      TR,      TR,               TR,      TR,
    TR,                        TR,      TR,               TR,      TR,      TR,               TR,      TR,               TR,      TR,      TR),

   LAYOUT // -RU
   (TR,               _Q,      _RUENT_, TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,
    TR,               _Q,      _RUENT_, TR,      TR,      TR,               TR,      TR,      TR,      TR,      TR,      TR,      TR,      TR,
    TR,               TR,      TR,      TR,      TR,      TR,               TR,      TR,      TR,      TR,      TR,      TR,               TR,
    TR,      TR,      TR,      TR,      TR,      TR,      TR,               TR,      TR,      TR,      TR,      TR,               TR,      TR,
    TR,                        TR,      TR,               TR,      TR,      TR,               TR,      TR,               TR,      TR,      TR),

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
