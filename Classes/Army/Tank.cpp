#include "Tank.h"
Tank::Tank() {
	Hp = 150;
	MovingSpeed = 2.25;               //�ƶ��ٶ�
	AttackDistance = 7;            //��������
	DPS = 25;                       //�˺�
	CostMine = 150;                  //���ѵĿ�
	CostElec = 150;                 //���ѵĵ�
	Costime = 4;                  //���ѵ�ʱ��
	kind = 2;
}
Tank::~Tank() {

}

bool Tank::init()
{
	return true;
}

void Tank::showUI() {
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("hpBar_1.ExportJson");
	this->addChild(UI);
	Size size = this->getContentSize();
	UI->setPosition(Point(size.width*0.4f, size.height*0.9f));

	hpBar = (LoadingBar*)Helper::seekWidgetByName(UI, "HpBar");
	hpBar->setPercent(100);
	totalHp = Hp;
}

//void Tank::readJson()
//{
//	Json::Reader reader;
//	Json::Value root;
//
//	std::string data = FileUtils::getInstance()->getStringFromFile("StarCC.json");
//
//	if (reader.parse(data, root, false) == true)
//	{
//		Hp = root["Tank"]["Hp"].asInt();
//		MovingSpeed = root["Tank"]["Speed"].asDouble();               //�ƶ��ٶ�
//		AttackDistance = root["Tank"]["Range"].asInt();            //��������
//		DPS = root["Tank"]["Dps"].asInt();                       //�˺�
//		CostMine = root["Tank"]["CostMime"].asInt();                  //���ѵĿ�
//		CostElec = root["Tank"]["CostElec"].asInt();                 //���ѵĵ�
//		Costime = root["Tank"]["Costime"].asInt();                  //���ѵ�ʱ��
//	}
//}