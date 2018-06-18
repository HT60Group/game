#pragma once
#include<vector>
#include<list>
#include"cocos2d.h"

const int Cost22 = 22;
const int Cost20 = 20;
const int Cost40 = 40;



struct Pos
{
	int x, y; //�����꣬����Ϊ�˷��㰴��C++�����������㣬x������ţ�y��������  
	int F, G, H; //F=G+H  
	Pos *parent; //parent�����꣬����û����ָ�룬�Ӷ��򻯴���  
	Pos(int _x, int _y) :x(_x), y(_y), F(0), G(0), H(0), parent(NULL)  //������ʼ��  
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
	bool isCanreach(const Pos *point, const Pos *target, bool isIgnoreCorner) const; //�ж�ĳ���Ƿ����������һ���ж�  
	Pos *isInList(const std::list<Pos *> &list, const Pos *point) const; //�жϿ���/�ر��б����Ƿ����ĳ��  
	Pos *getLeastFpoint(); //�ӿ����б��з���Fֵ��С�Ľڵ�  
							 //����FGHֵ  
	int calcG(Pos *temp_start, Pos *point);
	int calcH(Pos *point, Pos *end);
	int calcF(Pos *point);
private:
	std::vector<std::vector<int>> maze;
	std::list<Pos *> openList;  //�����б�  
	std::list<Pos *> closeList; //�ر��б�  
};