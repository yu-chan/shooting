// shooting/source/cpp/draw�̒�

/*
  �摜�̕`��
*/
#include "./../../h/global.h" 

//�����̋P�x
static int char_br = 0;
static int charClearOver = 0;
int i = 2;

//�J�����̕`��͈͂����߂�
void setCamera() {
	SetCameraNearFar(CAMERA_MIN, CAMERA_MAX);						 
	SetCameraPositionAndTarget_UpVecY(camera_pos, camera_look);
}

//���@�̕`��
void draw_Player() {
	substance *sub = player.getSub();
	if (sub[0].flag == true) {
		MV1SetPosition(sub[0].MHandle, VGet(sub[0].x, sub[0].y, sub[0].z));
		MV1SetRotationXYZ(sub[0].MHandle, VGet(0.0f, sub[0].angy * DX_PI_F / 180.0f, 0.0f));
		MV1DrawModel(sub[0].MHandle);
	}
}

//�G�̕`��
void draw_Enemy() {
	substance *sub = enemy.getSub();
	for (int i = 0; i < enemy.getSize(); i++) {
		if (sub[i].flag == true) {
			MV1SetPosition(sub[i].MHandle, VGet(sub[i].x, sub[i].y, sub[i].z));
			MV1SetRotationXYZ(sub[i].MHandle,VGet(0.0f, sub[i].angy * DX_PI_F / 180.0f, 0.0f));
			MV1DrawModel(sub[i].MHandle);
		}
	}
}

//�v���C���[�e�̕`��
void draw_Player_shot() {
	substance *sub = player_shot.getSub();
	for (int i = 0; i < player_shot.getSize(); i++) {
		if (sub[i].flag == true) {
			DrawSphere3D(VGet(sub[i].x, sub[i].y + SHOT_PLAYER_Y, sub[i].z), SHOT_CAPSULE_R, SHOT_CAPSULE_DIVNUM, GetColor(0, 255, 255), GetColor(0, 0, 255), TRUE);
		}
	}
}

//�G�̒e�̕`��
void draw_Enemy_shot() {
	substance *sub = enemy_shot.getSub();
	for (int i = 0; i < enemy_shot.getSize(); i++) {
		if (sub[i].flag == true) {
			DrawSphere3D(VGet(sub[i].x, sub[i].y, sub[i].z), SHOT_CAPSULE_R, SHOT_CAPSULE_DIVNUM, GetColor(255, 0, 0), GetColor(255, 0, 0), TRUE);
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

	//�o�̍��W�������_���Ɍ��߂邽�߂ɁA������ݒ�
	unsigned int seed = int(rand() % 1000 + 1);
	srand(0);

	//float range = 20.0f;		  
	float range = 500.0f;
	for (int i = 0; i < dust.getSize(); i++) {
		//�����̂��͓̂_�ŕ`��
		sub[i].x = (float)GetRandom(-DUST_RANGE, DUST_RANGE);
		sub[i].y = (float)GetRandom(-DUST_RANGE, DUST_RANGE);
		sub[i].z = (float)GetRandom(-DUST_RANGE, DUST_RANGE);
		DrawPixel3D(VGet(sub[i].x, sub[i].y, sub[i].z), GetColor(255, 255, 255));

		//�߂��̂��̂͐��ŕ`�� 
		sub[i].x = (float)GetRandom(0, DUST_RANGE);
		sub[i].y = (float)GetRandom(0, DUST_RANGE);
		sub[i].z = (float)GetRandom(0, DUST_RANGE);
		sub[i].x = modulo(-p[0].x + sub[i].x, range) - range * 0.5f;
		sub[i].y = modulo(-p[0].y + sub[i].y, range) - range * 0.5f;
		sub[i].z = modulo(-p[0].z + sub[i].z, range) - range * 0.5f;
		DrawLine3D(VGet(sub[i].x, sub[i].y, sub[i].z), VGet(sub[i].x - p[0].x * (range * 0.001f) + 0.001f, sub[i].y - p[0].y * (range * 0.001f), sub[i].z - p[0].z * (range * 0.001f)), GetColor(255, 255, 255));
	}

	srand(seed);
}

//���f���̕`��
void draw_Planet() {
	substance *sub = planet.getSub();
	DrawSphere3D(VGet(sub[0].x, sub[0].y, sub[0].z), PLANET_R, PLANET_DIVNUM, GetColor(0, 0, 255), GetColor(255, 255, 255), TRUE);
}

//�G�t�F�N�g�̕`��
void draw_Effect() {
	effect* eff = player_shot.getEff();
	for (int i = 0; i < player_shot.getSize(); i++) {
		if (eff[i].flag == true) {
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, eff[i].br);
			DrawSphere3D(VGet(eff[i].x, eff[i].y, eff[i].z), eff[i].r, 8, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		}
	}
}

//Player��HP�̕`��
void draw_Player_HP() {
	character *cha = player.getCha();
	int px = 480, py = 10;
	int addx = 100, addy = 15;
	unsigned int white = GetColor(255, 255, 255), ygreen = GetColor(0, 255, 0);//���A����

	//HP�̕�����\�L
	DrawFormatString(px - 20, py, white, "HP");

	//�l�p�̕`��
	DrawBox(px, py, px + cha[0].hp - 1, py + addy - 1, ygreen, TRUE);

	//�g�̕`��
	DrawLine(px - 1                , py - 1        , px + cha[0].hp_max - 1 , py - 1       , white);//�㉡��
	DrawLine(px - 1                , py - 1        , px - 1                 , py + addy - 1, white);//���c��
	DrawLine(px + cha[0].hp_max - 1, py - 1        , px + cha[0].hp_max - 1 , py + addy    , white);//�E�c��
	DrawLine(px - 1                , py + addy - 1 , px + cha[0].hp_max - 1 , py + addy - 1, white);//������
}

//�^�C�g���̕`��
void draw_Title() {
	int FontHandle = CreateFontToHandle("HGS�n�p�p�߯�ߑ�", 64, 8, DX_FONTTYPE_ANTIALIASING_EDGE);
	char *str = "Space Shooting";
	int Strlen = strlen(str);
	int Width = GetDrawStringWidthToHandle(str, Strlen, FontHandle);

	DrawStringToHandle(320 - Width / 2, 208, str, GetColor(255, 255, 255), FontHandle);


	/*�t�F�[�h�C���A�t�F�[�h�A�E�g*/

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, char_br);
	str = "�X�y�[�X�L�[�������Ă�������";
	Strlen = strlen(str);
	Width = GetDrawStringWidth(str, Strlen);
	DrawString(320 - Width / 2, 280, str, GetColor(255, 255, 255));

	//�u�����h�����ɖ߂�
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	if (char_br > 255 || char_br < 0) {
		i *= -1;
	}
	char_br += i;

	//�t�H���g���폜
	DeleteFontToHandle(FontHandle);
}

//�N���A�̕`��
void draw_GameClear() {
	int FontHandle = CreateFontToHandle("HGS�n�p�p�߯�ߑ�", 64, 8, DX_FONTTYPE_ANTIALIASING_EDGE);
	char *str = "Game Clear!!";
	int Strlen = strlen(str);
	int Width = GetDrawStringWidthToHandle(str, Strlen, FontHandle);

	DrawStringToHandle(320 - Width / 2, 208, str, GetColor(255, 255, 255), FontHandle);


	/*�t�F�[�h�C���A�t�F�[�h�A�E�g*/

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, charClearOver);
	str = "�X�y�[�X�L�[�������΁A������x�v���C�ł��܂�";
	Strlen = strlen(str);
	Width = GetDrawStringWidth(str, Strlen);
	DrawString(320 - Width / 2, 280, str, GetColor(255, 255, 255));

	//�u�����h�����ɖ߂�
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	if (charClearOver > 255 || charClearOver < 0) {
		i *= -1;
	}
	charClearOver += i;

	//�t�H���g���폜
	DeleteFontToHandle(FontHandle);
}

