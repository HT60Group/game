#include "ModeChoose.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "OneVsOne.h"
#include "OneVsOneVsOne.h"
#include "TwoVsTwo.h"

USING_NS_CC;
Scene* ModeChoose::createScene() {
	auto scene = Scene::create();
	auto layer = ModeChoose::create();
	scene->addChild(layer);
	return scene;
}
bool ModeChoose::init() {
	if (!Scene::init()) { return false; }


	//Scene
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("Mode.ExportJson");
	UI->setPosition(Point(0, 0));
	this->addChild(UI);

	//button Button_1v1
	Button* Button_1v1 = (Button*)Helper::seekWidgetByName(UI, "Button_1v1");
	Button_1v1->setTouchEnabled(true);
	Button_1v1->addTouchEventListener(CC_CALLBACK_1(ModeChoose::buttonTurnTo1vs1, this));

	//button Button_1v1v1
	Button* Button_1v1v1 = (Button*)Helper::seekWidgetByName(UI, "Button_1v1v1");
	Button_1v1v1->setTouchEnabled(true);
	Button_1v1v1->addTouchEventListener(CC_CALLBACK_1(ModeChoose::buttonTurnTo1vs1vs1, this));

	//button Button_2v2
	Button* Button_2v2 = (Button*)Helper::seekWidgetByName(UI, "Button_2v2");
	Button_2v2->setTouchEnabled(true);
	Button_2v2->addTouchEventListener(CC_CALLBACK_1(ModeChoose::buttonTurnTo2vs2, this));
	return true;
}

void ModeChoose::buttonTurnTo1vs1(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	auto scene = OneVsOne::createScene();
	Director::getInstance()->replaceScene(scene);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}
void ModeChoose::buttonTurnTo2vs2(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	auto scene = TwoVsTwo::createScene();
	Director::getInstance()->replaceScene(scene);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}
void ModeChoose::buttonTurnTo1vs1vs1(Ref* pSender)
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
