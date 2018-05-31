#ifndef _Mine_H_
#define _Mine_H_

#include"Entity/Entity.h"

using namespace cocos2d;

//��
class Mine :public Entity
{
public:
	CREATE_FUNC(Mine);
	virtual bool init();
	void addMine(int num);
	void decMine(int num);

protected:
	int MineNumber;      //�������
};

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
