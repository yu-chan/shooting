// shooting/source/hの中

/*
  ここにグローバル宣言したい変数を書く
*/

//プレイヤーのモデル
GLOBAL int ModelAirCraft;

//敵のモデル
GLOBAL int ModelEnemy;

//弾のモデル
GLOBAL int ModelPlayerShot;
GLOBAL int ModelEnemyShot;

//ステージのカウント
GLOBAL int stage_count;

//倒した敵の数
GLOBAL int down_enemy_num;

//カメラの座標、注視点
GLOBAL VECTOR camera_pos, camera_look;

//プレイモード
GLOBAL bool play_mode;