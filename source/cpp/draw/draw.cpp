// shooting/source/cpp/draw‚Ì’†

/*
  ‰æ‘œ‚Ì•`‰æ
*/
#include "./../../h/global.h" 

//ƒJƒƒ‰‚Ì•`‰æ”ÍˆÍ‚ğŒˆ‚ß‚é
void setCamera() {
	SetCameraNearFar(CAMERA_MIN, CAMERA_MAX);
	SetCameraPositionAndTarget_UpVecY(VGet(0, 10, -20), VGet(0.0f, 10.0f, 0.0f));
}

//©‹@‚Ì•`‰æ
void draw_Player() {
	substance *sub;
	sub = player.getSub();
	if (sub[0].flag == TRUE) {
		MV1SetPosition(ModelAirCraft, VGet(sub[0].x, sub[0].y, sub[0].z));
		MV1DrawModel(ModelAirCraft);
	}
}

//“G‚Ì•`‰æ
void draw_Enemy() {
	substance *sub = enemy.getSub();
	for (int i = 0; i < enemy.getSize(); i++) {
		if (sub[i].flag == TRUE) {
			MV1SetPosition(ModelEnemy, VGet(sub[i].x, sub[i].y, sub[i].z));
			MV1DrawModel(ModelEnemy);
		}
	}
}

//ƒvƒŒƒCƒ„[’e‚Ì•`‰æ
void draw_Player_shot() {
	substance *sub = player_shot.getSub();
	for (int i = 0; i < player_shot.getSize(); i++) {
		if (sub[i].flag == TRUE) {
			MV1SetPosition(ModelPlayerShot, VGet(sub[i].x, sub[i].y, sub[i].z));
			MV1DrawModel(ModelPlayerShot);
		}
	}
}

//“G‚Ì’e‚Ì•`‰æ
void draw_Enemy_shot() {
	substance *sub = enemy_shot.getSub();
	for (int i = 0; i < enemy_shot.getSize(); i++) {
		if (sub[i].flag == TRUE) {
			MV1SetPosition(ModelEnemyShot, VGet(sub[i].x, sub[i].y, sub[i].z));
			MV1DrawModel(ModelEnemyShot);
		}
	}
}

void draw() {
	setCamera();
	draw_Player();
	draw_Player_shot();
	draw_Enemy();
	draw_Enemy_shot();
}