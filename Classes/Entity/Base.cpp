#include "Base.h"

const double BaseSizeX=0;
const double BaseSizeY=0;

Base::Base() {
}
Base::~Base(){}

bool Base::init()
{
	//readJson();
	//create base
	Base* base = new Base();
	Building::create(base, "Base.png");     //�˴���ҪͼƬ����ͼƬ

	this->addChild(base);

	base->setPosition(Point(0, 0));            //setPosition
	return true;
}
//
//void Base::readJson()
//{
//	Json::Reader reader;
//	Json::Value root;
//
//	std::string data = FileUtils::getInstance()->getStringFromFile("StarCC.json");
//
//	if (reader.parse(data, root, false) == true)
//	{
//		Hp = root["Base"]["Hp"].asInt();
//		Costime = root["Base"]["Costime"].asInt();
//		CostMine = root["Base"]["CostMine"].asInt();
//		CostElec = root["Base"]["CostElec"].asInt();
//	}
//}
//
//void Base::CreateScv()             //����Scv
//{
//	Scv* scv = new Scv();
//	Army::create(scv, "Scv.png");     //�˴���ҪͼƬ�������ͼƬ
//
//	this->addChild(scv);
//
//	scv->setPosition(Point(0, 0));            //setPosition
//}