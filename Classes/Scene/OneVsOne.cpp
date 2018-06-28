#include "OneVsOne.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "leaf\API.h"
#include "leaf\Client.h"
#include "leaf\Server.h"
#include "Player.h"
USING_NS_CC;
Scene* OneVsOne::createScene() {
	auto scene = Scene::create();
	auto layer = OneVsOne::create();
	scene->addChild(layer);
	return scene;
}
bool OneVsOne::init() {
	if (!Scene::init()) { return false; }

	if (Player::getInstance()->is_Server)
	{
		RecvAndSend(Player::getInstance()->p_server);
	}
	SendMsgMod(Player::getInstance()->p_client);
	RecvMsgMod(Player::getInstance()->p_client);
	Player::getInstance()->p_client->_chatMsgSend.push_back("leaf66");
	
	
	
	//Scene
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("1v1.ExportJson");
	UI->setPosition(Point(0, 0));
	this->addChild(UI);

	//button Create OneVsOne
	Button* Start = (Button*)Helper::seekWidgetByName(UI, "Start");
	Start->setTouchEnabled(false);
	Start->addTouchEventListener(CC_CALLBACK_1(OneVsOne::buttonTurnToStart, this));


	auto chat = (cocos2d::ui::TextField*)Helper::seekWidgetByName(UI, "chat");
	const Size s = chat->getTouchSize();
	log("%f\n\n", s.width);
	chat->setMaxLength(50);
	chat->setMaxLengthEnabled(true);
	chat->addEventListener(CC_CALLBACK_2(OneVsOne::textFieldEvent, this));

	//Player::getInstance()->p_client->_chatMsgSend.push_back();



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
		buttonTurnToStart(this);
		//}

	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, Start);


	listView=(ListView*)Helper::seekWidgetByName(UI, "ListView_5");
	listView->setDirection(ListView::Direction::BOTH);
	listView->addEventListener(CC_CALLBACK_2(OneVsOne::selectedItemEvent, this)); //添加监听函数
	listView->addEventListener(CC_CALLBACK_2(OneVsOne::selectedItemEventScrollView, this));


	this->schedule(schedule_selector(OneVsOne::checkVector));//每帧调用函数

	return true;
}

void OneVsOne::buttonTurnToStart(Ref* pSender)
{
	if (Player::getInstance()->is_Server)
	{
        Player::getInstance()->p_server->SendStep();
		log("%d\n\n\n\n\n\n\n", Player::getInstance()->p_server->_step);
		//Close the cocos2d-x game scene and quit the application
		auto scene = MapScene::createScene();
		Director::getInstance()->replaceScene(scene);
	}
	else {

		log("%d\n\n\n\n\n\n\n", Player::getInstance()->p_client->_step);
		if (Player::getInstance()->p_client->_step == 2)
		{
			//Close the cocos2d-x game scene and quit the application
			auto scene = MapScene::createScene();
			Director::getInstance()->replaceScene(scene);
		}
	}
	
	

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif

	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);


}

void OneVsOne::selectedItemEvent(Ref* pSender, cocos2d::ui::ListView::EventType type)
{
	switch (type)
	{
	case cocos2d::ui::ListView::EventType::ON_SELECTED_ITEM_START:
	{
		ListView* listView = static_cast<ListView*>(pSender);
		CC_UNUSED_PARAM(listView);
		CCLOG("select child start index = %ld", listView->getCurSelectedIndex());
		break;
	}
	case cocos2d::ui::ListView::EventType::ON_SELECTED_ITEM_END:
	{
		ListView* listView = static_cast<ListView*>(pSender);
		CC_UNUSED_PARAM(listView);
		CCLOG("select child end index = %ld", listView->getCurSelectedIndex());
		break;
	}
	default:
		break;
	}
}


void OneVsOne::selectedItemEventScrollView(Ref* pSender, ui::ScrollView::EventType type)
{
	switch (type) {
	case ui::ScrollView::EventType::SCROLL_TO_BOTTOM://滑动到底部
		CCLOG("SCROLL_TO_BOTTOM");
		break;
	case ui::ScrollView::EventType::SCROLL_TO_TOP://滑动到头部
		CCLOG("SCROLL_TO_TOP");
		break;
	default:
		break;
	}


}

void OneVsOne::textFieldEvent(Ref *pSender, cocos2d::ui::TextField::EventType type)
{
	switch (type)
	{
	case cocos2d::ui::TextField::EventType::ATTACH_WITH_IME:
	{
		cocos2d::ui::TextField* textField = dynamic_cast<cocos2d::ui::TextField*>(pSender);
		Size screenSize = CCDirector::getInstance()->getWinSize();

		//_pleaseStartButton->setVisible(true);
		m_msgSend = textField->getString();
	}
	break;

	case cocos2d::ui::TextField::EventType::DETACH_WITH_IME:
	{
		cocos2d::ui::TextField* textField = dynamic_cast<cocos2d::ui::TextField*>(pSender);

		// _playerName = textField->getString();
		m_msgSend = textField->getString();
		// _pleaseStartButton->setVisible(true);
		Player::getInstance()->p_client->_chatMsgSend.push_back(m_msgSend);
	}
	break;

	case cocos2d::ui::TextField::EventType::INSERT_TEXT:
	{
		TextField* textField = dynamic_cast<cocos2d::ui::TextField*>(pSender);
		// _pleaseStartButton->setVisible(false);
		//_playerName = textField->getString();
		m_msgSend = textField->getString();
		//_nameStartButton->setVisible(true);

	}
	break;

	case cocos2d::ui::TextField::EventType::DELETE_BACKWARD:
	{
		TextField* textField = dynamic_cast<cocos2d::ui::TextField*>(pSender);
		m_msgSend= textField->getString();

		Player::getInstance()->p_client->_chatMsgSend.push_back(m_msgSend);
	}
	break;

	default:
		break;
	}
}

void OneVsOne::checkVector(float dt)
{
	if (!Player::getInstance()->p_client->_chatMsgRecv.empty())
	{
		for (int i = 0; i < Player::getInstance()->p_client->_chatMsgRecv.size(); i++)
		{
			Layout *layout = Layout::create();        //先创建一个layout，直接添加到ListView  
			layout->setContentSize(Size(listView->getContentSize().width, 60));

			std::string txt = Player::getInstance()->p_client->_chatMsgRecv[i];
			auto str = txt;
			auto text = cocos2d::ui::Text::create(str, "fonts/OpenSans-Regular.ttf", 32);
			text->setColor(cocos2d::Color3B::BLUE);
			text->setContentSize(Size(400, 50));
			layout->addChild(text);
			text->setPosition(Vec2(layout->getContentSize() / 2));
			log("%s", txt);

			listView->addChild(layout);
			//if (listView->getChildrenCount() > 50)
			//	listView->removeItem(0);

		}
		Player::getInstance()->p_client->_chatMsgRecv.clear();
	}
}