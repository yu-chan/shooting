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
	substance *sub_ = player.getSub();
	////character &cha = *getCha();
	for (int i = 0; i < getSize(); i++) {
		if (sub[i].flag == true) {
			//動く前の敵、プレイヤーの座標を保存
			VECTOR pre_enemy = VGet(sub[i].x, sub[i].y, sub[i].z);
			VECTOR pre_player = VGet(sub_[0].x, sub_[0].y, sub_[0].z);

			//プレイヤーと敵のベクトルの差
			VECTOR p_e_sub = VSub(pre_player, pre_enemy);

			//ベクトルのサイズを求める
			float vsize = VSize(p_e_sub);

			//敵がプレイヤーの方への移動量を1にする
			p_e_sub = VScale(p_e_sub, 1 / (10 * vsize));

			sub[i].x += p_e_sub.x;
			sub[i].y += p_e_sub.y;
			sub[i].z += p_e_sub.z;

			/*if (sub[i].x < ENEMY_RANGE_X_MIN || sub[i].x > ENEMY_RANGE_X_MAX) {
				sub[i].vx *= -1;
			}
			sub[i].x += sub[i].vx;
			sub[i].count++;*/
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