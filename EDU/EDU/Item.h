#pragma once
#include "Object.h"

class CItem : public CObject
{
public:
	CItem(hgeResourceManager*, char* name);
	virtual ~CItem(){}

	virtual bool Init();
	virtual void Render();
	virtual void Update(float);
	virtual void Cleanup(){}

private:
	hgeSprite*		m_spr;
	bool			m_bInSence;
	bool			m_bDrag;

};