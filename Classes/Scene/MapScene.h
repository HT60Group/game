#ifndef _MapScene_H_
#define _MapScene_H_
#define MAP_LAYEER_LVL 3
#define UI_LAYEER_LVL 10
#define BUILDING_LAYEER_LVL 15
#define ARMY_LAYEER_LVL 20


#include"cocos2d.h"
#include "AIManager/BuildingManager.h"
using namespace cocos2d;

class MapScene :public Scene {
public:
	static Scene* createScene();
	CREATE_FUNC(MapScene);
	virtual bool init();
	TMXTiledMap* map;
	Vec2 ConvertToMap(float x, float y);
	Vec2 ConvertToScene(int x, int y);
	bool _isCollidable = false;//ÊÇ·ñÅö×²
};
#endif
