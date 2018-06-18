#include"MapManager.h"
//#include"AIManager/BuildingManager.h"
using namespace cocos2d;


Scene* MapScene::createScene() {
	auto scene = Scene::create();
	auto layer = MapScene::create();
	scene->addChild(layer,0);
	return scene;
}

bool MapScene::init() {
	map = TMXTiledMap::create("gandw.tmx");

	this->addChild(map, MAP_LAYEER_LVL);//��ӵ�ͼ

	MapManager* _mapmanager = MapManager::create();
	this->addChild(_mapmanager, MAP_LAYEER_LVL);//��ӹ�����

	MenuLayer* _menulayer = MenuLayer::create();
	this->addChild(_menulayer, UI_LAYEER_LVL);

	_mapmanager->SetMouseController();
	_mapmanager->schedule(schedule_selector(MapManager::ControllerUpdate));//ÿ֡���ú���
	

	//BuildingManager* m_buildingMgr = BuildingManager::createBuildingMgr();
	//this->addChild(m_buildingMgr, 1);
	
	return true;
}

Vec2 MapScene::ConvertToMap(float x, float y)
{
	int tilewidth =map->getTileSize().width;
	int tileheight = map->getTileSize().height;//��ȷ
	/*log("tile.w=%d,tile.h=%d", tilewidth, tileheight);*/
	
	
	//��Ƭ��ͼԭ���gl����
	float mapOrginX = map->getPosition().x + map->getMapSize().width *tilewidth/ 2;
	float mapOrginY = map->getPosition().y + map->getMapSize().height*tileheight;//��ȷ
	log("org=(%.2f,%.2f)", mapOrginX, mapOrginY);
	
	
	//��ѡȡ��A��ԭ�����Ե�gl����
	float OA_x = x - mapOrginX;
	float OA_y = y - mapOrginY;
	//log("oa=(%.2f,%.2f)", OA_x, OA_y);//��ȷ

	float m = (OA_x / 64) -( OA_y / 32);
	/*log("m=%d",(int) m);*/
	float n = -(OA_y / 32 )-( OA_x / 64);
	/*log("n=%d", (int)n);*/

	if (m<0 || n<0 || m>map->getMapSize().width || n>map->getMapSize().height)
	{
		return Vec2(-1, -1);
	}
	m = (int)m;
	n = (int)n;
	
	return Vec2(m, n);
}

Vec2 MapScene::ConvertToScene(int x, int y)
{
	float tilewidth = map->getTileSize().width;
	float tileheight = map->getTileSize().height;

	int mapOrginX = map->getPosition().x + map->getContentSize().width / 2;
	int mapOrginY = map->getPosition().y + map->getContentSize().height;

	if (x > map->getMapSize().width || x<0
		|| y>map->getMapSize().height || y < 0)
	{
		return Point(0, 0);
	}
	float OA_x = (x - y)*tilewidth / 2.0;
	float OA_y = -(x + y)*tileheight / 2.0;
	return Vec2(mapOrginX + OA_x, mapOrginY + OA_y);
}


