#ifndef _Dog_H_
#define _Dog_H_

#include "Army.h"

using namespace cocos2d;
class Dog :public Army
{
public:
	CREATE_FUNC(Dog);
	virtual bool init();
	virtual void showUI();

	////��ȡ�����ļ�
	//virtual void readJson();

};

#endif