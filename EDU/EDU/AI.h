#pragma once
#include "stdafx.h"

class CMoveableObj;

class CAi
{
public:
	CAi(int type = RANDDOM_WALK);
	~CAi(){m_pHge->Release();}

	void Update(CMoveableObj*, float);

	enum AI_type
	{
		RANDDOM_WALK
	};

private:
	int			m_type;	

	float		m_time,m_time2;
	bool		m_bChangeState;

	HGE*		m_pHge;
};