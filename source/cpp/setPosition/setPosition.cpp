// shooting/source/cpp/setPosition�̒�

/*
  �J�����A�摜�A���f���̍��W���Z�b�g����
*/
//#include "./../../../DxLib_VC/DxLib.h"
//#include "DxLib.h"
//#include "./../../h/globalVariable.h"
//#include "./../source/h/define.h"
#include "./../source/h/global.h"

//�J�����̕`��͈͂����߂�
void setCamera() {
	SetCameraNearFar(CAMERA_MIN, CAMERA_MAX);
	SetCameraPositionAndTarget_UpVecY(VGet(0, 10, -20), VGet(0.0f, 10.0f, 0.0f));
}