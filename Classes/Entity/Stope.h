#ifndef _Stope_H_
#define _Stope_H_

#include "Building.h"

//�ɿ�
class Stope :public Building
{
public:
	CREATE_FUNC(Stope);
	virtual bool init();

protected:
	void CreateMine();             //������
};
#endif