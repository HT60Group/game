
#ifndef _MapScene_H_
#define _MapScene_H_

#include"cocos2d.h"
#include"MapLayer.h"

using namespace cocos2d;
class MapLayer;

class MapScene :public Scene {
public:
	static Scene* createScene();
	CREATE_FUNC(MapScene);
	virtual bool init();
	
	bool _isCollidable = false;//ÊÇ·ñÅö×²
	MapLayer* _maplayer;


	TMXTiledMap * map;
	/*TMXLayer * meta;*/
private:

	


};
#endif
