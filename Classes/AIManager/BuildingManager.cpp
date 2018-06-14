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

	//������������
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [&](Touch* touch, Event* event) {
		return true;
	};
	listener->onTouchEnded = [&](Touch* touch, Event* event) {
		Point pos = Director::getInstance()->convertToGL(touch->getLocationInView());

        createBase(pos);
		////��ȡ������������
		//Building* clickBuilding = findClickBuilding(pos);

		//if (clickBuilding == NULL) {
		//	
		//}
		////���ǵ��ͼ��
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
		//	//��Ӧս�������Ľ���

		//}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


	return true;
}

void BuildingManager::createBarrack(Point tpos) {
	//create Barrack
	Barrack* barrack = new Barrack();
	Building::create(barrack, "Barrack.png");     //�˴���ҪͼƬ�������ͼƬ

	this->addChild(barrack);
	barrack->setPosition(tpos);            //setPosition

	m_BuildingList.pushBack(barrack);

	//�Ѵ˴����Ϊ���ɾ���
	//
}
void BuildingManager::createBase(Point tpos) {
	//create Base
	Base* base = new Base();
	Building::create(base, "Base.png");     //�˴���ҪͼƬ�������ͼƬ

	this->addChild(base);
	base->setPosition(tpos);            //setPosition

	m_BuildingList.pushBack(base);

	//�Ѵ˴����Ϊ���ɾ���
	//
}
void BuildingManager::createProducer(Point tpos) {
	//create producer
	Producer* producer = new Producer();
	Building::create(producer, "Producer.png");     //�˴���ҪͼƬ�������ͼƬ

	this->addChild(producer);
	producer->setPosition(tpos);            //setPosition

	m_BuildingList.pushBack(producer);

	//�Ѵ˴����Ϊ���ɾ���
	//
}
void BuildingManager::createStope(Point tpos) {
	//create stope
	Stope* stope = new Stope();
	Building::create(stope, "Stope.png");     //�˴���ҪͼƬ�������ͼƬ

	this->addChild(stope);
	stope->setPosition(tpos);            //setPosition

	m_BuildingList.pushBack(stope);

	//�Ѵ˴����Ϊ���ɾ���
	//
}
void BuildingManager::createWarFactory(Point tpos) {
	//create warfac
	WarFactory* warfac = new WarFactory();
	Building::create(warfac, "WarFactory.png");     //�˴���ҪͼƬ�������ͼƬ

	this->addChild(warfac);
	warfac->setPosition(tpos);            //setPosition

	m_BuildingList.pushBack(warfac);

	//�Ѵ˴����Ϊ���ɾ���
	//
}


//����Ӧ���Ǳ�������vector
Building* BuildingManager::findClickBuilding(Point pos) {
	for (auto tBuilding : m_BuildingList) {
		if (tBuilding->isClickMe(pos)) {
			return tBuilding;
		}
	}
	return NULL;
}