#include "InputName.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "NetMenu.h"
USING_NS_CC;
Scene* InputName::createScene() {
	auto scene = Scene::create();
	auto layer = InputName::create();
	scene->addChild(layer);
	return scene;
}
bool InputName::init() {
	if (!Scene::init()) { return false; }

	//Scene
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("landin_1.ExportJson");
	UI->setPosition(Point(0, 0));
	this->addChild(UI);

	//button
	Button* NEXT = (Button*)Helper::seekWidgetByName(UI, "NEXT");
	NEXT->setTouchEnabled(true);
	NEXT->addTouchEventListener(CC_CALLBACK_1(InputName::menuCloseCallback, this));
	return true;
}

void InputName::menuCloseCallback(Ref* pSender)
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