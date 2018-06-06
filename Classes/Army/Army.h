#ifndef __Player_H__
#define __Player_H__

#include"cocos2d.h"
#include "json/json.h"
using namespace cocos2d;

class Army : public Sprite
{
public:
	CREATE_FUNC(Army);
	virtual bool init();

	static Army* create(Army* sprite,const char *filename);

	//��ȡ�����ļ�
	virtual void readJson();

protected:
	int Hp;                           //Ѫ��
    double MovingSpeed;               //�ƶ��ٶ�
    int AttackDistance;            //��������
	int DPS;                       //�˺�
	int CostMine;                  //���ѵĿ�
	int CostElec;                 //���ѵĵ�
	int ViewDistance;              //��Ұ
	int Costime;                  //���ѵ�ʱ��
	int Belong;
};
#endif