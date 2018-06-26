#include<math.h>
#include"Astar.h"
#include"cocos2d.h"
#include"Army/Army.h"

void Astar::InitAstar(std::vector<std::vector<int> > &_maze)
{
	maze = _maze;
}

int Astar::getG(Pos *temp_start, Pos* point)
{
	int extraG;
	if (abs(point->x - temp_start->x) + abs(point->y - temp_start->y) == 1)
	{
		extraG = cost10;
	}
	else
	{
		extraG = cost14;
	}
	int parentG = point->parent == NULL ? 0 : point->parent->G;

	return parentG + extraG;
}

int Astar::getH(Pos* point, Pos* end)
{
	return (abs(point->x - end->x) * 10 + abs(point->y - end->y) * 10);
}

int Astar::getF(Pos* point)
{
	point->F = point->G + point->H;
	return point->F;
}

Pos* Astar::getLeastFPoint()
{
	if (!openList.empty())
	{
		auto resPoint = openList.front();//设list中第一个元素F最小
		for (auto &point : openList)
		{
			if (point->F < resPoint->F)
			{
				resPoint = point;
			}
		}
		return resPoint;
	}
	return NULL;
}

Pos* Astar::findPath(Pos& startPoint, Pos& endPoint)
{
	openList.push_back(new Pos(startPoint.x, startPoint.y));
	while (!openList.empty())
	{
		auto curPoint = getLeastFPoint();
		openList.remove(curPoint);
		closeList.push_back(curPoint);

		auto surroundPoints = getSurroundPoints(curPoint);
		for (auto &target : surroundPoints)
		{
			if (!isInList(openList, target))
			{
				target->parent = curPoint;

				target->G = getG(curPoint, target);
				target->H = getH(target, &endPoint);
				target->F = getF(target);

				openList.push_back(target);

			}
			else
			{
				int tempG = getG(curPoint, target);
				if (tempG < target->G)
				{
					target->parent = curPoint;

					target->G = tempG;
					target->F = getF(target);
				}
			}
			Pos *resPoint = isInList(openList, &endPoint);
			if (resPoint)
				return resPoint;
		}
	}

	return NULL;
}
void Astar::GetPath(cocos2d::Point &start, cocos2d::Point& end,Army* army)
{
	Pos startPoint(start.x, start.y);
	Pos endPoint(end.x, end.y);
	Pos* result = findPath(startPoint, endPoint);

	
	cocos2d::Point temp;
	while (result)
	{
		temp = cocos2d::Point(result->x, result->y);
		army->way.push_front(temp);
		result = result->parent;
	}
	return ;
}

Pos* Astar::isInList(const std::list<Pos*> &list, const Pos* point)const
{
	for (auto p : list)
	{
		if (p->x == point->x &&p->y == point->y)
		{
			return p;
		}
	}
	return NULL;
}

bool Astar::isCanreach(const Pos * point, const Pos* target) const
{
	if (target->x<0 || target->x>maze.size() - 1
		|| target->y<0 || target->y>maze[0].size() - 1
		|| maze[target->x][target->y] == 1
		|| (target->x == point->x&&target->y == point->y)
		|| isInList(closeList, target))
	{
		return false;
	}
	else
	{
		if (abs(point->x - target->x) + abs(point->y - target->y) == 1)
			return true;
		else
		{
			if (maze[point->x][target->y] == 1 && maze[target->x][point->y] == 1)
			{
				return false;
			}
		}
	}
}

std::vector<Pos*> Astar::getSurroundPoints(const Pos* point)const
{
	std::vector<Pos*> surroundPoints;

	for (int x = point->x - 1; x <= point->x + 1; x++)
	{
		for (int y = point->y - 1; y <= point->y + 1; y++)
		{
			if (isCanreach(point, new Pos(x, y)))
			{
				surroundPoints.push_back(new Pos(x, y));
			}

		}
	}
	return surroundPoints;
}

