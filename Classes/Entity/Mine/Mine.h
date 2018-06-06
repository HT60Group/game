#ifndef _Mine_H_
#define _Mine_H_

#include"Entity/Entity.h"

using namespace cocos2d;

//��
class Mine :public Entity
{
public:
	virtual bool init();
	int getMine();
	void addMine(int num);
	void decMine(int num);

protected:
	int MineNumber;      //�������
};

//���ؿ������
int Mine::getMine()
{
	return MineNumber;
}

//���ӿ������
void Mine::addMine(int num)
{
	MineNumber += num;
}

//���ٿ������
void Mine::decMine(int num)
{
	MineNumber -= num;
}
#endif
