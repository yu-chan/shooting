#include "./../../../../h/global.h"


Enemy_shot::Enemy_shot()
{
	mallocSub(1);
	memset(getSub(), 0, sizeof(substance) * getSize());
}


Enemy_shot::~Enemy_shot()
{
	free(getSub());
}

void Enemy_shot::shot_regist() {
	substance *sub = enemy.getSub();
	substance player_sub = player.getSub()[0];
	substance *_sub = getSub();

	for (int i = 0; i < enemy.getSize(); i++) {
		//敵が出現してから増えた時間がショットを打つ時間と同じになったら、弾を打つ
		if (sub[i].count % 30 == 0 && sub[i].flag == true) {	
			for (int j = 0; j < getSize(); j++) {
				//ショットのフラグがまだ立ってないなら、登録する
				if (_sub[j].flag == false) {
					//現在の敵とプレイヤーのベクトルを保存
					VECTOR cur_enemy = VGet(sub[i].x, sub[i].y, sub[i].z);
					VECTOR cur_player = VGet(player_sub.x, player_sub.y, player_sub.z);

					//差を求める
					VECTOR p_e_sub = VSub(cur_player, cur_enemy);

					//サイズを求める
					//float vsize = VSize(p_e_sub);

					//移動量を0.2にする
					//p_e_sub = VScale(p_e_sub, 0.2f * 1 / vsize);

					//差ベクトルから角度を求める	   
					float p_e_angy = atan2(p_e_sub.z, p_e_sub.x) / DX_PI_F * 180.0f;
					//float p_e_angy = atan2(p_e_sub.z, p_e_sub.x);

					_sub[j].x = sub[i].x;
					_sub[j].y = sub[i].y + SHOT_ENEMY_Y + 1;
					_sub[j].z = sub[i].z;

					_sub[j].vx = 2.0f * cos(p_e_angy * DX_PI_F / 180.0f);
					_sub[j].vz = 2.0f * sin(p_e_angy * DX_PI_F / 180.0f);
					//_sub[i].vz = -0.1f;

					_sub[j].count = 0;
					_sub[j].flag = true;

					//ショット音のフラグを立てる
					music.se_flag(SHOT_NO);

					//ショット音を立てる
					music.se_play(SHOT_NO);
					break;
				}
				else {
					OutputDebugStringW(L"Enemy_shot true\n");
				}
			}
		}
	}
}

void Enemy_shot::move() {
	substance *sub = getSub();
	for (int i = 0; i < getSize(); i++) {
		if (sub[i].flag == true) {
			sub[i].x += sub[i].vx;
			sub[i].z += sub[i].vz;
			sub[i].count++;
			//DrawFormatString(0, 0, GetColor(255, 255, 255), "count:%d", sub[i].count);

			//相手に当たってるなら、フラグを消す
			/*if (collision_detection(&player, VGet(sub[i].x, sub[i].y + 10, sub[i].z), VGet(sub[i].x, sub[i].y + 10, sub[i].z + 5), ModelAirCraft, PLAYER_MODEL_FRAMEINDEX)) {
				sub[i].flag = false;
			}*/
			/*if (collision_detection(&player, VGet(sub[i].x, sub[i].y + SHOT_ENEMY_Y, sub[i].z + SHOT_ENEMY_Z), ModelAirCraft, PLAYER_MODEL_FRAMEINDEX)) {
				sub[i].flag = false;
			}*/	   
			/*if (collision_detection(&player, VGet(sub[i].x, sub[i].y, sub[i].z), -1) == true) {
				sub[i].flag = false;
				OutputDebugStringW(L"Enemy_shot Hit!!\n");
				continue;
			}*/	     
			if (collision_detection(&player, player.getCha(), VGet(sub[i].x, sub[i].y, sub[i].z), -1, 1) == true) {
				sub[i].flag = false;
				OutputDebugStringW(L"Enemy_shot Hit!!\n");
				continue;
			}

			//範囲外に出たらフラグを消す
			/*if (sub[i].x < SHOT_RANGE_X_MIN || sub[i].x > SHOT_RANGE_X_MAX ||
				sub[i].y < SHOT_RANGE_Y_MIN || sub[i].y > SHOT_RANGE_Y_MAX ||
				sub[i].z < SHOT_RANGE_Z_MIN) {
				sub[i].flag = false;
			}*/

			if (sub[i].count == 100) {
				sub[i].flag = false;
				OutputDebugStringW(L"Enemy_shot Vanish!!\n");
			}
		}
	}
}