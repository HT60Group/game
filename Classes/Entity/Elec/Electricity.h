#ifndef _Electricity_H_
#define _Electricity_H_

#include"Entity/Entity.h"

using namespace cocos2d;

//��
class Electricity :public Entity
{
public:
	CREATE_FUNC(Electricity);
	virtual bool init();
	void addElectricity(int num);     //���ӵ������
	void decElectricity(int num);     //���ٵ������

protected:
	int ElectricityNumber;      //�������
};

//���ӵ������
void Electricity::addElectricity(int num)
{
	ElectricityNumber += num;
}

//���ٵ������
void Electricity::decElectricity(int num)
{
	ElectricityNumber -= num;
}
#endif