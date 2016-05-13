// shooting/source/cpp/initialization

#include "./../../h/global.h"

//いろいろなものを初期化
void initialization() {
	//ステージのカウントを0にする
	stage_count = 0;

	//倒した敵の数を0にする
	down_enemy_num = 0;

	//惑星の座標を決める
	planet.mallocSub(1);
	substance *sub = planet.getSub();
	sub[0].x = 0.0f;
	sub[0].y = 0.0f;
	sub[0].z = 600.0f;
}