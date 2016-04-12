#include "./../../../../h/global.h"


Enemy_shot::Enemy_shot()
{
	//substance &sub = *getSub();
	//sub.flag = TRUE;
}


Enemy_shot::~Enemy_shot()
{
}

void Enemy_shot::shot_regist() {
	substance &sub = *enemy.getSub();
	//DrawFormatString(0, 50, GetColor(255, 255, 255), "count=%d", sub.count);
	if (sub.count == 30) {
		substance &_sub = *getSub();
		_sub.x = sub.x;
		_sub.y = sub.y;
		_sub.z = sub.z;
		_sub.vz = 0.1f;
		//ショット音のフラグを立てる
		music.se_flag(SHOT_NO);
	}
	music.se_play(SHOT_NO);
}

void Enemy_shot::move() {
	substance &sub = *getSub();
	sub.z += sub.vz;
}