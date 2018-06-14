#include"cocos2d.h"
#include"MapManager.h"
#include"MapScene.h"

using namespace cocos2d;

bool MapManager::init()
{
	if(!Node::init())
	{
		return false;
	}
	return true;
}

void MapManager::SetMouseController()
{
	auto listener = EventListenerMouse::create();
	listener->onMouseDown = [&](Event*) {_isClick = true; };
	listener->onMouseMove=[&](Event* event)
	{
		_mousePosition.x = static_cast<EventMouse*>(event)->getCursorX();
		_mousePosition.y = static_cast<EventMouse*>(event)->getCursorY();
	};

	listener->onMouseUp = [&](Event*) {_isClick = false; };

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void MapManager::ControllerUpdate(float dt)
{
	auto _map = static_cast<MapScene*>(this->getParent())->map;//得到地图
	auto _visibleSize = Director::getInstance()->getVisibleSize();//屏幕大小
	auto _currentPos = _map->getPosition();//地图的绝对坐标
	auto _orgin = Director::getInstance()->getVisibleOrigin();//屏幕坐标原点
	auto _mapTiledNum = _map->getMapSize();//瓦片数目
	auto _tiledSize = _map->getTileSize();//瓦片大小
	

	Point _mapSize = Point(_mapTiledNum.width*_tiledSize.width, _mapTiledNum.width*_tiledSize.height);
	int speed = 20;
	if (_isClick == true)
	{
		log("pos_gl (%.2f,%.2f)", _mousePosition.x, _mousePosition.y);
		Vec2 TiledPos = static_cast<MapScene*>(this->getParent())->ConvertToMap(_mousePosition.x, _mousePosition.y);
		log("pos_ti (%.2f,%.2f)", TiledPos.x, TiledPos.y);
	}
	/*log("pos_world(%.2f,%.2f)", ConvertToMap(_mousePosition.x)
		, scene->ConvertToMap(_mousePosition.y);*/

	if (_mousePosition.x < (_visibleSize.width / 32) && !_isClick)
	{
		if (_currentPos.x < 0)
		{
			_currentPos += Point(speed, 0);
		}
	}


	if (_mousePosition.x > (_visibleSize.width*31 / 32) && !_isClick)
	{
		if (_currentPos.x+_mapSize.x > _visibleSize.width)
		{
			_currentPos += Point(-speed, 0);
		}
	}

	if (_mousePosition.y < (_visibleSize.height / 32) && !_isClick)
	{
		if (_currentPos.y < 0)
		{
			_currentPos += Point(0, speed);
		}
	}
	
	if (_mousePosition.y > (_visibleSize.height*31 / 32) && !_isClick)
	{
		if (_currentPos.y+ _mapSize.y > _visibleSize.height)
		{
			_currentPos += Point(0, -speed);
		}
	}

	_map->setPosition(_currentPos);
}