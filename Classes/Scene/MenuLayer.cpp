#include "MenuLayer.h"
TMXTiledMap* MapLayer::map;
bool MenuLayer::init()
{
	auto _visibleSize = Director::getInstance()->getVisibleSize();//屏幕大小


	//设置菜单层
	menuLayer = LayerColor::create(Color4B(225, 105, 180, 80));
	menuLayer->setPosition(_visibleSize.width * 5 / 6, 0);
	this->addChild(menuLayer, UI_LAYEER_LVL);
	//放置UI
	auto UI_menu = cocostudio::GUIReader::getInstance()->
		widgetFromJsonFile("menu_1.ExportJson");
	UI_menu->setPosition(Point(0, 0));

	this->addChild(UI_menu, UI_LAYEER_LVL);

	Button* barrack = (Button*)Helper::seekWidgetByName(UI_menu, "Button_barracks");
	barrack->setTouchEnabled(false);
	Button* producer = (Button*)Helper::seekWidgetByName(UI_menu, "Button_producer");
	producer->setTouchEnabled(false);
	Button* stope = (Button*)Helper::seekWidgetByName(UI_menu, "Button_Stope");
	stope->setTouchEnabled(false);
	Button* warfac = (Button*)Helper::seekWidgetByName(UI_menu, "Button_WarFactory");
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
	auto _currentPos = static_cast<MapLayer*>(static_cast<MapScene*>(this->getParent())->_mapLayer)->map->getPosition();//地图的绝对坐标

	tpos.x -= _currentPos.x;
	tpos.y -= _currentPos.y;
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
	//create Barrack
	Barrack* barrack = new Barrack();
	Building::create(barrack, "Barracks.png");     //此处需要图片——大兵图片
												   //this->addChild(barrack);
	//auto tmap = static_cast<MapScene*>(this->getParent())->_mapLayer->map;
	auto tmap = MapLayer::map;
	//tmap->addChild(barrack, BUILDING_LAYEER_LVL);
	tmap->addChild(barrack, BUILDING_LAYEER_LVL);
	barrack->setPosition(tpos);            //setPosition
	barrack->showUI();
	Vec2 a = static_cast<MapScene*>(this->getParent())->_mapLayer->ConvertToMap(tpos.x, tpos.y, tmap);
	log("a(%f,%f)", a.x, a.y);
	static_cast<MapScene*>(this->getParent())->_mapLayer->_collidable[a.x][a.y]=1;
	log("%d", static_cast<MapScene*>(this->getParent())->_mapLayer->_collidable[a.x][a.y]);
										   /*m_BuildingList.pushBack(barrack);*/
}
void MenuLayer::createProducer(Point tpos) {
	//create Producer
	Producer* producer = new Producer();
	Building::create(producer, "Producer.png");     //此处需要图片——大兵图片
													//this->addChild(barrack);
	static_cast<MapScene*>(this->getParent())->_mapLayer->map->addChild(producer, BUILDING_LAYEER_LVL);
	producer->setPosition(tpos);            //setPosition
	producer->showUI();
											/*m_BuildingList.pushBack(barrack);*/
}
void MenuLayer::createStope(Point tpos) {
	//create Stope
	Stope* stope = new Stope();
	Building::create(stope, "Stope.png");     //此处需要图片——大兵图片
												   //this->addChild(barrack);
	static_cast<MapScene*>(this->getParent())->_mapLayer->map->addChild(stope, BUILDING_LAYEER_LVL);
	stope->setPosition(tpos);            //setPosition
	stope->showUI();
										   /*m_BuildingList.pushBack(barrack);*/
}
void MenuLayer::createWarFactory(Point tpos) {
	//create WarFactory
	WarFactory* warfac = new WarFactory();
	Building::create(warfac, "WarFactory.png");     //此处需要图片——大兵图片
											  //this->addChild(barrack);
	static_cast<MapScene*>(this->getParent())->_mapLayer->map->addChild(warfac, BUILDING_LAYEER_LVL);
	warfac->setPosition(tpos);            //setPosition
	warfac->showUI();
										 /*m_BuildingList.pushBack(barrack);*/
}