#include "MenuLayer.h"
#include"Entity/Building.h"
#include"Entity/Base.h"
#include"Entity/Barrack.h"
#include"Entity/Stope.h"
#include"Entity/WarFactory.h"
#include"Entity/Producer.h"
#include "MapLayer.h"
#include "AIManager\BuildingManager.h"
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

	//log("tpos=(%f,%f)", mypos.x, mypos.y);
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
	//create Producer
	Producer* producer = new Producer();
	Building::createWithSpriteFrameName(producer, "Producer.png");     //此处需要图片——大兵图片
													//this->addChild(barrack);
	auto tmap = MapLayer::map;
	auto _currentPos = tmap->getPosition();//地图的绝对坐标
	Point mypos;
	mypos.x = tpos.x - _currentPos.x;
	mypos.y = tpos.y - _currentPos.y;

	tmap->addChild(producer, BUILDING_LAYEER_LVL);
	producer->setPosition(mypos);    //setPosition
	producer->showUI();

	Vec2 a = MapLayer::ConvertToMap(tpos.x, tpos.y, tmap);
	static_cast<MapScene*>(this->getParent())->_mapLayer->setcollidable(a.x, a.y, 1);
											/*m_BuildingList.pushBack(barrack);*/
}
void MenuLayer::createStope(Point tpos) {
	//create Stope
	Stope* stope = new Stope();
	Building::createWithSpriteFrameName(stope, "Stope.png");     //此处需要图片——大兵图片
												   //this->addChild(barrack);
	static_cast<MapScene*>(this->getParent())->_mapLayer->map->addChild(stope, BUILDING_LAYEER_LVL);
	stope->setPosition(tpos);            //setPosition
	stope->showUI();
										   /*m_BuildingList.pushBack(barrack);*/
}
void MenuLayer::createWarFactory(Point tpos) {
	//create WarFactory
	WarFactory* warfac = new WarFactory();
	Building::createWithSpriteFrameName(warfac, "WarFactory.png");     //此处需要图片——大兵图片
											  //this->addChild(barrack);
	static_cast<MapScene*>(this->getParent())->_mapLayer->map->addChild(warfac, BUILDING_LAYEER_LVL);
	warfac->setPosition(tpos);            //setPosition
	warfac->showUI();
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
	soldier->setTouchEnabled(false);
	Button* stope = (Button*)Helper::seekWidgetByName(UIMenu, "Button_Stope");
	soldier->setTouchEnabled(false);

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
		return false;
	};
	listener->onTouchEnded = [&](Touch *touch, Event *event)
	{

	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, soldier);
}
