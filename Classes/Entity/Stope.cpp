#include "Stope.h"

Stope::Stope() {
	Hp = 600;
	CostMine = 100;                  //���ѵĿ�
	CostElec = 0;                 //���ѵĵ�
	Costime = 3;                  //���ѵ�ʱ��
}
Stope::~Stope()
{

}
bool Stope::init()
{

	//readJson();
	return true;
}
void Stope::showUI() {
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("hpBar_1.ExportJson");
	this->addChild(UI);
	Size size = this->getContentSize();
	UI->setPosition(Point(size.width*0.4f, size.height));

	hpBar = (LoadingBar*)Helper::seekWidgetByName(UI, "HpBar");
	hpBar->setPercent(100);
	totalHp = Hp;
}
//void Stope::readJson()
//{
//	Json::Reader reader;
//	Json::Value root;
//
//	std::string data = FileUtils::getInstance()->getStringFromFile("StarCC.json");
//
//	if (reader.parse(data, root, false) == true)
//	{
//		Hp = root["Stope"]["Hp"].asInt();
//		Costime = root["Stope"]["Costime"].asInt();
//		CostMine = root["Stope"]["CostMine"].asInt();
//		CostElec = root["Stope"]["CostElec"].asInt();
//	}
//}