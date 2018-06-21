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
	////��ȡ�����ļ�
	//virtual void readJson();

	//����
	static Building* createWithSpriteFrameName(Building* sprite, const char *filename);

	bool isClickMe(Point pos);

	virtual void hurt(int x);
	virtual bool isDeath();

	bool isBroken;             // �Ƿ񱻴ݻ�
	Sprite* normal;            // ����ͼƬ
protected:
	int Hp;                  //Ѫ��
	int totalHp;               // ������ֵ
	double sizeX;            //��С������
	double sizeY;            //��С������
	int Costime;             //�������ѵ�ʱ��
	int CostMine;            //���컨�ѵĿ�
	int CostElec;            //���컨�ѵĵ�

	int index;                 // �ڴ��е������±�
	int id;                    // ���
	int BuildingID;            // �������ID
	//virtual void ondied() override;
	//virtual void onHurt(int iHurtValue) override;
	LoadingBar* hpBar;         // Ѫ��
	Entity* target;
};

#endif