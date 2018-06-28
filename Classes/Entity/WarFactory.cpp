#include "WarFactory.h"

bool WarFactory::init()
{
	//readJson();

	//create WarFactory
	//WarFactory* warfactory = new WarFactory();
	//Building::create(warfactory, "WarFactory.png");     //此处需要图片——图片

	//this->addChild(warfactory);

	//warfactory->setPosition(Point(0, 0));            //setPosition
	return true;
}
void WarFactory::showUI() {
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("hpBar_1.ExportJson");
	this->addChild(UI);
	Size size = this->getContentSize();
	UI->setPosition(Point(size.width*0.4f, size.height));

	hpBar = (LoadingBar*)Helper::seekWidgetByName(UI, "HpBar");
	hpBar->setPercent(100);
	totalHp = Hp;
}
//
//void WarFactory::readJson()
//{
//	Json::Reader reader;
//	Json::Value root;
//
//	std::string data = FileUtils::getInstance()->getStringFromFile("StarCC.json");
//
//	if (reader.parse(data, root, false) == true)
//	{
//		Hp = root["WarFactory"]["Hp"].asInt();
//		Costime = root["WarFactory"]["Costime"].asInt();
//		CostMine = root["WarFactory"]["CostMine"].asInt();
//		CostElec = root["WarFactory"]["CostElec"].asInt();
//	}
//}

//void WarFactory::CreateTank()             //产生Tank
//{
//	Tank* tank = new Tank();
//	Army::create(tank, "Tank.png");     //此处需要图片——大兵图片
//
//	this->addChild(tank);
//
//	tank->setPosition(Point(0, 0));            //setPosition
//}