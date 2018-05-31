#ifndef _WarFactory_H_
#define _WarFactory_H_

#include "Building.h"

//战车工厂
class WarFactory :public Building
{
public:
	CREATE_FUNC(WarFactory);
	virtual bool init();

protected:
	void CreateTanks();             //产生Tanks
};
#endif