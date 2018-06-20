#include <math.h>  
#include "Astar.h"  
#include"cocos2d.h"
//��ʼ����ײ
void Astar::InitAstar(std::vector<std::vector<int>> &_maze)
{
	maze = _maze;
}

int Astar::calcG(Pos *temp_start, Pos *point)
{
	int extraG;
	if (abs(point->x - temp_start->x) + abs(point->y - temp_start->y) == 1)
	{
		extraG = Cost22;
	}
	else if ((point->x - temp_start->x)*(point->y - temp_start->y) > 0)
	{
		extraG = Cost20;
	}
	else
	{
		extraG = Cost40;
	}
	int parentG = point->parent == NULL ? 0 : point->parent->G; //����ǳ�ʼ�ڵ㣬���丸�ڵ��ǿ�  
	return parentG + extraG;
}

int Astar::calcH(Pos *point, Pos *end)
{
	//�ü򵥵�ŷ����þ������H�����H�ļ����ǹؼ������кܶ��㷨��û�����о�^_^  
	return (abs(point->x - end->x) + abs(point->y - point->y))*Cost22;
}

int Astar::calcF(Pos *point)
{
	return point->G + point->H;
}

Pos *Astar::getLeastFpoint()
{
	if (!openList.empty())
	{
		auto resPoint = openList.front();
		for (auto &point : openList)
			if (point->F<resPoint->F)
				resPoint = point;
		return resPoint;
	}
	return NULL;
}

Pos *Astar::findPath(Pos &startPoint, Pos &endPoint, bool isIgnoreCorner)
{
	openList.push_back(new Pos(startPoint.x, startPoint.y)); //�������,��������һ���ڵ㣬�������  
	while (!openList.empty())
	{
		auto curPoint = getLeastFpoint(); //�ҵ�Fֵ��С�ĵ�  
		openList.remove(curPoint); //�ӿ����б���ɾ��  
		closeList.push_back(curPoint); //�ŵ��ر��б�  
									   //1,�ҵ���ǰ��Χ�˸����п���ͨ���ĸ���  
		auto surroundPoints = getSurroundPoints(curPoint, isIgnoreCorner);
		for (auto &target : surroundPoints)
		{
			//2,��ĳһ�����ӣ���������ڿ����б��У����뵽�����б������õ�ǰ��Ϊ�丸�ڵ㣬����F G H  
			if (!isInList(openList, target))
			{
				target->parent = curPoint;

				target->G = calcG(curPoint, target);
				target->H = calcH(target, &endPoint);
				target->F = calcF(target);

				openList.push_back(target);
			}
			//3����ĳһ�����ӣ����ڿ����б��У�����Gֵ, �����ԭ���Ĵ�, ��ʲô������, �����������ĸ��ڵ�Ϊ��ǰ��,������G��F  
			else
			{
				int tempG = calcG(curPoint, target);
				if (tempG<target->G)
				{
					target->parent = curPoint;

					target->G = tempG;
					target->F = calcF(target);
				}
			}
			Pos *resPoint = isInList(openList, &endPoint);
			if (resPoint)
				return resPoint;  
		}
	}

	return NULL;
}

std::list<cocos2d::Point > Astar::GetPath(cocos2d::Point &start, cocos2d::Point &end, bool isIgnoreCorner)
{
	Pos startPoint(start.x,start.y);
	Pos endPoint(end.x, end.y);
	Pos *result = findPath(startPoint, endPoint, isIgnoreCorner);
	std::list<cocos2d::Point> path;
	cocos2d::Point temp;
	//����·�������û�ҵ�·�������ؿ�����  
	while (result)
	{
		temp = cocos2d::Point(result->x, result->y);
		path.push_front(temp);
		result = result->parent;
	}
	return path;
}

Pos *Astar::isInList(const std::list<Pos *> &list, const Pos *point) const
{
	//�ж�ĳ���ڵ��Ƿ����б��У����ﲻ�ܱȽ�ָ�룬��Ϊÿ�μ����б����¿��ٵĽڵ㣬ֻ�ܱȽ�����  
	for (auto p : list)
		if (p->x == point->x&&p->y == point->y)
			return p;
	return NULL;
}

bool Astar::isCanreach(const Pos *point, const Pos *target, bool isIgnoreCorner) const
{
	if (target->x<0 || target->x>maze.size() - 1
		|| target->y<0 && target->y>maze[0].size() - 1
		|| maze[target->x][target->y] == 1
		|| target->x == point->x&&target->y == point->y
		|| isInList(closeList, target)) //������뵱ǰ�ڵ��غϡ�������ͼ�����ϰ�������ڹر��б��У�����false  
		return false;
	else
	{
		if (abs(point->x - target->x) + abs(point->y - target->y) == 1) //��б�ǿ���  
			return true;
		else
		{
			//б�Խ�Ҫ�ж��Ƿ��ס  
			if (maze[point->x][target->y] == 0 && maze[target->x][point->y] == 0)
				return true;
			else
				return isIgnoreCorner;
		}
	}
}

std::vector<Pos *> Astar::getSurroundPoints(const Pos *point, bool isIgnoreCorner) const
{
	std::vector<Pos *> surroundPoints;

	for (int x = point->x - 1; x <= point->x + 1; x++)
		for (int y = point->y - 1; y <= point->y + 1; y++)
			if (isCanreach(point, new Pos(x, y), isIgnoreCorner))
				surroundPoints.push_back(new Pos(x, y));

	return surroundPoints;
}
std::list<cocos2d::Point> Findway(cocos2d::Point start, cocos2d::Point end, std::vector<std::vector<int>> &_maze)
{
	Astar astar;
	astar.InitAstar(_maze);
	return astar.GetPath(start, end, false);

}