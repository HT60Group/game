#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include"cocos-ext.h"
#include"ui/cocosGUI.h"
#include"editor-support/cocostudio/CCSGUIReader.h"

USING_NS_CC_EXT;
using namespace cocos2d::extension;
using namespace cocos2d::ui;
using namespace cocostudio;
class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	//void menuCloseCallback();
	void buttonTurnToSetting(cocos2d::Ref* pSender);
	//void buttonTurnToSetting();
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
	int n = 0;
};

#endif // __HELLOWORLD_SCENE_H__
