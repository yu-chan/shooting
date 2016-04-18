// shooting/source/cpp/drawΜ

/*
  ζΜ`ζ
*/
#include "./../../h/global.h"

//©@Μ`ζ
void draw_Player() {
	substance *sub;
	sub = player.getSub();
	if (sub[0].flag == TRUE)
		MV1DrawModel(ModelAirCraft);
}

//GΜ`ζ
void draw_Enemy() {
	substance *sub = enemy.getSub();
	if (sub[0].flag == TRUE)
		MV1DrawModel(ModelEnemy);
}

//vC[eΜ`ζ
void draw_Player_shot() {
	substance *sub = player_shot.getSub();
	if (sub[0].flag == TRUE)
		MV1DrawModel(ModelPlayerShot);
}

//GΜeΜ`ζ
void draw_Enemy_shot() {
	substance *sub = enemy_shot.getSub();
	if (sub[0].flag == TRUE)
		MV1DrawModel(ModelEnemyShot);
}

void draw() {
	draw_Player();
	draw_Player_shot();
	draw_Enemy();
	draw_Enemy_shot();
}