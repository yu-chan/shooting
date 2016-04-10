#include "./../../../../h/global.h"


Enemy::Enemy()
{
	//substance &sub = *getSub();
	//sub.flag = TRUE;
}


Enemy::~Enemy()
{
}

void Enemy::move() {
	substance &sub = *getSub();
	//character &cha = *getCha();
	if (sub.x < ENEMY_RANGE_X_MIN || sub.x > ENEMY_RANGE_X_MAX) {
		sub.vx *= -1;
	}
	sub.x += sub.vx;
}