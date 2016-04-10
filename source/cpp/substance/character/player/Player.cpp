//#include "..\..\..\..\h\substance\character\player\Player.h"
#include "./../../../../h/global.h"


float x=0, y=0;
Player::Player()
{
	key[0] = KEY_INPUT_LEFT;
	key[1] = KEY_INPUT_RIGHT;
	key[2] = KEY_INPUT_UP;
	key[3] = KEY_INPUT_DOWN;
	//substance &sub = *getSub();
	//sub.flag = TRUE;
	//sub.flag = FALSE;
}


Player::~Player()
{
}

void Player::move() {
	float sp_x[KEY_MOVE] = { -0.1f, 0.1f, 0.0f, -0.0f };
	float sp_y[KEY_MOVE] = { -0.0f, 0.0f, 0.1f, -0.1f };
	float sp_z[2] = { -0.1f, 0.1f };
	float slanting = 1.0;//斜め
	substance &sub = *getSub();
	sub.vx = 0;
	sub.vy = 0;
	sub.vz = 0;

	if (keyboard.checkKey(KEY_INPUT_Z) > 0) {
		if (keyboard.checkKey(KEY_INPUT_LSHIFT)) {
			sub.z += sp_z[0];
		}
		else {
			sub.z += sp_z[1];
		}
	}

	if (keyboard.getLRFlag() == TRUE && keyboard.getUDFlag() == TRUE) {
		slanting = (float)ROOT2;
	}
	//sub.x += sub.vx;
	//sub.y += sub.vy;

	for (int i = 0; i < KEY_MOVE; i++) {
		if (keyboard.checkKey(key[i]) > 0) {
			sub.x += sp_x[i] / slanting;
			sub.y += sp_y[i] / slanting;
		}
		//ウィンドウ外に行かないようにする
		if (sub.x < PLAYER_RANGE_X_MIN) { sub.x = PLAYER_RANGE_X_MIN; }
		if (sub.x > PLAYER_RANGE_X_MAX) { sub.x = PLAYER_RANGE_X_MAX; }
		if (sub.y < PLAYER_RANGE_Y_MIN) { sub.y = PLAYER_RANGE_Y_MIN; }
		if (sub.y > PLAYER_RANGE_Y_MAX) { sub.y = PLAYER_RANGE_Y_MAX; }
	}

	//DrawFormatString(0, 0, GetColor(255, 255, 255), "x=%.1f y=%.1f z=%.1f", sub.x, sub.y, sub.z);
}
