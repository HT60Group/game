#ifndef _Scv_H_
#define _Scv_H_

#include "Army.h"

using namespace cocos2d;
class Scv :public Army
{
public:
	CREATE_FUNC(Scv);
	virtual bool init();
	virtual void showUI();

	//¶ÁÈ¡ÅäÖÃÎÄ¼ş
	//virtual void readJson();
};
#endif