#include "BackToTitle.h"
#include"../TitleScene/TitleScene.h"

BackToTitle::BackToTitle() : nowState(false)
{
	tex = GetResource.GetTexture(BackToTitle_Tex);
	D3DXMatrixTranslation(&mat, 0, 0, 0);

	YesButton = new BackToTitleButton();
	ButtonData TmpData;
	TmpData.Pos = D3DXVECTOR2(440, 300);
	TmpData.BoxSize = D3DXVECTOR2(132, 132);
	YesButton->Initialize(TmpData, GetResource.GetTexture(YesButton_Tex));		//CSVから読み込むように変更する☆
	
	NoButton = new BackToTitleButton();
	TmpData.Pos = D3DXVECTOR2(740, 300);
	TmpData.BoxSize = D3DXVECTOR2(132, 132);
	NoButton->Initialize(TmpData, GetResource.GetTexture(NoButton_Tex));
}

BackToTitle::~BackToTitle()
{
}

void BackToTitle::Draw()
{
	if (nowState == true)		//タイトルバック確認画面が呼ばれている間のみ描画
	{
		RECT RectTmp = { 0, 0, 1280, 720 };
		lpSprite->SetTransform(&mat);
		lpSprite->Draw(tex, &RectTmp, &D3DXVECTOR3(0, 0, 0), NULL, D3DCOLOR_ARGB(255, 255, 255, 255));

		YesButton->Draw();
		NoButton->Draw();

		GetCursor.Draw();
	}
}

RETURN_STATE BackToTitle::CallBackToTitle()
{
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		if (isESCKey == true)
		{
			if (nowState == true)
			{
				//カーソル
				GetCursor.ShowCursor(false);

				nowState = false;
				isESCKey = false;	//ESCを連続して押せないように
				return CANCEL;
			}
			else
			{
				GetCursor.ShowCursor(true);
				nowState = true;
				isESCKey = false;	//実行ESCを連続して押せないように
			}
		}
	}
	else
	{
		isESCKey = true;
	}
	
	if (nowState == false)return NOT_ACTIVE;

	YesButton->Update();
	NoButton->Update();

	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		if (YesButton->GetState() == true)
		{
			GetSound.Play2D(Success_Sound);
			nowState = false;
			GetCursor.ShowCursor(false);

			nowState = false;

			return RETURN_TITLE;
		}
		if (NoButton->GetState() == true) 
		{
			nowState = false;
			GetCursor.ShowCursor(false);
			nowState = false;
			return CANCEL;
		}
	}

	return WAITING_INPUT;
}
