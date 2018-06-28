#include "Tank.h"
Tank::Tank() {
	Hp = 150;
	MovingSpeed = 2.25;               //移动速度
	AttackDistance = 7;            //攻击距离
	DPS = 25;                       //伤害
	CostMine = 150;                  //花费的矿
	CostElec = 150;                 //花费的电
	Costime = 4;                  //花费的时间
	kind = 2;
}
Tank::~Tank() {

}

bool Tank::init()
{
	return true;
}

void Tank::showUI() {
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("hpBar_1.ExportJson");
	this->addChild(UI);
	Size size = this->getContentSize();
	UI->setPosition(Point(size.width*0.4f, size.height*0.9f));

	hpBar = (LoadingBar*)Helper::seekWidgetByName(UI, "HpBar");
	hpBar->setPercent(100);
	totalHp = Hp;
}

//void Tank::readJson()
//{
//	Json::Reader reader;
//	Json::Value root;
//
//	std::string data = FileUtils::getInstance()->getStringFromFile("StarCC.json");
//
//	if (reader.parse(data, root, false) == true)
//	{
//		Hp = root["Tank"]["Hp"].asInt();
//		MovingSpeed = root["Tank"]["Speed"].asDouble();               //移动速度
//		AttackDistance = root["Tank"]["Range"].asInt();            //攻击距离
//		DPS = root["Tank"]["Dps"].asInt();                       //伤害
//		CostMine = root["Tank"]["CostMime"].asInt();                  //花费的矿
//		CostElec = root["Tank"]["CostElec"].asInt();                 //花费的电
//		Costime = root["Tank"]["Costime"].asInt();                  //花费的时间
//	}
//}