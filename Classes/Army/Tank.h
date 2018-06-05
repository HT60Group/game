#ifndef _Tank_H_
#define _Tank_H_

#include "Entity.h"

using namespace cocos2d;
class Tank :public Entity
{
public:
	CREATE_FUNC(Tank);
	virtual bool init();

};
#endif