#include "EffectManager.h"

EffectManager::EffectManager()
{
}

EffectManager::~EffectManager()
{
	for (unsigned int i = 0; i < snowFrag.size(); i++)
	{
		delete snowFrag[i];
	}
	snowFrag.clear();
}

void EffectManager::Draw(void)
{
	for (unsigned int i = 0; i < snowFrag.size(); i++)	//くそ
	{
		snowFrag[i]->Draw();
	}
}


void EffectManager::Update(void)
{
	for (unsigned int i = 0; i < snowFrag.size(); i++)
	{
		if (snowFrag[i]->Update() == false)	//falseが帰ってきたら削除
		{
			delete snowFrag[i];
			snowFrag.erase(snowFrag.begin() + i);
			i--;
		}
	}
}
