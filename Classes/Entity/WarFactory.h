#ifndef _WarFactory_H_
#define _WarFactory_H_

#include "Building.h"
#include "Army/Tank.h"
//ս������
class WarFactory :public Building
{
public:
	CREATE_FUNC(WarFactory);
	virtual bool init();

	virtual void readJson();

protected:
	void CreateTank();             //����Tanks
};

#endif