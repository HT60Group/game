#ifndef _Dog_H_
#define _Dog_H_

#include "Entity.h"

using namespace cocos2d;
class Dog :public Entity
{
public:
	CREATE_FUNC(Dog);
	virtual bool init();
	
};
#endif