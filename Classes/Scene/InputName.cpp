#include "InputName.h"
#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "NetMenu.h"
#include "Player.h"
USING_NS_CC;

Scene* InputName::createScene() {
	log("InputName\n\n\n\n");
	//auto scene = Scene::create();
	//auto layer = InputName::create();
	//scene->addChild(layer);

	return InputName::create();
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
	

	auto name = (cocos2d::ui::TextField*)Helper::seekWidgetByName(UI, "Name");
	const Size s = name->getTouchSize();
	log("%f\n\n", s.width);
	/*name->setCursorChar('|');
	name->setCursorEnabled(true);*/
	name->setMaxLength(50);
	name->setMaxLengthEnabled(true);
	name->addEventListener(CC_CALLBACK_2(InputName::textFieldEvent, this));
	

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

void InputName::textFieldEvent(Ref *pSender, cocos2d::ui::TextField::EventType type)
{
	switch (type)
	{
	case cocos2d::ui::TextField::EventType::ATTACH_WITH_IME:
	{
		cocos2d::ui::TextField* textField = dynamic_cast<cocos2d::ui::TextField*>(pSender);
		Size screenSize = CCDirector::getInstance()->getWinSize();

		//_pleaseStartButton->setVisible(true);
	}
	break;

	case cocos2d::ui::TextField::EventType::DETACH_WITH_IME:
	{
		cocos2d::ui::TextField* textField = dynamic_cast<cocos2d::ui::TextField*>(pSender);

		// _playerName = textField->getString();
		_playerName = textField->getString();
		Player::getInstance()->setname(_playerName);
		// _pleaseStartButton->setVisible(true);
	}
	break;

	case cocos2d::ui::TextField::EventType::INSERT_TEXT:
	{
		TextField* textField = dynamic_cast<cocos2d::ui::TextField*>(pSender);
		// _pleaseStartButton->setVisible(false);
		//_playerName = textField->getString();
		//_nameStartButton->setVisible(true);
		_playerName = textField->getString();
		Player::getInstance()->setname(_playerName);
		log("%s", _playerName);
	}
	break;

	case cocos2d::ui::TextField::EventType::DELETE_BACKWARD:
	{
		TextField* textField = dynamic_cast<cocos2d::ui::TextField*>(pSender);

		_playerName = textField->getString();
		Player::getInstance()->setname(_playerName);
		log("%s", _playerName);
	}
	break;

	default:
		break;
	}
}