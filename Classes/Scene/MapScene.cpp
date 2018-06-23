#include "MapScene.h"
#include "Scene/MapLayer.h"
#include "Scene/MenuLayer.h"
#include "Scene/TollgateDataLayer.h"
#include "AIManager\BuildingManager.h"
#include"AIManager.h"
Scene* MapScene::createScene() {
	log("Mapscene\n\n\n\n");
	//auto scene = Scene::create();
	//auto layer = MapScene::create();
	//TollgateDataLayer* dataLayer = TollgateDataLayer::create();
	//scene->addChild(layer);
	//scene->addChild(dataLayer, 5, UI_LAYEER_LVL);

	return MapScene::create();
}

bool MapScene::init() {
	if (!Scene::init()) { return false; }
	_mapLayer = MapLayer::create();
	this->addChild(_mapLayer);//Ìí¼Ó¹ÜÀí
	//_mapLayer = this->_mapLayer;
	//map = _mapLayer->map;

	_menuLayer = MenuLayer::create();
	this->addChild(_menuLayer);

	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("Warrior.plist", "Warrior.png");
	
	auto aimanager = AIManager::create();
	this->addChild(aimanager);
	return true;
}

MenuLayer* MapScene::GetMenuLayer()
{
	return _menuLayer;
}
MenuLayer* MapScene::_menuLayer;
