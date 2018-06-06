#include "Barrack.h"

bool Barrack::init()
{
	readJson();

	//create Barrack
	Barrack* barrack = new Barrack();
	Building::create(barrack, "Barrack.png");     //�˴���ҪͼƬ����ͼƬ

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

void Barrack::CreateSoldier()             //����soldiers
{
	Soldier* soldier = new Soldier();
	Army::create(soldier, "Soldier.png");     //�˴���ҪͼƬ�������ͼƬ
	
	this->addChild(soldier);

	soldier->setPosition(Point(0, 0));            //setPosition
}

void Barrack::CreateSniper()             //����snipers
{
	Sniper* sniper = new Sniper();
	Army::create(sniper, "Sniper.png");     //�˴���ҪͼƬ�������ͼƬ

	this->addChild(sniper);

	sniper->setPosition(Point(0, 0));            //setPosition
}

void Barrack::CreateDog()             //����dogs
{
	Dog* dog = new Dog();
	Army::create(dog, "Dog.png");     //�˴���ҪͼƬ�������ͼƬ

	this->addChild(dog);

	dog->setPosition(Point(0, 0));            //setPosition
}