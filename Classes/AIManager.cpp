#include"AIManager.h"
#include"cocos2d.h"
using namespace cocos2d;

bool AIManager::init()
{
	/*selection = LayerColor::create(Color4B(0, 128, 128, 100));*/
	//selection->setContentSize(CCSizeMake(120, 80));
	/*selection->setPosition(Point(500, 500));*/
	/*this->addChild(selection);*/
	this->selectionController();
	return true;
}
void AIManager::selectionController()
{
	auto listener = EventListenerTouchOneByOne::create();
	
	listener->onTouchBegan = [&](Touch* touch, Event* event)
	{
		auto _visibleSize = Director::getInstance()->getVisibleSize();
		mousePos_began = touch->getLocation();
		if (mousePos_began.x < (_visibleSize.width * 5 / 6))
		{
			log("began=(%f,%f)", mousePos_began.x, mousePos_began.y);
			selection = LayerColor::create(Color4B(0, 128, 128, 100));
			selection->setContentSize(CCSizeMake(0, 0));
			this->addChild(selection);
		}
		return true;
	};
	listener->onTouchMoved = [&](Touch* touch, Event* event)
	{
		mousePos_moved = touch->getLocation();
		auto _visibleSize = Director::getInstance()->getVisibleSize();
	
		if (mousePos_began.x < (_visibleSize.width * 5 / 6))
		{
			selection->setContentSize(CCSize(mousePos_moved.x - mousePos_began.x, mousePos_moved.y - mousePos_began.y));
			selection->setPosition(mousePos_began);
		}
		

		log("moved=(%f,%f)", mousePos_moved.x, mousePos_moved.y);

	};
	listener->onTouchEnded = [&](Touch* touch, Event* event)
	{
		mousePos_ended = touch->getLocation();
		auto _visibleSize = Director::getInstance()->getVisibleSize();
		log("ended=(%f,%f)", mousePos_ended.x, mousePos_ended.y);
		if (mousePos_began.x < (_visibleSize.width * 5 / 6))
		{
			selection->setContentSize(CCSize(0,0));
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
}