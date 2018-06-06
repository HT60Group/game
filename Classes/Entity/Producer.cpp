#include "Producer.h"

bool Producer::init()
{
	readJson();
	
	//create Producer
	Producer* producer = new Producer();
	Building::create(producer, "Producer.png");     //�˴���ҪͼƬ����ͼƬ

	this->addChild(producer);

	producer->setPosition(Point(0, 0));            //setPosition
	return true;
}

void Producer::readJson()
{
	Json::Reader reader;
	Json::Value root;

	std::string data = FileUtils::getInstance()->getStringFromFile("StarCC.json");

	if (reader.parse(data, root, false) == true)
	{
		Hp = root["Producer"]["Hp"].asInt();
		Costime = root["Producer"]["Costime"].asInt();
		CostMine = root["Producer"]["CostMine"].asInt();
		CostElec = root["Producer"]["CostElec"].asInt();
	}
}