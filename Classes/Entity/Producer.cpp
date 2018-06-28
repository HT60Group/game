#include "Producer.h"

Producer::Producer() {
	Hp = 500;
	CostMine = 125;                  //花费的矿
	CostElec = 0;                 //花费的电
	Costime = 3;                  //花费的时间
}
Producer::~Producer()
{

}
bool Producer::init()
{
	//readJson();
	
	//create Producer
	//Producer* producer = new Producer();
	//Building::create(producer, "Producer.png");     //此处需要图片——图片

	//this->addChild(producer);

	//producer->setPosition(Point(0, 0));            //setPosition
	return true;
}
void Producer::showUI(){
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("hpBar_1.ExportJson");
	this->addChild(UI);
	Size size = this->getContentSize();
	UI->setPosition(Point(size.width*0.4f, size.height));

	hpBar = (LoadingBar*)Helper::seekWidgetByName(UI, "HpBar");
	hpBar->setPercent(100);
	totalHp = Hp;
}
//
//void Producer::readJson()
//{
//	Json::Reader reader;
//	Json::Value root;
//
//	std::string data = FileUtils::getInstance()->getStringFromFile("StarCC.json");
//
//	if (reader.parse(data, root, false) == true)
//	{
//		Hp = root["Producer"]["Hp"].asInt();
//		Costime = root["Producer"]["Costime"].asInt();
//		CostMine = root["Producer"]["CostMine"].asInt();
//		CostElec = root["Producer"]["CostElec"].asInt();
//	}
//}
