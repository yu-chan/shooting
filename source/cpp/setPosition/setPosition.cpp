// shooting/source/cpp/setPosition�̒�

/*
  �J�����A�摜�A���f���̍��W���Z�b�g����
*/
#include "./../../h/global.h"

//�J�����̕`��͈͂����߂�
void setCamera() {
	SetCameraNearFar(CAMERA_MIN, CAMERA_MAX);
	SetCameraPositionAndTarget_UpVecY(VGet(0, 10, -20), VGet(0.0f, 10.0f, 0.0f));
}

//�v���C���[�̈ʒu���Z�b�g
void setPosition_Player() {
	substance *sub;
	sub = player.getSub();
	MV1SetPosition(ModelAirCraft, VGet(sub[0].x, sub[0].y, sub[0].z));
}

//�G�̈ʒu���Z�b�g
void setPosition_Enemy() {
	substance *sub = enemy.getSub();
	MV1SetPosition(ModelEnemy, VGet(sub[0].x, sub[0].y, sub[0].z));
}

//�v���C���[�e�̈ʒu���Z�b�g
void setPosition_Player_shot() {
	substance *sub = player_shot.getSub();
	MV1SetPosition(ModelPlayerShot, VGet(sub[0].x, sub[0].y, sub[0].z));
}

//�G�̒e�̈ʒu���Z�b�g
void setPosition_Enemy_shot() {
	substance *sub = enemy_shot.getSub();
	MV1SetPosition(ModelEnemyShot, VGet(sub[0].x, sub[0].y, sub[0].z));
}

void setPosition() {
	setCamera();
	setPosition_Player();
	setPosition_Player_shot();
	setPosition_Enemy();
	setPosition_Enemy_shot();
}
