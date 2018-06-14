#ifndef _BuildingManager_H_
#define _BuildingManager_H_

#include "cocos2d.h"

#include "Entity/Entity.h"
#include "Entity/Building.h"
#include "Entity/Base.h"
#include "Entity/Barrack.h"
#include "Entity/Producer.h"
#include "Entity/Stope.h"
#include "Entity/WarFactory.h"
#include "ManagerBase.h"
#include <typeinfo>

#define SPEED 1
using namespace cocos2d;

class BuildingManager :public ManagerBase
{
public:
	BuildingManager();
	~BuildingManager();
	virtual bool init();

	CREATE_FUNC(BuildingManager);

	void gameOver(int state);

	static BuildingManager* createBuildingMgr();

protected:
	Vector<Building*> m_BuildingList;
	void createBase(Point tpos);
	void createBarrack(Point tpos);
	void createProducer(Point tpos);
	void createStope(Point tpos);
	void createWarFactory(Point tpos);

	std::vector<std::vector<int>> _collidable;
	Building* findClickBuilding(Point pos);
};
#endif