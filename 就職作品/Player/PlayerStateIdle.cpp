#include"PlayerStateIdle.h"
#include"Player.h"
#include"MakeSnowBallState.h"
#include"../Item/DecorationManager.h"


PlayerStateIdle::PlayerStateIdle(D3DXMATRIX *StartMatL, D3DXMATRIX *StartMatR):animeFrame(0), KeyFlag(false)
{
	startMatL = *StartMatL;
	startMatR = *StartMatR;

	D3DXMATRIX EndRotRTmp, EndTransRTmp, EndRotZLTmp, EndRotXLTmp, EndTransLTmp;

	D3DXMatrixRotationZ(&EndRotZLTmp, D3DXToRadian(-90));
	D3DXMatrixRotationX(&EndRotXLTmp, D3DXToRadian(90));
	D3DXMatrixTranslation(&EndTransLTmp, -1.8f, -1.5f, -2.0f);		//カメラからの距離

	endMatL = EndRotZLTmp * EndRotXLTmp * EndTransLTmp;			//待機の位置

	D3DXMatrixRotationZ(&EndRotRTmp, D3DXToRadian(30));
	D3DXMatrixTranslation(&EndTransRTmp, 1.8f, -1.5f, 3.0f);		//カメラからの距離

	endMatR = EndRotRTmp * EndTransRTmp;			//待機の位置
}

PlayerStateIdle::~PlayerStateIdle()
{
}

PlayerStateBase* PlayerStateIdle::Anime(D3DXMATRIX *NowMatL, D3DXMATRIX *NowMatR)
{
	animeFrame += AnimeSpeed;

	if (animeFrame > 1.0f)
	{
		animeFrame = 1.0f;
	}

	QuaternionAnime(NowMatL, NowMatL, &startMatL, &endMatL, animeFrame);		//終わりの状態に移行しキープする
	QuaternionAnime(NowMatR, NowMatR, &startMatR, &endMatR, animeFrame);


	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)		//何か投げられる状態なら
	{
		if (GetPlayer.IsThrowAnything() == true)
		{
			return new WindUpState(NowMatR);
		}
	}
	
	if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
	{
		if(KeyFlag == true)return nullptr;		//拾ったあと押しっぱなしで雪玉を作れないようにしている
		if(GetPlayer.CanMakeSnowBall() == true)
		{
			return new MakeSnowBallState(NowMatL, NowMatR);	
		}
		else
		{
			KeyFlag = true;
			return nullptr;		//拾える状態なら雪玉を作らない(新しく拾えないが近くにデコレーションがあって作れないという状況が発生する☆)
		}
	}
	else
	{
		KeyFlag = false;
	}
	return nullptr;
}
