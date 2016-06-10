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

			/*座標*/
			//動く前の敵、プレイヤーの座標を保存
			VECTOR pre_enemy = VGet(sub[i].x, sub[i].y, sub[i].z);
			VECTOR pre_player = VGet(sub_[0].x, sub_[0].y, sub_[0].z);

			//プレイヤーと敵のベクトルの差
			VECTOR p_e_sub = VSub(pre_player, pre_enemy);

			//ベクトルのサイズを求める
			float vsize = VSize(p_e_sub);

			//敵がプレイヤーの方への移動量を0.1にする
			p_e_sub = VScale(p_e_sub, 1 / (10 * vsize));

			sub[i].x += p_e_sub.x;
			sub[i].y += p_e_sub.y;
			sub[i].z += p_e_sub.z;
			DrawFormatStringF(0.0f, 60.0f, GetColor(255, 255, 255), "Enemy 位置X : %f 位置Z : %f", sub[i].x, sub[i].z);


			/*角度*/
			//動く前の角度yを保存
			float pre_angy = sub[i].angy;

			//差ベクトルから角度yを求める
			float p_e_angy = atan2(p_e_sub.z, p_e_sub.x) / DX_PI_F * 180.0f;
			DrawFormatStringF(0.0f, 0.0f, GetColor(255, 255, 255), "ベクトル角度Y : %f", p_e_angy);

			//角度yの差分を求める
			float angy_sub = p_e_angy - pre_angy;
			DrawFormatStringF(0.0f, 20.0f, GetColor(255, 255, 255), "差角度Y : %f", angy_sub);

			//角度を求める
			//sub[i].angx = acos(p_e_sub.z / vsize);
			//sub[i].angy += angy_sub;
			//sub[i].angy += angy_sub;
			sub[i].angy = p_e_angy - 90.0f;
			//sub[i].angz = acos(p_e_sub.y / vsize);
			DrawFormatStringF(0.0f, 80.0f, GetColor(255, 255, 255), "Enemy角度Y : %f", sub[i].angy);

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