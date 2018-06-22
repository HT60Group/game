#include "Dog.h"

bool Dog::init()
{
	return true;
}
void Dog::showUI() {
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("hpBar_1.ExportJson");
	this->addChild(UI);
	Size size = this->getContentSize();
	UI->setPosition(Point(size.width*0.4f, size.height*0.9f));

	hpBar = (LoadingBar*)Helper::seekWidgetByName(UI, "HpBar");
	hpBar->setPercent(100);
	totalHp = Hp;
}
//void Dog::readJson()
//{
//	Json::Reader reader;
//	Json::Value root;
//
//	std::string data = FileUtils::getInstance()->getStringFromFile("StarCC.json");
//
//	if (reader.parse(data, root, false) == true)
//	{
//		Hp = root["Dog"]["Hp"].asInt();
//		MovingSpeed = root["Dog"]["Speed"].asDouble();               //移动速度
//		AttackDistance = root["Dog"]["Range"].asInt();            //攻击距离
//		DPS = root["Dog"]["Dps"].asInt();                       //伤害
//		CostMine = root["Dog"]["CostMime"].asInt();                  //花费的矿
//		CostElec = root["Dog"]["CostElec"].asInt();                 //花费的电
//		Costime = root["Dog"]["Costime"].asInt();                  //花费的时间
//	}
//}