#include "RoomList.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
Scene* RoomList::createScene() {
	auto scene = Scene::create();
	auto layer = RoomList::create();
	scene->addChild(layer);
	return scene;
}
bool RoomList::init() {
	if (!Scene::init()) { return false; }

	//Scene
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("RoomList_1.ExportJson");
	UI->setPosition(Point(0, 0));
	this->addChild(UI);
	return true;
}
