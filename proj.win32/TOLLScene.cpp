#include "TOLLScene.h"


Scene* TOLLScene::createScene() {
	auto scene = Scene::create();
	auto layer = TOLLScene::create();
	scene->addChild(layer);
	return scene;
}
bool TOLLScene::init() {
	if (!Layer::init() ){ return false; }

	TMXTiledMap* map = TMXTiledMap::create("gandw.tmx");

	this->addChild(map);
	return true;
}