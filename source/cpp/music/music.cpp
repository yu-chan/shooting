#define _CRT_SECURE_NO_WARNINGS

#include "./../../h/global.h"


//SEの初期化
void Music::se_initialization() {
	for (int i = 0; i < SE_NUM; i++) {
		se[i].flag = 0;
	}
}

//SEのフラグを立てる
void Music::se_flag(int flag) {
	se[flag].flag = TRUE;
}

//SE再生
void Music::se_play(int flag) {
	if (se[flag].flag == TRUE) {
		PlaySoundMem(se[flag].handle, DX_PLAYTYPE_BACK);
	}
}

//BGMのロード
void Music::load_bgm(int stage, int flag) {
	char str[64];
	sprintf(str, "./data/music/bgm/stage%d_%d.mp3", stage, flag);
	bgm[stage].handle = LoadSoundMem(str);
}

//BGMの削除
void Music::delete_bgm(int stage) {
	DeleteSoundMem(bgm[stage].handle);
}

void Music::bgm_main() {
	int flag = bgm[stage_num].flag;
	switch (flag) {
		case 0:
			load_bgm(stage_num, 0);
			SetLoopPosSoundMem(bgm[stage_num].loop_pos[0], bgm[stage_num].handle);
			bgm[stage_num].flag = 1;
			break;
		case 1:
			switch (bgm[stage_num].knd[0]) {
				case 0:
					if (stage_count == 60) {
						PlaySoundMem(bgm[stage_num].handle, DX_PLAYTYPE_LOOP);
						bgm[stage_num].flag = 2;
					}
					break;
				default:
					break;
			}
			break;
		case 2:
			/*
			60はいずれ変える	 
			*/
			if (stage_count == 60) {
				StopSoundMem(bgm[stage_num].handle);
				delete_bgm(stage_num);
				load_bgm(stage_num, 1);
				SetLoopPosSoundMem(bgm[stage_num].loop_pos[1], bgm[stage_num].handle);
				bgm[stage_num].flag = 3;
			}
			break;
		case 3:
			switch (bgm[stage_num].knd[0]) {
				case 0:
					/*
					60はいずれ変える
					*/
					if (stage_count == 60) {
						PlaySoundMem(bgm[stage_num].handle, DX_PLAYTYPE_LOOP);
						bgm[stage_num].flag = 4;
					}
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
}