// shooting/source/h

#include "DxLib.h"
#include <math.h>
#include "./define.h"

#ifdef GLOBAL_INSTANCE
#define GLOBAL
#else
#define GLOBAL extern
#endif

#include "./struct.h"
#include "./keyboard/Keyboard.h"
#include "./vector/Vector.h"
#include "./globalVariable.h"
#include "./music/Music.h"
#include "./substance/Substance.h"
#include "./substance/character/Character.h"
#include "./substance/character/player/Player.h"
#include "./substance/character/enemy/Enemy.h"
#include "./substance/bullet/Shot.h"
#include "./substance/bullet/player_shot/Player_shot.h"
#include "./substance/bullet/enemy_shot/Enemy_shot.h"
#include "./substance/item/Item.h"
#include "./fps/Fps.h"
#include "./globalClass.h"
#include "./globalFunction.h"
