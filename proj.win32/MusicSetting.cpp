#include "MusicSetting.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
Scene* MusicSetting::createScene() {
	auto scene = Scene::create();
	auto layer = MusicSetting::create();
	scene->addChild(layer);
	return scene;
}
bool MusicSetting::init() {
	if (!Scene::init()) { return false; }

	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("MusicSetting.ExportJson");
	UI->setPosition(Point(0, 0));
	this->addChild(UI);
	return true;
}