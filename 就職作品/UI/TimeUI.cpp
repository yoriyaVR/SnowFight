#include "TimeUI.h"

TimeUI::TimeUI()
{
	numberTex = GetResource.GetTexture(TimeNumber_Tex);
	D3DXMatrixTranslation(&numberOffsetMat, 10, 56, 0);

	logoTex = GetResource.GetTexture(TimeLogo_Tex);
	D3DXMatrixTranslation(&logoMat, 10, 10, 0);
}

TimeUI::~TimeUI()
{
}

void TimeUI::Draw()
{
	RECT RcLogo = { 0, 0, 194, 46 };
	lpSprite->SetTransform(&logoMat);
	lpSprite->Draw(logoTex, &RcLogo, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));


	int DisplayNum;
	const int NUM_DIGITS = 4;		//末尾に\0が挿入されるため3桁表示する際4をいれる
	char cTime[NUM_DIGITS];
	D3DXMATRIX NumberMat, NumberDisMat;

	D3DXMatrixTranslation(&NumberDisMat, 40, 0, 0);			//文字の間隔

	NumberMat = logoMat * numberOffsetMat;

	sprintf_s(cTime, sizeof(cTime), "%d", displayTime_s);		//1桁ずつ取り出せるように文字に変換
	

	for (int i = 0; i < NUM_DIGITS; i++)
	{
		if (cTime[i] == '\0')break;		//要素の終端ならbreak

		DisplayNum = cTime[i] - '0';		//数字に変換

		RECT RcNumber = { 46 * DisplayNum, 0, 46 * (DisplayNum + 1), 46 };

		lpSprite->SetTransform(&NumberMat);
		lpSprite->Draw(numberTex, &RcNumber, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

		NumberMat = NumberDisMat * NumberMat;			//右にずらす
	}
	
	//大きく薄くなっていく文字表示
	for (auto BoldNumber : BoldNumber)
	{
		RECT RcBoldNumber = { 46 * BoldNumber->DisplayNum, 0, 46 * (BoldNumber->DisplayNum + 1), 46 };

		D3DXMATRIX TmpMat;

		TmpMat = /*BoldNumber->ScalMat */ logoMat * numberOffsetMat;
		lpSprite->SetTransform(&TmpMat);
		lpSprite->Draw(numberTex, &RcBoldNumber, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
}

void TimeUI::Update()
{
	//10秒から強調とサウンド再生

	if (GetAsyncKeyState(VK_SPACE))
	{
		BoldNumber.push_back(new BoldNumberData);

		//終端の要素初期化
		auto Tmp = BoldNumber.back();
		Tmp->Alpha = 255;
		Tmp->DisplayNum = 9;
	}
}

void TimeUI::SetTime_s(int setTime_s)
{
	displayTime_s = setTime_s;
}
