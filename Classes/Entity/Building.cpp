#include "Building.h"

bool Building::init()
{
	readJson();


	//��������Ϊtest����Ϣ,��������NULL
	NotificationCenter::getInstance()->addObserver(
		this,
		callfuncO_selector(Building::testMsg),
		"test",
		NULL);

	//3��󷢲�test��Ϣ
	this->schedule(schedule_selector(Building::sendMsg), 3.0f);

	this->scheduleUpdate();
	return true;
}

void Building::changeState(EnumState enState)
{
	this->enCurState = enState;
}

//���Ѫ������0����� 
bool Building::isAlive()
{
	if (Hp > 0){
		return true;
	}
	else {
		return false;
	}
}

//���������㹻��������
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
	//����test��Ϣ
}

void Building::getMsg(float dt)
{
	//����test��Ϣ
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

