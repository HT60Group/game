#include "MenuLayer.h"

bool MenuLayer::init()
{
	auto _visibleSize = Director::getInstance()->getVisibleSize();//屏幕大小

																  //设置菜单层
	menuLayer = LayerColor::create(Color4B(225, 105, 180, 80));
	menuLayer->setPosition(_visibleSize.width * 5 / 6, 0);
	this->addChild(menuLayer);
	//放置UI
	auto UI_menu = cocostudio::GUIReader::getInstance()->
		widgetFromJsonFile("menu_1.ExportJson");
	UI_menu->setPosition(Point(0, 0));


	this->addChild(UI_menu);
	
	//auto menu_listener = EventListenerTouchOneByOne::create();

	//Button* button_producer = (Button*)Helper::seekWidgetByName(UI_menu, "button_producer");
	///*OnClick_producer(UI_menu);*/

	Button* barrack = (Button*)Helper::seekWidgetByName(UI_menu, "Button_barracks");
	barrack->setTouchEnabled(false);

	//barrack->addTouchEventListener(CC_CALLBACK_1(MenuLayer::barrackbutton, this));
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(MenuLayer::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(MenuLayer::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(MenuLayer::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, barrack);

	return true;
}
//void MenuLayer::barrackbutton(Ref* pSender)
//{
//	auto listener= EventListenerTouchOneByOne::create();
//	listener->onTouchBegan = [&](Touch*touch,Event* event) {
//		createBarrack(Point(0,0));
//		auto target = static_cast<Sprite*>(event->getCurrentTarget());
//		Point pos = target->convertToNodeSpace(touch->getLocation());
//		Size s = target->getContentSize();
//		Rect rect = Rect(0, 0, s.width, s.height);
//		if (rect.containsPoint(pos))
//		{
//			log("sprite began... x = %f, y = %f", pos.x, pos.y);
//			target->setOpacity(180);
//			return true;
//		}
//		return false;
//	};
//	listener->onTouchEnded = [&](Touch*touch,Event* event) {
//		Point tpos = Director::getInstance()->convertToGL(touch->getLocationInView());
//		createBarrack(tpos);
//	};
//
//}


//void MenuLayer::OnClick_producer(cocos2d::ui::Widget* UI_menu )
//{
//	auto listener = EventListenerMouse::create();
//	Button* button_producer = (Button*)Helper::seekWidgetByName(UI_menu, "button_producer");
//	bool _isClick = false;
//	listener->onMouseUp = [&](Event* event)
//	{
//		return true;
//	};
//	listener->onMouseDown = [&](EventMouse* event )
//	{
//	
//	};
//	listener->onMouseMove = [&](EventMouse* event)
//	{
//
//	};
//}
void MenuLayer::createBarrack(Point tpos) {
	//create Barrack
	Barrack* barrack = new Barrack();
	Building::create(barrack, "Barracks.png");     //此处需要图片——大兵图片
	this->addChild(barrack);
	//static_cast<MapScene*>(this->getParent())->map->addChild(barrack);
	barrack->setPosition(tpos);            //setPosition

	/*m_BuildingList.pushBack(barrack);*/
}

bool MenuLayer::onTouchBegan(Touch* touch, Event* event)
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
}
void MenuLayer::onTouchMoved(Touch* touch, Event* event)
{
    auto target = static_cast<Sprite*>(event->getCurrentTarget());
	Point pos = target->convertToNodeSpace(touch->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);
	if (rect.containsPoint(pos))
	{
		//target->setPosition(target->getPosition() + touch->getDelta());
	}
}
void MenuLayer::onTouchEnded(Touch* touch, Event* event)
{
	Point tpos = Director::getInstance()->convertToGL(touch->getLocationInView());
	createBarrack(tpos);
}