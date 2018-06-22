#include "MenuLayer.h"
#include"Entity/Building.h"
#include"Entity/Base.h"
#include"Entity/Barrack.h"
#include"Entity/Stope.h"
#include"Entity/WarFactory.h"
#include"Entity/Producer.h"
#include "MapLayer.h"
#include "AIManager\BuildingManager.h"
#include "Army/Soldier.h"
#include "Army\Army.h"
#include "Army\Dog.h"
#include "Army/Scv.h"
#include "Army\Sniper.h"
#include "Army\Tank.h"

bool MenuLayer::init()
{
	auto _visibleSize = Director::getInstance()->getVisibleSize();//屏幕大小
		
	auto tmap = MapLayer::map;
	auto _currentPos = tmap->getPosition();//地图的绝对坐标

	buildingMgr = BuildingManager::createBuildingMgr();
	tmap->addChild(buildingMgr);
																  //设置菜单层
	menuLayer = LayerColor::create(Color4B(225, 105, 180, 80));
	menuLayer->setPosition(_visibleSize.width * 5 / 6, 0);

	this->addChild(menuLayer, UI_LAYEER_LVL);
	//放置UI
	/*cocos2d::ui::Widget*/
	//auto UI_menu = cocostudio::GUIReader::getInstance()->
	//	widgetFromJsonFile("menu_1.ExportJson");
	UIMenu= cocostudio::GUIReader::getInstance()->
		widgetFromJsonFile("menu_1.ExportJson");
	
	UIMenu->setPosition(Point(0, 0));

	this->addChild(UIMenu, UI_LAYEER_LVL);

	Button* barrack = (Button*)Helper::seekWidgetByName(UIMenu, "Button_barracks");
	barrack->setTouchEnabled(false);
	Button* producer = (Button*)Helper::seekWidgetByName(UIMenu, "Button_producer");
	producer->setTouchEnabled(false);
	Button* stope = (Button*)Helper::seekWidgetByName(UIMenu, "Button_Stope");
	stope->setTouchEnabled(false);
	Button* warfac = (Button*)Helper::seekWidgetByName(UIMenu, "Button_WarFactory");
	warfac->setTouchEnabled(false);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(MenuLayer::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(MenuLayer::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(MenuLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, barrack);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), producer);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), stope);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), warfac);
	return true;
}
bool MenuLayer::onTouchBegan(Touch* touch, Event* event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	Point pos = target->convertToNodeSpace(touch->getLocation());

	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);
	if (rect.containsPoint(pos))
	{
		log("%f", touch->getLocation().y);
		if (touch->getLocation().y > 700)
		{
			message = "barrack";
		}
		else if(touch->getLocation().y>500){
			message = "producer";
		}
		else if(touch->getLocation().y>270){
			message = "stope";
		}
		else {
			message = "warfac";
		}
		return true;
	}
	return false;
}
void MenuLayer::onTouchMoved(Touch* touch, Event* event)
{  
}
void MenuLayer::onTouchEnded(Touch* touch, Event* event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	Point tpos = Director::getInstance()->convertToGL(touch->getLocationInView());
	//auto _currentPos = static_cast<MapLayer*>(static_cast<MapScene*>(this->getParent())->_mapLayer)->map->getPosition();//地图的绝对坐标
	//tpos.x -= _currentPos.x;
	//tpos.y -= _currentPos.y;
	if (message == "barrack") {
	    createBarrack(tpos);
	}
	if (message == "producer"){
		createProducer(tpos);
	}
	if (message == "stope") {
		createStope(tpos);
	}
	if (message == "warfac") {
		createWarFactory(tpos);
	}
}
void MenuLayer::createBarrack(Point tpos) {
	auto tmap = MapLayer::map;
	auto _currentPos = tmap->getPosition();//地图的绝对坐标
	Vec2 a = MapLayer::ConvertToMap(tpos.x, tpos.y, tmap);
	log("tpos2=(%f,%f)", tpos.x, tpos.y);
	log("a(%f,%f)", a.x, a.y);
	//create Barrack
	if (a.x > 74 || a.x < 0 || a.y>74 || a.y < 0)
	{
		return;
	}
	
	Barrack* barrack = new Barrack();
	Building::createWithSpriteFrameName(barrack, "Barracks.png");     //此处需要图片——图片

	Point mypos;
	mypos.x=tpos.x - _currentPos.x;
	mypos.y=tpos.y - _currentPos.y;

	tmap->addChild(barrack, 20);
	barrack->setPosition(mypos);    //setPosition
	barrack->showUI();
	buildingMgr->SetBarrackController(barrack);
	
	log("getScenePosition(%f,%f)", barrack->getScenePosition().x, barrack->getScenePosition().y);
	for (int i = -2; i < 3; i++)
	{
		for (int j = -2; j < 3; j++)
		{
			static_cast<MapScene*>(this->getParent())->_mapLayer->setcollidable(a.x+i, a.y+j, 1);
		}
	}
										   /*m_BuildingList.pushBack(barrack);*/
}
void MenuLayer::createProducer(Point tpos) {
	auto tmap = MapLayer::map;
	auto _currentPos = tmap->getPosition();//地图的绝对坐标
	Vec2 a = MapLayer::ConvertToMap(tpos.x, tpos.y, tmap);
	log("tpos2=(%f,%f)", tpos.x, tpos.y);
	log("a(%f,%f)", a.x, a.y);
	//create Barrack
	if (a.x > 74 || a.x < 0 || a.y>74 || a.y < 0)
	{
		return;
	}

	Producer* producer = new Producer();
	Building::createWithSpriteFrameName(producer, "Producer.png");     //此处需要图片——图片

	Point mypos;
	mypos.x = tpos.x - _currentPos.x;
	mypos.y = tpos.y - _currentPos.y;

	tmap->addChild(producer, 20);
	producer->setPosition(mypos);    //setPosition
	producer->showUI();

	for (int i = -2; i < 3; i++)
	{
		for (int j = -2; j < 3; j++)
		{
			static_cast<MapScene*>(this->getParent())->_mapLayer->setcollidable(a.x + i, a.y + j, 1);
		}
	}
											/*m_BuildingList.pushBack(barrack);*/
}
void MenuLayer::createStope(Point tpos) {
	//create Stope
	auto tmap = MapLayer::map;
	auto _currentPos = tmap->getPosition();//地图的绝对坐标
	Vec2 a = MapLayer::ConvertToMap(tpos.x, tpos.y, tmap);
	log("tpos2=(%f,%f)", tpos.x, tpos.y);
	log("a(%f,%f)", a.x, a.y);
	//create Barrack
	if (a.x > 74 || a.x < 0 || a.y>74 || a.y < 0)
	{
		return;
	}

	Stope* stope= new Stope();
	Building::createWithSpriteFrameName(stope, "Stope.png");     //此处需要图片——图片

	Point mypos;
	mypos.x = tpos.x - _currentPos.x;
	mypos.y = tpos.y - _currentPos.y;

	tmap->addChild(stope, 20);
	stope->setPosition(mypos);    //setPosition
	stope->showUI();

	for (int i = -2; i < 3; i++)
	{
		for (int j = -2; j < 3; j++)
		{
			static_cast<MapScene*>(this->getParent())->_mapLayer->setcollidable(a.x + i, a.y + j, 1);
		}
	}
										   /*m_BuildingList.pushBack(barrack);*/
}
void MenuLayer::createWarFactory(Point tpos) {
	//create WarFactory
	auto tmap = MapLayer::map;
	auto _currentPos = tmap->getPosition();//地图的绝对坐标
	Vec2 a = MapLayer::ConvertToMap(tpos.x, tpos.y, tmap);
	log("tpos2=(%f,%f)", tpos.x, tpos.y);
	log("a(%f,%f)", a.x, a.y);
	//create Barrack
	if (a.x > 74 || a.x < 0 || a.y>74 || a.y < 0)
	{
		return;
	}

	WarFactory* warf = new WarFactory();
	Building::createWithSpriteFrameName(warf, "WarFactory.png");     //此处需要图片——图片

	Point mypos;
	mypos.x = tpos.x - _currentPos.x;
	mypos.y = tpos.y - _currentPos.y;

	tmap->addChild(warf, 20);
	warf->setPosition(mypos);    //setPosition
	warf->showUI();
	buildingMgr->SetBarrackController(warf);

	for (int i = -2; i < 3; i++)
	{
		for (int j = -2; j < 3; j++)
		{
			static_cast<MapScene*>(this->getParent())->_mapLayer->setcollidable(a.x + i, a.y + j, 1);
		}
	}
										 /*m_BuildingList.pushBack(barrack);*/
}
 
