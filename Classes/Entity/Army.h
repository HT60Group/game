#ifndef _Player_H_
#define _Player_H_

#include"cocos2d.h"
#include "Entity/Entity.h"
//#include "json/json.h"
//#include "ArmyTFSM.h"
//#include "AIManager/AIManager.h"
#include"cocos-ext.h"
#include"ui/cocosGUI.h"
#include"editor-support/cocostudio/CCSGUIReader.h"
#include <math.h>
USING_NS_CC_EXT;
using namespace cocos2d::extension;
using namespace cocos2d::ui;
using namespace cocostudio;
using namespace cocos2d;

class Army : public Entity
{
public:
	Army();
	~Army();
	CREATE_FUNC(Army);
	virtual bool init();
	virtual void showUI();

	Point getScenePosition();
	static Army* createWithSpriteFrameName(Army* sprite,const char *filename);
	//void moveByPosList(Vector<Point*> posList);

	//virtual void move();
	//virtual void atk();
	//virtual void hurt(int x);
	//virtual bool isDeath();  

	//void update(float dt);


	//读取配置文件
	//virtual void readJson();
	bool isbroken;

	//void checkAtkEntity(float ft, Vector<Entity*> EntityList);
	//void checkAimIsOutOfRange(Vector<Entity*> EntityList);
	//void chooseAim();
	//bool isInAtkRange(Point pos);
	//void chooseAtkEntity(Entity* entity);
	//void atkCoolDownEnd(float dt);
	//void missAtkEntity();
protected:
	Point nowPoint;                //相对于屏幕坐标
	Vector<Entity*> EntityList;
	Entity* m_atkEntity;
	bool m_isAtkCoolDown;
	int Hp;                  //血量
	int totalHp;               // 总生命值
	double MovingSpeed;               //移动速度
    int AttackDistance;            //攻击距离
	int DPS;                       //伤害
	int attackSpeed;
	int CostMine;                  //花费的矿
	int CostElec;                 //花费的电
	int ViewDistance;              //视野
	int Costime;                  //花费的时间
	int Belong;
	LoadingBar* hpBar;         // 血条
	Entity* target;
};
#endif