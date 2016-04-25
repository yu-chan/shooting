typedef struct {
	float x, y, z;//座標
	float cX, cY, cZ;//中心座標
	float ang;//角度
	bool flag;//フラグ
	int count;//出現時間
	float sp;//スピード
	float ax, ay, az;//加速度
	float vx, vy, vz;//速度
}substance;

//キャラクターが持つ情報
typedef struct {
	int hp, hp_mx;
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
	int flag, handle, knd[2], loop_pos[2];
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