void MenuLayer::CreateBarrackLayer()
{
	//放置UI
	//auto UI_menu = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("BarrackUI/BarrackUI_1.ExportJson");
	this->removeChild(UIMenu);
	UIMenu = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("BarrackUI/BarrackUI_1.ExportJson");
	UIMenu->setPosition(Point(0, 0));
	this->addChild(UIMenu, UI_LAYEER_LVL+1);
	Button* soldier = (Button*)Helper::seekWidgetByName(UIMenu, "Button_Soldier");
	soldier->setTouchEnabled(false);
	Button* dog = (Button*)Helper::seekWidgetByName(UIMenu, "Button_Dog");
	dog->setTouchEnabled(false);
	Button* sniper = (Button*)Helper::seekWidgetByName(UIMenu, "Button_Snipe");
	sniper->setTouchEnabled(false);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [&](Touch *touch, Event *event)
	{
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		Point pos = target->convertToNodeSpace(touch->getLocation());

		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);
		if (rect.containsPoint(pos))
		{
			log("soldier->%f", touch->getLocation().y);
			if (touch->getLocation().y > 500 && touch->getLocation().y<600)
			{
				message = "soldier";
			}
			else if (touch->getLocation().y<410 && touch->getLocation().y>300) {
				message = "dog";
			}
			else if (touch->getLocation().y<240 && touch->getLocation().y>140) {
				message = "sniper";
			}
			return true;
		}
		return false;
		return true;
	};
	listener->onTouchEnded= [&](Touch* touch, Event* event)
	{
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		Point tpos = Director::getInstance()->convertToGL(touch->getLocationInView());
		if (message == "soldier") {
			createSoldier(Point(600,600));
		}
		if (message == "dog") {
			createDog(Point(600, 600));
		}
		if (message == "sniper") {
			createSniper(Point(600, 600));
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, soldier);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), dog);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), sniper);
}
void MenuLayer::createSoldier(Point tpos) {
	auto tmap = MapLayer::map;
	auto _currentPos = tmap->getPosition();//地图的绝对坐标
	//Vec2 a = MapLayer::ConvertToMap(tpos.x, tpos.y, tmap);

	Soldier* soldier_1 = new Soldier();
	Army::createWithSpriteFrameName(soldier_1, "ALLArmy/soldier_1.png");     //此处需要图片——图片

	//Point mypos;
	//mypos.x = tpos.x - _currentPos.x;
	//mypos.y = tpos.y - _currentPos.y;

	tmap->addChild(soldier_1, 19);
	soldier_1->setPosition(tpos);    //setPosition
	soldier_1->showUI();

	//static_cast<MapScene*>(this->getParent())->_mapLayer->setcollidable(a.x, a.y, 1);
	/*m_BuildingList.pushBack(barrack);*/
}
void MenuLayer::createDog(Point tpos) {
	auto tmap = MapLayer::map;
	auto _currentPos = tmap->getPosition();//地图的绝对坐标
										   //Vec2 a = MapLayer::ConvertToMap(tpos.x, tpos.y, tmap);

	Dog* soldier_1 = new Dog();
	Army::createWithSpriteFrameName(soldier_1, "ALLArmy/dog_1.png");     //此处需要图片——图片

																   //Point mypos;
																   //mypos.x = tpos.x - _currentPos.x;
																   //mypos.y = tpos.y - _currentPos.y;

	tmap->addChild(soldier_1, 19);
	soldier_1->setPosition(tpos);    //setPosition
	soldier_1->showUI();

	//static_cast<MapScene*>(this->getParent())->_mapLayer->setcollidable(a.x, a.y, 1);
	/*m_BuildingList.pushBack(barrack);*/
}
void MenuLayer::createSniper(Point tpos) {
	auto tmap = MapLayer::map;
	auto _currentPos = tmap->getPosition();//地图的绝对坐标
										   //Vec2 a = MapLayer::ConvertToMap(tpos.x, tpos.y, tmap);

	Sniper* soldier_1 = new Sniper();
	Army::createWithSpriteFrameName(soldier_1, "Sniper.png");     //此处需要图片——图片
															   //Point mypos;
															   //mypos.x = tpos.x - _currentPos.x;
															   //mypos.y = tpos.y - _currentPos.y;

	tmap->addChild(soldier_1, 19);
	soldier_1->setPosition(tpos);    //setPosition
	soldier_1->showUI();

	//static_cast<MapScene*>(this->getParent())->_mapLayer->setcollidable(a.x, a.y, 1);
	/*m_BuildingList.pushBack(barrack);*/
}

