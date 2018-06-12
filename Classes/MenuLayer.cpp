#include "MenuLayer.h"
#include "cocos2d.h"

using namespace cocos2d;

bool MenuLayer::init()
{
	auto _visibleSize = Director::getInstance()->getVisibleSize();//屏幕大小
	

	menuLayer = LayerColor::create(Color4B(225, 105, 180,80));
	
	menuLayer->setPosition(_visibleSize.width *5/6, 0);
	this->addChild(menuLayer);

	button_producer = MenuItemImage::create("producer.png", "producer.png");//缺少回调函数
	button_producer->setPosition(Point(_visibleSize.width * 5 / 6, _visibleSize.height / 2));
	this->addChild(button_producer, 1);
	return true;
}
