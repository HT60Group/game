#ifndef _Tank_H_
#define _Tank_H_

#include "Army.h"

using namespace cocos2d;
class Tank :public Army
{
public:
	CREATE_FUNC(Tank);
	virtual bool init();
	virtual void showUI();

	//��ȡ�����ļ�
	//virtual void readJson();
};
#endif