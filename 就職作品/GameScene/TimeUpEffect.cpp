#include"TimeUpEffect.h"
GameSceneState TimeUpEffect::AddUpdate()
{
	timeUpEffectCnt++;
	if (timeUpEffectCnt > timeUpEffectPlayTime)
	{
		return SWITCH_RESULT;		//移行先の状態を返す
	}
	return TIME_UP_EFFECT;
}