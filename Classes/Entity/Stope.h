#ifndef _Stope_H_
#define _Stope_H_

#include "Building.h"

//采矿厂
class Stope :public Building
{
public:
	CREATE_FUNC(Stope);
	virtual bool init();

	virtual void readJson();

protected:
	void CreateMine();             //产生矿
};

#endif