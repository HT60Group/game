#ifndef _Entity_H_
#define _Entity_H_

#include"cocos2d.h"
#include "json/json.h"

using namespace cocos2d;
class Entity :public Node {
public:
	//��sprite
	void bindSprite(Sprite* sprite);
	virtual bool init();
	CREATE_FUNC(Entity);

	//��ȡ�����ļ�
	virtual void readJson();
protected:
	Sprite* m_sprite;  

};
#endif