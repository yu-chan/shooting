// shooting/source/hの中 


//true,false
//#define TRUE 1
//#define FALSE 0

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

//プレイヤーの行動範囲
#define PLAYER_RANGE_X_MIN -15
#define PLAYER_RANGE_X_MAX 15
#define PLAYER_RANGE_Y_MIN -10
#define PLAYER_RANGE_Y_MAX 10
//プレイヤーモデルのFrameIndex
#define PLAYER_MODEL_FRAMEINDEX 0

//敵の行動範囲
#define ENEMY_RANGE_X_MIN -20
#define ENEMY_RANGE_X_MAX 20
#define ENEMY_RANGE_Y_MIN -20
#define ENEMY_RANGE_Y_MAX 20
#define ENEMY_RANGE_Z_MIN -20
#define ENEMY_RANGE_Z_MAX 20
//敵データの数
#define ENEMY_DATA_CSV_NUM 6
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
//ショットの行動範囲
#define SHOT_RANGE_X_MIN -20
#define SHOT_RANGE_X_MAX 20
#define SHOT_RANGE_Y_MIN -20
#define SHOT_RANGE_Y_MAX 20
#define SHOT_RANGE_Z_MIN -20
#define SHOT_RANGE_Z_MAX 20
#define SHOT_CAPSULE_R 1.0f
#define SHOT_CAPSULE_DIVNUM 8
