#ifndef _Entity_H_
#define _Entity_H_#include"cocos2d.h"
using namespace cocos2d;class Entity :public Node {public:
	//°ó¶¨sprite
	void bindSprite(Sprite* sprite);protected:
	Sprite* m_sprite;  }
#endif