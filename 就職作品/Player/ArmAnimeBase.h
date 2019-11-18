#pragma once
#include"../main.h"
class ArmAnimeBase {
public:
	virtual ArmAnimeBase* Anime(D3DXMATRIX *NowMat) = 0;
protected:
	D3DXMATRIX endMat, startMat;
	float animeFrame;
	float animeSpeed;
};