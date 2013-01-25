#include "Item.h"

CItem::CItem(hgeResourceManager * rm, char* name):
CObject(rm),
m_spr(0),
m_bDrag(false)
{
	m_name = name;
}

bool CItem::Init()
{
	m_spr = m_pRs->GetSprite(m_name);
	return true;
}

void CItem::Render()
{
	m_spr->Render(m_pos.x, m_pos.y);
}

void CItem::Update(float dt)
{
	m_spr->GetBoundingBox(m_pos.x, m_pos.y, &m_rect);
	if(m_pHge->Input_GetKeyState(HGEK_LBUTTON))
	{
		float x,y;
		m_pHge->Input_GetMousePos(&x, &y);
		if(m_rect.TestPoint(x, y))
			m_bDrag = true;
	}
	else
		m_bDrag = false;

	if(m_bDrag)
	{
		float x,y;
		m_pHge->Input_GetMousePos(&x, &y);
		m_pos.x = x;
		m_pos.y = y+10;
	}


}