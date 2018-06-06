#ifndef __Player_H__
#define __Player_H__

#include"cocos2d.h"
#include "json/json.h"
using namespace cocos2d;

class Army : public Sprite
{
public:
	CREATE_FUNC(Army);
	virtual bool init();

	static Army* create(Army* sprite,const char *filename);

	//读取配置文件
	virtual void readJson();

protected:
	int Hp;                           //血量
    double MovingSpeed;               //移动速度
    int AttackDistance;            //攻击距离
	int DPS;                       //伤害
	int CostMine;                  //花费的矿
	int CostElec;                 //花费的电
	int ViewDistance;              //视野
	int Costime;                  //花费的时间
	int Belong;
};
#endif