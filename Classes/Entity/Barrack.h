#ifndef _Barrack_H_
#define _Barrack_H_

#include "Building.h"

//±øÓª
class Barrack :public Building
{
public:
	CREATE_FUNC(Barrack);
	virtual bool init();

protected:
	void CreateSoldiers();             //²úÉúsoldiers
};
#endif