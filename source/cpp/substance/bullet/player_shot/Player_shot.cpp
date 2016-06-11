#define _CRT_SECURE_NO_WARNINGS

#include "./../../../../h/global.h"



Player_shot::Player_shot()
{
	mallocSub(PLAYER_SHOT_MAX);
	/*if (getSub() == NULL)
		OutputDebugStringW(L"Player_shotでメモリが確保できてない\n");
	else
		OutputDebugStringW(L"Player_shotでメモリが確保されている\n");*/
	memset(getSub(), 0, sizeof(substance) * getSize());
}


Player_shot::~Player_shot()
{
	free(getSub());
}

void Player_shot::shot_regist() {
	substance* sub = player.getSub();
	//char str[256];
	if (keyboard.checkKey(KEY_INPUT_SPACE)==1) { 
		substance* _sub = getSub();
		for (int i = 0; i < getSize(); i++) {
			if (_sub[i].flag == false){	
				/*OutputDebugStringW(L"Player_shotでメモリがfalse\n");
				sprintf(str, "%d:フラグが%d\n", i, _sub[i].flag);
				OutputDebugString(str);*/
				_sub[i].flag = true;
				_sub[i].x = sub[0].x;
				_sub[i].y = sub[0].y;
				_sub[i].z = sub[0].z;
				_sub[i].vx = 0.2f * sin((sub[0].angy - 180.0f) * DX_PI_F / 180.0f);
				_sub[i].vz = 0.2f * cos((sub[0].angy - 180.0f) * DX_PI_F / 180.0f);
				_sub[i].count = 0;

				//ショット音のフラグを立てる
				music.se_flag(SHOT_NO);

				return;
			}
			else {
				/*OutputDebugStringW(L"Player_shotでメモリがtrue\n");;
				sprintf(str, "%d:フラグが%d\n", i, _sub[i].flag);
				OutputDebugString(str);*/
			}
		}
	}
	music.se_play(SHOT_NO);
}

void Player_shot::move() {
	substance *sub = getSub();
	for (int i = 0; i < getSize(); i++){
		if (sub[i].flag == true) {
			sub[i].x += sub[i].vx;
			sub[i].z += sub[i].vz;
			sub[i].count++;

			//相手に当たってるならフラグを0にする
			/*if (collision_detection(&enemy, VGet(sub[i].x, sub[i].y + SHOT_PLAYER_Y, sub[i].z), VGet(sub[i].x, sub[i].y + 10, sub[i].z + 5), ModelEnemy, ENEMY_MODEL_FRAMEINDEX)) {
				sub[i].flag = false;
			}*/
			/*if (collision_detection(&enemy, VGet(sub[i].x, sub[i].y + SHOT_PLAYER_Y, sub[i].z), ModelEnemy, ENEMY_MODEL_FRAMEINDEX)) {
				sub[i].flag = false;
				OutputDebugStringW(L"Player_shot Hit!!\n");
			}*/
			if (collision_detection(&enemy, VGet(sub[i].x, sub[i].y + SHOT_PLAYER_Y, sub[i].z), ENEMY_MODEL_FRAMEINDEX)) {
				sub[i].flag = false;
				OutputDebugStringW(L"Player_shot Hit!!\n");
			}
			
			//範囲外に出たらフラグを消す
			/*if (sub[i].x < SHOT_RANGE_X_MIN || sub[i].x > SHOT_RANGE_X_MAX ||
				sub[i].y < SHOT_RANGE_Y_MIN || sub[i].y > SHOT_RANGE_Y_MAX ||
				sub[i].z < SHOT_RANGE_Z_MIN || sub[i].z > SHOT_RANGE_Z_MAX) {
				sub[i].flag = false;
				OutputDebugStringW(L"Player_shot Vanish!!\n");
			}*/

			/*if (sub[i].count >= 50) {
				sub[i].flag = false;
				OutputDebugStringW(L"Player_shot Vanish!!\n");
			}*/
		}
	}
}