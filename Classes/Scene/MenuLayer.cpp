#include "MenuLayer.h"
#include "Entity/Entity.h"
#include"Entity/Building.h"
#include"Entity/Base.h"
#include"Entity/Barrack.h"
#include"Entity/Stope.h"
#include"Entity/WarFactory.h"
#include"Entity/Producer.h"
#include "MapLayer.h"
#include "AIManager\BuildingManager.h"
#include "AIManager.h"
#include "Army/Soldier.h"
#include "Army\Army.h"
#include "Army\Dog.h"
#include "Army/Scv.h"
#include "Army\Sniper.h"
#include "Army\Tank.h"
#include"TollgateDataLayer.h"

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

	createBase(Point(600, 1300),true);

	createBase(Point(4200, 1300), false);

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
		log("begin%f", touch->getLocation().y);
		if (touch->getLocation().y > 700 && touch->getLocation().y<800)
		{
			message = "barrack";
		}
		else if(touch->getLocation().y>500 && touch->getLocation().y<600){
			message = "producer";
		}
		else if(touch->getLocation().y>270 && touch->getLocation().y<370){
			message = "stope";
		}
		else if(touch->getLocation().y>75 && touch->getLocation().y<175){
			message = "warfac";
		}
		return true;
	}
	return false;
}
void MenuLayer::onTouchMoved(Touch* touch, Event* event)
{  
	//auto target = static_cast<Sprite*>(event->getCurrentTarget());
	//Point pos = newsprite->convertToNodeSpace(touch->getLocation());

	//Size s = newsprite->getContentSize();
	//Rect rect = Rect(0, 0, s.width, s.height);
	//if (rect.containsPoint(pos))
	//{
	//	newsprite->setPosition(newsprite->getPosition() + touch->getDelta());
	//}
}
void MenuLayer::onTouchEnded(Touch* touch, Event* event)
{
	auto target = static_cast<Sprite*>(event->getCurrentTarget());
	Point tpos = Director::getInstance()->convertToGL(touch->getLocationInView());
	//auto _currentPos = static_cast<MapLayer*>(static_cast<MapScene*>(this->getParent())->_mapLayer)->map->getPosition();//地图的绝对坐标
	//tpos.x -= _currentPos.x;
	//tpos.y -= _currentPos.y;
	if (message == "barrack") {
	    createBarrack(tpos,true);
	}
	if (message == "producer"){
		createProducer(tpos,true);
	}
	if (message == "stope") {
		createStope(tpos,true);
	}
	if (message == "warfac") {
		createWarFactory(tpos,true);
	}
}
void MenuLayer::createBarrack(Point tpos, bool not_enemy) {
	
	if (TollgateDataLayer::m_iGold<TollgateDataLayer::BarrackCostMine)
	{
		return;
	}
	TollgateDataLayer::m_iGold -= TollgateDataLayer::BarrackCostMine;
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
		for (int i = -2; i < 3; i++)
		{
			for (int j = -2; j < 3; j++)
			{
				if (static_cast<MapScene*>(this->getParent())->_mapLayer->getCollidable(a.x + i, a.y + j) == 1) {
					log("collidable=%f,%f", a.x + i, a.y + j);
					return;
				}
			}
		}

		Barrack* barrack = new Barrack();
		Building::createWithSpriteFrameName(barrack, "Barracks.png");     //此处需要图片——图片
		barrack->setZOrder(a.x + a.y);
	/*	TollgateDataLayer::m_iGold -= Barrack::getInstance()->costMine();*/
		Point mypos;
		mypos.x = tpos.x - _currentPos.x;
		mypos.y = tpos.y - _currentPos.y;

		log("a.x+a.y=%f", a.x + a.y);
		tmap->addChild(barrack, BUILDING_LAYEER_LVL);
		barrack->setPosition(mypos);    //setPosition

		barrack->showUI();

		if (not_enemy)
		{
			buildingMgr->SetBarrackController(barrack);
			//add m_buildingVec
			BuildingManager::m_buildingVec.push_back(barrack);
			barrack->_numInVec = BuildingManager::m_buildingVec.size() - 1;
		}
		else {
			//add m_buildingVec
			BuildingManager::m_enemyBuildingVec.push_back(barrack);
			barrack->_numInVec = BuildingManager::m_enemyBuildingVec.size() - 1;
			barrack->is_Enemy();
		}

		log("getScenePosition(%f,%f)", barrack->getScenePosition().x, barrack->getScenePosition().y);
		for (int i = -2; i < 3; i++)
		{
			for (int j = -2; j < 3; j++)
			{
				static_cast<MapScene*>(this->getParent())->_mapLayer->setcollidable(a.x + i, a.y + j, 1);
			}
		}
	}
