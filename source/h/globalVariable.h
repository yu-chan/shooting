// shooting/source/hの中

/*
  ここにグローバル宣言したい変数を書く
*/

#include "./../../DxLib_VC/DxLib.h"

#ifdef GLOBAL_INSTANCE
#define GLOBAL
#else
#define GLOBAL extern
#endif

GLOBAL int ModelAirCraft;