#include "Barrack.h"

bool Barrack::init()
{
	readJson();

	//create Barrack
	Barrack* barrack = new Barrack();
	Building::create(barrack, "Barrack.png");     //此处需要图片——图片

	this->addChild(barrack);

	barrack->setPosition(Point(0, 0));            //setPosition
	return true;
}

void Barrack::readJson()
{
	Json::Reader reader;
	Json::Value root;

	std::string data = FileUtils::getInstance()->getStringFromFile("StarCC.json");

	if (reader.parse(data, root, false) == true)
	{
		Hp = root["Barrack"]["Hp"].asInt();
		Costime = root["Barrack"]["Costime"].asInt();
		CostMine = root["Barrack"]["CostMine"].asInt();
		CostElec = root["Barrack"]["CostElec"].asInt();
	}
}

void Barrack::CreateSoldier()             //产生soldiers
{
	Soldier* soldier = new Soldier();
	Army::create(soldier, "Soldier.png");     //此处需要图片——大兵图片
	
	this->addChild(soldier);

	soldier->setPosition(Point(0, 0));            //setPosition
}

void Barrack::CreateSniper()             //产生snipers
{
	Sniper* sniper = new Sniper();
	Army::create(sniper, "Sniper.png");     //此处需要图片——大兵图片

	this->addChild(sniper);

	sniper->setPosition(Point(0, 0));            //setPosition
}

void Barrack::CreateDog()             //产生dogs
{
	Dog* dog = new Dog();
	Army::create(dog, "Dog.png");     //此处需要图片——大兵图片

	this->addChild(dog);

	dog->setPosition(Point(0, 0));            //setPosition
}