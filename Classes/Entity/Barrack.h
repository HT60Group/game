#ifndef _Barrack_H_
#define _Barrack_H_

#include "Building.h"

//��Ӫ
class Barrack :public Building
{
public:
	CREATE_FUNC(Barrack);
	virtual bool init();

protected:
	void CreateSoldiers();             //����soldiers
};
#endif