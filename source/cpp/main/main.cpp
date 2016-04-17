// shooting/source/cpp/main�̒�

#define GLOBAL_INSTANCE
//#include "./../../../DxLib_VC/DxLib.h"

#include <windows.h>

#include "DxLib.h"
#include "./../../h/global.h"

//���s���ɃG���[���o����A�Q�[���������I������֐�
int Process_Screen() {
	//�v���Z�X�����ɃG���[���o���Ȃ�A-1��Ԃ�
	if (ProcessMessage() != 0) { 
		return -1;  
	}
	//��ʃN���A�������G���[�Ȃ�A-1��Ԃ�
	if (ClearDrawScreen() != 0) {
		return -1;
	}

	keyboard.updateKey();

	//�G���[���o�ĂȂ��Ȃ�A����Ȃ̂�0��Ԃ�
	return 0;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);


	// �c�w���C�u�����̏�����
	if (DxLib_Init() < 0) {
		//�������Ɏ��s������I��
		return -1;
	}

	//����ʉ�
	if (SetDrawScreen(DX_SCREEN_BACK) != 0) {
		//���s������I��
		return -1;
	}


	//�ŏ��ɂP�x�����f�[�^�����[�h����
	load();

	//�����Ɋ֐���u��
	while (Process_Screen() == 0) {
		//ESC���[�������΋����I��
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}

		music.se_initialization();

		//�v���C���[�𓮂���
		player.move();

		//�v���C���[�̒e�𐶐�
		//player_shot.shot_regist();
		//�v���C���[�̒e�𓮂���
		//player_shot.move();

		//�G�𓮂���
		//enemy.add_count();
		//enemy.move();
		//�G�̒e�𓮂���
		//enemy_shot.shot_regist();
		//enemy_shot.move();

		//���W���Z�b�g
		setPosition();

		//�`��
		draw();

		//BGM�𗬂�
		//music.bgm_main();


		//����ʔ��f
		ScreenFlip();
	}

	//�G���[�������������ɂ�����g����
	//OutputDebugStringW(L"�Ƃ肠����\n");

	// �c�w���C�u�����̌�n��
	DxLib_End();

	//�������̊J��
	keyboard.~Keyboard();

	// �\�t�g�̏I��
	return 0;
}