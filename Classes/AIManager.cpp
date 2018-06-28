#include"AIManager.h"
#include"cocos2d.h"
#include "Scene/Astar.h"
#include"Scene/MapLayer.h"
using namespace cocos2d;

std::list<cocos2d::Point> Findway(cocos2d::Point start, cocos2d::Point end, std::vector<std::vector<int>> &_maze);
Animate* AIManager::animate;
bool AIManager::init()
{
	
	


	this->selectionController();
	this->moveController();
	
	return true;
}
void AIManager::S_Update(float dt)
{
	for (auto army : s_armyVec)
	{
		if (!army->getM_isDied())
		{
			army->runAction(AIManager::animate);
			

		}
	}
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
				selection->setContentSize(CCSize(0, 0));
			}



			//dog_animate
			auto animation_dog = Animation::create();
			for (int i = 1; i < 3; i++)
			{
				char nameSize[100] = { 0 };
				sprintf(nameSize, "dog_%d.png", i);
				animation_dog->addSpriteFrameWithFile(nameSize);
			}
			animation_dog->setDelayPerUnit(0.1f);
			animation_dog->setLoops(-1);
			animation_dog->setRestoreOriginalFrame(true);
			AIManager::animate = Animate::create(animation_dog);







			


			for (auto army : m_armyVec)
			{
				auto pos_s = army->getScenePosition();
				if (((pos_s.x - mousePos_began.x)*(pos_s.x - mousePos_ended.x)<0)
					&& ((pos_s.y - mousePos_began.y)*(pos_s.y - mousePos_ended.y) < 0))
				{
					//可用


					s_armyVec.push_back(army);
					if ((army->kind) == 1)
					{
						army->runAction(animate->clone());
					}

				}
			}
		
		
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	//log("controller");
	this->setTouchEnabled(false);
}
void Findway(cocos2d::Point start, cocos2d::Point end, std::vector<std::vector<int>> &_maze, Army* army)
{
	Astar astar;
	astar.InitAstar(_maze);
	astar.GetPath(start, end, army);
	return;

}

void AIManager::move(Army* army, Point endPos)
{
	auto map_pos = MapLayer::map->getPosition();//地图绝对坐标
	Point temp_tile;
	if (army->way.begin() != army->way.end())
	{

		temp_tile = (army->way).front();
		log("tempTile<%f,%f>", temp_tile.x, temp_tile.y);
		for (auto path : army->way)
		{
			log("path<%f,%f>", path.x, path.y);
		}
	}
	else
	{
		MoveTo* movetoend = MoveTo::create(0.2f, endPos);
		army->runAction(movetoend);
		return;
	}

	army->way.pop_front();
	auto temp_pos = MapLayer::ConvertToScene(temp_tile.x, temp_tile.y, MapLayer::map);
	log("temppos<%f,%f>", temp_pos.x, temp_pos.y);
	auto tar_pos = temp_pos - map_pos;

	auto callfunc = [&, army]()
	{
		log("call/////////////////////////////////////////////////////////////////////");
		AIManager::move(army, endPos);


	};
	auto callFunc = CallFunc::create(callfunc);
	MoveTo* moveto = MoveTo::create(0.2f, tar_pos);

	Action* actions = Sequence::create(moveto, callFunc, NULL);

	army->runAction(actions);


}
void AIManager::move(Army* army)
{
	auto map_pos = MapLayer::map->getPosition();//地图绝对坐标
	Point temp_tile;
	if (army->way.begin() != army->way.end())
	{

		temp_tile = (army->way).front();
		log("tempTile<%f,%f>", temp_tile.x, temp_tile.y);
		for (auto path : army->way)
		{
			log("path<%f,%f>", path.x, path.y);
		}
	}
	else
	{
		/*MoveTo* movetoend = MoveTo::create(0.2f, endPos);
		army->runAction(movetoend);*/
		return;
	}

	army->way.pop_front();
	auto temp_pos = MapLayer::ConvertToScene(temp_tile.x, temp_tile.y, MapLayer::map);
	log("temppos<%f,%f>", temp_pos.x, temp_pos.y);
	auto tar_pos = temp_pos - map_pos;

	auto callfunc = [&, army]()
	{
		log("call/////////////////////////////////////////////////////////////////////");
		AIManager::move(army);


	};
	auto callFunc = CallFunc::create(callfunc);
	MoveTo* moveto = MoveTo::create(0.2f, tar_pos);

	Action* actions = Sequence::create(moveto, callFunc, NULL);

	army->runAction(actions);


}
void AIManager::moveController()
{
	auto listener = EventListenerMouse::create();
	listener->onMouseDown = [&](Event* event)
	{
		return true;
	};
	listener->onMouseMove = [&](Event* event)
	{
		return true;
	};
	listener->onMouseUp = [&](Event* event)
	{
		if (static_cast<int>(static_cast<EventMouse*>(event)->getMouseButton()) == 1)
		{
			if (!s_armyVec.empty())
			{
				int n = 0;
				for (auto army : s_armyVec)
				{
					if (!army->getM_isDied())
					{
						army->stopAllActions();
						army->way.clear();
						auto mousePos = Point(static_cast<EventMouse*>(event)->getCursorX(), static_cast<EventMouse*>(event)->getCursorY());
						auto mapPos = MapLayer::map->getPosition();
						auto endPos = mousePos - mapPos;


						auto end_tile = MapLayer::ConvertToMap(mousePos.x, mousePos.y, MapLayer::map) + Point(n, n);

						auto maze = MapLayer::Collidable();

						if (maze[end_tile.x][end_tile.y] == 0)
						{
							auto start_pos = army->getPosition() + MapLayer::map->getPosition();
							auto start_tile = MapLayer::ConvertToMap(start_pos.x, start_pos.y, MapLayer::map);
							Findway(start_tile, end_tile, maze, army);
							AIManager::move(army);
							n++;
						}

					}
				}
				/*s_armyVec.clear();*/
			}




		}
		return true;
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

std::vector<Army*> AIManager::m_armyVec;
std::vector<Army*> AIManager::m_enemyArmyVec;
std::vector<Army*> AIManager::s_armyVec;