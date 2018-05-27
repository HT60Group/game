#include "NetMenu.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "Room.h"
USING_NS_CC;
Scene* NetMenu::createScene() {
	auto scene = Scene::create();
	auto layer = NetMenu::create();
	scene->addChild(layer);
	return scene;
}
bool NetMenu::init() {
	if (!Scene::init()) { return false; }

	//Scene
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("NetMenu_1.ExportJson");
	UI->setPosition(Point(0, 0));
	this->addChild(UI);

	//button NetFight
	Button* NetFight = (Button*)Helper::seekWidgetByName(UI, "NetFight");
	NetFight->setTouchEnabled(true);
	NetFight->addTouchEventListener(CC_CALLBACK_1(NetMenu::buttonTurnToNetFight, this));
	
	//buttonLANFight
	Button* LANFight = (Button*)Helper::seekWidgetByName(UI, "LANFight");
	LANFight->setTouchEnabled(true);
	LANFight->addTouchEventListener(CC_CALLBACK_1(NetMenu::buttonTurnToLANFight, this));
	return true;
}

void NetMenu::buttonTurnToNetFight(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	auto scene = Room::createScene();
	Director::getInstance()->replaceScene(scene);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}
void NetMenu::buttonTurnToLANFight(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	auto scene = NetMenu::createScene();
	Director::getInstance()->replaceScene(scene);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}
