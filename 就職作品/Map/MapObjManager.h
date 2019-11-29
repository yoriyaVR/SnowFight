#pragma once
#include<vector>
#include"MapObj.h"
#include"Tree.h"
#include"Bench.h"
#include"XmasTree.h"
#include"Bobbin_Red.h"

class MapObjManager {
public:
	std::vector<MapObj*> mapObj;

	MapObjManager();
	~MapObjManager();

	void SetTree(D3DXVECTOR3 Pos, float Ang);
	void SetBench(D3DXVECTOR3 Pos, float Ang);
	void SetBobbin_Red(D3DXVECTOR3 Pos, float Ang);
	void SetXmasTree(D3DXVECTOR3 Pos);

	void Draw();
	void Update();
};
