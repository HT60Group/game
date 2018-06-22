#ifndef _MenuLayer_H_
#define _MenuLayer_H_

#include"MapScene.h"
#include "cocos2d.h"
#include"cocos-ext.h"
#include"ui/cocosGUI.h"
#include"editor-support/cocostudio/CCSGUIReader.h"
#include "ui/UIWidget.h"

#define MAP_LAYEER_LVL 3
#define UI_LAYEER_LVL 10
#define BUILDING_LAYEER_LVL 15
#define ARMY_LAYEER_LVL 20

using namespace cocos2d;
USING_NS_CC_EXT;
using namespace cocos2d::extension;
using namespace cocos2d::ui;
using namespace cocostudio;
class BuildingManager;
class Building;
class MenuLayer :public Layer
{
public:
	CREATE_FUNC(MenuLayer);
	virtual bool init();
	LayerColor* menuLayer;
	void setMouseController();
	void Controller();
	void createBarrack(Point tpos);
	void createProducer(Point tpos);
	void createStope(Point tpos);
	void createWarFactory(Point tpos);
	void createBase(Point tpos);

	void createSoldier(Point tpos);
	void createScv(Point tpos);
	void createDog(Point tpos);
	void createSniper(Point tpos);
	void createTank(Point tpos);

	//void CreateBarrackLayer();
	void CreateBarrackLayer(Building* building);
	void CreateBaseLayer(Building* building);
	void CreateWarFactoryLayer(Building* building);

	void onTouchMoved(Touch* touch, Event* event);
	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
	std::string message;
	BuildingManager* buildingMgr;
	cocos2d::ui::Widget* UIMenu;
};
#endif