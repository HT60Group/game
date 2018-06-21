#include "cocos2d.h"
#include"cocos-ext.h"
#include"ui/cocosGUI.h"
#include"editor-support/cocostudio/CCSGUIReader.h"
#include "ui/UIWidget.h"

USING_NS_CC_EXT;
using namespace cocos2d::extension;
using namespace cocos2d::ui;
using namespace cocostudio;
using namespace cocos2d;
class TollgateDataLayer :public Layer {
public:
	TollgateDataLayer();
	~TollgateDataLayer();

	CREATE_FUNC(TollgateDataLayer);
	virtual bool init();

	void recvRefreshGoldNum(Ref* pData);
	void recvRefreshElecNum(Ref* pData);
	void recvRefreshPopNum(Ref* pData);

	int m_iGold;
	int m_iElec;
	int m_iPop;

	Text* m_GoldLab;
	Text* m_ElecLab;
	Text* m_PopLab;
};