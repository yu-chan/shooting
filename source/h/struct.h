typedef struct {
	float x, y, z;//座標
	float cX, cY, cZ;//中心座標
	float ang;//角度
	bool flag;//フラグ
	int count, aptime, bltime;//カウンタ、出現時間、発車時間
	float sp;//スピード
	float ax, ay, az;//加速度
	float vx, vy, vz;//速度
}substance;

//キャラクターが持つ情報
typedef struct {
	int hp, hp_max;
}character;

//弾
typedef struct {
	int power, num;
}bullet;

//アイテム
typedef struct {
	int num, kind;
}item;

//音楽
typedef struct {
	//フラグ、音楽を格納する、種類、ループ位置
	int flag, handle, knd[2], loop_pos;
}music_;

//ステージが持つ情報
typedef struct {
	music_ mus;
	int count;
}stage;

//ベクトル演算に使う
typedef struct {
	float x, y, z;
}vec3;
