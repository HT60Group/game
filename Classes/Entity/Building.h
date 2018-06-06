#ifndef _Building_H_
#define _Building_H_

#include"cocos2d.h"
#include "json/json.h"

using namespace cocos2d;
enum EnumState {
	enAlive,            //���״̬
	enCreate,           //����״̬����������һ��Ҫ��
	enCreateSoldiers,   //���״̬
};
class Building :public Sprite
{
public:
	CREATE_FUNC(Building);
	virtual bool init();

	EnumState enCurState;       //��ǰ״̬

	bool isAlive();             //�ж��Ƿ���
	bool isCreateSoldiers();    //�ж��Ƿ��ܹ����

	void changeState(EnumState enState);   //�л�״̬

	virtual void update(float dt);

	//������Ϣ�Ļص�����
	virtual void getMsg(float dt);
	//������Ϣ
	virtual void sendMsg(float dt);

	//��ȡ�����ļ�
	virtual void readJson();

	static Building* create(Building* sprite, const char *filename);


protected:
	int Hp;                  //Ѫ��
	double sizeX;            //��С������
	double sizeY;            //��С������
	int Costime;             //�������ѵ�ʱ��
	int CostMine;            //���컨�ѵĿ�
	int CostElec;            //���컨�ѵĵ�
};

#endif