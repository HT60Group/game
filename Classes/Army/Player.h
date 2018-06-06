#ifndef __Player_H__
#define __Player_H__

#include"cocos2d.h"
#include "Entity.h"
using namespace cocos2d;

#define JUMP_ACTION_TAG 1
class Player : public Entity {
public:
	CREATE_FUNC(Player);
	virtual bool init();
	void run();
protected:
	int MovingSpeed;
	int AttackDistance;
	int DPS;
	int MineCost;
	int ElectCost;
	int ViewDistance;
	void SpecialEffect();
	int TimeCost;
	bool Belong();
};
#endif