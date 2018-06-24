#ifndef _Entity_H_
#define _Entity_H_

#include"cocos2d.h"
//#include "json/json.h"

using namespace cocos2d;
class Entity :public Sprite
{
public:
	Entity();
	~Entity();

	virtual bool init();
	CREATE_FUNC(Entity);
	////��ȡ�����ļ�
	//virtual void readJson();

	//virtual void hurt(int x);
	//virtual void idle();
	//virtual bool isDied();

	//�õ�������Ե�ͼ����
	Point getScenePosition();
	//������
	void hurtMe(int iHurtValue);
	void onDied();

	void is_Enemy();
	int _numInVec;             //��vec�е�λ��

	Vec2 pos;
	bool Belonging;             //true��ʾ���Լ���
protected:
	Sprite* m_sprite;  

	int Hp;
	int totalHp;
	bool m_isDied;
	int Costime;             //�������ѵ�ʱ��
	int CostMine;            //���컨�ѵĿ�
	int CostElec;            //���컨�ѵĵ�
	bool isDied();

};
#endif