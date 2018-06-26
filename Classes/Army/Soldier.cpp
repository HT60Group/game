#include "Soldier.h"
//#include "json/json.h"

bool Soldier::init()
{
	return true;
}
void Soldier::showUI() {
	log("init");
	//Hp = 1;
	//totalHp = 1;
	//DPS = 1;
	readJson();
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("hpBar_1.ExportJson");
	this->addChild(UI);
	Size size = this->getContentSize();
	UI->setPosition(Point(size.width*0.4f, size.height*0.9f));

	hpBar = (LoadingBar*)Helper::seekWidgetByName(UI, "HpBar");
	hpBar->setPercent(100);
	totalHp = Hp;
}
void Soldier::readJson()
{
	Hp = 45;
	MovingSpeed = 2.25;               //�ƶ��ٶ�
	AttackDistance = 5;            //��������
	DPS = 6;                       //�˺�
	CostMine = 50;                  //���ѵĿ�
	CostElec = 0;                 //���ѵĵ�
	Costime =25;                  //���ѵ�ʱ��
	log("Hp=%d\nAttackDistance=%d\nCostMine=%d", Hp, AttackDistance, CostMine);
}