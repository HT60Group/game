#include "Room.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "RoomList.h"
#include "ModeChoose.h"
#include "Player.h"
#include "Scene/OneVsOne.h"
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
	CreateRoom->setTouchEnabled(false);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [&](Touch *touch, Event *event)
	{
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		Point pos = target->convertToNodeSpace(touch->getLocation());

		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);
		if (rect.containsPoint(pos))
		{
			return true;
		}
	};
	listener->onTouchMoved = [&](Touch *touch, Event *event)
	{

	};
	listener->onTouchEnded = [&](Touch *touch, Event *event)
	{
		//if (n == 0) {
		log("button1");
		buttonTurnToCreateRoom(this);
		//}

	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, CreateRoom);

	//buttonJoin room
	Button* JoinRoom = (Button*)Helper::seekWidgetByName(UI, "JoinRoom");
	JoinRoom->setTouchEnabled(false);

	auto listener1 = EventListenerTouchOneByOne::create();
	listener1->onTouchBegan = [&](Touch *touch, Event *event)
	{
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		Point pos = target->convertToNodeSpace(touch->getLocation());

		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);
		if (rect.containsPoint(pos))
		{
			return true;
		}
	};
	listener1->onTouchMoved = [&](Touch *touch, Event *event)
	{

	};
	listener1->onTouchEnded = [&](Touch *touch, Event *event)
	{
		//if (n == 0) {
		log("button1");		
		buttonTurnToJoinRoom(this);
		//}

	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, JoinRoom);

	return true;
}

void Room::buttonTurnToCreateRoom(Ref* pSender)
{

	Server* _server = new Server();
	Client* _client = new Client();
	Player::getInstance()->p_server = _server;
	Player::getInstance()->p_client = _client;

	OpenTheRoom(Player::getInstance()->p_server, Player::getInstance()->p_client, 11111);
	
	Player::getInstance()->is_Server = true;
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
void Room::buttonTurnToJoinRoom(Ref* pSender)
{
	Client* _client = new Client();

	Player::getInstance()->p_client = _client;
	RoomJoinerClient(Player::getInstance()->p_client, 11111);
	Player::getInstance()->is_Server = false;
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
