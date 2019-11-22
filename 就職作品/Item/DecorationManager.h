#pragma once
#include<vector>
#include"DecorationBase.h"
#include"Decoration_RedBall.h"
#include"Decoration_BlueBall.h"
#include"Decoration_YellowBall.h"

class DecorationManager {
public:
	DecorationManager();
	~DecorationManager();
	std::vector<DecorationBase*> decoration;
	bool CheckForCanPicUp(const D3DXVECTOR3 *_Pos);
	DecorationID PickUp(const D3DXVECTOR3 *_Pos);
	void Drop(const D3DXVECTOR3 *_Pos, DecorationID ID);

	void Draw(void);
	void Updata(void);
private:
};