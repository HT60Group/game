#ifndef _MenuLayer_H_
#define _MenuLayer_H_
#include"MapScene.h"
#include "cocos2d.h"
#include"cocos-ext.h"
#include"ui/cocosGUI.h"
#include"editor-support/cocostudio/CCSGUIReader.h"
#include "ui/UIWidget.h"
#include"Entity/Building.h"
#include"Entity/Base.h"
#include"Entity/Barrack.h"
#include"Entity/Stope.h"
#include"Entity/WarFactory.h"
#include"Entity/Producer.h"
#define MAP_LAYEER_LVL 3
#define UI_LAYEER_LVL 10
#define BUILDING_LAYEER_LVL 15
#define ARMY_LAYEER_LVL 20
using namespace cocos2d;
USING_NS_CC_EXT;
using namespace cocos2d::extension;
using namespace cocos2d::ui;
using namespace cocostudio;

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

	void onTouchMoved(Touch* touch, Event* event);
	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
	std::string message;
};
#endif