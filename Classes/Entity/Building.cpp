#include "Building.h"

bool Building::init()
{
	readJson();


	//订阅类型为test的消息,传递数据NULL
	NotificationCenter::getInstance()->addObserver(
		this,
		callfuncO_selector(Building::testMsg),
		"test",
		NULL);

	//3秒后发布test消息
	this->schedule(schedule_selector(Building::sendMsg), 3.0f);

	this->scheduleUpdate();
	return true;
}

void Building::changeState(EnumState enState)
{
	this->enCurState = enState;
}

//如果血量大于0即存活 
bool Building::isAlive()
{
	if (Hp > 0){
		return true;
	}
	else {
		return false;
	}
}

//如果矿和气足够就能制造
bool Building::isCreateSoldiers()
{
	return true;
}


void Building::update(float dt)
{
	switch (enCurState) {
	case enAlive:
		if (!isAlive())
		{

		}
		break;
	};
}

void Building::sendMsg(float dt)
{
	NotificationCenter::getInstance()->postNotification("test", NULL);
	//发布test消息
}

void Building::getMsg(float dt)
{
	//接受test消息
}

void Building::readJson()
{
	Json::Reader reader;
	Json::Value root;

	std::string data = FileUtils::getInstance()->getStringFromFile("StarCC.json");
}


Building* Building::create(Building* sprite, const char *filename)
{
	if (sprite &&sprite->initWithFile(filename))
	{
		sprite->autorelease();

		return sprite;
	}

	CC_SAFE_DELETE(sprite);

	return nullptr;
}

