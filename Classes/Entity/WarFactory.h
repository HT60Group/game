#ifndef _WarFactory_H_
#define _WarFactory_H_

#include "Building.h"
#include "Army/Tank.h"
//战车工厂
class WarFactory :public Building
{
public:
	CREATE_FUNC(WarFactory);
	virtual bool init();

	virtual void readJson();

protected:
	void CreateTank();             //产生Tanks
};

#endif