// -*- compile-command: "make dz60:ak-first:dfu" -*- 

#include QMK_KEYBOARD_H

#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

static bool isCmdSetByMeta = false;

enum custom_keycodes {
		      MMETA,
		      RCMD,
		      LCMD,
		      _VIMRC = SAFE_RANGE,
                      CC_PLS,
                      CC_MIN,
		      CXCS,
		      CXCS_CXE,
		      CXCS_CZ,
		      CXCS_CXCC,
		      LSWITCH,
		      CMDTAB,
		      SCMDTAB,
		      CMDTAB2,
		      LBR_RBR_LFT,
		      CX_G,
		      CX_F,
		      CX_O,
		      CX_B,
		      CX_0,
		      CX_1,
		      CX_3,
		      M0_CK,
		      CXCJ_B,
		      CXCJ_I,
		      CXCJ_CC,
		      CXCJ_D,
		      CXCJ_CD,
		      CXCJ_MD,
};

enum {
      RU = 1,
      LSFT,
      LSFTRU,
      ENTMETA,
      RUENTMETA,
      RSFT,
      RSFTRU,
      NMETA,
      QMETA,
      HMETA, // 7
      LCMETA,
      RCMETA,
      META, // 10
      TABMETA,
      RCMDL,
      LCMDL,
};

void unregister_cmd_after_cmdtab(void) {
  uint8_t layer = biton32(layer_state);
  /* bool isCmdOn = get_mods() & MOD_BIT(KC_LGUI); */
  /* if (layer != META && isCmdSetByMeta && isCmdOn) { */
  /*   unregister_mods(MOD_LGUI); */
  /*   isCmdSetByMeta = false; */
  /* } */
  if (layer == META) unregister_mods(MOD_LGUI);
};

static uint16_t timer, rcmd_timer;
static const uint16_t timer_threshold = 150;

