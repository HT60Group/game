#include "ManagerBase.h"

bool ManagerBase::init()
{
	if (!Node::init()) { return false; }


	return true;
}


ManagerBase::ManagerBase()
{
	m_isMoving = false;
	m_isXLeft = false;
	m_isYUp = false;
	m_iCheckMoveSpeed = 2;
	m_entity = NULL;
}
ManagerBase::~ManagerBase() {}

Point ManagerBase::getNextPos(Point curPos, Point destPos)
{
	if (curPos.x > destPos.x) {
		m_isXLeft = true;
	}
	else {
		m_isXLeft = false;
	}
	if (curPos.y < destPos.y) {
		m_isYUp = true;
	}
	else {
		m_isYUp = false;
	}

	if (curPos.x < destPos.x && m_isXLeft == false) {
		curPos.x += m_iSpeed;
		if (curPos.x > destPos.x) {
			curPos.x = destPos.x;
		}
	}
	else if (curPos.x > destPos.x &&m_isXLeft == true) {
		curPos.x -= m_iSpeed;
		if (curPos.x < destPos.x) {
			curPos.x = destPos.x;
		}
	}

	if (curPos.y < destPos.y && m_isYUp == true) {
		curPos.y += m_iSpeed;
		if (curPos.y > destPos.y) {
			curPos.y = destPos.y;
		}
	}

	else if (curPos.y > destPos.y && m_isYUp == false) {
		curPos.y -= m_iSpeed;
		if (curPos.y < destPos.y) {
			curPos.y = destPos.y;
		}
	}

	return curPos;
}