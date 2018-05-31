#ifndef _Building_H_#define _Building_H_#include "Entity/Entity.h"
class Building :public Entity
{
public:
	CREATE_FUNC(Building);
	virtual bool init();
	void run();
protected:
	double PositionX;        //x坐标
	double PositionY;        //y坐标
	int Blood;               //血量
	double sizeX;            //大小——长
	double sizeY;            //大小——宽
};
#endif