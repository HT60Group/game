#include "Scv.h"

bool Scv::init()
{
	return true;
}

void Scv::readJson()
{
	Json::Reader reader;
	Json::Value root;

	std::string data = FileUtils::getInstance()->getStringFromFile("StarCC.json");

	if (reader.parse(data, root, false) == true)
	{
		Hp = root["Scv"]["Hp"].asInt();
		MovingSpeed = root["Scv"]["Speed"].asDouble();               //移动速度
		AttackDistance = root["Scv"]["Range"].asInt();            //攻击距离
		DPS = root["Scv"]["Dps"].asInt();                       //伤害
		CostMine = root["Scv"]["CostMime"].asInt();                  //花费的矿
		CostElec = root["Scv"]["CostElec"].asInt();                 //花费的电
		Costime = root["Scv"]["Costime"].asInt();                  //花费的时间
	}
}