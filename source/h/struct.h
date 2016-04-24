//�v���C���[�A�G�A���Ɏg��
typedef struct {
	float x, y, z;//���W
    float cX, cY, cZ;//中心座標
	float ang;//�p�x
	bool flag;//�t���O
	int count;//�o������
	float sp;//�X�s�[�h
	float ax, ay, az;//�����x
	float vx, vy, vz;//���x
}substance;

//�L�����N�^�[�����X�e�[�^�X
typedef struct {
	int hp, hp_mx;
}character;

//�e
typedef struct {
	int power, num;
}bullet;

//�A�C�e��
typedef struct {
	int num, kind;
}item;

//���y�Ɋւ����\����
typedef struct {
	int flag, handle, knd[2], loop_pos[2];
}music_;

//�X�e�[�W�������Ă�������
typedef struct {
	music_ mus;
	int count;
}stage;

//�x�N�g�����Z
typedef struct {
	float x, y, z;
}vec3;