//�Q�[���I�[�o�[�̕`��
void draw_GameOver() {
	int FontHandle = CreateFontToHandle("HGS�n�p�p�߯�ߑ�", 64, 8, DX_FONTTYPE_ANTIALIASING_EDGE);
	char *str = "Game Over....";
	int Strlen = strlen(str);
	int Width = GetDrawStringWidthToHandle(str, Strlen, FontHandle);

	DrawStringToHandle(320 - Width / 2, 208, str, GetColor(255, 255, 255), FontHandle);


	/*�t�F�[�h�C���A�t�F�[�h�A�E�g*/

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, charClearOver);
	str = "�X�y�[�X�L�[�������΁A������x�v���C�ł��܂�";
	Strlen = strlen(str);
	Width = GetDrawStringWidth(str, Strlen);
	DrawString(320 - Width / 2, 280, str, GetColor(255, 255, 255));

	//�u�����h�����ɖ߂�
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	if (charClearOver > 255 || charClearOver < 0) {
		i *= -1;
	}
	charClearOver += i;

	//�t�H���g���폜
	DeleteFontToHandle(FontHandle);
}

void draw() {
	if (play_mode == false) {
		draw_Title();
		if (keyboard.checkKey(KEY_INPUT_SPACE) == 1) {
			play_mode = true;
		}
	}
	else {
		if (over_flag == false) {
			SetUseZBuffer3D(TRUE);
			SetWriteZBuffer3D(TRUE);
			setCamera();
			draw_Planet();
			draw_Dust();
			draw_Player_shot();
			draw_Enemy_shot();
			draw_Player();
			draw_Enemy();
			draw_Effect();
			draw_Player_HP();
			if (clear_flag == true) {
				draw_GameClear();
				if (keyboard.checkKey(KEY_INPUT_SPACE) == 1) {
					play_mode = true;
					initialization();
				}
			}
			
		}
		else {
			draw_GameOver();
			if (keyboard.checkKey(KEY_INPUT_SPACE) == 1) {
				play_mode = true;
				initialization();
			}
		}
	}
}