#include "Army.h"
#include "Scene\MapLayer.h"
#include "AIManager/BuildingManager.h"
#include "Entity/Entity.h"
#include "AIManager.h"
Army::Army() {
	//ai = NULL;
	m_atkEntity = NULL;
	m_isAtkCoolDown = false;
}
Army::~Army() {}

bool Army::init()
{
	//ai = AIManager::createAIManager();
	//this->addChild(ai);
	showUI();
	//readJson();
	DPS = 1;
	_numInVec = 0;
	AttackDistance = 9;
	return true;
}
void Army::showUI() {
	auto UI = cocostudio::GUIReader::getInstance()->widgetFromJsonFile("HpBar/hpBar_1.ExportJson");
	this->addChild(UI);
	Size size = this->getContentSize();
	UI->setPosition(Point(size.width*0.5f, size.height));

	hpBar = (LoadingBar*)Helper::seekWidgetByName(UI, "HpBar");
	hpBar->setPercent(100);
	totalHp = Hp;
}
//void Army::readJson()
//{
//	Json::Reader reader;
//	Json::Value root;
//
//	std::string data = FileUtils::getInstance()->getStringFromFile("StarCC.json");
//
//	if (reader.parse(data, root, false) == true)
//	{
//		Hp = root["Army"]["Hp"].asInt();
//		MovingSpeed = root["Army"]["Speed"].asDouble();               //移动速度
//		AttackDistance = root["Army"]["Range"].asInt();            //攻击距离
//		DPS = root["Army"]["Dps"].asInt();                       //伤害
//		CostMine = root["Army"]["CostMime"].asInt();                  //花费的矿
//		CostElec = root["Army"]["CostElec"].asInt();                 //花费的电
//		Costime = root["Army"]["Costime"].asInt();                  //花费的时间
//	}
//}

Army* Army::createWithSpriteFrameName(Army* sprite, const char *filename)
{
	if (sprite &&sprite->initWithFile(filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

//Point Army::getScenePosition()
//{
//	auto tmap = MapLayer::map;
//	auto _currentPos = tmap->getPosition();//地图的绝对坐标
//	Point tpos = this->getPosition();
//	tpos += _currentPos;
//	return tpos;
//}

//
//void Army::checkAtkEntity(float ft, Vector<Entity*> EntityList) {
//	if (m_atkEntity != NULL) {
//		//died
//		if (m_atkEntity->isDied()){
//			EntityList.eraseObject(m_atkEntity);
//			//清除锁定的怪物
//			m_atkEntity = NULL;
//			return;
//		}
//		if (m_isAtkCoolDown == false) {
//			atk();
//		}
//
//		checkAimIsOutOfRange(EntityList);
//	}
//	else {
//		chooseAim();
//	}
//}
//
bool Army::isInAtkRange(Entity* entity) {
	//如果是空就直接返回false
	if (entity == nullptr) {return false; }

	Point myPos = this->getScenePosition();
	Point enemyPos = entity->getScenePosition();

	myPos=MapLayer::ConvertToMap(myPos.x,myPos.y,MapLayer::map);
	enemyPos = MapLayer::ConvertToMap(enemyPos.x, enemyPos.y, MapLayer::map);
	log("myPos=%f,%f", myPos.x, myPos.y);
	log("enemyPos=%f,%f", enemyPos.x, enemyPos.y);
	int iDistance = (myPos.x - enemyPos.x)*(myPos.x - enemyPos.x);
	iDistance += (myPos.y - enemyPos.y)*(myPos.y - enemyPos.y);

	int range2 = 81;
	log("%d", range2);
	if (iDistance <= range2)
	{
		log("local\n\n\n\n\n");
		return true;
	}
	else {
		return false;
	}
}
Entity* Army::chooseAtkEntity() {
	int sum = BuildingManager::m_enemyBuildingVec.size();
	for (int i = 0; i < sum; i++)
	{
		if (isInAtkRange(BuildingManager::m_enemyBuildingVec[i])) {
			log("emmmmmm\n\n\n\n\n");
			return BuildingManager::m_enemyBuildingVec[i];
		}
	}

	int soldiersum = AIManager::m_enemyArmyVec.size();
	for (int i = 0; i < soldiersum; i++)
	{
		if (isInAtkRange(AIManager::m_enemyArmyVec[i]))
		{
			return AIManager::m_enemyArmyVec[i];
		}
	}
	
	return nullptr;
}

void Army::Attack(Entity* entity) {
	if (entity != nullptr)
	{
		log("Attack!!!\n\n\n");
	    entity->hurtMe(DPS);
	}
}

void Army::autoAttack(float dt) 
{
	Attack(this->chooseAtkEntity());
}

//void Army::atkCoolDownEnd(float dt) {
//	m_isAtkCoolDown = false;
//}
//
//void Army::checkAimIsOutOfRange(Vector<Entity*> EntityList) {
//	if (m_atkEntity != NULL) {
//		if (isInAtkRange(m_atkEntity->getPosition()) == false) {
//			missAtkEntity();
//		}
//	}
//}