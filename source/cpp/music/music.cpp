#define _CRT_SECURE_NO_WARNINGS

#include "./../../h/global.h"


Music::Music()
{
}


Music::~Music()
{
}

//SE�̏�����
void Music::se_initialization() {
	for (int i = 0; i < SE_NUM; i++) {
		se[i].flag = 0;
	}
}

//SE�̃t���O�𗧂Ă�
void Music::se_flag(int flag) {
	se[flag].flag = TRUE;
}

//SE�Đ�
void Music::se_play(int flag) {
	if (se[flag].flag == TRUE) {
		PlaySoundMem(se[flag].handle, DX_PLAYTYPE_BACK);
	}
}

//BGM�̃��[�h
void Music::load_bgm(int stage, int flag) {
}

//BGM�̍폜
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