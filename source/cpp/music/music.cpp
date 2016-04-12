#define _CRT_SECURE_NO_WARNINGS

#include "./../../h/global.h"


Music::Music()
{
}


Music::~Music()
{
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
void Music::load_bgm(int stage, int flag) {
}

//BGMの削除
void Music::delete_bgm() {
}

void Music::bgm_main() {
}

music_ Music::getBgm(int flag) {
	return bgm[flag];
}

music_ Music::getSe(int flag) {
	return se[flag];
}