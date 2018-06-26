#include"AIManager.h"
#include"cocos2d.h"
#include "Scene/Astar.h"
#include"Scene/MapLayer.h"
using namespace cocos2d;

std::list<cocos2d::Point> Findway(cocos2d::Point start, cocos2d::Point end, std::vector<std::vector<int>> &_maze);


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
void Findway(cocos2d::Point start, cocos2d::Point end, std::vector<std::vector<int>> &_maze,Army* army)
{
	Astar astar;
	astar.InitAstar(_maze);
	astar.GetPath(start, end,army);
	return;

}

void AIManager::move(Army* army,Point endPos)
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
		return	;
	}

	army->way.pop_front();
	auto temp_pos = MapLayer::ConvertToScene(temp_tile.x, temp_tile.y, MapLayer::map);
	log("temppos<%f,%f>", temp_pos.x, temp_pos.y);
	auto tar_pos = temp_pos - map_pos;
	
	auto callfunc = [&,army]()
	{
		log("call/////////////////////////////////////////////////////////////////////");
		AIManager::move(army,endPos); 
	
	   
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
						auto mousePos= Point( static_cast<EventMouse*>(event)->getCursorX(),static_cast<EventMouse*>(event)->getCursorY());
						auto mapPos = MapLayer::map->getPosition();
						auto endPos = mousePos - mapPos;
						auto mouse_tile = MapLayer::ConvertToMap(mousePos.x, mousePos.y, MapLayer::map)+Point(n,n);
						
						auto maze = MapLayer::Collidable();
						if (maze[mouse_tile.x][mouse_tile.y] == 0)
						{
							auto start_pos = army->getPosition() + MapLayer::map->getPosition();
							auto start_tile = MapLayer::ConvertToMap(start_pos.x, start_pos.y, MapLayer::map);
							Findway(start_tile, mouse_tile, maze, army);
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

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener,this);
}

std::vector<Army*> AIManager::m_armyVec;
std::vector<Army*> AIManager::m_enemyArmyVec;
std::vector<Army*> AIManager::s_armyVec;