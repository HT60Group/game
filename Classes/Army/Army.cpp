#include "Army.h"

bool Army::init()
{
	return true;
}

void Army::readJson()
{
	Json::Reader reader;
	Json::Value root;

	std::string data = FileUtils::getInstance()->getStringFromFile("StarCC.json");

	if (reader.parse(data, root, false) == true)
	{
		Hp = root["Army"]["Hp"].asInt();
		MovingSpeed=root["Army"]["Speed"].asDouble();               //移动速度
		AttackDistance = root["Army"]["Range"].asInt();            //攻击距离
		DPS = root["Army"]["Dps"].asInt();                       //伤害
		CostMine = root["Army"]["CostMime"].asInt();                  //花费的矿
		CostElec = root["Army"]["CostElec"].asInt();                 //花费的电
		Costime = root["Army"]["Costime"].asInt();                  //花费的时间
	}
}

Army* Army::create(Army* sprite,const char *filename)
{
	if (sprite &&sprite->initWithFile(filename))
	{
		sprite->autorelease();

		return sprite;
	}

	CC_SAFE_DELETE(sprite);

	return nullptr;
}
