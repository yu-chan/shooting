// shooting/source/cpp/initialization

#include "./../../h/global.h"

//いろいろなものを初期化
void initialization() {
	//substance *sub;
	//カメラの座標、注視点を初期化する
	substance *sub = player.getSub();
	camera_pos = VGet(sub[0].x, sub[0].y + 10.0f, sub[0].z - 30); //カメラの位置
	camera_look = VGet(0.0f, 0.0f, 30.0f); //カメラの注視点(カメラの座標から足したもの)
	camera_look = VAdd(camera_pos, camera_look);

	//ステージのカウントを0にする
	stage_count = 0;

	//倒した敵の数を0にする
	down_enemy_num = 0;

	//プレイヤーのモデルをY軸に180度回転させるためにangyを初期化
	sub = player.getSub();
	sub[0].angy = 180.0f;

	//敵のモデルをY軸に180度回転させるためにangyを初期化
	sub = enemy.getSub();
	int size = enemy.getSize();
	for (int i = 0; i < size; i++) {
		//sub[i].angy = -90.0f;			 
		sub[i].angy = 0.0f;
		sub[i].flag = false;
	}

	//惑星の座標を決める
	planet.mallocSub(1);
	sub = planet.getSub();
	sub[0].x = 0.0f;
	sub[0].y = 0.0f;
	sub[0].z = 600.0f;

	//塵の初期化
	dust.mallocSub(DUST_NUM);
}