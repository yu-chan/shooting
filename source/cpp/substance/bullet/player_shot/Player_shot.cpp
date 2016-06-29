#define _CRT_SECURE_NO_WARNINGS

#include "./../../../../h/global.h"



Player_shot::Player_shot()
{
	mallocSub(PLAYER_SHOT_MAX);
	mallocEff(getSize());
	/*if (getSub() == NULL)
		OutputDebugStringW(L"Player_shotでメモリが確保できてない\n");
	else
		OutputDebugStringW(L"Player_shotでメモリが確保されている\n");*/
	memset(getSub(), 0, sizeof(substance) * getSize());
	memset(getEff(), 0, sizeof(effect) * getSize());
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
			if (stage_count != 0 && _sub[i].flag == false){	
				/*OutputDebugStringW(L"Player_shotでメモリがfalse\n");
				sprintf(str, "%d:フラグが%d\n", i, _sub[i].flag);
				OutputDebugString(str);*/
				_sub[i].flag = true;
				_sub[i].x = sub[0].x;
				_sub[i].y = sub[0].y - 2.0f;
				_sub[i].z = sub[0].z;
				_sub[i].vx = 2.0f * sin((sub[0].angy - 180.0f) * DX_PI_F / 180.0f);
				_sub[i].vz = 2.0f * cos((sub[0].angy - 180.0f) * DX_PI_F / 180.0f);
				if (keyboard.checkKey(KEY_INPUT_C)) {
					_sub[i].vx *= 3;
					_sub[i].vz *= 3;
				}
				_sub[i].count = 0;

				//ショット音のフラグを立てる
				music.se_flag(SHOT_NO);

				return;
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

			if (collision_detection(&enemy, enemy.getCha(),  VGet(sub[i].x, sub[i].y, sub[i].z), ENEMY_MODEL_FRAMEINDEX, SHOT_POWER) == true) {
				sub[i].flag = false;
				effect_regist(VGet(sub[i].x, sub[i].y, sub[i].z));
				//OutputDebugStringW(L"Player_shot Hit!!\n");
				continue;
			}

			if (sub[i].count == 100) {
				sub[i].flag = false;
				//OutputDebugStringW(L"Player_shot Vanish!!\n");
			}
		}
	}
}