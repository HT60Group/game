#ifndef _WarFactory_H_
#define _WarFactory_H_

#include "Building.h"

//ս������
class WarFactory :public Building
{
public:
	CREATE_FUNC(WarFactory);
	virtual bool init();

protected:
	void CreateTanks();             //����Tanks
};
#endif