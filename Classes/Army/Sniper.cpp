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
//		MovingSpeed = root["Sniper"]["Speed"].asDouble();               //�ƶ��ٶ�
//		AttackDistance = root["Sniper"]["Range"].asInt();            //��������
//		DPS = root["Sniper"]["Dps"].asInt();                       //�˺�
//		CostMine = root["Sniper"]["CostMime"].asInt();                  //���ѵĿ�
//		CostElec = root["Sniper"]["CostElec"].asInt();                 //���ѵĵ�
//		Costime = root["Sniper"]["Costime"].asInt();                  //���ѵ�ʱ��
//	}
//}