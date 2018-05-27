
#ifndef _TOLLScene_H_
#define _TOLLScene_H_

#include"cocos2d.h"
using namespace cocos2d;

class TOLLScene :public Layer
{
public:
	static Scene* createScene();
	CREATE_FUNC(TOLLScene);
	virtual bool init();
};
#endif

