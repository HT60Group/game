#include "Producer.h"

Producer::Producer() {
	Hp = 500;
	CostMine = 125;                  //���ѵĿ�
	CostElec = 0;                 //���ѵĵ�
	Costime = 3;                  //���ѵ�ʱ��
}
Producer::~Producer()
{

}
bool Producer::init()
{
	//readJson();
	
	//create Producer
	//Producer* producer = new Producer();
	//Building::create(producer, "Producer.png");     //�˴���ҪͼƬ����ͼƬ

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
