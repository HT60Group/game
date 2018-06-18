#include "Scene/TollgateDataLayer.h"

TollgateDataLayer::TollgateDataLayer() {
	m_iGold = 0;
	m_iElec = 0;
	m_iPop = 0;
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

	NotificationCenter::getInstance()->addObserver(this,
		callfuncO_selector(TollgateDataLayer::recvRefreshGoldNum),
		"GoldNumChange",
		NULL);
	NotificationCenter::getInstance()->addObserver(this,
		callfuncO_selector(TollgateDataLayer::recvRefreshElecNum),
		"ElecNumChange",
		NULL);
	NotificationCenter::getInstance()->addObserver(this,
		callfuncO_selector(TollgateDataLayer::recvRefreshPopNum),
		"PopNumChange",
		NULL);
	return true;
}
void TollgateDataLayer::recvRefreshGoldNum(Ref* pData) {
	int iAltValue = (int)pData;
	m_iGold += iAltValue;
	m_GoldLab->setText(StringUtils::toString(m_iGold));
}
void TollgateDataLayer::recvRefreshElecNum(Ref* pData) {
	int iAltValue = (int)pData;
	m_iElec += iAltValue;
	m_ElecLab->setText(StringUtils::toString(m_iElec));
}
void TollgateDataLayer::recvRefreshPopNum(Ref* pData) {
	int iAltValue = (int)pData;
	m_iPop += iAltValue;
	m_PopLab->setText(StringUtils::toString(m_iPop));
}