#include "ThrowRAnime.h"
#include"ArmRAnimeMid.h"

ThrowRAnime::ThrowRAnime(D3DXMATRIX *StartMat)
{
	startMat = *StartMat;
	animeSpeed = 0.2;		//再生速度
	animeFrame = 0.0f;

	D3DXMATRIX EndRotXTmp, EndTransTmp;

	D3DXMatrixRotationX(&EndRotXTmp, D3DXToRadian(30));
	
	D3DXMatrixTranslation(&EndTransTmp, 1.5f, -3.0f, 3.0f);		//カメラからの距離

	endMat = EndRotXTmp * EndTransTmp;
}

ArmAnimeBase *ThrowRAnime::Anime(D3DXMATRIX *NowMat)
{
	animeFrame += animeSpeed;

	QuaternionAnime(NowMat, NowMat, &startMat, &endMat, animeFrame);

	if (animeFrame >= 1)
	{
		animeFrame = 1;
		return new ArmRAnimeMid(NowMat);
	}
	return nullptr;
}
