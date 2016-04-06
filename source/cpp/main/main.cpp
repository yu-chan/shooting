// shooting/source/cpp/main�̒�

#define GLOBAL_INSTANCE
#include "./../../../DxLib_VC/DxLib.h"

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

	//�G���[���o�ĂȂ��Ȃ�A����Ȃ̂�0��Ԃ�
	return 0;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);


	// �c�w���C�u�����̏�����
	if (DxLib_Init() < 0)
	{
		//�������Ɏ��s������I��
		return -1;
	}

	//����ʉ�
	if (SetDrawScreen(DX_SCREEN_BACK) != 0) {
		//���s������I��
		return -1;
	}

	//�����Ɋ֐���u��
	while (Process_Screen() == 0) {
		//ESC���[�������΋����I��
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}

		//����ʔ��f
		ScreenFlip();
	}

	// �R�c��ԏ�ɐ�����`�悷��
	//DrawLine3D(VGet(100.0f, 100.0f, 0.0f), VGet(300.0f, 200.0f, 0.0f), GetColor(255, 255, 255));

	// �L�[���͑҂�������
	WaitKey();

	// �c�w���C�u�����̌�n��
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}