//}
void MenuLayer::createProducer(Point tpos, bool not_enemy) {
	if (TollgateDataLayer::m_iGold<TollgateDataLayer::ProducerCostMine)
	{
		return;
	}

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
	for (int i = -2; i < 3; i++)
	{
		for (int j = -2; j < 3; j++)
		{
			if (static_cast<MapScene*>(this->getParent())->_mapLayer->getCollidable(a.x + i, a.y + j) == 1) {
				log("collidable=%f,%f", a.x + i, a.y + j);
				return;
			}
		}
	}

	Producer* producer = new Producer();
	Building::createWithSpriteFrameName(producer, "Producer.png");     //此处需要图片——图片

	TollgateDataLayer::addm_iGold += 50;
	TollgateDataLayer::m_iGold -= TollgateDataLayer::ProducerCostMine;

	Point mypos;
	mypos.x = tpos.x - _currentPos.x;
	mypos.y = tpos.y - _currentPos.y;

	tmap->addChild(producer, BUILDING_LAYEER_LVL);
	producer->setPosition(mypos);    //setPosition
	producer->showUI();

	if (not_enemy)
	{
		//add m_buildingVec
		BuildingManager::m_buildingVec.push_back(producer);
		producer->_numInVec = BuildingManager::m_buildingVec.size() - 1;
	}
	else {
		//add m_buildingVec
		BuildingManager::m_enemyBuildingVec.push_back(producer);
		producer->_numInVec = BuildingManager::m_enemyBuildingVec.size() - 1;
		producer->is_Enemy();
	}

	for (int i = -2; i < 3; i++)
	{
		for (int j = -2; j < 3; j++)
		{
			static_cast<MapScene*>(this->getParent())->_mapLayer->setcollidable(a.x + i, a.y + j, 1);
		}
	}
											/*m_BuildingList.pushBack(barrack);*/
}
void MenuLayer::createStope(Point tpos, bool not_enemy) {
	if (TollgateDataLayer::m_iGold<TollgateDataLayer::StopeCostMine)
	{
		return;
	}
	
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
	for (int i = -2; i < 3; i++)
	{
		for (int j = -2; j < 3; j++)
		{
			if (static_cast<MapScene*>(this->getParent())->_mapLayer->getCollidable(a.x + i, a.y + j) == 1) {
				log("collidable=%f,%f", a.x + i, a.y + j);
				return;
			}
		}
	}

	Stope* stope= new Stope();
	Building::createWithSpriteFrameName(stope, "Stope.png");     //此处需要图片——图片

	TollgateDataLayer::addm_iElect += 50;
	TollgateDataLayer::m_iGold -= TollgateDataLayer::StopeCostMine;

	Point mypos;
	mypos.x = tpos.x - _currentPos.x;
	mypos.y = tpos.y - _currentPos.y;

	tmap->addChild(stope, BUILDING_LAYEER_LVL);
	stope->setPosition(mypos);    //setPosition
	
	stope->showUI();

	if (not_enemy)
	{
		//add m_buildingVec
		BuildingManager::m_buildingVec.push_back(stope);
		stope->_numInVec = BuildingManager::m_buildingVec.size() - 1;
	}
	else {
		//add m_buildingVec
		BuildingManager::m_enemyBuildingVec.push_back(stope);
		stope->_numInVec = BuildingManager::m_enemyBuildingVec.size() - 1;
		stope->is_Enemy();
	}

	for (int i = -2; i < 3; i++)
	{
		for (int j = -2; j < 3; j++)
		{
			static_cast<MapScene*>(this->getParent())->_mapLayer->setcollidable(a.x + i, a.y + j, 1);
		}
	}
	
										   /*m_BuildingList.pushBack(barrack);*/
}
void MenuLayer::createWarFactory(Point tpos, bool not_enemy) {
	if (TollgateDataLayer::m_iGold<TollgateDataLayer::WarFactoryCostMine
		||TollgateDataLayer::m_iElec<TollgateDataLayer::WarFactoryCostMine)
	{
		return;
	}
	
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
	for (int i = -2; i < 3; i++)
	{
		for (int j = -2; j < 3; j++)
		{
			if (static_cast<MapScene*>(this->getParent())->_mapLayer->getCollidable(a.x + i, a.y + j) == 1) {
				log("collidable=%f,%f", a.x + i, a.y + j);
				return;
			}
		}
	}
	TollgateDataLayer::m_iGold -= TollgateDataLayer::WarFactoryCostMine;
	TollgateDataLayer::m_iElec -= TollgateDataLayer::WarFactoryCostElec;

	WarFactory* warf = new WarFactory();
	Building::createWithSpriteFrameName(warf, "WarFactory.png");     //此处需要图片——图片

	Point mypos;
	mypos.x = tpos.x - _currentPos.x;
	mypos.y = tpos.y - _currentPos.y;

	tmap->addChild(warf, BUILDING_LAYEER_LVL);
	warf->setPosition(mypos);    //setPosition
	warf->showUI();
	
	if (not_enemy)
	{
		buildingMgr->SetWarFactoryController(warf);
		//add m_buildingVec
		BuildingManager::m_buildingVec.push_back(warf);
		warf->_numInVec = BuildingManager::m_buildingVec.size() - 1;
	}
	else {
		//add m_buildingVec
		BuildingManager::m_enemyBuildingVec.push_back(warf);
		warf->_numInVec = BuildingManager::m_enemyBuildingVec.size() - 1;
		warf->is_Enemy();
	}

	for (int i = -2; i < 3; i++)
	{
		for (int j = -2; j < 3; j++)
		{
			static_cast<MapScene*>(this->getParent())->_mapLayer->setcollidable(a.x + i, a.y + j, 1);
		}
	}
										 /*m_BuildingList.pushBack(barrack);*/
}
void MenuLayer::createBase(Point tpos, bool not_enemy) {
	auto tmap = MapLayer::map;
	auto _currentPos = tmap->getPosition();//地图的绝对坐标
	Vec2 a = MapLayer::ConvertToMap(tpos.x, tpos.y, tmap);
	for (int i = -2; i < 3; i++)
	{
		for (int j = -2; j < 3; j++)
		{
			//static_cast<MapScene*>(this->getParent())->_mapLayer->setcollidable(a.x + i, a.y + j, 1);
		}
	}
	log("tpos2=(%f,%f)", tpos.x, tpos.y);
	log("a(%f,%f)", a.x, a.y);
	//create Barrack
	if (a.x > 74 || a.x < 0 || a.y>74 || a.y < 0)
	{
		return;
	}

	Base* base = new Base();
	Building::createWithSpriteFrameName(base, "Base.png");     //此处需要图片——图片

	Point mypos;
	mypos.x = tpos.x - _currentPos.x;
	mypos.y = tpos.y - _currentPos.y;

	tmap->addChild(base, BUILDING_LAYEER_LVL);
	base->setPosition(mypos);    //setPosition
	base->showUI();

	if (not_enemy)
	{
		buildingMgr->SetBaseController(base);
		//add m_buildingVec
		BuildingManager::m_buildingVec.push_back(base);
		base->_numInVec = BuildingManager::m_buildingVec.size() - 1;
	}
	else {
		//add m_buildingVec
		BuildingManager::m_enemyBuildingVec.push_back(base);
		base->_numInVec = BuildingManager::m_enemyBuildingVec.size() - 1;
		base->is_Enemy();
	}

	log("createBase");
	//add m_buildingVec
	BuildingManager::m_buildingVec.push_back(base);

	for (int i = -2; i < 3; i++)
	{
		for (int j = -2; j < 3; j++)
		{
			//static_cast<MapScene*>(this->getParent())->_mapLayer->setcollidable(a.x + i, a.y + j, 1);
		}
	}
}

