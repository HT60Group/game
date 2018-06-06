#include "Soldier.h"

bool Soldier::init()
{
	return true;
}

void Soldier::readJson()
{
	Json::Reader reader;
	Json::Value root;

	std::string data = FileUtils::getInstance()->getStringFromFile("StarCC.json");

	if (reader.parse(data, root, false) == true)
	{
		Hp = root["Soldier"]["Hp"].asInt();
		MovingSpeed = root["Soldier"]["Speed"].asDouble();               //移动速度
		AttackDistance = root["Soldier"]["Range"].asInt();            //攻击距离
		DPS = root["Soldier"]["Dps"].asInt();                       //伤害
		CostMine = root["Soldier"]["CostMime"].asInt();                  //花费的矿
		CostElec = root["Soldier"]["CostElec"].asInt();                 //花费的电
		Costime = root["Soldier"]["Costime"].asInt();                  //花费的时间
	}
}