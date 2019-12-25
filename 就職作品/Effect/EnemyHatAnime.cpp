#include "EnemyHatAnime.h"

EnemyHatAnime::EnemyHatAnime(Enemy &Enemy, SnowBall &SnowBall, bool HeadShot)
{
	//初期化

	mesh = GetResource.GetXFILE("EnemyHat.x");
	mat = startRotMat = Enemy.GetHatMat();

	//回転軸を求める
	D3DXVECTOR3 SnowBallMoveVec;

	SnowBallMoveVec = SnowBall.GetMoveVec();

	SnowBallMoveVec.y = 0;		//Y方向は無視する
	D3DXVec3Normalize(&SnowBallMoveVec, &SnowBallMoveVec);		//雪玉の方向ベクトルの逆に倒れる

	D3DXVec3Cross(&rotAxis, &D3DXVECTOR3(0, 1, 0), &SnowBallMoveVec);			//Y方向と雪玉の進行方向で外積を求め回転軸にする

	D3DXMATRIX InvMat;
	InvMat = startRotMat;

	D3DXMatrixInverse(&InvMat, NULL, &InvMat);		//逆行列を作る

	D3DXVec3TransformNormal(&rotAxis, &rotAxis, &InvMat);		//回転軸を対象のローカル座標に変換する

	moveVec = D3DXVECTOR3(0.0f, 0.8f, 0.0f);

	if (HeadShot == true)
	{
		moveVec.y = 1.5f;
	}

	moveVec += SnowBall.GetMoveVec();

	
}

void EnemyHatAnime::Draw()
{
	lpD3DDevice->SetTransform(D3DTS_WORLD, &mat);
	DrawMesh(&mesh);
}

bool EnemyHatAnime::Update()
{
	D3DXMatrixRotationAxis(&rotMat, &rotAxis, D3DXToRadian(15));

	
	//mat = rotMat * startRotMat;		//最初の姿勢に回転行列を足していく
	mat = rotMat * mat;		//回転行列を足して回転させていく

	

	D3DXMATRIX TmpTransMat;

	moveVec.y -= 0.1f;

	D3DXMatrixTranslation(&TmpTransMat, moveVec.x, moveVec.y, moveVec.z);
	mat = mat * TmpTransMat;

	if (mat._42 < 0.0f)
	{
		return false;
	}

	return true;
}