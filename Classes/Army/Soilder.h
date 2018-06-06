#ifndef _Soilder_H_
#define _Soilder_H_

#include "Entity.h"

using namespace cocos2d;
class Soilder :public Entity
{
public:
	CREATE_FUNC(Soilder);
	virtual bool init();

};
#endif