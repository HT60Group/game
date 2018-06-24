#include "Entity.h"
#include "Scene\MapLayer.h"

Entity::Entity()
{
}
Entity::~Entity() {
}

void Entity::hurtMe(int iHurtValue) {
	if (m_isDied) {
		return;
	}

	int iAfterHp= Hp - iHurtValue;

	if (iAfterHp > 0) {
		Hp=iAfterHp;
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
	Belonging = true;
	m_isDied = false;
	_numInVec = 0;
	Hp = 1;
	totalHp = 1;
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
	Point tpos = this->getPosition();
	tpos += _currentPos;
	return tpos;
}
//bool Entity::isDied() { CCLOG("Base isDied"); return false; }