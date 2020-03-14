#pragma once
#include"../ResourceManager.h"
#include"../SingletonBase.h"
#include<vector>

struct AddSnowBallData {
	D3DXMATRIX mat;
	int alpha;
};

class AddSnowBallUI : public SingletonBase<AddSnowBallUI> {
public:
	AddSnowBallUI();
	~AddSnowBallUI();
	void AddSnowBall();		//入手した場合呼ぶ(現状1つのみ追加なので数を変える場合変更する)
	void Draw();
	void Update();
private:
	std::vector<AddSnowBallData*> AddUI;
	LPDIRECT3DTEXTURE9 tex;
};