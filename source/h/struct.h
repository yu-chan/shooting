//�v���C���[�A�G�A���Ɏg��
typedef struct {
	float x, y, z;//���W
	float ang;//�p�x
	int flag, count;//�t���O�A�o������
	float sp;//�X�s�[�h
	float ax, ay, az;//�����x
	float vx, vy, vz;//���x
}object;

//�L�����N�^�[�����X�e�[�^�X
typedef struct {
	object status;
	int hp, hp_mx;
}character;

//�e
typedef struct {
	object status;
	int power, num;
}bullet;

//�v���C���[
typedef struct {
	character player;
	bullet shot;
};