
#ifndef _Open_H_
#define _Open_H_

#include"cocos2d.h"
using namespace cocos2d;

class Open :public Layer
{
public:
	static Scene* createScene();
	CREATE_FUNC(Open);
	virtual bool init();
//	void addBuilding(TMXTiledMap* map);
};
/*
void Open::addBuilding(TMXTiledMap* map)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//创建精灵    -------------这里需要图片
	Sprite* buildingSprite = Sprite::create("Base.png");

	//将精灵绑定到玩家对象上
	Building* mBuilding = Building::create();
	mBuilding->bindSprite(buildingSprite);

	//设置建筑坐标
	mBuilding->setPosition(Point(100, visibleSize.height / 2));

	//将建筑添加到地图
	map->addChild(mBuilding);
}
*/
#endif
