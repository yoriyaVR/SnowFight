#include "TurnToPlayer.h"
#include"EngagingMode.h"
#include"../Enemy.h"

EnemyStateBase * TurnToPlayer::Action(Enemy & Enemy)
{
	float Ang;

	Ang = Enemy.CalculateEnemyToPlayerAng();

	if (-5 <= Ang && Ang <= 5)
	{
		Enemy.Spin(Ang);
		return new EngagingMode();				//回転し終わったら状態遷移
	}

	if (Ang <= 0)
	{
		Enemy.Spin(-5);		//5度ずつ回転
	}
	else
	{
		Enemy.Spin(5);
	}
	
	return nullptr;
}