void MenuLayer::CreateBarrackLayer(Building* building)
{
	//放置UI
	//auto UI_menu = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("BarrackUI/BarrackUI_1.ExportJson");
	this->removeChild(UIMenu);
	UIMenu = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("BarrackUI/BarrackUI_1.ExportJson");
	UIMenu->setPosition(Point(0, 0));
	this->addChild(UIMenu, UI_LAYEER_LVL+1);
	log("barrackLayer");
	Button* soldier = (Button*)Helper::seekWidgetByName(UIMenu, "Button_Soldier");
	soldier->setTouchEnabled(false);
	Button* dog = (Button*)Helper::seekWidgetByName(UIMenu, "Button_Dog");
	dog->setTouchEnabled(false);
	Button* sniper = (Button*)Helper::seekWidgetByName(UIMenu, "Button_Snipe");
	sniper->setTouchEnabled(false);


	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [&,building](Touch *touch, Event *event)
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
	};
	listener->onTouchEnded= [&,building](Touch* touch, Event* event)
	{
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		Point tpos = Director::getInstance()->convertToGL(touch->getLocationInView());
		Point barrackPos = building->getPosition();
		barrackPos.x += 70;
		barrackPos.y -= 70;

		if (message == "soldier") {
			createSoldier(barrackPos,true);
		}
		if (message == "dog") {
			createDog(barrackPos,true);
		}
		if (message == "sniper") {
			createSniper(barrackPos,true);
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, soldier);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), dog);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener->clone(), sniper);
}
void MenuLayer::createSoldier(Point tpos, bool not_enemy) {

	if (TollgateDataLayer::m_iGold<TollgateDataLayer::SoldierCostMine)
	{
		return;
	}
	TollgateDataLayer::m_iGold -= TollgateDataLayer::SoldierCostMine;
	auto tmap = MapLayer::map;
	auto _currentPos = tmap->getPosition();//地图的绝对坐标
	//Vec2 a = MapLayer::ConvertToMap(tpos.x, tpos.y, tmap);

	Soldier* soldier_1 = new Soldier();

	Army::createWithSpriteFrameName(soldier_1, "ALLArmy/soldier_1.png");     //此处需要图片——图片

	
	//Point mypos;
	//mypos.x = tpos.x - _currentPos.x;
	//mypos.y = tpos.y - _currentPos.y;

	tmap->addChild(soldier_1, ARMY_LAYEER_LVL);
	soldier_1->setPosition(tpos);    //setPosition
	soldier_1->showUI();
	//Point mmmpos = soldier_1->getScenePosition();

	if (not_enemy)
	{
		//add m_buildingVec
		AIManager::m_armyVec.push_back(soldier_1);
		soldier_1->_numInVec = AIManager::m_armyVec.size() - 1;
	}
	else {
		//add m_buildingVec
		AIManager::m_enemyArmyVec.push_back(soldier_1);
		soldier_1->_numInVec = AIManager::m_enemyArmyVec.size() - 1;
		soldier_1->is_Enemy();
	}
	
	soldier_1->schedule(schedule_selector(Army::autoAttack));//每帧调用函数

	//static_cast<MapScene*>(this->getParent())->_mapLayer->setcollidable(a.x, a.y, 1);
	/*m_BuildingList.pushBack(barrack);*/
}

