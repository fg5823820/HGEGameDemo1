#include "MoveableObj.h"
#include "Utilities.h"


CMoveableObj::CMoveableObj(hgeResourceManager* rs) :
CObject(rs),
m_speed(0.f),
m_bMoving(false),
m_movingDir(0,1.f)
{
	
}

CMoveableObj::~CMoveableObj()
{
	
}

void CMoveableObj::Update(float dt)
{
	if(m_bMoving)
	{
		m_movingDir.Normalize();
		m_pos.x += m_movingDir.x * m_speed*dt;
		m_pos.y += m_movingDir.y * m_speed*dt;
		if(m_movingDir.x == 0 && m_movingDir.y == 0)
			m_movingDir.y = 1.0f;
	}
}

