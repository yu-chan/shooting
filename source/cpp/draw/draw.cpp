// shooting/source/cpp/draw�̒�

/*
  �摜�̕`��
*/				 
//#include "./../../../DxLib_VC/DxLib.h"
//#include "DxLib.h"
//#include "./../source/h/globalVariable.h"
#include "./../../h/global.h"

//���@�̕`��
void draw_Player() {
	MV1DrawModel(ModelAirCraft);
}

//�G�̕`��
void draw_Enemy() {
	MV1DrawModel(ModelEnemy);
}

void draw() {
	draw_Player();
	draw_Enemy();
}