#include "Building.h"

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


Building* Building::create(Building* sprite, const char *filename)
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

bool Building::isClickMe(Point pos) {
	Size size = getSprite()->getContentSize();
	Point borderPos = getPosition();

	Point srcPos = Point(borderPos.x - size.width / 2, borderPos.y + size.height / 2);
	Point destPos = Point(borderPos.x + size.width / 2, borderPos.y - size.height / 2);

	if (pos.x >= srcPos.x && pos.x <= destPos.x &&pos.y <= srcPos.y &&pos.y >= destPos.y) {
		return true;
	}
	return false;
}
 