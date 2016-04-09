// shooting/source/h

#include "DxLib.h"
#include <math.h>
#include "./define.h"

#ifdef GLOBAL_INSTANCE
#define GLOBAL
#else
#define GLOBAL extern
#endif

#include "./../source/h/keyboard/Keyboard.h"
#include "./struct.h"
#include "./globalFunction.h"
#include "./globalVariable.h"
#include "./substance/Substance.h"
#include "./substance/character/Character.h"
#include "./substance/character/player/Player.h"
#include "./substance/character/enemy/Enemy.h"
#include "./substance/bullet/Shot.h"
#include "./globalClass.h"
