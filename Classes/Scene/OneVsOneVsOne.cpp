#include "OneVsOneVsOne.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;
Scene* OneVsOneVsOne::createScene() {
	auto scene = Scene::create();
	auto layer = OneVsOneVsOne::create();
	scene->addChild(layer);
	return scene;
}
bool OneVsOneVsOne::init() {
	if (!Scene::init()) { return false; }

	//Scene
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("1v1v1.ExportJson");
	UI->setPosition(Point(0, 0));
	this->addChild(UI);

	//button Create OneVsOneVsOne
	Button* Start = (Button*)Helper::seekWidgetByName(UI, "Start");
	Start->setTouchEnabled(true);
	Start->addTouchEventListener(CC_CALLBACK_1(OneVsOneVsOne::buttonTurnToStart, this));
	return true;
}

void OneVsOneVsOne::buttonTurnToStart(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	auto scene = OneVsOneVsOne::createScene();
	Director::getInstance()->replaceScene(scene);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}
