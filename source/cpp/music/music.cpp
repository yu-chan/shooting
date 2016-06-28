#define _CRT_SECURE_NO_WARNINGS

#include "./../../h/global.h"

Music::Music() {
	bgm.flag = 0;
	bgm.loop_pos = 26672;
}

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
void Music::load_bgm() {
	char str[64];
	sprintf(str, "./data/music/bgm/stage.mp3");
	bgm.handle = LoadSoundMem(str);
}

//BGMの削除
void Music::delete_bgm() {
	DeleteSoundMem(bgm.handle);
}

void Music::bgm_main() {
	int flag = bgm.flag;
	switch (flag) {
		case 0:
			//load_bgm(0);
			//BGMを読み込む
			load_bgm();

			//ループ位置を設定する
			SetLoopPosSoundMem(bgm.loop_pos, bgm.handle);

			bgm.flag = 1;
			break;
		case 1:
					//ステージカウントが60になったら、BGMを流す
					if (stage_count == 60) {
						//BGMを流す
						PlaySoundMem(bgm.handle, DX_PLAYTYPE_LOOP);
					}
					break;
			break;
		default:
			break;
	}
}