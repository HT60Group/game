#ifndef _InputName_H_
#define _InputName_H_

#include "cocos2d.h"
#include"cocos-ext.h"
#include"ui/cocosGUI.h"
#include"editor-support/cocostudio/CCSGUIReader.h"

USING_NS_CC_EXT;
using namespace cocos2d::extension;
using namespace cocos2d::ui;
using namespace cocostudio;
class  InputName : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	void textFieldEvent(Ref *pSender, cocos2d::ui::TextField::EventType type);
	std::string _playerName;
	// implement the "static create()" method manually
	CREATE_FUNC(InputName);
};

#endif
