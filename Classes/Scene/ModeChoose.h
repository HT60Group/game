#ifndef _ModeChoose_H_
#define _ModeChoose_H_

#include "cocos2d.h"
#include"cocos-ext.h"
#include"ui/cocosGUI.h"
#include"editor-support/cocostudio/CCSGUIReader.h"

USING_NS_CC_EXT;
using namespace cocos2d::extension;
using namespace cocos2d::ui;
using namespace cocostudio;
class  ModeChoose : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	// a selector callback
	void buttonTurnTo1vs1(cocos2d::Ref* pSender);
	void buttonTurnTo2vs2(Ref* pSender);
	void buttonTurnTo1vs1vs1(Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(ModeChoose);
};

#endif

