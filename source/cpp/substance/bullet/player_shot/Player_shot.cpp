#include "./../../../../h/global.h"


Player_shot::Player_shot()
{
	mallocSub(1);
}


Player_shot::~Player_shot()
{
}

void Player_shot::shot_regist() {
	substance *sub = player.getSub();
	if (keyboard.checkKey(KEY_INPUT_SPACE) == 1) { 
		substance *_sub = getSub();
		//for (int i = 0; i < getSize(); i++) {
			//if (_sub[i].flag == FALSE){
				/*_sub[i].flag = TRUE;
				_sub[i].x = sub[0].x;
				_sub[i].y = sub[0].y;
				_sub[i].z = sub[0].z;
				_sub[i].vz = 0.1f;*/

				_sub[0].flag = TRUE;
				_sub[0].x = sub[0].x;
				_sub[0].y = sub[0].y;
				_sub[0].z = sub[0].z;
				_sub[0].vz = 0.1f;
				//ショット音のフラグを立てる
				music.se_flag(SHOT_NO);
			//}
		//}
	}
	music.se_play(SHOT_NO);
}

void Player_shot::move() {
	substance *sub = getSub();
	for (int i = 0; i < getSize(); i++){
		if (sub[i].flag == TRUE) {
			sub[i].z += sub[i].vz;
		}
	}
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "x=%.1f y=%.1f z=%.1f", sub.x, sub.y, sub.z);
}