#include "Army.h"
#include "Scene\MapLayer.h"

Army::Army() {
	//ai = NULL;
	m_iSpeed = 1;
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
//		MovingSpeed = root["Army"]["Speed"].asDouble();               //�ƶ��ٶ�
//		AttackDistance = root["Army"]["Range"].asInt();            //��������
//		DPS = root["Army"]["Dps"].asInt();                       //�˺�
//		CostMine = root["Army"]["CostMime"].asInt();                  //���ѵĿ�
//		CostElec = root["Army"]["CostElec"].asInt();                 //���ѵĵ�
//		Costime = root["Army"]["Costime"].asInt();                  //���ѵ�ʱ��
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

Point Army::getScenePosition()
{
	auto tmap = MapLayer::map;
	auto _currentPos = tmap->getPosition();//��ͼ�ľ�������
	Point tpos = this->getPosition();
	tpos += _currentPos;
	return tpos;
}
//void Army::move()
//{
//	Point nowPos = this->getPosition();
//	double length = (destination.x - nowPos.x)*(destination.x - nowPos.x);
//	length += (destination.y - nowPos.y)*(destination.y - nowPos.y);
//	length = sqrt(length);
//	double time = length / MovingSpeed;
//	MoveTo* moveTo = MoveTo::create(time, destination);
//
//	this->runAction(moveTo);
////}
//void Army::moveByPosList(Vector<Point*> posList) {
//	if (posList.size() < 1) {
//		return;
//	}
//	//ai->moveByPosList(posList, 2, 3);
//}
//
//void Army::checkAtkEntity(float ft, Vector<Entity*> EntityList) {
//	if (m_atkEntity != NULL) {
//		//died
//		if (m_atkEntity->isDied()){
//			EntityList.eraseObject(m_atkEntity);
//			//��������Ĺ���
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
//
//bool Army::isInAtkRange(Point pos) {
//	int isDoubleAtkRange = AttackDistance;
//	Point ArmyPos = getPosition();
//
//	float length = pos.getDistanceSq(ArmyPos);
//	if (length <= isDoubleAtkRange*isDoubleAtkRange) {
//		return true;
//	}
//	return false;
//}
//
//void Army::chooseAtkEntity(Entity* entity) {
//	m_atkEntity = entity;
//}
//
//void Army::atk() {
//	//��ǹ�����ȴ
//	m_isAtkCoolDown = true;
//	//ָ����������������
//	this->scheduleOnce(schedule_selector(Army::atkCoolDownEnd), 2 / 1000.0f);
//}
//
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
//void Army::missAtkEntity() {
//	m_atkEntity = NULL;
//}