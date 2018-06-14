#ifndef _Base_H_
#define _Base_H_

#include "Building.h"
//#include "Army/Scv.h"
class Base:public Building
{
public :
	Base();
	~Base();
	CREATE_FUNC(Base);
	virtual bool init();
	
	//virtual void readJson();
//protected:
	//void CreateScv();             //²úÉúscv
};

#endif