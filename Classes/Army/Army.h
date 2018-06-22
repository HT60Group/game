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


	//��ȡ�����ļ�
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
	Point nowPoint;                //�������Ļ����
	Vector<Entity*> EntityList;
	Entity* m_atkEntity;
	bool m_isAtkCoolDown;
	int Hp;                  //Ѫ��
	int totalHp;               // ������ֵ
	double MovingSpeed;               //�ƶ��ٶ�
    int AttackDistance;            //��������
	int DPS;                       //�˺�
	int attackSpeed;
	int CostMine;                  //���ѵĿ�
	int CostElec;                 //���ѵĵ�
	int ViewDistance;              //��Ұ
	int Costime;                  //���ѵ�ʱ��
	int Belong;
	LoadingBar* hpBar;         // Ѫ��
	Entity* target;
};
#endif