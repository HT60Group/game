#include "Sniper.h"

bool Sniper::init()
{
	return true;
}
void Sniper::showUI() {
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("hpBar_1.ExportJson");
	this->addChild(UI);
	Size size = this->getContentSize();
	UI->setPosition(Point(size.width*0.4f, size.height*0.9f));

	hpBar = (LoadingBar*)Helper::seekWidgetByName(UI, "HpBar");
	hpBar->setPercent(100);
	totalHp = Hp;
}
//void Sniper::readJson()
//{
//	Json::Reader reader;
//	Json::Value root;
//
//	std::string data = FileUtils::getInstance()->getStringFromFile("StarCC.json");
//
//	if (reader.parse(data, root, false) == true)
//	{
//		Hp = root["Sniper"]["Hp"].asInt();
//		MovingSpeed = root["Sniper"]["Speed"].asDouble();               //移动速度
//		AttackDistance = root["Sniper"]["Range"].asInt();            //攻击距离
//		DPS = root["Sniper"]["Dps"].asInt();                       //伤害
//		CostMine = root["Sniper"]["CostMime"].asInt();                  //花费的矿
//		CostElec = root["Sniper"]["CostElec"].asInt();                 //花费的电
//		Costime = root["Sniper"]["Costime"].asInt();                  //花费的时间
//	}
//}