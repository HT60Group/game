#ifndef _MapScene_H_
#define _MapScene_H_

#include "cocos2d.h"
#include "Scene/MapLayer.h"
#include "Scene/MenuLayer.h"
#include "Scene/TollgateDataLayer.h"

#define MAP_LAYEER_LVL 3
#define UI_LAYEER_LVL 10
#define BUILDING_LAYEER_LVL 15
#define ARMY_LAYEER_LVL 20

using namespace cocos2d;
//class MapLayer;

class MapScene :public Scene {
public:
	static Scene* createScene();
	CREATE_FUNC(MapScene);
	virtual bool init();
	
	bool _isCollidable = false;//ÊÇ·ñÅö×²
	MapLayer* _mapLayer;
	/*TMXTiledMap* map;*/
	/*TMXLayer * meta;*/


};
#endif
