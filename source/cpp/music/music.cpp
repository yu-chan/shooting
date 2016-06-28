#define _CRT_SECURE_NO_WARNINGS

#include "./../../h/global.h"

Music::Music() {
	bgm.flag = 0;
	bgm.loop_pos = 26672;
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
void Music::load_bgm() {
	char str[64];
	sprintf(str, "./data/music/bgm/stage.mp3");
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
			//load_bgm(0);
			//BGM��ǂݍ���
			load_bgm();

			//���[�v�ʒu��ݒ肷��
			SetLoopPosSoundMem(bgm.loop_pos, bgm.handle);

			bgm.flag = 1;
			break;
		case 1:
					//�X�e�[�W�J�E���g��60�ɂȂ�����ABGM�𗬂�
					if (stage_count == 60) {
						//BGM�𗬂�
						PlaySoundMem(bgm.handle, DX_PLAYTYPE_LOOP);
					}
					break;
			break;
		default:
			break;
	}
}