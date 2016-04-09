// shooting/source/cpp/setPositionの中

/*
  カメラ、画像、モデルの座標をセットする
*/
//#include "./../../../DxLib_VC/DxLib.h"
//#include "DxLib.h"
//#include "./../../h/globalVariable.h"
//#include "./../source/h/define.h"
#include "./../source/h/global.h"

//カメラの描画範囲を決める
void setCamera() {
	SetCameraNearFar(CAMERA_MIN, CAMERA_MAX);
	SetCameraPositionAndTarget_UpVecY(VGet(0, 10, -20), VGet(0.0f, 10.0f, 0.0f));
}

//プレイヤーの位置をセット
void setPosition_Player() {
	substance sub = player.getSub();
	MV1SetPosition(ModelAirCraft, VGet(sub.x, sub.y, sub.z));
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "x=%.1f y=%.1f z=%.1f", sub.x, sub.y, sub.z);
}
