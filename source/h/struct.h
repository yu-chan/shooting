//プレイヤー、敵、物に使う
typedef struct {
	float x, y, z;//座標
	float ang;//角度
	int flag, count;//フラグ、出現時間
	float sp;//スピード
	float ax, ay, az;//加速度
	float vx, vy, vz;//速度
}substance;

//キャラクターがもつステータス
typedef struct {
	int hp, hp_mx;
}character;

//弾
typedef struct {
	int power, num;
}bullet;