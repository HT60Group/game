#ifndef _Soilder_H_
#define _Soilder_H_

#include "Army.h"

using namespace cocos2d;
class Soldier :public Army
{
public:
	Soldier();
	~Soldier();
	CREATE_FUNC(Soldier);
	virtual bool init();

	//��ȡ�����ļ�
	void readJson();
	virtual void showUI();
};
#endif