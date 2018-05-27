
#ifndef _OneVsOneVsOne_H_
#define _OneVsOneVsOne_H_

#include "cocos2d.h"
#include"cocos-ext.h"
#include"ui/cocosGUI.h"
#include"editor-support/cocostudio/CCSGUIReader.h"

USING_NS_CC_EXT;
using namespace cocos2d::extension;
using namespace cocos2d::ui;
using namespace cocostudio;
class  OneVsOneVsOne : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	// a selector callback
	void buttonTurnToStart(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(OneVsOneVsOne);
};

#endif

