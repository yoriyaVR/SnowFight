#pragma once
#include"MapObj.h"
#include"../ResourceManager.h"
class Tree : public MapObj
{
public:
	Tree(D3DXVECTOR3 Pos);		//置く座標を渡す
	~Tree();
private:
	D3DXVECTOR3 pos;
};


