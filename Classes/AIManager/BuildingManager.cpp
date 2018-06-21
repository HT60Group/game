#include "BuildingManager.h"

#include "Entity/Entity.h"
#include "Entity/Building.h"
#include "Entity/Base.h"
#include "Entity/Barrack.h"
#include "Entity/Producer.h"
#include "Entity/Stope.h"
#include "Entity/WarFactory.h"
#include "Scene/MapScene.h"
#include "Scene/MapLayer.h"
#include "Scene/MenuLayer.h"

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
	//if (!Node::init()) { return false; }

	return true;
}


void BuildingManager::SetBarrackController(Building* building)
{
	auto listener = EventListenerTouchOneByOne::create();
	log("using setBarrack");
	listener->onTouchBegan = [&, building](Touch *touch, Event *event)
	{
		log("target");
		auto tmap = MapLayer::map;
		//auto _currentPos = tmap->getPosition();//地图的绝对坐标

		auto visibleSize = Director::getInstance()->getVisibleSize();
		Point pos = Director::getInstance()->convertToGL(touch->getLocationInView());
		auto target1 = static_cast<Building*>(event->getCurrentTarget());
		if (target1->getBoundingBox().containsPoint(pos - tmap->getPosition()))
		{
			log("OK");
			GetMenuLayer()->CreateBarrackLayer();
			return true;
		}
		return false;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, building);
}
MenuLayer* BuildingManager::GetMenuLayer()
{
	return 	MapScene::GetMenuLayer();
}
