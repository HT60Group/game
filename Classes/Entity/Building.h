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
	////读取配置文件
	//virtual void readJson();

	//建造
	static Building* createWithSpriteFrameName(Building* sprite, const char *filename);

	virtual bool isDeath();

	bool isBroken;             // 是否被摧毁

	Point getScenePosition();
protected:
	int index;                 // 内存中的数组下标
	int id;                    // 编号
	int BuildingID;            // 建筑编号ID
	Entity* target;
};

#endif