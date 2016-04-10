// shooting/source/cpp/draw‚Ì’†

/*
  ‰æ‘œ‚Ì•`‰æ
*/
#include "./../../h/global.h"

//©‹@‚Ì•`‰æ
void draw_Player() {
	/*substance &sub = *player_shot.getSub();
	if (sub.flag == TRUE) {
		MV1DrawModel(ModelAirCraft);
	}*/
	MV1DrawModel(ModelAirCraft);
}

//“G‚Ì•`‰æ
void draw_Enemy() {
	/*substance &sub = *player_shot.getSub();
	if (sub.flag == TRUE) {
		MV1DrawModel(ModelEnemy);
	}*/
	MV1DrawModel(ModelEnemy);
}

//ƒvƒŒƒCƒ„[’e‚Ì•`‰æ
void draw_Player_shot() {
	/*substance &sub = *player_shot.getSub();
	if (sub.flag == TRUE) {
		MV1DrawModel(ModelShot);
	}*/
	MV1DrawModel(ModelShot);
}

void draw() {
	draw_Player();
	draw_Player_shot();
	draw_Enemy();
}