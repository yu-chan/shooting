#include "./../../../../h/global.h"


Enemy::Enemy()
{
	mallocSub(1);
	substance *sub = getSub();
	//sub[0].x = 0;
	//sub[0].y = 0;
	//sub[0].z = 20;
	//sub[0].vx = 0.1f;
	//sub[0].count = 0;
	//sub[0].flag = true;
}


Enemy::~Enemy()
{
	free(getSub());
}

void Enemy::move() {
	substance *sub = getSub();
	////character &cha = *getCha();
	for (int i = 0; i < getSize(); i++) {
		if (sub[i].flag == true) {
			if (sub[i].x < ENEMY_RANGE_X_MIN || sub[i].x > ENEMY_RANGE_X_MAX) {
				sub[i].vx *= -1;
			}
			sub[i].x += sub[i].vx;
			sub[i].count++;
			//DrawFormatString(0, 0, GetColor(255, 255, 255), "count:%d", sub[i].count);
		}
	}
}

void Enemy::enemy_regist() {   
	substance *sub = getSub();

	for (int i = 0; i < getSize(); i++) {
		//敵の出現時間とステージのカウントが同じなら、敵を出現させる
		if (sub[i].aptime == stage_count) {
			sub[i].flag = true;
			sub[i].vx = 0.1f;
			sub[i].count = 0;
		}
	}
}