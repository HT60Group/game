#pragma once
#include<cocos2d.h>
#include<MapScene.h>

#include<vector>

using namespace cocos2d;

class MapManager;

class MapManager:public Node
{
public:
	CREATE_FUNC(MapManager);
	virtual bool init();

	void SetMouseController();
	void ControllerUpdate(float dt);
	bool isCollidable(Point);
	void fill_collidable();

	Vec2 ConvertToMap(float x, float y,TMXTiledMap* map);
	Vec2 ConvertToScene(int x, int y, TMXTiledMap* map);
private:
	Point _mapMoveSpeed = Point(0, 0);//��ʼ�ٶ�Ϊ0������
	bool _isClick = false;
	Point _mousePosition = Point(0, 0);
	/*std::vector<std::vector<int>> _collidable((int)75,std::vector<int>(75,0));*/
};