void MenuLayer::CreateBaseLayer()
{
	//放置UI
	//auto UI_menu = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("BarrackUI/BarrackUI_1.ExportJson");
	this->removeChild(UIMenu);
	UIMenu = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("BaseUI/BaseUI_1.ExportJson");
	UIMenu->setPosition(Point(0, 0));
	this->addChild(UIMenu, UI_LAYEER_LVL + 1);

	Button* scv = (Button*)Helper::seekWidgetByName(UIMenu, "Button_Scv");
	scv->setTouchEnabled(false);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [&](Touch *touch, Event *event)
	{
		createScv(Point(600, 600));
		return true;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, scv);
}
void MenuLayer::createScv(Point tpos) {
	auto tmap = MapLayer::map;
	auto _currentPos = tmap->getPosition();//地图的绝对坐标
										   //Vec2 a = MapLayer::ConvertToMap(tpos.x, tpos.y, tmap);

	Scv* soldier_1 = new Scv();
	Army::createWithSpriteFrameName(soldier_1, "Scv.png");     //此处需要图片——图片

																   //Point mypos;
																   //mypos.x = tpos.x - _currentPos.x;
																   //mypos.y = tpos.y - _currentPos.y;

	tmap->addChild(soldier_1, 19);
	soldier_1->setPosition(tpos);    //setPosition
	soldier_1->showUI();

	//static_cast<MapScene*>(this->getParent())->_mapLayer->setcollidable(a.x, a.y, 1);
	/*m_BuildingList.pushBack(barrack);*/
}

