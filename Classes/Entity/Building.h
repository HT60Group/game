#ifndef _Building_H_
#define _Building_H_

#include"cocos2d.h"
#include "Entity/Entity.h"
//#include "json/json.h"
//#include "AIManager/AIManager.h"
#include"cocos-ext.h"
#include"ui/cocosGUI.h"
#include"editor-support/cocostudio/CCSGUIReader.h"

USING_NS_CC_EXT;
using namespace cocos2d::extension;
using namespace cocos2d::ui;
using namespace cocostudio;
using namespace cocos2d;


class Building :public Entity
{
public:
	Building();
	~Building();
	CREATE_FUNC(Building);
	virtual bool init();
	virtual void showUI();
	////读取配置文件
	//virtual void readJson();

	//建造
	static Building* createWithSpriteFrameName(Building* sprite, const char *filename);

	bool isClickMe(Point pos);

	virtual void hurt(int x);
	virtual bool isDeath();

	bool isBroken;             // 是否被摧毁
	Sprite* normal;            // 正常图片
protected:
	int Hp;                  //血量
	int totalHp;               // 总生命值
	double sizeX;            //大小——长
	double sizeY;            //大小——宽
	int Costime;             //建筑花费的时间
	int CostMine;            //建造花费的矿
	int CostElec;            //建造花费的电

	int index;                 // 内存中的数组下标
	int id;                    // 编号
	int BuildingID;            // 建筑编号ID
	//virtual void ondied() override;
	//virtual void onHurt(int iHurtValue) override;
	LoadingBar* hpBar;         // 血条
	Entity* target;
};

#endif