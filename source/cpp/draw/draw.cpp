// shooting/source/cpp/drawΜ

/*
  ζΜ`ζ
*/
#include "./../../h/global.h"

//©@Μ`ζ
void draw_Player() {
	/*substance &sub = *player_shot.getSub();
	if (sub.flag == TRUE) {
		MV1DrawModel(ModelAirCraft);
	}*/
	MV1DrawModel(ModelAirCraft);
}

//GΜ`ζ
void draw_Enemy() {
	/*substance &sub = *player_shot.getSub();
	if (sub.flag == TRUE) {
		MV1DrawModel(ModelEnemy);
	}*/
	MV1DrawModel(ModelEnemy);
}

//vC[eΜ`ζ
void draw_Player_shot() {
	/*substance &sub = *player_shot.getSub();
	if (sub.flag == TRUE) {
		MV1DrawModel(ModelShot);
	}*/
	MV1DrawModel(ModelPlayerShot);
}

//GΜeΜ`ζ
void draw_Enemy_shot() {
	MV1DrawModel(ModelEnemyShot);
}

void draw() {
	draw_Player();
	draw_Player_shot();
	draw_Enemy();
	draw_Enemy_shot();
}