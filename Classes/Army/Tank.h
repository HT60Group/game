#ifndef _Tank_H_
#define _Tank_H_

#include "Army.h"

using namespace cocos2d;
class Tank :public Army
{
public:
	Tank();
	~Tank();
	CREATE_FUNC(Tank);
	virtual bool init();
	virtual void showUI();

	//¶ÁÈ¡ÅäÖÃÎÄ¼ş
	//virtual void readJson();
};
#endif