
#include "BattleScene.h"

BattleScene::BattleScene() {
}
BattleScene::~BattleScene() {}

bool BattleScene::init() {
	if (!Layer::init()) { return false; }
	bool bRet = false;

	loadConfig();

	m_BuildingMgr = BuildingManager::create();
	this->addChild(m_BuildingMgr, 1);

	/*m_AIMgr = AIManager::createAIManager();*/
	/*this->addChild(m_AIMgr, 3);
*/
	return true;
}


void BattleScene::loadConfig() {
	Size visibleSize = Director::getInstance()->getVisibleSize();

	////Ìí¼ÓÒôÀÖ
	//CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(
	//	StringUtils::format("music.mp3").c_str(), true);

	Sprite* map = Sprite::create("");
	map->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(map, 1);
}