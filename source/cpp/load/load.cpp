// shooting/source/cpp/load�̒�

/*
  �摜�A3D���f���Acsv�t�@�C�������[�h����
*/			 

#include <iostream>
#include <Windows.h>
#include <WinBase.h>
#include "./../../h/global.h"

using namespace std;

//3D���f����ǂݍ���
void load_3DModel() {
	//���@�̓ǂݍ���
	//ModelAirCraft = MV1LoadModel("./data/3D Model/Vehicles/Aircraft/Models/AircraftFuselage.x");
	ModelAirCraft = MV1LoadModel("./data/3D Model/Lat���~�N/Lat���~�NVer2.3_Normal.pmd");
}

void load() {
	load_3DModel();
}