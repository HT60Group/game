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

	//Point getScenePosition();
	static Army* createWithSpriteFrameName(Army* sprite,const char *filename);
	//void moveByPosList(Vector<Point*> posList);

	//virtual void move();

	void Attack(Entity* entity);
	void autoAttack(float dt);
	//virtual void hurt(int x);
	//virtual bool isDeath();  

	//void update(float dt);


	//��ȡ�����ļ�
	//virtual void readJson();

	bool isbroken;
	bool isInAtkRange(Entity* entity);
	Entity* chooseAtkEntity();

protected:
	Point nowPoint;                //�������Ļ����
	Vector<Entity*> EntityList;
	Entity* m_atkEntity;
	bool m_isAtkCoolDown;
	double MovingSpeed;               //�ƶ��ٶ�
    int AttackDistance;            //��������
	int DPS;                       //�˺�
	int attackSpeed;
	//int ViewDistance;              //��Ұ
	LoadingBar* hpBar;         // Ѫ��
	Entity* target;
};
#endif