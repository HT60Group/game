#ifndef _ManagerBase_H_
#define _ManagerBase_H_

#include "cocos2d.h"
#include "Entity/Entity.h"
//#include "Army/Army.h"
#include "Entity/Building.h"
#define SPEED 1
using namespace cocos2d;

class ManagerBase :public Node
{
public:
	ManagerBase();
	~ManagerBase();
	virtual bool init();
	CREATE_FUNC(ManagerBase);



	void gameOver(int state);

	//Vector<Army*> Armys;
	Vector<Building*> buildings;


	CC_SYNTHESIZE(int, m_iSpeed, iSpeed);
protected:
	Entity* m_entity;
	bool m_isMoving;
	bool m_isXLeft;
	bool m_isYUp;
	int m_iCheckMoveSpeed;
	Point getNextPos(Point curPos, Point destPos);
};
#endif