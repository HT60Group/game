#ifndef _Building_H_
#define _Building_H_

#include"cocos2d.h"
#include "Entity/Entity.h"
//#include "json/json.h"
//#include "AIManager/AIManager.h"

using namespace cocos2d;
enum EnumState {
	enAlive,            //���״̬
	enCreate,           //����״̬����������һ��Ҫ��
	enCreateSoldiers,   //���״̬
};
class Building :public Entity
{
public:
	Building();
	~Building();
	CREATE_FUNC(Building);
	virtual bool init();

	////��ȡ�����ļ�
	//virtual void readJson();

	//����
	static Building* create(Building* sprite, const char *filename);

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

//	LoadingBar* hpBar;         // Ѫ��
	Entity* target;
	//AIManager* ai;
};

#endif