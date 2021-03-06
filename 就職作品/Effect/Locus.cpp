#include "Locus.h"
#include"../DirectX/Direct3D.h"

SnowLocus::SnowLocus(const D3DXMATRIX &Mat)
{
	D3DXMatrixTranslation(&mat, Mat._41, Mat._42, Mat._43);

	vertex[0].Color = D3DCOLOR_ARGB(255, 255, 255, 255);
	vertex[1].Color = D3DCOLOR_ARGB(255, 255, 255, 255);
	vertex[2].Color = D3DCOLOR_ARGB(255, 255, 255, 255);
	vertex[3].Color = D3DCOLOR_ARGB(255, 255, 255, 255);


	tex = GetResource.GetTexture(SnowLocus_Tex);
}

SnowLocus::~SnowLocus()
{
}

void SnowLocus::Draw()
{
	Direct3D::GetInstance().GetD3DDevice()->SetFVF(FVF_VERTEX);
	Direct3D::GetInstance().GetD3DDevice()->SetRenderState(D3DRS_LIGHTING, FALSE);		//ライティング
	Direct3D::GetInstance().GetD3DDevice()->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);	//カリング
	Direct3D::GetInstance().GetD3DDevice()->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);		//加算合成オン
	Direct3D::GetInstance().GetD3DDevice()->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);			//Zバッファ書き込みオフ

	Direct3D::GetInstance().GetD3DDevice()->SetTexture(0, tex);

	Direct3D::GetInstance().GetD3DDevice()->SetTransform(D3DTS_WORLD, &billBoardMat);

	Direct3D::GetInstance().GetD3DDevice()->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, vertex, sizeof(VERTEX));

	Direct3D::GetInstance().GetD3DDevice()->SetRenderState(D3DRS_LIGHTING, TRUE);		//ライティング
	Direct3D::GetInstance().GetD3DDevice()->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);		//加算合成オフ
	Direct3D::GetInstance().GetD3DDevice()->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);	//カリングオン
	Direct3D::GetInstance().GetD3DDevice()->SetRenderState(D3DRS_ZWRITEENABLE, TRUE);			//Zバッファ書き込みオン
}

bool SnowLocus::Update()
{
	vertex[0].Tex = D3DXVECTOR2(0.0f, 0.0f);
	vertex[1].Tex = D3DXVECTOR2(1.0f, 0.0f);
	vertex[2].Tex = D3DXVECTOR2(1.0f, 1.0f);
	vertex[3].Tex = D3DXVECTOR2(0.0f, 1.0f);

	vertex[0].Pos = D3DXVECTOR3(-0.5f, 0.5f, 0.0f);
	vertex[1].Pos = D3DXVECTOR3(0.5f, 0.5f, 0.0f);
	vertex[2].Pos = D3DXVECTOR3(0.5f, -0.5f, 0.0f);
	vertex[3].Pos = D3DXVECTOR3(-0.5f, -0.5f, 0.0f);


	//段々と薄くしていく
	alpha -= 5;

	//見えなくなったら削除
	if (alpha < 0)
	{
		return false;
	}

	vertex[0].Color = D3DCOLOR_ARGB(alpha, 255, 255, 255);
	vertex[1].Color = D3DCOLOR_ARGB(alpha, 255, 255, 255);
	vertex[2].Color = D3DCOLOR_ARGB(alpha, 255, 255, 255);
	vertex[3].Color = D3DCOLOR_ARGB(alpha, 255, 255, 255);
	return true;
}

void SnowLocus::SetBillBoardMat(const D3DXMATRIX &BillBoardMat)
{
	billBoardMat = BillBoardMat * mat;
}
