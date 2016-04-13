// shooting/source/cpp/loadの中

/*
  画像、3Dモデル、音楽、csvファイルをロードする
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>
#include <WinBase.h>
#include "./../../h/global.h"

using namespace std;

//3Dモデルを読み込む
void load_3DModel() {
	/* ./../../../をつけると読み込めない
	　おそらく、MV1LoadModelはプロジェクトファイルをパスの最初の位置に指定し、
	 　そこを起点に読み込んでいると思われる
	  あくまで自分の推測だが...
	*/
	//自機の読み込み
	//ModelAirCraft = MV1LoadModel("./data/3D Model/Vehicles/Aircraft/Models/AircraftFuselage.x");
	ModelAirCraft = MV1LoadModel("./data/3dModel/Lat式ミク/Lat式ミクVer2.3_Normal.pmd");

	//敵の読み込み
	ModelEnemy = MV1LoadModel("./data/3dModel/Lat式ミク/Lat式ミクVer2.3_Normal.pmd");

	//ショットの読み込み
	ModelPlayerShot = MV1LoadModel("./data/3dModel/Lat式ミク/Lat式ミクVer2.3_Normal.pmd");
	ModelEnemyShot = MV1LoadModel("./data/3dModel/Lat式ミク/Lat式ミクVer2.3_Normal.pmd");
}

//敵の位置情報、行動パターン、ステータスを読み込む
void load_EnemyCsv() {
	int n = 0, num = 0, fp;
	char path[PATH_SIZE] = { "./../../../data/csv/Enemy/enemy0.csv" };
	int input[PATH_SIZE];
	char inputc[PATH_SIZE];

	//ファイルの読み込み
	fp = FileRead_open(path);

	//ファイルがなかったら終了
	if (fp == NULL) return;

	//各データの取得
	while (TRUE) {
		for (int i = 0; i < PATH_SIZE; i++) {
			inputc[i] = input[i] = FileRead_getc(fp);//１文字取得

			/*カンマか改行なら、そこまでを文字列として読み込む*/
			if (input[i] == ',' || input[i] == '\n') {
				inputc[i] = '\0';
				break;
			}

			//ファイルの終わりなら終了
			if (input[i] == EOF) return;
		}

		//それぞれのデータを格納
		/*switch (num) {
		}*/
		num++;
		if (num == 19) { 
			num = 0;
			n++;
		}
	}
	FileRead_close(fp);//ファイルを閉じる
}

//SEを読み込む
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
