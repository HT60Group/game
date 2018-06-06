#ifndef _Electricity_H_
#define _Electricity_H_

#include"Entity/Entity.h"

using namespace cocos2d;

//电
class Electricity :public Entity
{
public:
	CREATE_FUNC(Electricity);
	virtual bool init();
	void addElectricity(int num);     //增加电的数量
	void decElectricity(int num);     //减少电的数量

protected:
	int ElectricityNumber;      //电的数量
};

//增加电的数量
void Electricity::addElectricity(int num)
{
	ElectricityNumber += num;
}

//减少电的数量
void Electricity::decElectricity(int num)
{
	ElectricityNumber -= num;
}
#endif