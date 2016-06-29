// shooting/source/hの中 


//ラジアンパイ
#define PI 3.141592

//FPS
#define FPS 60

//カメラの描画範囲
#define CAMERA_MIN 0.1f
#define CAMERA_MAX 1000.0f

//取得するキーボード数
#define KEYBOARD_NUM 256

//プレイヤーを動かすキーの数
#define KEY_MOVE 4

//斜めに動かした時に必要
#define ROOT2 sqrt(2.0f)

//プレイヤーモデルのFrameIndex
#define PLAYER_MODEL_FRAMEINDEX 0

//敵の数
#define ENEMY_NUM 10
//敵モデルのFrameIndex
#define ENEMY_MODEL_FRAMEINDEX 0

//パスのサイズ
#define PATH_SIZE 64

//音楽
#define BGM_NUM 1 //BGMの数
#define SE_NUM 1  //SEの数
#define SHOT_NO 0 //ショット音のNo

//ショットの最大数
#define PLAYER_SHOT_MAX 100
#define ENEMY_SHOT_MAX 100
#define SHOT_CAPSULE_R 1.0f
#define SHOT_CAPSULE_DIVNUM 8
//プレイヤーがショットを打った時のプラスする座標
#define SHOT_PLAYER_Y 5.0f
//敵がショットを打った時のプラスする座標
#define SHOT_ENEMY_Y 1.0f
#define SHOT_ENEMY_Z -15.0f
//ショットのパワー
#define SHOT_POWER 10

//塵
#define DUST_NUM 200 //数
#define DUST_RANGE 1000 //プレイヤーの周りに存在する塵の描画範囲
