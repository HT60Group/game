#ifndef _Barrack_H_
#define _Barrack_H_

#include "Building.h"
//#include "Army/Soldier.h"
//#include "Army/Sniper.h"
//#include "Army/Dog.h"
//��Ӫ
class Barrack :public Building
{
public:
	CREATE_FUNC(Barrack);
	virtual bool init();
	virtual void showUI();
	void readJson();

protected:
	void CreateSoldier();             //����soldiers
	void CreateSniper();              //Sniper
	void CreateDog();                 //dog
};

#endif