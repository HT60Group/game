#include "BuildingManager.h"

BuildingManager::BuildingManager()
{
}
BuildingManager::~BuildingManager() {
}

BuildingManager* BuildingManager::createBuildingMgr() {
	BuildingManager* buildingMgr = new BuildingManager();
	if (buildingMgr &&buildingMgr->init()) {
		buildingMgr->autorelease();
	}
	else {
		CC_SAFE_DELETE(buildingMgr);
	}
	return buildingMgr;	
}

bool BuildingManager::init() {
	if (!Node::init()) { return false; }

	//创建触摸监听
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [&](Touch* touch, Event* event) {
		return true;
	};
	listener->onTouchEnded = [&](Touch* touch, Event* event) {
		Point pos = Director::getInstance()->convertToGL(touch->getLocationInView());

        createBase(pos);
		////获取被单击的坐标
		//Building* clickBuilding = findClickBuilding(pos);

		//if (clickBuilding == NULL) {
		//	
		//}
		////若是点击图标
		//if (typeid(*clickBuilding) == typeid(Barrack))
		//{
		//	Barrack* barrack = static_cast<Barrack*>(clickBuilding);



		//}
		//if (typeid(*clickBuilding) == typeid(Producer))
		//{
		//	Producer* producer = static_cast<Producer*>(clickBuilding);


		//}
		//if (typeid(*clickBuilding) == typeid(Stope))
		//{
		//	Stope* stope = static_cast<Stope*>(clickBuilding);


		//}
		//if (typeid(*clickBuilding) == typeid(WarFactory))
		//{
		//	WarFactory* warfac = static_cast<WarFactory*>(clickBuilding);
		//	//对应战车工厂的界面

		//}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


	return true;
}

void BuildingManager::createBarrack(Point tpos) {
	//create Barrack
	Barrack* barrack = new Barrack();
	Building::create(barrack, "Barrack.png");     //此处需要图片——大兵图片

	this->addChild(barrack);
	barrack->setPosition(tpos);            //setPosition

	m_BuildingList.pushBack(barrack);

	//把此处标记为不可经过
	//
}
void BuildingManager::createBase(Point tpos) {
	//create Base
	Base* base = new Base();
	Building::create(base, "Base.png");     //此处需要图片——大兵图片

	this->addChild(base);
	base->setPosition(tpos);            //setPosition

	m_BuildingList.pushBack(base);

	//把此处标记为不可经过
	//
}
void BuildingManager::createProducer(Point tpos) {
	//create producer
	Producer* producer = new Producer();
	Building::create(producer, "Producer.png");     //此处需要图片——大兵图片

	this->addChild(producer);
	producer->setPosition(tpos);            //setPosition

	m_BuildingList.pushBack(producer);

	//把此处标记为不可经过
	//
}
void BuildingManager::createStope(Point tpos) {
	//create stope
	Stope* stope = new Stope();
	Building::create(stope, "Stope.png");     //此处需要图片——大兵图片

	this->addChild(stope);
	stope->setPosition(tpos);            //setPosition

	m_BuildingList.pushBack(stope);

	//把此处标记为不可经过
	//
}
void BuildingManager::createWarFactory(Point tpos) {
	//create warfac
	WarFactory* warfac = new WarFactory();
	Building::create(warfac, "WarFactory.png");     //此处需要图片——大兵图片

	this->addChild(warfac);
	warfac->setPosition(tpos);            //setPosition

	m_BuildingList.pushBack(warfac);

	//把此处标记为不可经过
	//
}


//这里应该是遍历所有vector
Building* BuildingManager::findClickBuilding(Point pos) {
	for (auto tBuilding : m_BuildingList) {
		if (tBuilding->isClickMe(pos)) {
			return tBuilding;
		}
	}
	return NULL;
}