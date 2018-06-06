#include "Entity.h"

void Entity::bindSprite(Sprite* sprite)
{
	Sprite* m_sprite = sprite;

    //°ó¶¨sprite
	this->addChild(m_sprite);

}

bool Entity::init()
{

	readJson();
	return true;
}

void Entity::readJson()
{
	Json::Reader reader;
	Json::Value root;

	std::string data = FileUtils::getInstance()->getStringFromFile("StarCC.json");

}