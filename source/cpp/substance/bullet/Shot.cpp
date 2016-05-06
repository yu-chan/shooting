#include "./../../../h/global.h"


Shot::Shot()
{
}

/*
	�������ł������A����ɂ������Ă邩�ǂ������肷��

	Sub:����(��Q���A���f��)�̃A�h���X
	v1, v2:�����̃x�N�g��
*/
bool Shot::collision_detection(Substance *Sub, VECTOR v1, VECTOR v2) {
	Substance *mSub = Sub;
	substance *msub = mSub->getSub();
	int msize = mSub->getSize();
	for (int i = 0; i < msize; i++) {
		//����̃t���O���I���ŁA���������Ă�Ȃ�true��Ԃ�
		if (msub[i].flag == true) {
			MV1_COLL_RESULT_POLY_DIM HitPolyDim = MV1CollCheck_Capsule(ModelEnemy, ENEMY_MODEL_FRAMEINDEX, v1, v2, SHOT_CAPSULE_DIVNUM);
			if (HitPolyDim.HitNum >= 1) {
				return true;
			}
		}
	}
	return false;
}

bullet* Shot::getBul() {
	return &bul;
}