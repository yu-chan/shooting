#include "./../../../h/global.h"


Shot::Shot()
{
}

/*
	�������ł������A����ɂ������Ă邩�ǂ������肷��

	Sub:����(��Q���A���f��)�̃A�h���X
	v1, v2:�����̃x�N�g��
*/
bool Shot::collision_detection(Substance *Sub, VECTOR v1, VECTOR v2, int ModelHandle, int ModelHandleFrameIndex) {
	Substance *mSub = Sub;
	substance *msub = mSub->getSub();
	MV1_COLL_RESULT_POLY_DIM HitPolyDim;
	int msize = mSub->getSize();

	for (int i = 0; i < msize; i++) {
		//�R���W���������\�z����
		MV1SetupCollInfo(ModelHandle, ModelHandleFrameIndex, 8, 8, 8);

		//����̃t���O���I���ŁA���������Ă�Ȃ�true��Ԃ�
		if (msub[i].flag == true) {
			HitPolyDim = MV1CollCheck_Capsule(ModelHandle, ModelHandleFrameIndex, v1, v2, SHOT_CAPSULE_DIVNUM);
			if (HitPolyDim.HitNum >= 1) {
				//�R���W���������X�V����
				MV1RefreshCollInfo(ModelHandle, ModelHandleFrameIndex);

				return true;
			}
		}
	}

	//�R���W�������̌�n��
	MV1CollResultPolyDimTerminate(HitPolyDim);

	return false;
}

bool Shot::collision_detection(Substance *Sub, VECTOR v, int ModelHandle, int ModelHandleFrameIndex) {
	Substance *mSub = Sub;
	substance *msub = mSub->getSub();
	MV1_COLL_RESULT_POLY_DIM HitPolyDim;
	int msize = mSub->getSize();

	for (int i = 0; i < msize; i++) {
		//�R���W���������\�z����
		MV1SetupCollInfo(ModelHandle, ModelHandleFrameIndex, 8, 8, 8);

		//����̃t���O���I���ŁA���������Ă�Ȃ�true��Ԃ�
		if (msub[i].flag == true) {
			HitPolyDim = MV1CollCheck_Sphere(ModelHandle, ModelHandleFrameIndex, v, SHOT_CAPSULE_R);
			if (HitPolyDim.HitNum >= 1) {
				//�R���W���������X�V����
				MV1RefreshCollInfo(ModelHandle, ModelHandleFrameIndex);

				return true;
			}
		}
	}

	//�R���W�������̌�n��
	MV1CollResultPolyDimTerminate(HitPolyDim);

	return false;
}

bool Shot::collision_detection(Substance *Sub, VECTOR v, int ModelHandleFrameIndex) {
	Substance *mSub = Sub;
	substance *msub = mSub->getSub();
	MV1_COLL_RESULT_POLY_DIM HitPolyDim;
	int msize = mSub->getSize();

	for (int i = 0; i < msize; i++) {
		//�R���W���������\�z����
		MV1SetupCollInfo(msub[i].MHandle, ModelHandleFrameIndex, 8, 8, 8);

		//����̃t���O���I���ŁA���������Ă�Ȃ�true��Ԃ�
		if (msub[i].flag == true) {
			HitPolyDim = MV1CollCheck_Sphere(msub[i].MHandle, ModelHandleFrameIndex, v, SHOT_CAPSULE_R);

			if (HitPolyDim.HitNum >= 1) {
				//�R���W���������X�V����
				MV1RefreshCollInfo(msub[i].MHandle, ModelHandleFrameIndex);

				return true;
			}
		}
	}

	//�R���W�������̌�n��
	MV1CollResultPolyDimTerminate(HitPolyDim);

	return false;
}

bool Shot::collision_detection(Substance *Sub, character* cha, VECTOR v, int ModelHandleFrameIndex, int power) {
	Substance *mSub = Sub;
	substance *msub = mSub->getSub();
	MV1_COLL_RESULT_POLY_DIM HitPolyDim;
	int msize = mSub->getSize();

	for (int i = 0; i < msize; i++) {
		//�R���W���������\�z����
		MV1SetupCollInfo(msub[i].MHandle, ModelHandleFrameIndex, 8, 8, 8);

		//����̃t���O���I���ŁA���������Ă�Ȃ�true��Ԃ�
		if (msub[i].flag == true) {
			HitPolyDim = MV1CollCheck_Sphere(msub[i].MHandle, ModelHandleFrameIndex, v, SHOT_CAPSULE_R);

			if (HitPolyDim.HitNum >= 1) {
				//�R���W���������X�V����
				MV1RefreshCollInfo(msub[i].MHandle, ModelHandleFrameIndex);

				//HP�����炷
				cha[i].hp -= power;

				//HP��0�ɂȂ�����A���f��������
				if (cha[i].hp <= 0) {
					msub[i].flag = false;
					msub[i].fall_flag = true;
					
					if (cha[i].knd == 1) {//�|���ꂽ�̂��G�Ȃ�A���₷
						down_enemy_num++;
					} else if (cha[i].knd == 0) {//�|���ꂽ�̂��v���C���[�Ȃ�Aover_flag��true�ɂ���
						over_flag = true;
					}
				}

				//�R���W�������̌�n��
				MV1CollResultPolyDimTerminate(HitPolyDim);

				return true;
			}
		}
	}

	//�R���W�������̌�n��
	//MV1CollResultPolyDimTerminate(HitPolyDim);

	return false;
}

bullet* Shot::getBul() {
	return &bul;
}