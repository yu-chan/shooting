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
	substance *sub = enemy.getSub();
	character *cha = enemy.getCha();
	int n = 0, num = 0, fp;
	char path[PATH_SIZE] = { "./../../../data/csv/Enemy/enemy_0.csv" };
	int input[PATH_SIZE];
	char inputc[PATH_SIZE];

	//ファイルの読み込み
	fp = FileRead_open(path);

	//ファイルがなかったら終了
	if (fp == NULL) return;

	//ファイルの最初の2行を読み飛ばす
	for (int i = 0; i < 2; i++) {
		while (FileRead_getc(fp) != '\n');
	}

	//各データの取得
	while (true) {
		for (int i = 0; i < PATH_SIZE; i++) {
			inputc[i] = input[i] = FileRead_getc(fp);//１文字取得

			//スラッシュがあれば開業までループして、最初のデータに行く
			if (inputc[i] == '/') {
				while (FileRead_getc(fp) != '\n');
				i = -1;//カウンタを最初に戻す
				continue;
			}

			/*カンマか改行なら、そこまでを文字列として読み込む*/
			if (input[i] == ',' || input[i] == '\n') {
				inputc[i] = '\0';
				break;
			}

			//ファイルの終わりなら終了
			if (input[i] == EOF) return;
		}

		/*それぞれのデータを格納
		  0:カウント(出現時間)
		  1:x座標
		  2:y座標
		  3:z座標
		  4:スピード
		  5:体力
		  6:発車時間
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
		//1行のデータ数と同じだった場合、次の行の最初のデータに行く
		if (num == ENEMY_DATA_CSV_NUM) { 
			num = 0;
			n++;
		}
		//データが予め確保した敵メモリより大きいなら、メモリを拡大する
		if (n >= enemy.getSize()) {
			enemy.reallocSub(n);
		}
	}
	FileRead_close(fp);//ファイルを閉じる
}

//ボスの位置情報、行動パターン、ステータスを読み込む
void load_BossCsv() {
	substance *sub = enemy.getSub();
	character *cha = enemy.getCha();
	int n = 0, num = 0, fp;
	char path[PATH_SIZE] = { "./../../../data/csv/Boss/boss0.csv" };
	int input[PATH_SIZE];
	char inputc[PATH_SIZE];

	//ファイルの読み込み
	fp = FileRead_open(path);

	//ファイルがなかったら終了
	if (fp == NULL) return;

	//ファイルの最初の2行を読み飛ばす
	for (int i = 0; i < 2; i++) {
		while (FileRead_getc(fp) != '\n');
	}

	//各データの取得
	while (true) {
		for (int i = 0; i < PATH_SIZE; i++) {
			inputc[i] = input[i] = FileRead_getc(fp);//１文字取得

			//スラッシュがあれば開業までループして、最初のデータに行く
			if (inputc[i] == '/') {
				while (FileRead_getc(fp) != '\n');
				i = -1;//カウンタを最初に戻す
				continue;
			}

			/*カンマか改行なら、そこまでを文字列として読み込む*/
			if (input[i] == ',' || input[i] == '\n') {
				inputc[i] = '\0';
				break;
			}

			//ファイルの終わりなら終了
			if (input[i] == EOF) return;
		}

		//それぞれのデータを格納
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
		//1行のデータ数と同じだった場合、次の行の最初のデータに行く
		if (num == ENEMY_DATA_CSV_NUM) {
			num = 0;
			n++;
		}
		//データが予め確保した敵メモリより大きいなら、メモリを拡大する
		if (n >= enemy.getSize()) {
			enemy.reallocSub(n);
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
	//load_EnemyCsv();
	//load_BossCsv();
	load_se();
}
