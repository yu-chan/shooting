#define _CRT_SECURE_NO_WARNINGS

#include "./../../h/global.h"


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
void Music::load_bgm(int flag) {
	char str[64];
	sprintf(str, "./data/music/bgm/stage%d_%d.mp3", 0, flag);
	bgm.handle = LoadSoundMem(str);
}

//BGM�̍폜
void Music::delete_bgm() {
	DeleteSoundMem(bgm.handle);
}

void Music::bgm_main() {
	int flag = bgm.flag;
	switch (flag) {
		case 0:
			load_bgm(0);
			SetLoopPosSoundMem(bgm.loop_pos[0], bgm.handle);
			bgm.flag = 1;
			break;
		case 1:
			switch (bgm.knd[0]) {
				case 0:
					if (stage_count == 60) {
						PlaySoundMem(bgm.handle, DX_PLAYTYPE_LOOP);
						bgm.flag = 2;
					}
					break;
				default:
					break;
			}
			break;
		case 2:
			/*
			60�͂�����ς���	 
			*/
			if (stage_count == 60) {
				StopSoundMem(bgm.handle);
				delete_bgm();
				load_bgm(1);
				SetLoopPosSoundMem(bgm.loop_pos[1], bgm.handle);
				bgm.flag = 3;
			}
			break;
		case 3:
			switch (bgm.knd[0]) {
				case 0:
					/*
					60�͂�����ς���
					*/
					if (stage_count == 60) {
						PlaySoundMem(bgm.handle, DX_PLAYTYPE_LOOP);
						bgm.flag = 4;
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