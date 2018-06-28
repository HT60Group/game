#include "Barrack.h"

Barrack::Barrack() {
	Hp = 1000;
	CostMine = 150;                  //花费的矿
	CostElec = 0;                 //花费的电
	Costime = 6;                  //花费的时间
}
Barrack::~Barrack() {

}
bool Barrack::init()
{

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
