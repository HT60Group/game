#include "Entity.h"
void Entity::bindSprite(Sprite* sprite)
{
	m_sprite = sprite;    //°ó¶¨sprite
	this->addChild(m_sprite);
}