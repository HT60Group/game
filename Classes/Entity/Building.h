#ifndef _Building_H_
#define _Building_H_

#include"cocos2d.h"
#include "json/json.h"

using namespace cocos2d;
enum EnumState {
	enAlive,            //存活状态
	enCreate,           //建造状态————不一定要有
	enCreateSoldiers,   //造兵状态
};
class Building :public Sprite
{
public:
	CREATE_FUNC(Building);
	virtual bool init();

	EnumState enCurState;       //当前状态

	bool isAlive();             //判断是否存活
	bool isCreateSoldiers();    //判断是否能够造兵

	void changeState(EnumState enState);   //切换状态

	virtual void update(float dt);

	//接收消息的回调函数
	virtual void getMsg(float dt);
	//发送消息
	virtual void sendMsg(float dt);

	//读取配置文件
	virtual void readJson();

	static Building* create(Building* sprite, const char *filename);


protected:
	int Hp;                  //血量
	double sizeX;            //大小——长
	double sizeY;            //大小——宽
	int Costime;             //建筑花费的时间
	int CostMine;            //建造花费的矿
	int CostElec;            //建造花费的电
};

#endif