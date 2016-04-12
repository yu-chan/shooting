#include "./../../../../h/global.h"


Player_shot::Player_shot()
{
	substance &sub = *getSub();
	//sub.vy = 0.1f;
	//sub.flag = TRUE;
}


Player_shot::~Player_shot()
{
}

void Player_shot::shot_regist() {
	//substance &sub = *getSub();
	//sub.vy = 0.1f;
	if (keyboard.checkKey(KEY_INPUT_SPACE) == 1) { 
		substance &sub = *getSub();
		sub.vz = 0.1f;
		//ショット音のフラグを立てる
		music.se_flag(SHOT_NO);
	}
	music.se_play(SHOT_NO);
}

void Player_shot::move() { 
	substance &sub = *getSub();
	sub.z += sub.vz;
	/*if (sub.y < ENEMY_RANGE_Y_MIN || sub.y > ENEMY_RANGE_Y_MAX) {
		sub.vy *= -1;
	}
	sub.y += sub.vy;*/
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "x=%.1f y=%.1f z=%.1f", sub.x, sub.y, sub.z);
}