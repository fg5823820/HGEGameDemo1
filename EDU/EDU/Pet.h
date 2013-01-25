#pragma once
#include "MoveableObj.h"
#include <deque>
#include <vector>



class CPet;
class CAi;
typedef std::deque<Pos>	DEQUE;
typedef std::vector<CPet*>				PETS;
typedef std::vector<CPet*>::iterator	PETS_ITR;

struct Attribute
{
	UINT			constitution;		//体质
	UINT			intelligence;		//智力

	UINT			strength;			//力量
	UINT			dexterity;			//敏捷
	UINT			technique;			//技巧
	UINT			spirit;				//精神
	UINT			will;				//意志
	UINT			charm;				//魅力
};

class CPet : public CMoveableObj
{
public:
	CPet(hgeResourceManager*, char* name, CAi*, float spd = 50.f);
	virtual~CPet(){}

	virtual bool Init();
	virtual void Update(float);
	virtual void Render();
	virtual void Cleanup();
	static PETS* GetPets(){return m_pets;}
	
	void SetPos(float x,float y) {m_pos.x = x;m_pos.y = y;}

	enum Dir{ UP, DOWN, LEFT, RIGHT };

	friend void NumRender(hgeFont* font, CPet* pet);

protected:
	void ComputeDir();
	void Stop(){m_pAni[m_dir]->Stop();
	m_pAni[m_dir]->SetFrame(0);m_bMoving = false;}
	/////////////////////////////////////


	Attribute		m_Attribute;

	/////////////////////////////////////
	hgeAnimation*	m_pAni[4];
	CAi*			m_pAi;
	int				m_dir;
	static PETS*	m_pets;
};

void NumRender(hgeFont* font, CPet* pet);
