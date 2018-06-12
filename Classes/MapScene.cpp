#include "MapScene.h"
#include "cocos2d.h"
#include"MapManager.h"
#include "MenuLayer.h"

using namespace cocos2d;


Scene* MapScene::createScene() {
	auto scene = Scene::create();
	auto layer = MapScene::create();
	scene->addChild(layer);
	return scene;
}

bool MapScene::init() {
	map = TMXTiledMap::create("gandw.tmx");
	
	this->addChild(map);//��ӵ�ͼ

	//meta = map->getLayer("meta");//�����ײ��
	/*this->addChild(meta);*/

	MapManager* _mapmanager = MapManager::create();
	this->addChild(_mapmanager);//��ӹ���

	MenuLayer* _menulayer = MenuLayer::create();
	this->addChild(_menulayer);

	_mapmanager->fill_collidable();
	_mapmanager->SetMouseController();
	_mapmanager->schedule(schedule_selector(MapManager::ControllerUpdate));//ÿ֡���ú���
	
	
	
	
	
	return true;
}




