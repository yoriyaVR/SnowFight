#pragma once
#include"../main.h"
#include<vector>
#include"SnowBall.h"
#include"../Effect/EffectManager.h"
class SnowBallManager {
private:
public:
	std::vector <SnowBall*> snowBall;
	SnowBallManager();
	~SnowBallManager();
	//初期化にsnowBallInitValue型をポインタで渡す
	void SetSnowBall(SnowBallInitValue *snowBallInitValue);
	void Draw(void);
	void Update(void);
};
