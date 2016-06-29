#include "./../../../../h/global.h"



Enemy::Enemy()
{
	mallocSub(ENEMY_NUM);
	mallocCha(getSize());
}


Enemy::~Enemy()
{
	free(getSub());
	free(getCha());
}

void Enemy::move() {
	substance *sub = getSub();
	substance *sub_ = player.getSub();
	character *cha = getCha();

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
			p_e_sub = VScale(p_e_sub, 1 / (3 * vsize));	

			sub[i].x += p_e_sub.x;
			sub[i].y += p_e_sub.y;
			sub[i].z += p_e_sub.z;

			for (int j = 0; j < getSize(); j++) {
				if (j == i) {
					OutputDebugStringW(L"一緒\n");
					continue;
				}
				if (sub[j].flag == false) {
					OutputDebugStringW(L"まだ作られてない\n");
					continue;
				}

				/*別の敵と当たりそうなら、座標を元に戻す */
				MV1SetupCollInfo(sub[j].MHandle, -1, 8, 8, 8);
				MV1_COLL_RESULT_POLY_DIM Hit = MV1CollCheck_Sphere(sub[j].MHandle, -1, VGet(sub[i].x, sub[i].y, sub[i].z), 7);
				if (Hit.HitNum >= 1) {
					OutputDebugStringW(L"enemy同士が当たってる\n");
					sub[i].x = pre_enemy.x;
					sub[i].y = pre_enemy.y;
					sub[i].z = pre_enemy.z;
					//当たり判定情報の後始末
					//MV1CollResultPolyDimTerminate(Hit);
					//break;
				}

				//当たり判定情報の後始末
				MV1CollResultPolyDimTerminate(Hit);
			}


			/*角度*/
			//動く前の角度yを保存
			float pre_angy = sub[i].angy;

			//差ベクトルから角度yを求める
			float p_e_angy = atan2(p_e_sub.z, p_e_sub.x) / DX_PI_F * 180.0f;

			//角度yの差分を求める
			float angy_sub = p_e_angy - pre_angy;

			//角度を求める
			sub[i].angy = 90.0f - p_e_angy;

			sub[i].count++;
		}
	}
}

void Enemy::enemy_regist() {   
	substance *sub = getSub();

	srand((unsigned)time(NULL));

	for (int i = 0; i < getSize(); i++) {
		//敵の出現時間とステージのカウントが同じなら、敵を出現させる

		//100カウントごとに、１体ずつ登録
		if (stage_count != 0 && stage_count % 100 == 0 && sub[i].flag == false && sub[i].fall_flag == false) {
			OutputDebugStringW(L"enemy作った\n");
			sub[i].flag = true;
			sub[i].x = (float)GetRandom(-100, 100);
			sub[i].y = 0;
			sub[i].z = (float)GetRandom(-100, 100);
			sub[i].count = 0;
			break;
		}
	}
	srand(0);
}