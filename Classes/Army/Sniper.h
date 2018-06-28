#ifndef _Sniper_H_
#define _Sniper_H_

#include "Army.h"

using namespace cocos2d;
class Sniper :public Army
{
public:
	Sniper();
	~Sniper();
	CREATE_FUNC(Sniper);
	virtual bool init();
	virtual void showUI();

	//¶ÁÈ¡ÅäÖÃÎÄ¼ş
	//virtual void readJson();
};
#endif