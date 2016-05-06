#include "./../../../h/global.h"


Shot::Shot()
{
}

/*
	自分が打った時、相手にあたってるかどうか判定する

	Sub:相手(障害物、モデル)のアドレス
	v1, v2:自分のベクトル
*/
bool Shot::collision_detection(Substance *Sub, VECTOR v1, VECTOR v2, int ModelHandle, int ModelHandleFrameIndex) {
	Substance *mSub = Sub;
	substance *msub = mSub->getSub();
	MV1_COLL_RESULT_POLY_DIM HitPolyDim;
	int msize = mSub->getSize();

	for (int i = 0; i < msize; i++) {
		//コリジョン情報を構築する
		MV1SetupCollInfo(ModelHandle, ModelHandleFrameIndex, 8, 8, 8);

		//相手のフラグがオンで、かつ当たってるならtrueを返す
		if (msub[i].flag == true) {
			HitPolyDim = MV1CollCheck_Capsule(ModelHandle, ModelHandleFrameIndex, v1, v2, SHOT_CAPSULE_DIVNUM);
			if (HitPolyDim.HitNum >= 1) {
				//コリジョン情報を更新する
				MV1RefreshCollInfo(ModelHandle, ModelHandleFrameIndex);

				return true;
			}
		}
	}

	//コリジョン情報の後始末
	MV1CollResultPolyDimTerminate(HitPolyDim);

	return false;
}

bullet* Shot::getBul() {
	return &bul;
}