void increase_timer(void) {
  uint8_t layer = biton32(layer_state);
  if (layer == META) timer += timer_threshold;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  /* unregiterCmdAfterCMDTAB(); */
  if (keycode != MMETA) increase_timer();
  switch(keycode) {
  case MMETA:
    if (record->event.pressed) {
      timer = timer_read();
      layer_on(META);
    } else {
      layer_off(META);
      clear_mods();
      unregister_code(KC_LGUI);
      if (timer_elapsed(timer) < timer_threshold) {
	register_code(KC_SPACE);
	unregister_code(KC_SPACE);
      }
    }
    return false;
  case CMDTAB:
    if (record->event.pressed) {
      register_code(KC_LGUI);
      register_code(KC_TAB);
      unregister_code(KC_TAB);
    } else {
    }
    return false;
  case SCMDTAB:
    if (record->event.pressed) {
      register_code(KC_LGUI);
      register_code(KC_LSHIFT);
      register_code(KC_TAB);
      unregister_code(KC_TAB);
      unregister_code(KC_LSHIFT);
    } else {
    }
    return false;
  case CMDTAB2:
    if (record->event.pressed) {
      bool isCmdOn = get_mods() & MOD_BIT(KC_LGUI); 
      if (!isCmdOn) {
      register_code(KC_LGUI);
      isCmdSetByMeta = true;
      }
      register_code(KC_TAB);
      unregister_code(KC_TAB);
    } else {
    }
    return false;
  default:
    unregister_cmd_after_cmdtab();
  }
  switch(keycode) {
  case RCMD:
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
  }
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
    case CXCS_CXCC:
      SEND_STRING(SS_LCTRL("xsxc"));
      return false;
    case LBR_RBR_LFT:
      SEND_STRING("[]" SS_TAP(X_LEFT));
      return false;
    case CX_G:
      SEND_STRING(SS_LCTRL("x") "g");
      return false;
    case CX_F:
      SEND_STRING(SS_LCTRL("x") "f");
      return false;
    case CX_O:
      SEND_STRING(SS_LCTRL("x") "o");
      return false;
    case CX_B:
      SEND_STRING(SS_LCTRL("x") "b");
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
    case CXCJ_B:
      SEND_STRING(SS_LCTRL("xj") "b");
      return false;
    case CXCJ_I:
      SEND_STRING(SS_LCTRL("xj") "i");
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
    case CXCJ_MD:
      SEND_STRING(SS_LCTRL("xj") SS_LALT("d"));
      return false;
    case LSWITCH:
      SEND_STRING(SS_LALT(SS_LGUI(SS_TAP(X_TAB))));
      layer_invert(RU);
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
#define ALG(x) LALT(LGUI(x))
#define GACS(x) LGUI(LALT(LCTL(LSFT(x))))
#define _PGUP KC_PGUP
#define _PGDN KC_PGDN

#define _UND S(KC_MINS)
#define _LS__ LT(LSFT, KC_RBRC)
#define _LSRU LT(LSFTRU, KC_RBRC)
#define _RS__ LT(RSFT, KC_LBRC)
#define _RSRU LT(RSFTRU, KC_LBRC)
#define _ENT_ LT(ENTMETA, KC_ENT)
#define _RUENT_ LT(RUENTMETA, KC_ENT)
#define _TAB__ LT(TABMETA, KC_TAB)
#define _NM__ LT(NMETA, KC_SCLN)
#define _QM__ LT(QMETA, KC_Q)
#define _QMRU__ LT(QMETA, KC_DOT)
#define _HM__ LT(HMETA, KC_H)
#define _HMRU__ LT(HMETA, KC_R)
#define _LC__ LT(LCMETA, KC_ESC)
#define _RC__ LT(RCMETA, KC_ESC)
#define _SPC__ LT(META, KC_SPC)
  
#define C(x) LCTL(x)
#define A(x) LALT(x)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = 
  {
   LAYOUT
   (_ESC,             S(_1),   _UND,    _COM,    _TAB__,  S(_5),   _CAP,    S(_7),   _MIN,    S(_9),   S(_0),   KC__VOLDOWN,KC__VOLUP,_NO, _BSP,
    _LS__,            _Y,      _ENT_,   _O,      _DOT,    _U,               _Z,      _G,      _C,      _R,      _F,      _RS__,   _SLS,    _BSL,
    _NM__,            _I,      _A,      _E,      _QM__,   _L,               _D,      _HM__,   _T,      _N,      _S,      _B,               _QUO,
    _LC__,   _NO,     _BSL,    S(_5),   _J,      _K,      _QUO,             _P,      _M,      _W,      _V,      _X,               _RC__,   _NO,
    _LC_,                      _LA_,    _LG_,             _SPC,    MMETA,   _SPC,             RCMD,    _SPC,             _NO,     _DOW,    _UP),

   LAYOUT // -RU
   (_______,          _______, _RUENT_, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _LSRU,            _Q,      _RUENT_, _J,      _SLS,    _E,               _LBR,    _U,      _Z,      _H,      _P,      _RSRU,   _O,      _______,
    _______,          _B,      _F,      _T,      _QMRU__, _K,               _L,      _HMRU__, _N,      _Y,      _C,      _COM,             _O,
    _______, _______, _QUO,    _I,      _SCLN,   _M,      _S,               _G,      _V,      _D,      _X,      _A,               _______, _______,
    _______,                   _______, _______,          _______, _______, _______,          _______, _______,          _______, _______, _______),

   LAYOUT // -lshift = 1
   (_______,          S(S(_1)),S(_UND), S(_COM), _TAB__,  S(_5),   S(_CAP), S(_7),   S(_MIN), S(_9),   S(_0),   S(_LBR), S(_RBR), _NO,     S(_BSP),
    _LS__,            S(_Y),   _ENT_,   S(_O),   S(_DOT), S(_U),            S(_Z),   S(_G),   S(_C),   S(_R),   S(_F),   LBR_RBR_LFT,S(_SLS),S(_BSL),
    _NM__,            S(_I),   S(_A),   S(_E),   S(_Q),   S(_L),            S(_D),   S(_H),   S(_T),   S(_N),   S(_S),   S(_B),            S(_QUO),
    _LC__,   _NO,     S(_BSL), S(_5),   S(_J),   S(_K),   S(_QUO),          S(_P),   S(_M),   S(_W),   S(_V),   S(_X),            _RC__,   _NO,
    _LC_,                      _LG_,    MMETA,            _SPC,    MMETA,   _SPC,             _RG_,    _SPC,             _NO,     _DOW,    _UP),

   LAYOUT // -lshiftRU
   (_______,          _______, _RUENT_, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,          S(_Q),   _RUENT_, S(_J),   S(_SLS), S(_E),            S(_LBR), S(_U),   S(_Z),   S(_H),   S(_P),   _______, S(_O),   _______,
    _______,          S(_B),   S(_F),   S(_T),   S(_DOT), S(_K),            S(_L),   S(_R),   S(_N),   S(_Y),   S(_C),   S(_COM),          S(_O),
    _______, _______, S(_QUO), S(_I),   S(_SCLN),S(_M),   S(_S),            S(_G),   S(_V),   S(_D),   S(_X),   S(_A),            _______, _______,
    _______,                   _______, _______,          _______, _______, _______,          _______, _______,          _______, _______, _______),

   LAYOUT // -ENTMETA_
   (_______,          _______, _______, _______, _______, _______, _______, _______, _______, S(_GRV), _GRV,   _______,  _______, _______, _______,
    _______,          _______, _______,GUI(_ENT),_______, _______,          S(_6),   S(_COM), _EQL,    S(_QUO), S(_DOT), S(_7),   _______, _______,
    _______,          S(_2),   _______, _______, _______, _______,          S(_1),   S(_SCLN), S(_8),   S(_EQL), S(_4),   S(_3),            _______,
    _______, _______, _______, _______, _______, _______, _______,          LCTL(_R),CTA(_S), LCTL(_W),LCTL(_S),_______,          _______, _______,
    _______,                   _______, _______,          _______, _______, _______,          _______, _______,          _______, _______, _______),

   LAYOUT // -RUENTMETA_
   (_______,          _______, _______, _______, _______, _______, _______, _______, _______, S(_GRV), _GRV,    _______,  _______, _______, _______,
    _______,          _______, _______,GUI(_ENT),_______, _______,          S(_6),   S(_COM), _EQL,    S(_QUO), S(_DOT), _SLS,     _______, _______,
    _______,          _______, _______, _______, _______, _______,          S(_1),   S(_6),   S(_8),   S(_EQL), S(_4),   S(_3),            _______,
    _______, _______, _______, _______, _______, _______, _______,          LCTL(_R),CTA(_S), LCTL(_W),_______, _______,          _______, _______,
    _______,                   _______, _______,          _______, _______, _______,          _______, _______,          _______, _______, _______),

   LAYOUT // -rshift = 4
   (_ESC,             _______, S(_UND), S(_COM), _TAB__,  S(_5),   S(_CAP), S(_7),   S(_MIN), S(_9),   S(_0),   S(_LBR), S(_RBR), _NO,     S(_BSP),
    _LS__,            S(_Y),   _ENT_,   S(_O),   S(_DOT), S(_U),            S(_Z),   S(_G),   S(_C),   S(_R),   S(_F),   LBR_RBR_LFT,S(_SLS),S(_BSL),
    _NM__,            S(_I),   S(_A),   S(_E),   S(_Q),   S(_L),            S(_D),   S(_H),   S(_T),   S(_N),   S(_S),   S(_B),            S(_QUO),
    _LC__,   _NO,     S(_BSL), S(_5),   S(_J),   S(_K),   S(_QUO),          S(_P),   S(_M),   S(_W),   S(_V),   S(_X),            _RC__,   _NO,
    _LC_,                      _LG_,    MMETA,            _SPC,    MMETA,   _SPC,             _RG_,    _SPC,             _NO,     _DOW,    _UP),

   LAYOUT // -rshiftRU
   (_______,          _______, _RUENT_, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,          S(_Q),   _RUENT_, S(_J),   S(_SLS), S(_E),            S(_LBR), S(_U),   S(_Z),   S(_H),   S(_P),   _______, S(_O),   _______,
    _______,          S(_B),   S(_F),   S(_T),   S(_Q),   S(_K),            S(_L),   S(_H),   S(_N),   S(_Y),   S(_C),   S(_COM),          S(_O),
    _______, _______, S(_QUO), S(_I),   S(_SCLN),S(_M),   S(_S),            S(_G),   S(_V),   S(_D),   S(_X),   S(_A),            _______, _______,
    _______,                   _______, _______,          _______, _______, _______,          _______, _______,          _______, _______, _______),

   LAYOUT // -NMETA = 5
   (_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _VIMRC,
    _______,          _______, _______, _______, _______, _______,          _______, _______, _0,      _9,      _______, _______, _______, _______,
    _______,          _______, _______, _______, _______, _______,          _6,      _1,      _2,      _3,      _4,      _5,               _______,
    _______, _______, _______, _______, _______, _______, _______,          _7,      _8,      _______, CC_PLS,  CC_MIN,  _______, _______,
    _______,                   _______, _______,          _______, _______, _______,          _______, _______,          _______, _______, _______),

   LAYOUT // -eMETA
   (_______,          _______, _______, _______, _______, _______, _______, _______,A(_BSP),  _______, _______, _______, _______, _______, _______,
    _______,          A(_D),   _______, _ESC,    C(S(_MIN)),_______,        _______, _PGDN,   _DN,     _UP,     _PGUP,   _______, _______, _______,
    _______,          C(_K),   C(_D),   A(_U),   _______, _______,          GUI(_LT),_BSP,    _RT,     A(_RT),  GUI(_RT),M0_CK,            _______,
    _______, _______, _______, _______, _______, _______, _______,          A(_LT),  _LT,     A(_W),   CTA(_Y),_______,           A(_BSL), _______,
    _______,                   _______, _______,          _______, _______, _______,          _______, _______,          _______, _______, _______),

   LAYOUT // -hMETA
   (_______,          _______, _______, _______, _______, _______, _______, _______, ALG(_TAB),S(_LBR),S(_RBR), _______, _______, _______, _______,
    _______,          _______, _______, _______, _______, _______,          _______, _______, _ESC,    _______, C(_G),   _______, _______, _______,
    _______,          _______, _______, _______, LSWITCH, _______,          _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, CXCS,    CXCS_CXE,CXCS_CZ, CXCS_CXCC,_______,
    _______,                   _______, _______,          _______, _______, _______,          _______, _______,          _______, _______, _______),

   LAYOUT // -LCMETA
   (_______,          S(_1),   _UND,    _COM,    _TAB__,  S(_5),   _CAP,    S(_7),   C(_MIN),  S(_9),  S(_0),   C(_LBR), C(_RBR), _NO,     C(_BSP),  
    _LS__,            C(_Y),   _ENT_,   C(_O),   C(_DOT),  C(_U),           C(_Z),   C(_G),   C(_C),   C(_R),   C(_F),   _RS__,   _SLS,    _BSL,
    _NM__,            C(_I),   C(_A),   C(_E),   C(_Q),   C(_L),            C(_X),   C(_H),   C(_T),   C(_N),   C(_S),   C(_B),            C(_QUO),  
    _LC__,   _NO,     _BSL,    S(_5),   C(_J),   C(_K),   C(_QUO),          C(_P),   C(_M),   C(_W),   C(_V),   C(_X),            _RC__,   _NO,
    _______,                   _______, _______,          _______, _______, _______,          _______, _______,          _______, _______, _______),

   LAYOUT // -RCMETA
   (_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,          _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______,
    _______,          _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______,          _______, _______,
    _______,                   _______, _______,          _______, _______, _______,          _______, _______,          _______, _______, _______),

   LAYOUT // -SPC (META) = 10
   (_______,          _______, KC_F17,  KC_F18,  _______, _______, _______, _______, _______, C(S(_TAB)),C(_TAB),GUI(_W),_______, _______, _______,
    _______,          _______,GUI(_ENT),_______, KC_F15,  _______,          _______, _______, SCMDTAB, CMDTAB,  _______, _______, _______, _______,
    _______,          _______, _______, _______, GACS(_SPC),_______,        _______, GUA(_DN),CTA(_S), CMDTAB,  GUI(_L), GUI(_Q),          _______,
    _______, _______, _______, _______, _______, _______, _______,          _______, CTA(_M), _______, _______, _______,          _______, _______,
    _______,                   _______, _______,          _______, _______, _______,          _______, _______,          _______, _______, _______),

   LAYOUT // -TAB (4META)
   (_______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, CX_F,    CX_3,    _______, _______, _______,
    _______,          _______, _______, _______, _______, _______,          _______, CX_G,    CX_O,    CX_B,    CX_1,    CX_0,    CX_0,    _______,
    _______,          _______, _______, _______, _______, _______,          A(S(_SCLN)),A(_X),CXCJ_B,  _______, CX_1,    _______,          _______,
    _______, _______, _______, _______, _______, _______, _______,          CXCJ_I,  CXCJ_D,  CXCJ_CD, CXCJ_MD, _______,          CXCJ_CC, _______,
    _______,                   _______, _______,          _______, _______, _______,          _______, _______,          _______, _______, _______),

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
