#ifndef _BuildingTFSM_H_
#define _BuildingTFSM_H_

#include "cocos2d.h"
#include "Entity/Building.h"
using namespace cocos2d;

class BuildingTFSM :public Node
{
public:
	~BuildingTFSM();
	static BuildingTFSM* createWithBuilding(Building* kkk);
	
private:

};
#endif
