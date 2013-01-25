#include "AI.h"
#include "MoveableObj.h"

CAi::CAi(int type):
m_type(type),
m_pHge(0),
m_time(0.f),
m_time2(0.f),
m_bChangeState(false)
{
	m_pHge = hgeCreate(HGE_VERSION);
	m_pHge->Random_Seed();
}

void CAi::Update(CMoveableObj* v, float dt)
{
	m_time += dt;
	if(m_time > 1.0f + m_time2)
	{
		m_time = 0.f;
		m_bChangeState = !m_bChangeState;
		v->SetMoveSate(m_bChangeState);
		m_time2 = m_pHge->Random_Float(0,5);
		if(m_bChangeState)
			v->SetDir(m_pHge->Random_Float(0,M_PI));
	}
}