//void MenuLayer::AttackUpdate(float dt) {
//	this->autoAttack();
//}

void MenuLayer::createDog(Point tpos, bool not_enemy) {
	if (TollgateDataLayer::m_iGold<TollgateDataLayer::DogCostMine)
	{
		return;
	}
	TollgateDataLayer::m_iGold -= TollgateDataLayer::DogCostMine;
	auto tmap = MapLayer::map;
	auto _currentPos = tmap->getPosition();//地图的绝对坐标
										   //Vec2 a = MapLayer::ConvertToMap(tpos.x, tpos.y, tmap);

	Dog* soldier_1 = new Dog();
	Army::createWithSpriteFrameName(soldier_1, "ALLArmy/dog_1.png");     //此处需要图片——图片

																   //Point mypos;
																   //mypos.x = tpos.x - _currentPos.x;
																   //mypos.y = tpos.y - _currentPos.y;

	tmap->addChild(soldier_1, ARMY_LAYEER_LVL);
	soldier_1->setPosition(tpos);    //setPosition
	soldier_1->showUI();

	if (not_enemy)
	{
		//add m_buildingVec
		AIManager::m_armyVec.push_back(soldier_1);
		soldier_1->_numInVec = AIManager::m_armyVec.size() - 1;
	}
	else {
		//add m_buildingVec
		AIManager::m_enemyArmyVec.push_back(soldier_1);
		soldier_1->_numInVec = AIManager::m_enemyArmyVec.size() - 1;
		soldier_1->is_Enemy();
	}

	soldier_1->schedule(schedule_selector(Army::autoAttack));//每帧调用函数
	//static_cast<MapScene*>(this->getParent())->_mapLayer->setcollidable(a.x, a.y, 1);
	/*m_BuildingList.pushBack(barrack);*/
}
void MenuLayer::createSniper(Point tpos, bool not_enemy) {
	if (TollgateDataLayer::m_iGold<TollgateDataLayer::SniperCostMine)
	{
		return;
	}
	TollgateDataLayer::m_iGold -= TollgateDataLayer::SniperCostMine;
	auto tmap = MapLayer::map;
	auto _currentPos = tmap->getPosition();//地图的绝对坐标
										   //Vec2 a = MapLayer::ConvertToMap(tpos.x, tpos.y, tmap);

	Sniper* soldier_1 = new Sniper();
	Army::createWithSpriteFrameName(soldier_1, "Sniper.png");     //此处需要图片——图片
															   //Point mypos;
															   //mypos.x = tpos.x - _currentPos.x;
															   //mypos.y = tpos.y - _currentPos.y;

	tmap->addChild(soldier_1, ARMY_LAYEER_LVL);
	soldier_1->setPosition(tpos);    //setPosition
	soldier_1->showUI();

	if (not_enemy)
	{
		//add m_buildingVec
		AIManager::m_armyVec.push_back(soldier_1);
		soldier_1->_numInVec = AIManager::m_armyVec.size() - 1;
	}
	else {
		//add m_buildingVec
		AIManager::m_enemyArmyVec.push_back(soldier_1);
		soldier_1->_numInVec = AIManager::m_enemyArmyVec.size() - 1;
		soldier_1->is_Enemy();
	}

	soldier_1->schedule(schedule_selector(Army::autoAttack));//每帧调用函数
	//static_cast<MapScene*>(this->getParent())->_mapLayer->setcollidable(a.x, a.y, 1);
	/*m_BuildingList.pushBack(barrack);*/
}

