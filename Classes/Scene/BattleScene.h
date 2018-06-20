#ifndef _BattleScene_H_
#define _BattleScene_H_
#include "cocos2d.h"
#include "AIManager/BuildingManager.h"
using namespace cocos2d;

class BattleScene :public Layer {
public:
	BattleScene();
	~BattleScene();

	CREATE_FUNC(BattleScene);
	virtual bool init();
	void logic(float dt);
private:
	void loadConfig();
protected:
	BuildingManager* m_BuildingMgr;
	/*AIManager* m_AIMgr;*/
};
#endif