#include "Soldier.h"

bool Soldier::init()
{
	return true;
}
void Soldier::showUI() {
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("hpBar_1.ExportJson");
	this->addChild(UI);
	Size size = this->getContentSize();
	UI->setPosition(Point(size.width*0.4f, size.height*0.9f));

	hpBar = (LoadingBar*)Helper::seekWidgetByName(UI, "HpBar");
	hpBar->setPercent(100);
	totalHp = Hp;
}
//void Soldier::readJson()
//{
//	Json::Reader reader;
//	Json::Value root;
//
//	std::string data = FileUtils::getInstance()->getStringFromFile("StarCC.json");
//
//	if (reader.parse(data, root, false) == true)
//	{
//		Hp = root["Soldier"]["Hp"].asInt();
//		MovingSpeed = root["Soldier"]["Speed"].asDouble();               //移动速度
//		AttackDistance = root["Soldier"]["Range"].asInt();            //攻击距离
//		DPS = root["Soldier"]["Dps"].asInt();                       //伤害
//		CostMine = root["Soldier"]["CostMime"].asInt();                  //花费的矿
//		CostElec = root["Soldier"]["CostElec"].asInt();                 //花费的电
//		Costime = root["Soldier"]["Costime"].asInt();                  //花费的时间
//	}
//}