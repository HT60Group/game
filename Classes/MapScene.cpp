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

	//this->meta = map->getLayer("meta");//�����ײ��
	//this->meta->setVisible(false);//������ײ��
	
	this->addChild(map);//��ӵ�ͼ

	MapManager* _mapmanager = MapManager::create();
	this->addChild(_mapmanager);//��ӹ�����

	_mapmanager->SetMouseController();
	_mapmanager->schedule(schedule_selector(MapManager::ControllerUpdate));//ÿ֡���ú���
	

	
	
	
	return true;
}




