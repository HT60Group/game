#include "Entity.h"

Entity::Entity()
{
	m_sprite = NULL;
	m_sName = "";
	m_iHP = 1;
	m_isDied = false;
	m_iSpeed = 1;
}
Entity::~Entity() {
}
Sprite* Entity::getSprite() {
	return this->m_sprite;
}

void Entity::hurtMe(int iHurtValue) {
	if (m_isDied) {
		return;
	}

	int iCurHP = getiHP();
	int iAfterHP = iCurHP - iHurtValue;

	onHurt(iHurtValue);
	if (iAfterHP > 0) {
		setiHP(iAfterHP);
	}
	else {
		m_isDied = true;
		onDied();
	}
}
bool Entity::isDied() {
	return this->m_isDied;
}

void Entity::onDied() {
}
void Entity::onHurt(int iHurtValue){}

bool Entity::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	//readJson();
	return true;
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

void Entity::atk() { CCLOG("Base atk"); }
void Entity::run() { CCLOG("Base run"); }
void Entity::hurt(int x) { CCLOG("Base hurt"); }
void Entity::idle() { CCLOG("Base idle"); }
//bool Entity::isDied() { CCLOG("Base isDied"); return false; }