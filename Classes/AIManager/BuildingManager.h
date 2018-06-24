#include "cocos2d.h"
#include <typeinfo>
#include "ManagerBase.h"

#define SPEED 1
using namespace cocos2d;
class MenuLayer;
class Building;
class BuildingManager :public ManagerBase
{
public:
	BuildingManager();
	~BuildingManager();
	virtual bool init();

	CREATE_FUNC(BuildingManager);

	void gameOver(int state);
	

	//��ͬ�����ĵ���¼�
	void SetBaseController(Building*);
	void SetBarrackController(Building*);
	void SetWarFactoryController(Building*);

	cocos2d::TMXTiledMap* GetMap();
    MenuLayer* GetMenuLayer();

	static BuildingManager* createBuildingMgr();
	//�����б�
	static std::vector<Building*> m_buildingVec;
	static std::vector<Building*> m_enemyBuildingVec;

	void DestoryBuilding(Building* building);
protected:

	std::vector<std::vector<int>> _collidable;
};