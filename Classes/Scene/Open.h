
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

	//��������    -------------������ҪͼƬ
	Sprite* buildingSprite = Sprite::create("Base.png");

	//������󶨵���Ҷ�����
	Building* mBuilding = Building::create();
	mBuilding->bindSprite(buildingSprite);

	//���ý�������
	mBuilding->setPosition(Point(100, visibleSize.height / 2));

	//��������ӵ���ͼ
	map->addChild(mBuilding);
}
*/
#endif
