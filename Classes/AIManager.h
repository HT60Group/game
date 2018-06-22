#pragma once
#include"cocos2d.h"
using namespace cocos2d;
class AIManager :public cocos2d::Layer
{
public:
	CREATE_FUNC(AIManager);
	virtual bool init();
	void selectionController();
	/*LayerColor* layer;*/
private:
	Point mousePos_began = cocos2d::Point(0,0);
	Point mousePos_moved = cocos2d::Point(0, 0);
	Point mousePos_ended = cocos2d::Point(0, 0);
	LayerColor* selection;

	
	
};