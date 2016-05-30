#include "./../../../../h/global.h"


//float x = 0, y = 0;
static const float ROTATE_SPEED = 10.0f * DX_PI_F / 180.0f; //��]�X�s�[�h

void ini(substance* s) {
	substance *sub = s;
	sub[0].x = 0;
	sub[0].y = 0;
	sub[0].z = 0;
	sub[0].flag = true;
	sub[0].vx = 0;
	sub[0].vy = 0;
	sub[0].vz = 0;
}

Player::Player()
{
	mallocSub(1);
	ini(getSub());
	key[0] = KEY_INPUT_LEFT;
	key[1] = KEY_INPUT_RIGHT;
	key[2] = KEY_INPUT_UP;
	key[3] = KEY_INPUT_DOWN;
}


Player::~Player()
{
	free(getSub());
}

void Player::move() {
	float sp_x[KEY_MOVE] = { -0.1f, 0.1f, 0.0f, -0.0f };
	float sp_y[KEY_MOVE] = { -0.0f, 0.0f, 0.1f, -0.1f };
	float sp_z[2] = { -0.1f, 0.1f };
	float slanting = 1.0;//�΂�
	substance *sub;
	sub = getSub();
	if (sub == NULL)OutputDebugStringW(L"�|�C���^�Ⴄ\n");
	if (getSub() == NULL)OutputDebugStringW(L"�Ƃ肠����\n");

	//�����O�̃v���C���[�ƃJ�����̍��W��ۑ�
	VECTOR pre_player = VGet(sub[0].x, sub[0].y, sub[0].z);
	VECTOR pre_camera_pos = camera_pos, pre_camera_look = camera_look;

	if (keyboard.checkKey(KEY_INPUT_Z) > 0) {
		if (keyboard.checkKey(KEY_INPUT_LSHIFT)) {
			sub[0].z += sp_z[0];
		} else {	
			sub[0].z += sp_z[1];
		}
	}

	if (keyboard.getLRFlag() == true && keyboard.getUDFlag() == true) {
		slanting = (float)ROOT2;
	}

	/*
	for (int i = 0; i < KEY_MOVE; i++) {
		if (keyboard.checkKey(key[i]) > 0) {
			sub[0].x += sp_x[i] / slanting;
			sub[0].y += sp_y[i] / slanting;

			camera_pos = VGet(sub[0].x, sub[0].y + 10.0f, sub[0].z - 30); //�J�����̈ʒu
			camera_look = VGet(0.0f, 0.0f, 30.0f); //�J�����̒����_(�J�����̍��W���瑫��������)
			camera_look = VAdd(camera_pos, camera_look);
		}
		//�E�B���h�E�O�ɍs���Ȃ��悤�ɂ���
		if (sub[0].x < PLAYER_RANGE_X_MIN) { sub[0].x = PLAYER_RANGE_X_MIN; }
		if (sub[0].x > PLAYER_RANGE_X_MAX) { sub[0].x = PLAYER_RANGE_X_MAX; }
		if (sub[0].y < PLAYER_RANGE_Y_MIN) { sub[0].y = PLAYER_RANGE_Y_MIN; }
		if (sub[0].y > PLAYER_RANGE_Y_MAX) { sub[0].y = PLAYER_RANGE_Y_MAX; }
	}
	*/

	//�E��������Ă���A�E�Ɉړ�
	if (keyboard.checkKey(KEY_INPUT_RIGHT)) {
		sub[0].vx = 0.1f * cos(-(sub[0].angy - 180.0f) * DX_PI_F / 180.0f);
		sub[0].vz = 0.1f * sin(-(sub[0].angy - 180.0f) * DX_PI_F / 180.0f);
		//sub[0].x += 0.1f * cos((sub[0].angy - 180.0f) * DX_PI_F / 180.0f);
		//sub[0].z += 0.1f * sin((sub[0].angy - 180.0f) * DX_PI_F / 180.0f);
		sub[0].x += sub[0].vx;
		sub[0].z += sub[0].vz;
	}

	//����������Ă���A���Ɉړ�
	if (keyboard.checkKey(KEY_INPUT_LEFT)) {
		sub[0].vx = -0.1f * cos(-(sub[0].angy - 180.0f) * DX_PI_F / 180.0f);
		sub[0].vz = -0.1f * sin(-(sub[0].angy - 180.0f) * DX_PI_F / 180.0f);
		//sub[0].x += -0.1f * cos((sub[0].angy - 180.0f) * DX_PI_F / 180.0f);
		//sub[0].z += -0.1f * sin((sub[0].angy - 180.0f) * DX_PI_F / 180.0f);	
		sub[0].x += sub[0].vx;
		sub[0].z += sub[0].vz;
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "x:%f  z:%f", sub[0].x, sub[0].z);
	DrawFormatString(0, 50, GetColor(255, 255, 255), "vx:%f vz:%f", sub[0].vx, sub[0].vz);

	//���f������������A�J������������悤�ɂ���
	VECTOR player_sub = VSub(VGet(sub[0].x, sub[0].y, sub[0].z), pre_player);
	camera_pos = VAdd(camera_pos, player_sub);
	camera_look = VAdd(camera_look, player_sub);

	//���f������]����
	if (keyboard.checkKey(KEY_INPUT_C)) {
		sub[0].angy += ROTATE_SPEED / DX_PI_F * 180.0f;
	/*�����O��̍��W�̍������߂�*/
	VECTOR player_sub = VSub(VGet(sub[0].x, sub[0].y, sub[0].z), pre_player);//�v���C���[�̑O��̃x�N�g���̍�
	VECTOR p_cp_sub = VSub(pre_camera_pos, pre_player);//�����O�̃J�����̍��W�ƃv���C���[�̍�
	VECTOR p_cl_sub = VSub(pre_camera_look, pre_player);//�����O�̃J�����̒����_�ƃv���C���[�̍�

	//�v���C���[����]���Ă���΁A����ɉ����ăJ�����̍��W�ƒ����_��ς���
	MATRIX matrix = MGetRotY(ROTATE_SPEED);
	camera_pos = VTransform(p_cp_sub, matrix);
	camera_pos = VAdd(camera_pos, VGet(sub[0].x, sub[0].y, sub[0].z));
	camera_look = VTransform(p_cl_sub, matrix);
	camera_look = VAdd(camera_look, VGet(sub[0].x, sub[0].y, sub[0].z));
	/*
	camera_pos = VTransform(camera_pos, matrix);
	camera_pos = VAdd(camera_pos, VGet(sub[0].x, sub[0].y, sub[0].z));
	camera_look = VTransform(camera_look, matrix);
	camera_look = VAdd(camera_look, VGet(sub[0].x, sub[0].y, sub[0].z));
	*/									  
	}
}