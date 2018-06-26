#include "Barrack.h"
#include "json/json.h"

bool Barrack::init()
{
	readJson();

	return true;
}
void Barrack::showUI() {
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("hpBar_1.ExportJson");
	this->addChild(UI);
	Size size = this->getContentSize();
	UI->setPosition(Point(size.width*0.4f, size.height*0.9f));

	hpBar = (LoadingBar*)Helper::seekWidgetByName(UI, "HpBar");
	hpBar->setPercent(100);
	totalHp = Hp;
}

void Barrack::readJson()
{
	Json::Reader reader;
	Json::Value root;

	std::string data = FileUtils::getInstance()->getStringFromFile("StarCC.json");

	if (reader.parse(data, root, false) == true)
	{
		Hp = root["Barrack"]["Hp"].asInt();
		Costime = root["Barrack"]["Costime"].asInt();
		CostMine = root["Barrack"]["CostMine"].asInt();
		CostElec = root["Barrack"]["CostElec"].asInt();
	}
}
