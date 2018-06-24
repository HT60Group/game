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

	//virtual void hurt(int x);
	//virtual void idle();
	//virtual bool isDied();

	//得到建筑相对地图坐标
	Point getScenePosition();
	//被攻击
	void hurtMe(int iHurtValue);
	void onDied();

	void is_Enemy();
	int _numInVec;             //在vec中的位置

	Vec2 pos;
	bool Belonging;             //true表示是自己的
protected:
	Sprite* m_sprite;  

	int Hp;
	int totalHp;
	bool m_isDied;
	int Costime;             //建筑花费的时间
	int CostMine;            //建造花费的矿
	int CostElec;            //建造花费的电
	bool isDied();

};
#endif