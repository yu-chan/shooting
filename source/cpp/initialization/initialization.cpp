// shooting/source/cpp/initialization

#include "./../../h/global.h"

//いろいろなものを初期化
void initialization() {
	//プレイヤーのモデルをY軸に180度回転させるためにangyを初期化
	substance *sub = player.getSub();
	character *cha = player.getCha();
	sub[0].x = 0;
	sub[0].y = 0;
	sub[0].z = 0;
	sub[0].flag = true;
	sub[0].fall_flag = false;
	sub[0].angy = 180.0f;
	cha[0].hp = cha[0].hp_max;

	//カメラの座標、注視点を初期化する
	camera_pos = VGet(sub[0].x, sub[0].y + 10.0f, sub[0].z - 30); //カメラの位置
	camera_look = VGet(0.0f, 0.0f, 30.0f); //カメラの注視点(カメラの座標から足したもの)
	camera_look = VAdd(camera_pos, camera_look);

	//ステージのカウントを0にする
	stage_count = 0;

	//プレイモードをfalseにする
	play_mode = false;

	//クリア、オーバーフラグをfalseにする
	clear_flag = false;
	over_flag = false;

	//倒した敵の数を0にする
	down_enemy_num = 0;


	//敵のモデルをY軸に180度回転させるためにangyを初期化
	sub = enemy.getSub();
	cha = enemy.getCha();
	int size = enemy.getSize();
	for (int i = 0; i < size; i++) {
		//sub[i].angy = -90.0f;			 
		sub[i].angy = 0.0f;
		sub[i].flag = false;
		sub[i].fall_flag = false;
		cha[i].hp = 10;
		cha[i].knd = 1;
	}

	//塵の初期化
	dust.mallocSub(DUST_NUM);
}