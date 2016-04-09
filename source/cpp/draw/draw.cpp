// shooting/source/cpp/draw‚Ì’†

/*
  ‰æ‘œ‚Ì•`‰æ
*/				 
//#include "./../../../DxLib_VC/DxLib.h"
//#include "DxLib.h"
//#include "./../source/h/globalVariable.h"
#include "./../../h/global.h"

//Ž©‹@‚Ì•`‰æ
void draw_Player() {
	MV1DrawModel(ModelAirCraft);
}

//“G‚Ì•`‰æ
void draw_Enemy() {
	MV1DrawModel(ModelEnemy);
}

void draw() {
	draw_Player();
	draw_Enemy();
}