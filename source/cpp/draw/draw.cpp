// shooting/source/cpp/draw‚Ì’†

/*
  ‰æ‘œ‚Ì•`‰æ
*/
#include "./../../h/global.h" 

//ƒJƒƒ‰‚Ì•`‰æ”ÍˆÍ‚ğŒˆ‚ß‚é
void setCamera() {
	substance *sub = player.getSub();
	SetCameraNearFar(CAMERA_MIN, CAMERA_MAX);
	SetCameraPositionAndTarget_UpVecY(VGet(sub[0].x, sub[0].y + 10, sub[0].z - 30), VGet(0.0f, 10.0f, 0.0f));
	//SetCameraPositionAndTarget_UpVecY(VGet(0.0f, 10.0f, -30), VGet(0.0f, 0.0f, 0.0f));
	//SetCameraPositionAndTarget_UpVecY(VGet(0, 20, -50), VGet(0.0f, 10.0f, 0.0f));				
	//SetCameraPositionAndTarget_UpVecY(VGet(sub[0].x, sub[0].y + 20, sub[0].z - 50), VGet(0.0f, 10.0f, 0.0f));
	//SetCameraPositionAndTarget_UpVecY(VGet(0.0f, 200.0f, 0), VGet(0.0f, 0.0f, 0.0f));
}

//©‹@‚Ì•`‰æ
void draw_Player() {
	substance *sub = player.getSub();
	if (sub[0].flag == true) {
		MV1SetPosition(ModelAirCraft, VGet(sub[0].x, sub[0].y, sub[0].z));
		MV1DrawModel(ModelAirCraft);
	}
}

//“G‚Ì•`‰æ
void draw_Enemy() {
	substance *sub = enemy.getSub();
	for (int i = 0; i < enemy.getSize(); i++) {
		if (sub[i].flag == true) {
			MV1SetPosition(ModelEnemy, VGet(sub[i].x, sub[i].y, sub[i].z));
			MV1DrawModel(ModelEnemy);
		}
	}
}

//ƒvƒŒƒCƒ„[’e‚Ì•`‰æ
void draw_Player_shot() {
	substance *sub = player_shot.getSub();
	for (int i = 0; i < player_shot.getSize(); i++) {
		if (sub[i].flag == true) {
			//MV1SetPosition(ModelPlayerShot, VGet(sub[i].x, sub[i].y, sub[i].z));
			//MV1DrawModel(ModelPlayerShot);
			DrawCapsule3D(VGet(sub[i].x, sub[i].y + 10, sub[i].z), VGet(sub[i].x, sub[i].y + 10, sub[i].z + 5), SHOT_CAPSULE_R, SHOT_CAPSULE_DIVNUM, GetColor(0, 0, 255), GetColor(255, 255, 255), TRUE);
		}
	}
	//DrawCapsule3D(VGet(15, 10, 0), VGet(15, 10, 5), SHOT_CAPSULE_R, SHOT_CAPSULE_DIVNUM, GetColor(0, 0, 255), GetColor(255, 255, 255), TRUE);
}

//“G‚Ì’e‚Ì•`‰æ
void draw_Enemy_shot() {
	substance *sub = enemy_shot.getSub();
	for (int i = 0; i < enemy_shot.getSize(); i++) {
		if (sub[i].flag == true) {
			//MV1SetPosition(ModelEnemyShot, VGet(sub[i].x, sub[i].y, sub[i].z));
			//MV1DrawModel(ModelEnemyShot);
			DrawCapsule3D(VGet(sub[i].x, sub[i].y + 10, sub[i].z), VGet(sub[i].x, sub[i].y + 10, sub[i].z + 5), SHOT_CAPSULE_R, SHOT_CAPSULE_DIVNUM, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);
		}
	}
}

void draw() {
	setCamera();
	draw_Player_shot();
	draw_Enemy_shot();
	draw_Player();
	draw_Enemy();
	//DrawLine3D(VGet(100.0f, 100.0f, 0.0f), VGet(300.0f, 200.0f, 0.0f), GetColor(255, 255, 255));
}