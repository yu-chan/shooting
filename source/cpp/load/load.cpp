// shooting/source/cpp/load�̒�

/*
  �摜�A3D���f���A���y�Acsv�t�@�C�������[�h����
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>
#include <WinBase.h>
#include "./../../h/global.h"

using namespace std;

//3D���f����ǂݍ���
void load_3DModel() {
	/* ./../../../������Ɠǂݍ��߂Ȃ�
	�@�����炭�AMV1LoadModel�̓v���W�F�N�g�t�@�C�����p�X�̍ŏ��̈ʒu�Ɏw�肵�A
	 �@�������N�_�ɓǂݍ���ł���Ǝv����
	  �����܂Ŏ����̐�������...
	*/
	substance *sub;

	//���@�̓ǂݍ���
	sub = player.getSub();
	sub[0].MHandle = MV1LoadModel("./data/3dModel/Player/AircraftFuselage.mv1");  //�傫�� x:182*4 y:�킩��� z:182*11	 
	//���f�����傫������̂ŁA����������
	MV1SetScale(sub[0].MHandle, VGet(0.01f, 0.01f, 0.01f));
	//���f���̐�[���v���C���[���Ɍ����Ă�̂ŁAY����180�x��]���� 
	MV1SetRotationXYZ(sub[0].MHandle, VGet(0.0f, player.getSub()[0].angy * DX_PI_F / 180.0f, 0.0f));


	//�G�̓ǂݍ���
	sub = enemy.getSub();
	ModelEnemy = MV1LoadModel("./data/3dModel/Enemy/enemy.mqo"); //�傫�� x:26*10 y:�킩��� z:26*
	for (int i = 0; i < enemy.getSize(); i++) {
		sub[i].MHandle = MV1DuplicateModel(ModelEnemy);
		//���f���̃T�C�Y������������
		MV1SetScale(sub[i].MHandle, VGet(0.05f, 0.05f, 0.05f));
	}
}

//SE��ǂݍ���
void load_se() {
	char str[64];
	for (int i = 0; i < SE_NUM; i++) {
		sprintf(str, "./data/music/se/se%d.wav", i);
		music.se[i].handle = LoadSoundMem(str);
	}
}

void load() {
	load_3DModel();
	load_se();
}
