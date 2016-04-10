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
	/*substance _sub, *sub = player.getSub();
	_sub = *sub;*/
	substance &sub = *player.getSub();
	MV1SetPosition(ModelAirCraft, VGet(sub.x, sub.y, sub.z));
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "x=%.1f y=%.1f z=%.1f", sub.x, sub.y, sub.z);
}

//�G�̈ʒu���Z�b�g
void setPosition_Enemy() {
	/*substance _sub, *sub = enemy.getSub();
	_sub = *sub;*/
	substance &sub = *enemy.getSub();
	MV1SetPosition(ModelEnemy, VGet(sub.x, sub.y, sub.z));
}

//�v���C���[�e�̂������Z�b�g
void setPosition_Player_shot() {
	substance &sub = *player_shot.getSub();
	MV1SetPosition(ModelShot, VGet(sub.x, sub.y, sub.z));
}

void setPosition() {
	setCamera();
	setPosition_Player();
	setPosition_Player_shot();
	setPosition_Enemy();
}
