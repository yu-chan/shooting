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
	substance *sub;

	//自機の読み込み
	sub = player.getSub();
	sub[0].MHandle = MV1LoadModel("./data/3dModel/Player/AircraftFuselage.mv1");  //大きさ x:182*4 y:わからん z:182*11	 
	//モデルが大きすぎるので、小さくする
	MV1SetScale(sub[0].MHandle, VGet(0.01f, 0.01f, 0.01f));
	//モデルの先端がプレイヤー側に向いてるので、Y軸に180度回転する 
	MV1SetRotationXYZ(sub[0].MHandle, VGet(0.0f, player.getSub()[0].angy * DX_PI_F / 180.0f, 0.0f));


	//敵の読み込み
	sub = enemy.getSub();
	ModelEnemy = MV1LoadModel("./data/3dModel/Enemy/enemy.mqo"); //大きさ x:26*10 y:わからん z:26*
	for (int i = 0; i < enemy.getSize(); i++) {
		sub[i].MHandle = MV1DuplicateModel(ModelEnemy);
		//モデルのサイズを小さくする
		MV1SetScale(sub[i].MHandle, VGet(0.05f, 0.05f, 0.05f));
	}
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
	load_se();
}
