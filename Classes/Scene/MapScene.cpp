#include "MapScene.h"
#include "Scene/MapLayer.h"
#include "Scene/MenuLayer.h"
#include "Scene/TollgateDataLayer.h"
#include "AIManager\BuildingManager.h"
#include"AIManager.h"
#include"SimpleAudioEngine.h"
Scene* MapScene::createScene() {
	log("Mapscene\n\n\n\n");

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

	TollgateDataLayer* dataLayer = TollgateDataLayer::create();
	this->addChild(dataLayer);

	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
	frameCache->addSpriteFramesWithFile("Warrior.plist", "Warrior.png");
	
	auto aimanager = AIManager::create();
	this->addChild(aimanager);

	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("REC002.mp3", true);
	return true;
}

MenuLayer* MapScene::GetMenuLayer()
{
	return _menuLayer;
}
MenuLayer* MapScene::_menuLayer;
