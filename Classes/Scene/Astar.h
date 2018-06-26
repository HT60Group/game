#pragma once
#include<vector>
#include<list>
#include"cocos2d.h"
#include"Army/Army.h"

//
const int cost10 = 10;//相邻格子
const int cost14 = 14;//对角格子

struct Pos
{
	float x, y;//瓦片坐标
	int F, G, H;//F=G+H
	Pos* parent;//父节点
	Pos(int _x, int _y) :x(_x), y(_y), F(0), G(0), H(0), parent(NULL)
	{}
};

class Astar
{
public:
	void InitAstar(std::vector<std::vector<int> >&_maze);
	void GetPath(cocos2d::Point &start, cocos2d::Point&end,Army* army);
private:
	Pos * findPath(Pos& startPoint, Pos& endPoint);
	std::vector<Pos*> getSurroundPoints(const Pos*point)const;
	bool isCanreach(const Pos* point, const Pos* target)const;
	Pos* isInList(const std::list<Pos*>&list, const Pos* point)const;
	Pos* getLeastFPoint();

	int getG(Pos* temp_start, Pos* point);
	int getH(Pos* point, Pos* end);
	int getF(Pos* point);

	std::vector<std::vector<int> >maze;
	std::list<Pos*> openList;
	std::list<Pos*> closeList;
};