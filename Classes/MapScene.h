
#ifndef _MapScene_H_
#define _MapScene_H_

#include"cocos2d.h"

using namespace cocos2d;

class MapScene :public Scene {
public:
	static Scene* createScene();
	CREATE_FUNC(MapScene);
	virtual bool init();
	
	bool _isCollidable = false;//�Ƿ���ײ
	


	TMXTiledMap * map;
	/*TMXLayer * meta;*/
private:

	


};
#endif
