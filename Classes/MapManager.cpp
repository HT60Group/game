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
		Vec2 TiledPos = this->ConvertToMap(_mousePosition.x, _mousePosition.y,_map);
		log("pos_ti (%.2f,%.2f)", TiledPos.x, TiledPos.y);
		int posx = TiledPos.x;
		int posy = TiledPos.y;
		if (posx >= 0 && posx<75 && posy >= 0 && posy<75)
		{
			log("%d", _collidable[posx][posy]);
		}
		

	
	}


	if (_mousePosition.x < (_visibleSize.width / 6) && !_isClick)
	{
		if (_currentPos.x < 0)
		{
			_currentPos += Point(speed, 0);
		}
	}

	if (_mousePosition.x > (_visibleSize.width*5 / 6) && !_isClick)
	{
		if (_currentPos.x+_mapSize.x > _visibleSize.width)
		{
			_currentPos += Point(-speed, 0);
		}
	}

	if (_mousePosition.y < (_visibleSize.height / 6) && !_isClick)
	{
		if (_currentPos.y < 0)
		{
			_currentPos += Point(0, speed);
		}
	}
	
	if (_mousePosition.y > (_visibleSize.height*5 / 6) && !_isClick)
	{
		if (_currentPos.y+ _mapSize.y > _visibleSize.height)
		{
			_currentPos += Point(0, -speed);
		}
	}

	_map->setPosition(_currentPos);
}
void MapManager::fill_collidable()
{
	
	auto _map = static_cast<MapScene*>(this->getParent())->map;
	auto _meta = _map->getLayer("meta");
	
	
	for (int i=0; i < 75; i++)
	{
		std::vector<int> temp;
	
		for ( int j=0 ; j < 75; j++)
		{
			
			temp.push_back(1);
			/*log("%d,%d", i, j);*/
		}
		_collidable.push_back(temp);
	}
	for (int i=0; i < 75; i++)
	{
		for (int j=0; j < 75; j++)
		{
			int tiledGid = _meta->getTileGIDAt(Vec2(i, j));
			if (tiledGid)
			{
				_collidable[i][j] = 1;
			}
			else {
				_collidable[i][j] = 0;
			}
			log("(%d,%d)=%d", i, j, _collidable[i][j]);
			
		}
		
	}
}
bool MapManager::isCollidable(Point pos)
{
	if (!_collidable[pos.x][pos.y] )
	{
		return true;
	}
	return true;
}
Vec2 MapManager::ConvertToMap(float x, float y,TMXTiledMap* map)
{
	int tilewidth = map->getTileSize().width;
	int tileheight = map->getTileSize().height;//正确
											   /*log("tile.w=%d,tile.h=%d", tilewidth, tileheight);*/


											   //瓦片地图原点的gl坐标
	float mapOrginX = map->getPosition().x + map->getMapSize().width *tilewidth / 2;
	float mapOrginY = map->getPosition().y + map->getMapSize().height*tileheight;//正确
																				 //log("org=(%.2f,%.2f)", mapOrginX, mapOrginY);


																				 //所选取点A与原点的相对的gl坐标
	float OA_x = x - mapOrginX;
	float OA_y = y - mapOrginY;
	//log("oa=(%.2f,%.2f)", OA_x, OA_y);//正确

	float m = (OA_x / 64) - (OA_y / 32);
	m = static_cast<int>(m);

	/*log("m=%d",(int) m);*/
	float n = -(OA_y / 32) - (OA_x / 64);
	n = static_cast<int>(n);
	/*log("n=%d", (int)n);*/
	
	/*int posx = m / 1;
	int posy = n / 1;*/

	/*log("%d,%d", posx, posy);*/

	
	

	//if (posx<0 || posy<0 || posx>map->getMapSize().width || posy>map->getMapSize().height)
	//{
	//	return Vec2(-1, -1);
	//}
	
	
	return Vec2(m,n);
}

Vec2 MapManager::ConvertToScene(int x, int y,TMXTiledMap* map)
{
	float tilewidth = map->getTileSize().width;
	float tileheight = map->getTileSize().height;

	int mapOrginX = map->getPosition().x + map->getContentSize().width / 2;
	int mapOrginY = map->getPosition().y + map->getContentSize().height;

	if (x > map->getMapSize().width || x<0
		|| y>map->getMapSize().height || y < 0)
	{
		return Point(0, 0);
	}
	float OA_x = (x - y)*tilewidth / 2.0;
	float OA_y = -(x + y)*tileheight / 2.0;
	return Vec2(mapOrginX + OA_x, mapOrginY + OA_y);
}