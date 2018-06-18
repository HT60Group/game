#pragma once
#include<cocos2d.h>
#include<MapScene.h>

#include<vector>

using namespace cocos2d;

class MapLayer;

class MapLayer:public Node
{
public:
	CREATE_FUNC(MapLayer);
	virtual bool init();

	void SetMouseController();
	void ControllerUpdate(float dt);
	bool isCollidable(Point);
	void fill_collidable();
	void FindWay();
	TMXTiledMap* map;



	Vec2 ConvertToMap(float x, float y,TMXTiledMap* map);
	Vec2 ConvertToScene(int x, int y, TMXTiledMap* map);
private:
	Point _mapMoveSpeed = Point(0, 0);//初始速度为0，向量
	bool _isClick = false;
	Point _mousePosition = Point(0, 0);
	 std::vector<std::vector<int> > _collidable;//用于储存碰撞层的碰撞属性

};