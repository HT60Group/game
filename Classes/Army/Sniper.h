#ifndef _Sniper_H_
#define _Sniper_H_

#include "Entity.h"

using namespace cocos2d;
class Sniper :public Entity
{
public:
	CREATE_FUNC(Sniper);
	virtual bool init();

};
#endif