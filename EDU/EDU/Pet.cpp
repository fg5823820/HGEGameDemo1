#include "Pet.h"
#include "Utilities.h"
#include "AI.h"
#include <string>


PETS* CPet::m_pets	= new PETS;

CPet::CPet(hgeResourceManager * rs, char* name, CAi* ai, float spd):
CMoveableObj(rs),
m_dir(DOWN),
m_pAi(ai)
{
	m_name = name;
	m_speed = spd;
	ZeroMemory(m_pAni, sizeof(m_pAni));
	ZeroMemory(&m_Attribute, sizeof(Attribute));

	m_Attribute.constitution	= m_pHge->Random_Int(1,10);
	m_Attribute.intelligence	= m_pHge->Random_Int(1,10);
	m_Attribute.strength		= m_pHge->Random_Int(1,10);
	m_Attribute.dexterity		= m_pHge->Random_Int(1,10);
	m_Attribute.technique		= m_pHge->Random_Int(1,10);
	m_Attribute.spirit			= m_pHge->Random_Int(1,10);
	m_Attribute.will			= m_pHge->Random_Int(1,10);
	m_Attribute.charm			= m_pHge->Random_Int(1,10);
	
	m_pets->push_back(this);
}

bool CPet::Init()
{
	std::string s(m_name);
	std::string up(".up");
	std::string down(".down");
	std::string right(".right");
	std::string left(".left");

	m_pAni[UP] = new hgeAnimation(*m_pRs->GetAnimation((s+up).c_str()));
	m_pAni[DOWN] = new hgeAnimation(*m_pRs->GetAnimation((s+down).c_str()));
	m_pAni[LEFT] = new hgeAnimation(*m_pRs->GetAnimation((s+left).c_str()));
	m_pAni[RIGHT] = new hgeAnimation(*m_pRs->GetAnimation((s+right).c_str()));
	for(int i = 0;i < 4; i ++)
		if(!m_pAni[i]) return false;
	
	return true;
}

void CPet::Cleanup()
{
	for(int i = 0;i < 4;i ++)
		Delete(m_pAni[i]);
	Delete(m_pets);
}

void CPet::Update(float dt)
{
	CMoveableObj::Update(dt);

	if(m_pos.x < Sence_Rect.x1)//◊Û
	{
		m_movingDir += hgeVector(1,0);
		m_pos.x = Sence_Rect.x1;
	}
	if(m_pos.x > Sence_Rect.x2)//”“
	{
		m_movingDir += hgeVector(-1,0);
		m_pos.x = Sence_Rect.x2;
	}
	if(m_pos.y < Sence_Rect.y1)//∂•
	{
		m_movingDir += hgeVector(0,1);
		m_pos.y = Sence_Rect.y1;
	}
	if(m_pos.y > Sence_Rect.y2)//µÕ
	{
		m_movingDir += hgeVector(0,-1);
		m_pos.y = Sence_Rect.y2;
	}

	m_pAi->Update(this, dt);
	ComputeDir();

	if(m_bMoving)
	{
		if(!m_pAni[m_dir]->IsPlaying())
			m_pAni[m_dir]->Play();
	}else
	{
		if(m_pAni[m_dir]->IsPlaying())
		{
			m_pAni[m_dir]->Stop();
			m_pAni[m_dir]->SetFrame(0);
		}
	}

	m_pAni[0]->GetBoundingBoxEx(m_pos.x, m_pos.y, 0.0f, 0.5f, 0.3f, &m_rect);

		
	m_pAni[m_dir]->Update(dt);

}
void CPet::Render()
{
	m_pAni[m_dir]->Render(floor(m_pos.x), floor(m_pos.y));
}

void CPet::ComputeDir()
{
	float dir = m_movingDir.Angle();
	dir -= M_PI_4;
	if(dir < 0)dir += M_PI*2;
	

	if(dir >= 0 && dir < M_PI_2)  
	{
		m_dir = DOWN;
		return;
	}
	if(dir >= M_PI_2 && dir < M_PI)
	{
		m_dir = LEFT;
		return;
	}
	if(dir >= M_PI && dir < M_PI_2+M_PI)   
	{
		m_dir = UP;
		return;
	}
	if(dir >= M_PI_2+M_PI && dir < M_PI*2) 
	{
		m_dir = RIGHT;
		return;
	}
	m_dir =	DOWN;
}

void NumRender(hgeFont* font, CPet* pet)
{
	font->printf(5,100,HGETEXT_LEFT,
		" PetID:%d\n CON:%d\n INT:%d\n STR:%d\n DEX:%d\n TEC:%d\n SPI:%d\n WILL:%d\n CHA:%d", 
		pet->GetID(),
		pet->m_Attribute.constitution,
		pet->m_Attribute.intelligence,
		pet->m_Attribute.strength,
		pet->m_Attribute.dexterity,
		pet->m_Attribute.technique,
		pet->m_Attribute.spirit,
		pet->m_Attribute.will,
		pet->m_Attribute.charm);
}