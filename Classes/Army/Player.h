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
	int movingspeed;
	int attackdistance;
	int DPS;
	int minecost;
	int electcost;
	int viewdistance;
	void specialeffect();
	int timecost;
	bool belong();
};
#endif