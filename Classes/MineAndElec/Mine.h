#ifndef _Mine_H_
#define _Mine_H_

#include"Entity/Entity.h"

using namespace cocos2d;

//矿
class Mine :public Entity
{
public:
	CREATE_FUNC(Mine);
	virtual bool init();
	void addMine(int num);
	void decMine(int num);

protected:
	int MineNumber;      //矿的数量
};

//增加矿的数量
void Mine::addMine(int num)
{
	MineNumber += num;
}

//减少矿的数量
void Mine::decMine(int num)
{
	MineNumber -= num;
}
#endif
