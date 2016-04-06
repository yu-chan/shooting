// shooting/source/cpp/loadの中

/*
  画像、3Dモデル、csvファイルをロードする
*/			 

#include <iostream>
#include <Windows.h>
#include <WinBase.h>
//#include "./../../../DxLib_VC/DxLib.h"
#include "DxLib.h"
#include "./../source/h/globalVariable.h"

using namespace std;

//3Dモデルを読み込む
void load_3DModel() {
	//自機の読み込み
	//ModelAirCraft = MV1LoadModel("./data/3D Model/Vehicles/Aircraft/Models/AircraftFuselage.x");
	ModelAirCraft = MV1LoadModel("./data/3D Model/Lat式ミク/Lat式ミクVer2.3_Normal.pmd");
}
