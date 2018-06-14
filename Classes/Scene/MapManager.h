#include"cocos2d.h"
#include"Scene/MapScene.h"
using namespace cocos2d;

class MapManager;

class MapManager:public Node
{
public:
	CREATE_FUNC(MapManager);
	virtual bool init();

	void SetMouseController();
	void ControllerUpdate(float dt);
private:
	Point _mapMoveSpeed = Point(0, 0);//��ʼ�ٶ�Ϊ0������
	bool _isClick = false;
	Point _mousePosition = Point(0, 0);
};