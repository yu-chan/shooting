// shooting/source/cpp/draw�̒�

/*
  �摜�̕`��
*/
#include "./../../h/global.h" 

//�J�����̕`��͈͂����߂�
void setCamera() {
	//substance *sub = player.getSub();
	//camera_pos = VGet(sub[0].x, sub[0].y + 10.0f, sub[0].z - 30); //�J�����̈ʒu
	//camera_look = VGet(0.0f, 0.0f, 30.0f); //�J�����̒����_(�J�����̍��W���瑫��������)
	//camera_look = VAdd(camera_pos, camera_look);
	SetCameraNearFar(CAMERA_MIN, CAMERA_MAX);
	//SetCameraPositionAndTarget_UpVecY(VGet(sub[0].x, sub[0].y + 10, sub[0].z - 30), VGet(0.0f, 10.0f, 0.0f));
	//SetCameraPositionAndTarget_UpVecY(VGet(0.0f, 10.0f, -30), VGet(0.0f, 0.0f, 0.0f));						 
	SetCameraPositionAndTarget_UpVecY(camera_pos, camera_look);
	//DrawPixel3D(camera_look, GetColor(255, 0, 0));
	//SetCameraPositionAndTarget_UpVecY(VGet(0, 20, -50), VGet(0.0f, 10.0f, 0.0f));				
	//SetCameraPositionAndTarget_UpVecY(VGet(sub[0].x, sub[0].y + 20, sub[0].z - 50), VGet(0.0f, 10.0f, 0.0f));
	//SetCameraPositionAndTarget_UpVecY(VGet(0.0f, 200.0f, 0), VGet(0.0f, 0.0f, 0.0f));
}

//���@�̕`��
void draw_Player() {
	substance *sub = player.getSub();
	if (sub[0].flag == true) {
		//MV1SetPosition(ModelAirCraft, VGet(sub[0].x, sub[0].y, sub[0].z));
		//MV1SetRotationXYZ(ModelAirCraft, VGet(0.0f, sub[0].angy * DX_PI_F / 180.0f, 0.0f));
		//MV1SetRotationXYZ(ModelAirCraft, VGet(0.0f, sub[0].angy, 0.0f));
		//MV1DrawModel(ModelAirCraft);

		MV1SetPosition(sub[0].MHandle, VGet(sub[0].x, sub[0].y, sub[0].z));
		MV1SetRotationXYZ(sub[0].MHandle, VGet(0.0f, sub[0].angy * DX_PI_F / 180.0f, 0.0f));
		//MV1SetRotationXYZ(ModelAirCraft, VGet(0.0f, sub[0].angy, 0.0f));
		MV1DrawModel(sub[0].MHandle);
	}
}

//�G�̕`��
void draw_Enemy() {
	substance *sub = enemy.getSub();
	for (int i = 0; i < enemy.getSize(); i++) {
		if (sub[i].flag == true) {
			//MV1SetPosition(ModelEnemy, VGet(sub[i].x, sub[i].y, sub[i].z));
			//MV1DrawModel(ModelEnemy);
			MV1SetPosition(sub[i].MHandle, VGet(sub[i].x, sub[i].y, sub[i].z));
			MV1DrawModel(sub[i].MHandle);
		}
	}
}

//�v���C���[�e�̕`��
void draw_Player_shot() {
	substance *sub = player_shot.getSub();
	for (int i = 0; i < player_shot.getSize(); i++) {
		if (sub[i].flag == true) {
			//MV1SetPosition(ModelPlayerShot, VGet(sub[i].x, sub[i].y, sub[i].z));
			//MV1DrawModel(ModelPlayerShot);
			//DrawCapsule3D(VGet(sub[i].x, sub[i].y + SHOT_PLAYER_Y, sub[i].z), VGet(sub[i].x, sub[i].y + SHOT_PLAYER_Y, sub[i].z + 5), SHOT_CAPSULE_R, SHOT_CAPSULE_DIVNUM, GetColor(0, 0, 255), GetColor(255, 255, 255), TRUE);
			DrawSphere3D(VGet(sub[i].x, sub[i].y + SHOT_PLAYER_Y, sub[i].z), SHOT_CAPSULE_R, SHOT_CAPSULE_DIVNUM, GetColor(0, 255, 255), GetColor(0, 0, 255), TRUE);
		}
	}
	//DrawCapsule3D(VGet(15, 10, 0), VGet(15, 10, 5), SHOT_CAPSULE_R, SHOT_CAPSULE_DIVNUM, GetColor(0, 0, 255), GetColor(255, 255, 255), TRUE);
}