void MenuLayer::CreateBaseLayer(Building* building)
{
	//放置UI
	//auto UI_menu = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("BarrackUI/BarrackUI_1.ExportJson");
	this->removeChild(UIMenu);
	UIMenu = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("menu_1.ExportJson");
	UIMenu->setPosition(Point(0, 0));
	this->addChild(UIMenu, UI_LAYEER_LVL + 1);

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

}
void MenuLayer::createScv(Point tpos, bool not_enemy) {
	auto tmap = MapLayer::map;
	auto _currentPos = tmap->getPosition();//地图的绝对坐标
										   //Vec2 a = MapLayer::ConvertToMap(tpos.x, tpos.y, tmap);

	Scv* soldier_1 = new Scv();
	Army::createWithSpriteFrameName(soldier_1, "Scv.png");     //此处需要图片——图片

																   //Point mypos;
																   //mypos.x = tpos.x - _currentPos.x;
																   //mypos.y = tpos.y - _currentPos.y;
	tmap->addChild(soldier_1, ARMY_LAYEER_LVL);
	soldier_1->setPosition(tpos);    //setPosition
	soldier_1->showUI();

	if (not_enemy)
	{
		//add m_buildingVec
		AIManager::m_armyVec.push_back(soldier_1);
		soldier_1->_numInVec = AIManager::m_armyVec.size() - 1;
	}
	else {
		//add m_buildingVec
		AIManager::m_enemyArmyVec.push_back(soldier_1);
		soldier_1->_numInVec = AIManager::m_enemyArmyVec.size() - 1;
		soldier_1->is_Enemy();
	}

	soldier_1->schedule(schedule_selector(Army::autoAttack));//每帧调用函数
	//static_cast<MapScene*>(this->getParent())->_mapLayer->setcollidable(a.x, a.y, 1);
	/*m_BuildingList.pushBack(barrack);*/
}

