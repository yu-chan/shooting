#include "./../../../../h/global.h"


Enemy::Enemy()
{
	//substance &sub = *getSub();
	//sub.flag = TRUE;
	mallocS(1);
	substance *sub = getS();
	sub[0].x = 0;
	sub[0].y = 0;
	sub[0].z = 0;
	sub[0].vx = 0.1f;
	sub[0].count = 0;
	sub[0].flag = TRUE;
}


Enemy::~Enemy()
{
}

void Enemy::move() {
	substance *sub = getS();
	//substance &sub = *getSub();
	////character &cha = *getCha();
	if (sub[0].x < ENEMY_RANGE_X_MIN || sub[0].x > ENEMY_RANGE_X_MAX) {
		sub[0].vx *= -1;
	}
	sub[0].x += sub[0].vx;
	sub[0].count++;
	//sub.x += sub.vx;
}

void Enemy::enemy_regist() {

}