void MenuLayer::CreateWarFactoryLayer()
{
	//放置UI
	this->removeChild(UIMenu);
	UIMenu = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("WarFactoryUI/WarFactoryUI_1.ExportJson");
	UIMenu->setPosition(Point(0, 0));
	this->addChild(UIMenu, UI_LAYEER_LVL + 1);

	Button* tank = (Button*)Helper::seekWidgetByName(UIMenu, "Button_Tank");
	tank->setTouchEnabled(false);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [&](Touch *touch, Event *event)
	{
		createTank(Point(600, 600));
		return true;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, tank);
}
void MenuLayer::createTank(Point tpos) {
	auto tmap = MapLayer::map;
	auto _currentPos = tmap->getPosition();//地图的绝对坐标
										   //Vec2 a = MapLayer::ConvertToMap(tpos.x, tpos.y, tmap);

	Tank* soldier_1 = new Tank();
	Army::createWithSpriteFrameName(soldier_1, "ALLArmy/tank_1.png");     //此处需要图片——图片

															   //Point mypos;
															   //mypos.x = tpos.x - _currentPos.x;
															   //mypos.y = tpos.y - _currentPos.y;

	tmap->addChild(soldier_1, 19);
	soldier_1->setPosition(tpos);    //setPosition
	soldier_1->showUI();

	//static_cast<MapScene*>(this->getParent())->_mapLayer->setcollidable(a.x, a.y, 1);
	/*m_BuildingList.pushBack(barrack);*/
}