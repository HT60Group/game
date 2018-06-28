#include "Entity.h"
#include "Scene\MapLayer.h"

Entity::Entity()
{
	Belonging = true;
	m_isDied = false;
	log("m_isDied is false\n\n\n");
	_numInVec = 0;
	Hp = 1;
	totalHp = 1;
}
Entity::~Entity() {
}

void Entity::hurtMe(int iHurtValue) {
	if (m_isDied) {
		log("endHp:%d", Hp);
		return;
	}

	log("Hp=%d",Hp);
	int iAfterHp= Hp - iHurtValue;

	log("iAfterHp:%d", iAfterHp);
	if (iAfterHp > 0) {
		Hp=iAfterHp;
		hpBar->setPercent(100.0 * Hp / totalHp);
	}
	else {
		onDied();
	}
}

void Entity::onDied() {
    m_isDied=true;
	this->removeFromParent();
}

bool Entity::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	//readJson();
	return true;
}

void Entity::is_Enemy()
{
	Belonging = false;
}
//
//void Entity::readJson()
//{
//	Json::Reader reader;
//	Json::Value root;
//
//	std::string data = FileUtils::getInstance()->getStringFromFile("StarCC.json");
//
//}
Point Entity::getScenePosition()
{
	auto tmap = MapLayer::map;
	auto _currentPos = tmap->getPosition();//地图的绝对坐标
	if (this != nullptr)
	{
	    Point tpos = this->getPosition();
		tpos += _currentPos;
	    return tpos;
	}

}
int Entity::getHp() {
	return Hp;
}
bool Entity::getM_isDied()
{
	return m_isDied;
}
//bool Entity::isDied() { CCLOG("Base isDied"); return false; }