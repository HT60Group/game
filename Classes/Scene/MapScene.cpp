#include "MapScene.h"

Scene* MapScene::createScene() {
	auto scene = Scene::create();
	auto layer = MapScene::create();
	//_mapLayer = MapLayer::create();
	//MenuLayer* menulayer = MenuLayer::create();
	TollgateDataLayer* dataLayer = TollgateDataLayer::create();
	scene->addChild(layer);
	//scene->addChild(layer);
	//scene->addChild(mapLayer,1);
	//scene->addChild(menulayer,3,UI_LAYEER_LVL);
	scene->addChild(dataLayer, 5, UI_LAYEER_LVL);
	return scene;

}

bool MapScene::init() {

	_mapLayer = MapLayer::create();
	this->addChild(_mapLayer);//Ìí¼Ó¹ÜÀí
	//_mapLayer = this->_mapLayer;
	//map = _mapLayer->map;
	MenuLayer* _menulayer = MenuLayer::create();
	this->addChild(_menulayer);
	
	
	return true;
}



