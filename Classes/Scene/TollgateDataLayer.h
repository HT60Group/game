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


	static int m_iGold;
	static int m_iElec;
	static int m_iPop;

	static int addm_iGold;
	static int addm_iElect;

	Text* m_GoldLab;
	Text* m_ElecLab;
	Text* m_PopLab;

	static int BarrackCostMine;
	static int ProducerCostMine;
	static int StopeCostMine;
	static int WarFactoryCostMine;
	static int WarFactoryCostElec;

	static int SoldierCostMine;
	static int DogCostMine;
	static int SniperCostMine;
	static int SniperCostElec;
	static int TankCostMine;
	static int TankCostElec;


	void Refresh(float dt);
};