//�G�̒e�̕`��
void draw_Enemy_shot() {
	substance *sub = enemy_shot.getSub();
	for (int i = 0; i < enemy_shot.getSize(); i++) {
		if (sub[i].flag == true) {
			//MV1SetPosition(ModelEnemyShot, VGet(sub[i].x, sub[i].y, sub[i].z));
			//MV1DrawModel(ModelEnemyShot);
			//DrawCapsule3D(VGet(sub[i].x, sub[i].y + 10, sub[i].z), VGet(sub[i].x, sub[i].y + 10, sub[i].z + 5), SHOT_CAPSULE_R, SHOT_CAPSULE_DIVNUM, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);
			//DrawSphere3D(VGet(sub[i].x, sub[i].y + SHOT_PLAYER_Y, sub[i].z), SHOT_CAPSULE_R, SHOT_CAPSULE_DIVNUM, GetColor(255, 0, 0), GetColor(255, 0, 0), TRUE);
			DrawSphere3D(VGet(sub[i].x, sub[i].y + SHOT_ENEMY_Y, sub[i].z + SHOT_ENEMY_Z), SHOT_CAPSULE_R, SHOT_CAPSULE_DIVNUM, GetColor(255, 0, 0), GetColor(255, 0, 0), TRUE);
		}
	}
}

//�����͈̔͂����߂�
int GetRandom(int min, int max) {
	return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}

//a��b�Ŋ������]���Ԃ�
float modulo(float a, float b) {
	return a - floorf(a / b) * b;
}

//�o�̕`��
void draw_Dust() {
	substance *sub = dust.getSub();
	substance *p = player.getSub();
	//�������������ƂɌ��߂�
	srand((unsigned)time(NULL));

	//�o�̍��W�������_���Ɍ��߂邽�߂ɁA������ݒ�
	int seed = int(rand() % 1000);
	float range = 20.0f;
	for (int i = 0; i < dust.getSize(); i++) {
		//�����̂��͓̂_�ŕ`��
		sub[i].x = (float)GetRandom(-DUST_RANGE, DUST_RANGE);
		sub[i].y = (float)GetRandom(-DUST_RANGE, DUST_RANGE);
		sub[i].z = (float)GetRandom(-DUST_RANGE, DUST_RANGE);
		DrawPixel3D(VGet(sub[i].x, sub[i].y, sub[i].z), GetColor(255, 255, 255));

		//�߂��̂��̂͐��ŕ`��
		sub[i].x = modulo(-p[0].x + sub[i].x, range) - range * 0.5f;
		sub[i].y = modulo(-p[0].y + sub[i].y, range) - range * 0.5f;
		sub[i].z = modulo(-p[0].z + sub[i].z, range) - range * 0.5f;
		DrawLine3D(VGet(sub[i].x, sub[i].y, sub[i].z), VGet(sub[i].x - p[0].x * (range * 0.001f) + 0.001f, sub[i].y - p[0].y * (range * 0.001f), sub[i].z - p[0].z * (range * 0.001f)), GetColor(255, 255, 255));
	}
}

//���f���̕`��
void draw_Planet() {
	substance *sub = planet.getSub();
	DrawSphere3D(VGet(sub[0].x, sub[0].y, sub[0].z), PLANET_R, PLANET_DIVNUM, GetColor(0, 0, 255), GetColor(255, 255, 255), TRUE);
}

void draw() {
	setCamera();
	draw_Planet();
	draw_Dust();
	draw_Player_shot();
	draw_Enemy_shot();
	draw_Player();
	draw_Enemy();
	//DrawLine3D(VGet(100.0f, 100.0f, 0.0f), VGet(300.0f, 200.0f, 0.0f), GetColor(255, 255, 255));
}