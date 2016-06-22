// shooting/source/cpp/initialization

#include "./../../h/global.h"

//���낢��Ȃ��̂�������
void initialization() {
	//substance *sub;
	//�J�����̍��W�A�����_������������
	substance *sub = player.getSub();
	camera_pos = VGet(sub[0].x, sub[0].y + 10.0f, sub[0].z - 30); //�J�����̈ʒu
	camera_look = VGet(0.0f, 0.0f, 30.0f); //�J�����̒����_(�J�����̍��W���瑫��������)
	camera_look = VAdd(camera_pos, camera_look);

	//�X�e�[�W�̃J�E���g��0�ɂ���
	stage_count = 0;

	//�|�����G�̐���0�ɂ���
	down_enemy_num = 0;

	//�v���C���[�̃��f����Y����180�x��]�����邽�߂�angy��������
	sub = player.getSub();
	sub[0].angy = 180.0f;

	//�G�̃��f����Y����180�x��]�����邽�߂�angy��������
	sub = enemy.getSub();
	int size = enemy.getSize();
	for (int i = 0; i < size; i++) {
		//sub[i].angy = -90.0f;			 
		sub[i].angy = 0.0f;
		sub[i].flag = false;
	}

	//�f���̍��W�����߂�
	planet.mallocSub(1);
	sub = planet.getSub();
	sub[0].x = 0.0f;
	sub[0].y = 0.0f;
	sub[0].z = 600.0f;

	//�o�̏�����
	dust.mallocSub(DUST_NUM);
}