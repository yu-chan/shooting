// shooting/source/cpp/setPositionの中

/*
  カメラ、画像、モデルの座標をセットする
*/
#include "./../../h/global.h"

//カメラの描画範囲を決める
void setCamera() {
	SetCameraNearFar(CAMERA_MIN, CAMERA_MAX);
	SetCameraPositionAndTarget_UpVecY(VGet(0, 10, -20), VGet(0.0f, 10.0f, 0.0f));
}

//プレイヤーの位置をセット
void setPosition_Player() {
	substance _sub, *sub = player.getSub();
	_sub = *sub;
	MV1SetPosition(ModelAirCraft, VGet(_sub.x, _sub.y, _sub.z));
	//DrawFormatString(0, 0, GetColor(255, 255, 255), "x=%.1f y=%.1f z=%.1f", sub.x, sub.y, sub.z);
}

//敵の位置をセット
void setPosition_Enemy() {
	substance _sub, *sub = enemy.getSub();
	_sub = *sub;
	MV1SetPosition(ModelEnemy, VGet(_sub.x, _sub.y, _sub.z));
}

void setPosition() {
	setCamera();
	setPosition_Player();
	setPosition_Enemy();
}
