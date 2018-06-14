#ifndef _Entity_H_
#define _Entity_H_

#include"cocos2d.h"
//#include "json/json.h"

using namespace cocos2d;
class Entity :public Sprite
{
public:
	Entity();
	~Entity();

	virtual bool init();
	CREATE_FUNC(Entity);
	////读取配置文件
	//virtual void readJson();

	virtual void atk();
	virtual void run();
	virtual void hurt(int x);
	virtual void idle();
	virtual bool isDied();
	//被攻击
	void hurtMe(int iHurtValue);
	Sprite* getSprite();
	
	Vec2 pos;
protected:
	Sprite* m_sprite;  
	virtual void onDied();
	virtual void onHurt(int iHurtValue);

	CC_SYNTHESIZE(int, m_ID, ID);
	CC_SYNTHESIZE(int, m_iModelID, iModelID);
	CC_SYNTHESIZE(std::string, m_sName, sName);
	CC_SYNTHESIZE(int, m_iHP, iHP);
	CC_SYNTHESIZE(int, m_iSpeed, iSpeed);
	bool m_isDied;

};
#endif