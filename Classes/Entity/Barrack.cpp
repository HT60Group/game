#include "Barrack.h"

Barrack::Barrack() {
	Hp = 1000;
	CostMine = 150;                  //���ѵĿ�
	CostElec = 0;                 //���ѵĵ�
	Costime = 6;                  //���ѵ�ʱ��
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
