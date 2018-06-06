#include "Dog.h"

bool Dog::init()
{
	return true;
}

void Dog::readJson()
{
	Json::Reader reader;
	Json::Value root;

	std::string data = FileUtils::getInstance()->getStringFromFile("StarCC.json");

	if (reader.parse(data, root, false) == true)
	{
		Hp = root["Dog"]["Hp"].asInt();
		MovingSpeed = root["Dog"]["Speed"].asDouble();               //�ƶ��ٶ�
		AttackDistance = root["Dog"]["Range"].asInt();            //��������
		DPS = root["Dog"]["Dps"].asInt();                       //�˺�
		CostMine = root["Dog"]["CostMime"].asInt();                  //���ѵĿ�
		CostElec = root["Dog"]["CostElec"].asInt();                 //���ѵĵ�
		Costime = root["Dog"]["Costime"].asInt();                  //���ѵ�ʱ��
	}
}