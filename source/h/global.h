// shooting/source/h

#include "./../../DxLib_VC/DxLib.h"
#include "./define.h"

#ifdef GLOBAL_INSTANCE
#define GLOBAL
#else
#define GLOBAL extern
#endif

#include "./struct.h"
#include "./globalFunction.h"
#include "./globalVariable.h"
#include "./globalClass.h"
#include "./../source/h/keyboard/Keyboard.h"
#include "./substance/Substance.h"
#include "./substance/character/Character.h"
#include "./substance/character/player/Player.h"
