// shooting/source/cpp/draw�̒�

/*
  �摜�̕`��
*/
#include "./../../h/global.h"

//���@�̕`��
void draw_Player() {
	/*substance &sub = *player_shot.getSub();
	if (sub.flag == TRUE) {
		MV1DrawModel(ModelAirCraft);
	}*/
	substance *sub;
	sub = player.getS();
	if (sub[0].flag == TRUE)
		MV1DrawModel(ModelAirCraft);
}

//�G�̕`��
void draw_Enemy() {
	/*substance &sub = *player_shot.getSub();
	if (sub.flag == TRUE) {
		MV1DrawModel(ModelEnemy);
	}*/
	substance *sub = enemy.getS();
	if (sub[0].flag == TRUE)
		MV1DrawModel(ModelEnemy);
}

//�v���C���[�e�̕`��
void draw_Player_shot() {
	/*substance &sub = *player_shot.getSub();
	if (sub.flag == TRUE) {
		MV1DrawModel(ModelShot);
	}*/
	MV1DrawModel(ModelPlayerShot);
}

//�G�̒e�̕`��
void draw_Enemy_shot() {
	substance *sub = enemy_shot.getS();
	if (sub[0].flag == TRUE)
		MV1DrawModel(ModelEnemyShot);
}

void draw() {
	draw_Player();
	//draw_Player_shot();
	draw_Enemy();
	draw_Enemy_shot();
}