void MenuLayer::CreateWarFactoryLayer(Building* building)
{
	//放置UI
	log("create  warfactorylayer");
	this->removeChild(UIMenu);
	UIMenu = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("WarFactory/WarFactory_1.ExportJson");
	UIMenu->setPosition(Point(0, 0));
	this->addChild(UIMenu, UI_LAYEER_LVL + 1);

	Button* tank = (Button*)Helper::seekWidgetByName(UIMenu, "Button_Tank");
	tank->setTouchEnabled(false);

	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [&,building](Touch *touch, Event *event)
	{	
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		Point pos = target->convertToNodeSpace(touch->getLocation());

		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);
		if (rect.containsPoint(pos))
		{
			log("tank");
			Point warfkPos = building->getPosition();
			warfkPos.x += 70;
			warfkPos.y -= 70;
			createTank(warfkPos,true);
			return true;
		}
		return false;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, tank);
}
void MenuLayer::createTank(Point tpos, bool not_enemy) {
	if (TollgateDataLayer::m_iGold<TollgateDataLayer::TankCostMine)
	{
		return;
	}
	TollgateDataLayer::m_iGold -= TollgateDataLayer::TankCostMine;
	log("using tank");
	auto tmap = MapLayer::map;
	auto _currentPos = tmap->getPosition();//地图的绝对坐标
										   //Vec2 a = MapLayer::ConvertToMap(tpos.x, tpos.y, tmap);

	Tank* soldier_1 = new Tank();
	Army::createWithSpriteFrameName(soldier_1, "ALLArmy/tank_1.png");     //此处需要图片——图片

															   //Point mypos;
															   //mypos.x = tpos.x - _currentPos.x;
															   //mypos.y = tpos.y - _currentPos.y;
	tmap->addChild(soldier_1, ARMY_LAYEER_LVL);
	soldier_1->setPosition(tpos);    //setPosition
	soldier_1->showUI();

	if (not_enemy)
	{
		//add m_buildingVec
		AIManager::m_armyVec.push_back(soldier_1);
		soldier_1->_numInVec = AIManager::m_armyVec.size() - 1;
	}
	else {
		//add m_buildingVec
		AIManager::m_enemyArmyVec.push_back(soldier_1);
		soldier_1->_numInVec = AIManager::m_enemyArmyVec.size() - 1;
		soldier_1->is_Enemy();
	}

	soldier_1->schedule(schedule_selector(Army::autoAttack));//每帧调用函数
	//static_cast<MapScene*>(this->getParent())->_mapLayer->setcollidable(a.x, a.y, 1);
	/*m_BuildingList.pushBack(barrack);*/
}
