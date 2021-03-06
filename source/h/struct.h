typedef struct {
	float x, y, z;//座標
	float angx, angy, angz;//角度
	int MHandle;//モデル
	bool flag, fall_flag;//フラグ、倒されているかどうかのフラグ
	int count;//カウンタ
	float vx, vy, vz;//速度
}substance;

//キャラクターが持つ情報
typedef struct {
	int hp, hp_max;
	int knd;//キャラクターの種類
}character;

//音楽
typedef struct {
	//フラグ、音楽を格納する、種類、ループ位置
	int flag, handle, knd[2], loop_pos;
}music_;

//エフェクト
typedef struct {
	float x, y, z;
	int br;
	bool flag;
	float r;
}effect;
