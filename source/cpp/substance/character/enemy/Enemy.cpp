#include "./../../../../h/global.h"


Enemy::Enemy()
{
	mallocSub(1);
	substance *sub = getSub();
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

			//敵がプレイヤーの方への移動量を0.1にする
			p_e_sub = VScale(p_e_sub, 1 / (10 * vsize));

			//角度を求める
			sub[i].angx = acos(p_e_sub.z / vsize);
			sub[i].angy = acos(p_e_sub.x / vsize);
			sub[i].angz = acos(p_e_sub.y / vsize);

			sub[i].x += p_e_sub.x;
			sub[i].y += p_e_sub.y;
			sub[i].z += p_e_sub.z;
			sub[i].count++;
		}
	}
}

void Enemy::enemy_regist() {   
	substance *sub = getSub();

	for (int i = 0; i < getSize(); i++) {
		//敵の出現時間とステージのカウントが同じなら、敵を出現させる
		if (sub[i].aptime == stage_count) {
			sub[i].flag = true;
			sub[i].count = 0;
		}
	}
}