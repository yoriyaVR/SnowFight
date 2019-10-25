#pragma once
#include<vector>
#include"../main.h"
#include"../ResourceManager.h"
#include"../commonObj/SnowBallManager.h"
class Enemy {
private:
	XFILE mesh;
	D3DXMATRIX mat, rotMat;
	virtual void ShootSnowBall(float TragetAng);
	virtual void EngagingMode(void);		//交戦中の行動
	virtual void FreeMode(void);			//未発見時の行動
	virtual void StageBorderProcessing(void);

	int ShootCoolTime;					//雪玉発射のクールタイム
	float MoveInterval;						//freeMode時動くまでの時間
	float freeMoveCnt;							//freeMode時動く必要のある時間の時間
	SnowBallManager *snowBallManager;		//snowBallManagerのポインタを保存する

	float searchRange;						//索敵範囲
	const float maxLength = 40.0f, minLength = 15.0f;						//交戦時の距離の最大最小範囲
	float limitLength;		//交戦時取る距離
	D3DXVECTOR3 moveVec = D3DXVECTOR3(0.0f, 0.0f, 0.0f);			//交戦時の移動		球発射時は止まるようにする
protected:

	

public:
	Enemy(D3DXVECTOR3);
	~Enemy();
	virtual bool Update(SnowBallManager *snowBallManager);
	virtual void Draw(void);
	virtual D3DXVECTOR3 GetPos(void);
	virtual void GetCollisionSphere(CollisionSphere *CollisionSphereA, CollisionSphere *CollisionSphereB);
};