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
	substance *sub = enemy.getSub();
	character *cha = enemy.getCha();
	int n = 0, num = 0, fp;
	char path[PATH_SIZE] = { "./../../../data/csv/Enemy/enemy_0.csv" };
	int input[PATH_SIZE];
	char inputc[PATH_SIZE];

	//�t�@�C���̓ǂݍ���
	fp = FileRead_open(path);

	//�t�@�C�����Ȃ�������I��
	if (fp == NULL) return;

	//�t�@�C���̍ŏ���2�s��ǂݔ�΂�
	for (int i = 0; i < 2; i++) {
		while (FileRead_getc(fp) != '\n');
	}

	//�e�f�[�^�̎擾
	while (true) {
		for (int i = 0; i < PATH_SIZE; i++) {
			inputc[i] = input[i] = FileRead_getc(fp);//�P�����擾

			//�X���b�V��������ΊJ�Ƃ܂Ń��[�v���āA�ŏ��̃f�[�^�ɍs��
			if (inputc[i] == '/') {
				while (FileRead_getc(fp) != '\n');
				i = -1;//�J�E���^���ŏ��ɖ߂�
				continue;
			}

			/*�J���}�����s�Ȃ�A�����܂ł𕶎���Ƃ��ēǂݍ���*/
			if (input[i] == ',' || input[i] == '\n') {
				inputc[i] = '\0';
				break;
			}

			//�t�@�C���̏I���Ȃ�I��
			if (input[i] == EOF) return;
		}

		/*���ꂼ��̃f�[�^���i�[
		  0:�J�E���g(�o������)
		  1:x���W
		  2:y���W
		  3:z���W
		  4:�X�s�[�h
		  5:�̗�
		  6:���Ԏ���
		*/
		switch (num) {
			case 0: sub[n].aptime =        atoi(inputc);                            break;
			case 1: sub[n].x      = (float)atoi(inputc);                            break;
			case 2:	sub[n].y      = (float)atoi(inputc);                            break;
			case 3: sub[n].z      = (float)atoi(inputc);                            break;
			case 4: sub[n].sp     = (float)atoi(inputc);                            break;
			case 5: cha[n].hp_max =        atoi(inputc); cha[n].hp = cha[n].hp_max; break;
			case 6: sub[n].bltime =        atoi(inputc);							break;
			default:                                                                break;
		}
		num++;
		//1�s�̃f�[�^���Ɠ����������ꍇ�A���̍s�̍ŏ��̃f�[�^�ɍs��
		if (num == ENEMY_DATA_CSV_NUM) { 
			num = 0;
			n++;
		}
		//�f�[�^���\�ߊm�ۂ����G���������傫���Ȃ�A���������g�傷��
		if (n >= enemy.getSize()) {
			enemy.reallocSub(n);
		}
	}
	FileRead_close(fp);//�t�@�C�������
}

//�{�X�̈ʒu���A�s���p�^�[���A�X�e�[�^�X��ǂݍ���
void load_BossCsv() {
	substance *sub = enemy.getSub();
	character *cha = enemy.getCha();
	int n = 0, num = 0, fp;
	char path[PATH_SIZE] = { "./../../../data/csv/Boss/boss0.csv" };
	int input[PATH_SIZE];
	char inputc[PATH_SIZE];

	//�t�@�C���̓ǂݍ���
	fp = FileRead_open(path);

	//�t�@�C�����Ȃ�������I��
	if (fp == NULL) return;

	//�t�@�C���̍ŏ���2�s��ǂݔ�΂�
	for (int i = 0; i < 2; i++) {
		while (FileRead_getc(fp) != '\n');
	}

	//�e�f�[�^�̎擾
	while (true) {
		for (int i = 0; i < PATH_SIZE; i++) {
			inputc[i] = input[i] = FileRead_getc(fp);//�P�����擾

			//�X���b�V��������ΊJ�Ƃ܂Ń��[�v���āA�ŏ��̃f�[�^�ɍs��
			if (inputc[i] == '/') {
				while (FileRead_getc(fp) != '\n');
				i = -1;//�J�E���^���ŏ��ɖ߂�
				continue;
			}

			/*�J���}�����s�Ȃ�A�����܂ł𕶎���Ƃ��ēǂݍ���*/
			if (input[i] == ',' || input[i] == '\n') {
				inputc[i] = '\0';
				break;
			}

			//�t�@�C���̏I���Ȃ�I��
			if (input[i] == EOF) return;
		}

		//���ꂼ��̃f�[�^���i�[
		switch (num) {
		case 0: sub[n].x  = (float)atoi(inputc); break;
		case 1:	sub[n].y  = (float)atoi(inputc); break;
		case 2: sub[n].sp = (float)atoi(inputc); break;
		case 3: cha[n].hp =        atoi(inputc); break;
			//case 4:
			//case 5:
		default:                          break;
		}
		num++;
		//1�s�̃f�[�^���Ɠ����������ꍇ�A���̍s�̍ŏ��̃f�[�^�ɍs��
		if (num == ENEMY_DATA_CSV_NUM) {
			num = 0;
			n++;
		}
		//�f�[�^���\�ߊm�ۂ����G���������傫���Ȃ�A���������g�傷��
		if (n >= enemy.getSize()) {
			enemy.reallocSub(n);
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
	//load_EnemyCsv();
	//load_BossCsv();
	load_se();
}
