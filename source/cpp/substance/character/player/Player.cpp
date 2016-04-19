//#include "..\..\..\..\h\substance\character\player\Player.h"
#include "./../../../../h/global.h"


//float x = 0, y = 0;

void ini(substance* s) {
	substance *sub = s;
	sub[0].x = 0;
	sub[0].y = 0;
	sub[0].z = 0;
	sub[0].flag = TRUE;
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
	float slanting = 1.0;//斜め
	substance *sub;
	sub = getSub();
	if (sub == NULL)OutputDebugStringW(L"ポインタ違う\n");
	if (getSub() == NULL)OutputDebugStringW(L"とりあえず\n");
	sub[0].vx = 0;
	sub[0].vy = 0;
	sub[0].vz = 0;

	if (keyboard.checkKey(KEY_INPUT_Z) > 0) {
		if (keyboard.checkKey(KEY_INPUT_LSHIFT)) {
			sub[0].z += sp_z[0];
		} else {	
			sub[0].z += sp_z[1];
		}
	}

	if (keyboard.getLRFlag() == TRUE && keyboard.getUDFlag() == TRUE) {
		slanting = (float)ROOT2;
	}

	for (int i = 0; i < KEY_MOVE; i++) {
		if (keyboard.checkKey(key[i]) > 0) {
			sub[0].x += sp_x[i] / slanting;
			sub[0].y += sp_y[i] / slanting;
		}
		//ウィンドウ外に行かないようにする
		if (sub[0].x < PLAYER_RANGE_X_MIN) { sub[0].x = PLAYER_RANGE_X_MIN; }
		if (sub[0].x > PLAYER_RANGE_X_MAX) { sub[0].x = PLAYER_RANGE_X_MAX; }
		if (sub[0].y < PLAYER_RANGE_Y_MIN) { sub[0].y = PLAYER_RANGE_Y_MIN; }
		if (sub[0].y > PLAYER_RANGE_Y_MAX) { sub[0].y = PLAYER_RANGE_Y_MAX; }
	}
}