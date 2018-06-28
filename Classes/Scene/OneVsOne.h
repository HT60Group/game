#ifndef _OneVsOne_H_
#define _OneVsOne_H_

#include "cocos2d.h"
#include"cocos-ext.h"
#include"ui/cocosGUI.h"
#include"editor-support/cocostudio/CCSGUIReader.h"
#include "scene/MapScene.h"

USING_NS_CC_EXT;
using namespace cocos2d::extension;
using namespace cocos2d::ui;
using namespace cocostudio;
class  OneVsOne : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	ListView* listView;
	// a selector callback
	void buttonTurnToStart(cocos2d::Ref* pSender);
	void selectedItemEvent(Ref* pSender, cocos2d::ui::ListView::EventType type);
	void selectedItemEventScrollView(Ref* pSender, ui::ScrollView::EventType type);
	void textFieldEvent(Ref *pSender, cocos2d::ui::TextField::EventType type);
	void checkVector(float dt);
	std::string m_msgSend;
	// implement the "static create()" method manually
	CREATE_FUNC(OneVsOne);
};

#endif

