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
		MovingSpeed = root["Scv"]["Speed"].asDouble();               //�ƶ��ٶ�
		AttackDistance = root["Scv"]["Range"].asInt();            //��������
		DPS = root["Scv"]["Dps"].asInt();                       //�˺�
		CostMine = root["Scv"]["CostMime"].asInt();                  //���ѵĿ�
		CostElec = root["Scv"]["CostElec"].asInt();                 //���ѵĵ�
		Costime = root["Scv"]["Costime"].asInt();                  //���ѵ�ʱ��
	}
}