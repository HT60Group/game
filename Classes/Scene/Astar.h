#pragma once
#include<vector>
#include<list>
#include"cocos2d.h"

const int Cost22 = 22;
const int Cost20 = 20;
const int Cost40 = 40;



struct Pos
{
	int x, y; //点坐标，这里为了方便按照C++的数组来计算，x代表横排，y代表竖列  
	int F, G, H; //F=G+H  
	Pos *parent; //parent的坐标，这里没有用指针，从而简化代码  
	Pos(int _x, int _y) :x(_x), y(_y), F(0), G(0), H(0), parent(NULL)  //变量初始化  
	{
	}
};


class Astar
{
public:
	void InitAstar(std::vector<std::vector<int>> &_maze);
	std::list<cocos2d::Point > GetPath(cocos2d::Point &start,cocos2d::Point &end, bool isIgnoreCorner);

private:
	Pos * findPath(Pos &startPoint, Pos &endPoint, bool isIgnoreCorner);
	std::vector<Pos *> getSurroundPoints(const Pos *point, bool isIgnoreCorner) const;
	bool isCanreach(const Pos *point, const Pos *target, bool isIgnoreCorner) const; //判断某点是否可以用于下一步判断  
	Pos *isInList(const std::list<Pos *> &list, const Pos *point) const; //判断开启/关闭列表中是否包含某点  
	Pos *getLeastFpoint(); //从开启列表中返回F值最小的节点  
							 //计算FGH值  
	int calcG(Pos *temp_start, Pos *point);
	int calcH(Pos *point, Pos *end);
	int calcF(Pos *point);
private:
	std::vector<std::vector<int>> maze;
	std::list<Pos *> openList;  //开启列表  
	std::list<Pos *> closeList; //关闭列表  
};