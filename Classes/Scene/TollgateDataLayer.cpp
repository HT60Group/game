#include "Scene/TollgateDataLayer.h"

TollgateDataLayer::TollgateDataLayer() {
	m_iGold = 100;
	m_iElec = 0;
	m_iPop = 0;
	BarrackCostMine = 150;
	ProducerCostMine = 100;
	StopeCostMine = 100;
	WarFactoryCostMine = 150;
	WarFactoryCostElec = 100;
	SoldierCostMine = 50;
	DogCostMine = 45;
	SniperCostMine = 200;
	SniperCostElec = 100;
	TankCostMine = 150;
	TankCostElec = 150;
	addm_iGold = 0;
	addm_iElect = 0;
}
TollgateDataLayer::~TollgateDataLayer() {
	NotificationCenter::getInstance()->removeAllObservers(this);
}
bool TollgateDataLayer::init() {
	if (!Layer::init()) {
		return false;
	}

	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("TollgateUI/TollgateUI_1.ExportJson");
	this->addChild(UI);
	UI->setTouchEnabled(false);

	m_GoldLab = (Text*)Helper::seekWidgetByName(UI, "GoldNumLab");
	m_ElecLab = (Text*)Helper::seekWidgetByName(UI, "ElecNumLab");
	m_PopLab = (Text*)Helper::seekWidgetByName(UI, "PopNumLab");


	m_GoldLab->setText(StringUtils::toString(m_iGold));
	this->schedule(schedule_selector(TollgateDataLayer::Refresh),1.0f);//每帧调用函数

	return true;
}
void TollgateDataLayer::Refresh(float dt)
{
	
	    m_iGold += addm_iGold;
		m_iElec += addm_iElect;

	m_GoldLab->setText(StringUtils::toString(m_iGold));
	m_ElecLab->setText(StringUtils::toString(m_iElec));
}
int TollgateDataLayer::m_iGold;
int TollgateDataLayer::m_iElec;
int TollgateDataLayer::m_iPop;
int TollgateDataLayer::BarrackCostMine;
int TollgateDataLayer::ProducerCostMine;
int TollgateDataLayer::StopeCostMine;
int TollgateDataLayer::WarFactoryCostMine;
int TollgateDataLayer::WarFactoryCostElec;

int TollgateDataLayer::SoldierCostMine;
int TollgateDataLayer::DogCostMine;
int TollgateDataLayer::SniperCostMine;
int TollgateDataLayer::SniperCostElec;
int TollgateDataLayer::TankCostMine;
int TollgateDataLayer::TankCostElec;
int TollgateDataLayer::addm_iGold;
int TollgateDataLayer::addm_iElect;