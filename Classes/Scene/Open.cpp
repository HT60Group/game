#include "Open.h"
#include "Entity/Building.h"

Scene* Open::createScene() {
	auto scene = Scene::create();
	auto layer = Open::create();
	scene->addChild(layer);
	return scene;
}
bool Open::init() {
	if (!Layer::init()) { return false; }

	TMXTiledMap* map = TMXTiledMap::create("gandw.tmx");

	this->addChild(map);
	
	addBuilding(map);                     //¼ÓÔØ½¨Öş
	return true;
}