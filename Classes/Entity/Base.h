#ifndef _Base_H_
#define _Base_H_

#include "Building.h"

class Base :public Building
{
public :
	CREATE_FUNC(Base);
	virtual bool init();

protected:
	void CreateScvs();             //²úÉúscv
};
#endif