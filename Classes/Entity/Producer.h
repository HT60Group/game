#ifndef _Producer_H_
#define _Producer_H_

#include "Building.h"

//�糧
class Producer :public Building
{
public:
	CREATE_FUNC(Producer);
	virtual bool init();

protected:
	void CreateElectricity();             //������
};
#endif