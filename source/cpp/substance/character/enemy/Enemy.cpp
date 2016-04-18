#include "./../../../../h/global.h"


Enemy::Enemy()
{
	mallocSub(1);
	substance *sub = getSub();
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
	substance *sub = getSub();
	////character &cha = *getCha();
	if (sub[0].x < ENEMY_RANGE_X_MIN || sub[0].x > ENEMY_RANGE_X_MAX) {
		sub[0].vx *= -1;
	}
	sub[0].x += sub[0].vx;
	sub[0].count++;
}

void Enemy::enemy_regist() {

}