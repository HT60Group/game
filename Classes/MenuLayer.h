#pragma once
#include "cocos2d.h"
using namespace cocos2d;

class MenuLayer :public Layer
{
public:
	CREATE_FUNC(MenuLayer);
	virtual bool init();
	LayerColor* menuLayer;
	MenuItemImage* button_producer;



};