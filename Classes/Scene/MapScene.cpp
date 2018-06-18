#include "MapScene.h"
#include "cocos2d.h"
#include"MapLayer.h"
#include "MenuLayer.h"

using namespace cocos2d;


Scene* MapScene::createScene() {
	auto scene = Scene::create();
	auto layer = MapScene::create();
	scene->addChild(layer);
	return scene;
}

bool MapScene::init() {
	


	_maplayer = MapLayer::create();
	this->addChild(_maplayer);//Ìí¼Ó¹ÜÀí

	MenuLayer* _menulayer = MenuLayer::create();
	this->addChild(_menulayer);

	
	
	
	
	
	
	return true;
}



