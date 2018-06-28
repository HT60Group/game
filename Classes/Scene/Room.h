#ifndef _Room_H_
#define _Room_H_

#include "cocos2d.h"
#include"cocos-ext.h"
#include"ui/cocosGUI.h"
#include"editor-support/cocostudio/CCSGUIReader.h"
#include "leaf\API.h"
#include "leaf\Client.h"
#include "leaf\Server.h"

USING_NS_CC_EXT;
using namespace cocos2d::extension;
using namespace cocos2d::ui;
using namespace cocostudio;
class  Room : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	// a selector callback
	void buttonTurnToCreateRoom(cocos2d::Ref* pSender);
	void buttonTurnToJoinRoom(Ref* pSender);

	//Server* _server;
	//Client* _client;
	// implement the "static create()" method manually
	CREATE_FUNC(Room);
};

#endif

