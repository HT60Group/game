#include "Entity.h"
void Entity::bindSprite(Sprite* sprite)
{
	m_sprite = sprite;    //��sprite
	this->addChild(m_sprite);
}