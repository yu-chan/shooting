// shooting/source/cpp/drawΜ

/*
  ζΜ`ζ
*/				 
//#include "./../../../DxLib_VC/DxLib.h"
//#include "DxLib.h"
//#include "./../source/h/globalVariable.h"
#include "./../../h/global.h"

//©@Μ`ζ
void draw_Player() {
	MV1DrawModel(ModelAirCraft);
}

//GΜ`ζ
void draw_Enemy() {
	MV1DrawModel(ModelEnemy);
}

void draw() {
	draw_Player();
	draw_Enemy();
}