#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "Scene/MusicSetting.h"
#include "Scene/InputName.h"
#include "Scene/MapScene.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("HtStarCOpen_1.ExportJson");
	UI->setPosition(Point(0, 0));
	this->addChild(UI);

	// button 
	Button* START = (Button*)Helper::seekWidgetByName(UI, "START");
	START->setTouchEnabled(true);
	START->addTouchEventListener(CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	Button* Setting = (Button*)Helper::seekWidgetByName(UI, "Setting");
	Setting->setTouchEnabled(true);
	Setting->addTouchEventListener(CC_CALLBACK_1(HelloWorld::buttonTurnToSetting, this));
	return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
	auto scene = InputName::createScene();
    Director::getInstance()->replaceScene(scene);

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
void HelloWorld::buttonTurnToSetting(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	auto scene = MusicSetting::createScene();
	Director::getInstance()->replaceScene(scene);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}

