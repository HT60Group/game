#include "Tank.h"

bool Tank::init()
{
	return true;
}

void Tank::readJson()
{
	Json::Reader reader;
	Json::Value root;

	std::string data = FileUtils::getInstance()->getStringFromFile("StarCC.json");

	if (reader.parse(data, root, false) == true)
	{
		Hp = root["Tank"]["Hp"].asInt();
		MovingSpeed = root["Tank"]["Speed"].asDouble();               //�ƶ��ٶ�
		AttackDistance = root["Tank"]["Range"].asInt();            //��������
		DPS = root["Tank"]["Dps"].asInt();                       //�˺�
		CostMine = root["Tank"]["CostMime"].asInt();                  //���ѵĿ�
		CostElec = root["Tank"]["CostElec"].asInt();                 //���ѵĵ�
		Costime = root["Tank"]["Costime"].asInt();                  //���ѵ�ʱ��
	}
}