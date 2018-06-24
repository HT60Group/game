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
//		MovingSpeed = root["Soldier"]["Speed"].asDouble();               //�ƶ��ٶ�
//		AttackDistance = root["Soldier"]["Range"].asInt();            //��������
//		DPS = root["Soldier"]["Dps"].asInt();                       //�˺�
//		CostMine = root["Soldier"]["CostMime"].asInt();                  //���ѵĿ�
//		CostElec = root["Soldier"]["CostElec"].asInt();                 //���ѵĵ�
//		Costime = root["Soldier"]["Costime"].asInt();                  //���ѵ�ʱ��
//	}
//}