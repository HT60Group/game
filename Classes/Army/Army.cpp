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
		MovingSpeed=root["Army"]["Speed"].asDouble();               //�ƶ��ٶ�
		AttackDistance = root["Army"]["Range"].asInt();            //��������
		DPS = root["Army"]["Dps"].asInt();                       //�˺�
		CostMine = root["Army"]["CostMime"].asInt();                  //���ѵĿ�
		CostElec = root["Army"]["CostElec"].asInt();                 //���ѵĵ�
		Costime = root["Army"]["Costime"].asInt();                  //���ѵ�ʱ��
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
