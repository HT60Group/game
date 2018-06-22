#include "Building.h"
#include "Scene\MapLayer.h"

Building::Building(){}
Building::~Building() {}
bool Building::init()
{
	//readJson();
	showUI();
	return true;
}
void Building::showUI() {
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("HpBar/hpBar_1.ExportJson");
	this->addChild(UI);
	Size size = this->getContentSize();
	UI->setPosition(Point(size.width*0.5f, size.height));

	hpBar = (LoadingBar*)Helper::seekWidgetByName(UI, "HpBar");
	hpBar->setPercent(100);
	totalHp = Hp;
}
//void Building::readJson()
//{
//	Json::Reader reader;
//	Json::Value root;
//	
//	totalHp = Hp;
//	std::string data = FileUtils::getInstance()->getStringFromFile("StarCC.json");
//}


Building* Building::createWithSpriteFrameName(Building* sprite, const char *filename)
{
	if (sprite &&sprite->initWithFile(filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

bool Building::isDeath()
{
	return isBroken;
}

void Building::hurt(int x)
{
	if (Hp <= 0 || isBroken == true) {
		isBroken = true;
		return;
	}

	Hp -= x;
	if (Hp <= 0) {

		this->isBroken = true;

		auto bg = (Sprite*)this->getChildByName("Bar");
		bg->removeFromParent();
		normal->setVisible(false);

	// 基地爆炸,游戏结束
	//	auto layer = (BattleMapLayer*)this->getParent();
	//	layer->_ai->gameOver(GAME_OVER_SUCCESS);
	}
	else {
		//血条变化
		//hpBar->setPercent(100.0 * Hp / totalHP);
	}
}

Point Building::getScenePosition()
{
	auto tmap = MapLayer::map;
	auto _currentPos = tmap->getPosition();//地图的绝对坐标
	Point tpos = this->getPosition();
	tpos += _currentPos;
	return tpos;
}