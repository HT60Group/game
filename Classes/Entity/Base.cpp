#include "Base.h"


Base::Base() {
	Hp = 1000;
	log("BaseHp=1000\n\n");
	totalHp = 1000;
}
Base::~Base(){}

bool Base::init()
{
	//readJson();

	return true;
}
void Base::showUI() {
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("hpBar_1.ExportJson");
	this->addChild(UI);
	Size size = this->getContentSize();
	UI->setPosition(Point(size.width*0.4f, size.height*0.9f));

	hpBar = (LoadingBar*)Helper::seekWidgetByName(UI, "HpBar");
	hpBar->setPercent(100);
	totalHp = Hp;
}
//
//void Base::readJson()
//{
//	Json::Reader reader;
//	Json::Value root;
//
//	std::string data = FileUtils::getInstance()->getStringFromFile("StarCC.json");
//
//	if (reader.parse(data, root, false) == true)
//	{
//		Hp = root["Base"]["Hp"].asInt();
//		Costime = root["Base"]["Costime"].asInt();
//		CostMine = root["Base"]["CostMine"].asInt();
//		CostElec = root["Base"]["CostElec"].asInt();
//	}
//}
//
//void Base::CreateScv()             //产生Scv
//{
//	Scv* scv = new Scv();
//	Army::create(scv, "Scv.png");     //此处需要图片——大兵图片
//
//	this->addChild(scv);
//
//	scv->setPosition(Point(0, 0));            //setPosition
//}