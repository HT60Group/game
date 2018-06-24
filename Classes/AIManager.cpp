#include"AIManager.h"
#include"cocos2d.h"
#include "Scene/Astar.h"
#include"Scene/MapLayer.h"
using namespace cocos2d;


bool AIManager::init()
{
	/*selection = LayerColor::create(Color4B(0, 128, 128, 100));*/
	//selection->setContentSize(CCSizeMake(120, 80));
	/*selection->setPosition(Point(500, 500));*/
	/*this->addChild(selection);*/
	this->selectionController();
	this->moveController();

	return true;
}
void AIManager::selectionController()
{
	auto listener = EventListenerTouchOneByOne::create();
	/*int i = 0;*/
	
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
		s_armyVec.clear();

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
		
		
		for (auto army:m_armyVec)
		{
			auto pos_s = army->getScenePosition();
			if (((pos_s.x-mousePos_began.x)*(pos_s.x-mousePos_ended.x)<0)
				&& ((pos_s.y - mousePos_began.y)*(pos_s.y - mousePos_ended.y) < 0))
			{
				
				s_armyVec.push_back(army);
				
			}
		}
		for (auto it = s_armyVec.begin(); it != s_armyVec.end(); it++)
		{
			log("s");
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
	//log("controller");
	this->setTouchEnabled(false);
}
void AIManager::moveController()
{
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [&](Touch* touch, Event* event)
	{
		
		return true;
	};
	listener->onTouchMoved = [&](Touch* touch, Event* event)
	{
		return true;
	};
	listener->onTouchEnded = [&](Touch* touch, Event* event)
	{

		auto mousePos_ended = touch->getLocation();
		//if (static_cast<int>(static_cast<EventMouse*>(event)->getMouseButton()) == 1)
		//{
			if (s_armyVec.begin() != s_armyVec.end())
			{

				auto it = s_armyVec.begin();
				auto _currentPos = MapLayer::map->getPosition();//地图的绝对坐标
				auto pos = touch->getLocation() - _currentPos;

				for (; it != s_armyVec.end(); it++)
				{
					MoveTo* moveto = MoveTo::create(0.2f, Point(pos.x, pos.y));
					(*it)->runAction(moveto);
				}


				log("pos(%f,%f)", pos.x, pos.y);
				return true;

			}
		//}
		
		return true;
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
}

std::vector<Army*> AIManager::m_armyVec;
std::vector<Army*> AIManager::m_enemyArmyVec;
std::vector<Army*> AIManager::s_armyVec;