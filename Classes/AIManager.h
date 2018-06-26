#pragma once
#include"cocos2d.h"
#include<vector>
#include"Army/Army.h"
using namespace cocos2d;
class AIManager :public cocos2d::Layer
{
public:
	CREATE_FUNC(AIManager);
	virtual bool init();
	void selectionController();
	void moveController();

	static std::vector<Army*> m_armyVec;
	static std::vector<Army*> m_enemyArmyVec;
	static std::vector<Army*> s_armyVec;
	static void move(Army* army,Point endPos);
	static void move(Army* army);
	/*LayerColor* layer;*/
private:
	Point mousePos_began = cocos2d::Point(0,0);
	Point mousePos_moved = cocos2d::Point(0, 0);
	Point mousePos_ended = cocos2d::Point(0, 0);
	LayerColor* selection;
	static std::vector<Army*> army_selected;
	
};