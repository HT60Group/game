#ifndef _Entity_H_
#define _Entity_H_

#include"cocos2d.h"
#include "json/json.h"

using namespace cocos2d;
class Entity :public Node {
public:
	//绑定sprite
	void bindSprite(Sprite* sprite);
	virtual bool init();
	CREATE_FUNC(Entity);

	//读取配置文件
	virtual void readJson();
protected:
	Sprite* m_sprite;  

};
#endif