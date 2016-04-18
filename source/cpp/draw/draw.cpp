// shooting/source/cpp/draw‚Ì’†

/*
  ‰æ‘œ‚Ì•`‰æ
*/
#include "./../../h/global.h"

//©‹@‚Ì•`‰æ
void draw_Player() {
	substance *sub;
	sub = player.getSub();
	if (sub[0].flag == TRUE)
		MV1DrawModel(ModelAirCraft);
}

//“G‚Ì•`‰æ
void draw_Enemy() {
	substance *sub = enemy.getSub();
	if (sub[0].flag == TRUE)
		MV1DrawModel(ModelEnemy);
}

//ƒvƒŒƒCƒ„[’e‚Ì•`‰æ
void draw_Player_shot() {
	substance *sub = player_shot.getSub();
	for (int i = 0; i < player_shot.getSize(); i++) {
		if (sub[i].flag == TRUE)
			MV1DrawModel(ModelPlayerShot);
	}
}

//“G‚Ì’e‚Ì•`‰æ
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