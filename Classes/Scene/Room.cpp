#include "Room.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "RoomList.h"
#include "ModeChoose.h"
USING_NS_CC;
Scene* Room::createScene() {
	auto scene = Scene::create();
	auto layer = Room::create();
	scene->addChild(layer);
	return scene;
}
bool Room::init() {
	if (!Scene::init()) { return false; }

	//Scene
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("room_1.ExportJson");
	UI->setPosition(Point(0, 0));
	this->addChild(UI);

	//button Create Room
	Button* CreateRoom = (Button*)Helper::seekWidgetByName(UI, "CreateRoom");
	CreateRoom->setTouchEnabled(true);
	CreateRoom->addTouchEventListener(CC_CALLBACK_1(Room::buttonTurnToCreateRoom, this));

	//buttonJoin room
	Button* JoinRoom = (Button*)Helper::seekWidgetByName(UI, "JoinRoom");
	JoinRoom->setTouchEnabled(true);
	JoinRoom->addTouchEventListener(CC_CALLBACK_1(Room::buttonTurnToJoinRoom, this));
	return true;
}

void Room::buttonTurnToCreateRoom(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	auto scene = ModeChoose::createScene();
	Director::getInstance()->replaceScene(scene);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}
void Room::buttonTurnToJoinRoom(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	auto scene = RoomList::createScene();
	Director::getInstance()->replaceScene(scene);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}
