#include "Dog.h"

Dog::Dog() {
	Hp = 35;
	MovingSpeed = 3.2;               //�ƶ��ٶ�
	AttackDistance = 2;            //��������
	DPS = 8;                       //�˺�
	CostMine = 45;                  //���ѵĿ�
	CostElec = 0;                 //���ѵĵ�
	Costime = 25;                  //���ѵ�ʱ��
}
Dog::~Dog()
{

}
bool Dog::init()
{
	return true;
}
void Dog::showUI() {
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("hpBar_1.ExportJson");
	this->addChild(UI);
	Size size = this->getContentSize();
	UI->setPosition(Point(size.width*0.4f, size.height*0.9f));

	hpBar = (LoadingBar*)Helper::seekWidgetByName(UI, "HpBar");
	hpBar->setPercent(100);
	totalHp = Hp;
}
//void Dog::readJson()
//{
//	Json::Reader reader;
//	Json::Value root;
//
//	std::string data = FileUtils::getInstance()->getStringFromFile("StarCC.json");
//
//	if (reader.parse(data, root, false) == true)
//	{
//		Hp = root["Dog"]["Hp"].asInt();
//		MovingSpeed = root["Dog"]["Speed"].asDouble();               //�ƶ��ٶ�
//		AttackDistance = root["Dog"]["Range"].asInt();            //��������
//		DPS = root["Dog"]["Dps"].asInt();                       //�˺�
//		CostMine = root["Dog"]["CostMime"].asInt();                  //���ѵĿ�
//		CostElec = root["Dog"]["CostElec"].asInt();                 //���ѵĵ�
//		Costime = root["Dog"]["Costime"].asInt();                  //���ѵ�ʱ��
//	}
//}