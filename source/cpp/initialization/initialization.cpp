// shooting/source/cpp/initialization

#include "./../../h/global.h"

//���낢��Ȃ��̂�������
void initialization() {
	//�X�e�[�W�̃J�E���g��0�ɂ���
	stage_count = 0;

	//�|�����G�̐���0�ɂ���
	down_enemy_num = 0;

	//�f���̍��W�����߂�
	planet.mallocSub(1);
	substance *sub = planet.getSub();
	sub[0].x = 0.0f;
	sub[0].y = 0.0f;
	sub[0].z = 600.0f;
}