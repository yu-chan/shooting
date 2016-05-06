#include "./../../../../h/global.h"


Enemy_shot::Enemy_shot()
{
	mallocSub(1);
}


Enemy_shot::~Enemy_shot()
{
	free(getSub());
}

void Enemy_shot::shot_regist() {
	substance *sub = enemy.getSub();
	if (sub[0].count == 30) {
		substance *_sub = getSub();
		_sub[0].x = sub[0].x;
		_sub[0].y = sub[0].y;
		_sub[0].z = sub[0].z;
		_sub[0].vz = -0.1f;
		_sub[0].flag = true;
		//ショット音のフラグを立てる
		music.se_flag(SHOT_NO);
	}
	music.se_play(SHOT_NO);
}

//bool Enemy_shot::collision_detection() {
//	return false;
//}

void Enemy_shot::move() {
	substance *sub = getSub();
	sub[0].z += sub[0].vz;
	sub[0].count++;

	//相手に当たってるなら、フラグを消す
	if (collision_detection(&player, VGet(sub[0].x, sub[0].y + 10, sub[0].z), VGet(sub[0].x, sub[0].y + 10, sub[0].z + 5), ModelAirCraft, PLAYER_MODEL_FRAMEINDEX)) {
		sub[0].flag = false;
	}

	//範囲外に出たらフラグを消す
	if (sub[0].x < SHOT_RANGE_X_MIN || sub[0].x > SHOT_RANGE_X_MAX ||
		sub[0].y < SHOT_RANGE_Y_MIN || sub[0].y > SHOT_RANGE_Y_MAX ||
		sub[0].z < SHOT_RANGE_Z_MIN || sub[0].z > SHOT_RANGE_Z_MAX) {
		sub[0].flag = false;
	}
}