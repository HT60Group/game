#ifndef _Building_H_
#define _Building_H_

#include"cocos2d.h"
#include "Entity/Entity.h"
//#include "json/json.h"
//#include "AIManager/AIManager.h"

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

	virtual bool isDeath();

	bool isBroken;             // �Ƿ񱻴ݻ�

	Point getScenePosition();
protected:
	int index;                 // �ڴ��е������±�
	int id;                    // ���
	int BuildingID;            // �������ID
	Entity* target;
};

#endif