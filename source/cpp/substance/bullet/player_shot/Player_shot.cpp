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
	if (keyboard.checkKey(KEY_INPUT_SPACE)) { 
		substance* _sub = getSub();
		for (int i = 0; i < getSize(); i++) {
			if (_sub[i].flag == FALSE){	
				/*OutputDebugStringW(L"Player_shotでメモリがFALSE\n");
				sprintf(str, "%d:フラグが%d\n", i, _sub[i].flag);
				OutputDebugString(str);*/
				_sub[i].flag = TRUE;
				_sub[i].x = sub[0].x;
				_sub[i].y = sub[0].y;
				_sub[i].z = sub[0].z;
				_sub[i].vz = 0.1f;
				_sub[i].count = 0;

				//ショット音のフラグを立てる
				music.se_flag(SHOT_NO);

				return;
			}
			else {
				/*OutputDebugStringW(L"Player_shotでメモリがTRUE\n");;
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
		if (sub[i].flag == TRUE) {
			sub[i].z += sub[i].vz;
			sub[i].count++;
			
			//範囲外に出たらフラグを消す
			if (sub[i].z < SHOT_RANGE_Z_MIN || sub[i].z > SHOT_RANGE_Z_MAX) {
				sub[i].flag = FALSE;
			}
		}
	}

	//DrawFormatString(0, 0, GetColor(255, 255, 255), "x=%.1f y=%.1f z=%.1f", sub.x, sub.y, sub.z);
}