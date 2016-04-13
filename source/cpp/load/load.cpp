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
	//���@�̓ǂݍ���
	//ModelAirCraft = MV1LoadModel("./data/3D Model/Vehicles/Aircraft/Models/AircraftFuselage.x");
	ModelAirCraft = MV1LoadModel("./data/3dModel/Lat���~�N/Lat���~�NVer2.3_Normal.pmd");

	//�G�̓ǂݍ���
	ModelEnemy = MV1LoadModel("./data/3dModel/Lat���~�N/Lat���~�NVer2.3_Normal.pmd");

	//�V���b�g�̓ǂݍ���
	ModelPlayerShot = MV1LoadModel("./data/3dModel/Lat���~�N/Lat���~�NVer2.3_Normal.pmd");
	ModelEnemyShot = MV1LoadModel("./data/3dModel/Lat���~�N/Lat���~�NVer2.3_Normal.pmd");
}

//�G�̈ʒu���A�s���p�^�[���A�X�e�[�^�X��ǂݍ���
void load_EnemyCsv() {
	int n = 0, num = 0, fp;
	char path[PATH_SIZE] = { "./../../../data/csv/Enemy/enemy0.csv" };
	int input[PATH_SIZE];
	char inputc[PATH_SIZE];

	//�t�@�C���̓ǂݍ���
	fp = FileRead_open(path);

	//�t�@�C�����Ȃ�������I��
	if (fp == NULL) return;

	//�e�f�[�^�̎擾
	while (TRUE) {
		for (int i = 0; i < PATH_SIZE; i++) {
			inputc[i] = input[i] = FileRead_getc(fp);//�P�����擾

			/*�J���}�����s�Ȃ�A�����܂ł𕶎���Ƃ��ēǂݍ���*/
			if (input[i] == ',' || input[i] == '\n') {
				inputc[i] = '\0';
				break;
			}

			//�t�@�C���̏I���Ȃ�I��
			if (input[i] == EOF) return;
		}

		//���ꂼ��̃f�[�^���i�[
		/*switch (num) {
		}*/
		num++;
		if (num == 19) { 
			num = 0;
			n++;
		}
	}
	FileRead_close(fp);//�t�@�C�������
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
	//load_EnemyCsv()
	load_se();
}
