#ifndef _Mine_H_
#define _Mine_H_

#include"Entity/Entity.h"

using namespace cocos2d;

//矿
class Mine :public Entity
{
public:
	virtual bool init();
	int getMine();
	void addMine(int num);
	void decMine(int num);

protected:
	int MineNumber;      //矿的数量
};

//返回矿的数量
int Mine::getMine()
{
	return MineNumber;
}

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
