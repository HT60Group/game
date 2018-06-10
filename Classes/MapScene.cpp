#include "MapScene.h"
#include "cocos2d.h"
#include"MapManager.h"

using namespace cocos2d;


Scene* MapScene::createScene() {
	auto scene = Scene::create();
	auto layer = MapScene::create();
	scene->addChild(layer);
	return scene;
}

bool MapScene::init() {
	map = TMXTiledMap::create("gandw.tmx");

	//this->meta = map->getLayer("meta");//获得碰撞层
	//this->meta->setVisible(false);//隐藏碰撞层
	
	this->addChild(map);//添加地图

	MapManager* _mapmanager = MapManager::create();
	this->addChild(_mapmanager);//添加管理器

	_mapmanager->SetMouseController();
	_mapmanager->schedule(schedule_selector(MapManager::ControllerUpdate));//每帧调用函数
	

	
	
	
	return true;
}




