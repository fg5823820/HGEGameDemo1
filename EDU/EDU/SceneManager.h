#pragma once 
#include "StdAfx.h"
#include "Camera.h"
#include "Pet.h"
#include "Item.h"

typedef std::vector<CObject*>			OBJECTS;
typedef std::vector<CObject*>::iterator OBJ_ITR;


class CSceneManager
{
public:
	CSceneManager();
	~CSceneManager(){m_pHge->Release();}

	bool Init();
	void Render();
	bool Update(float);
	void Cleanup();

private:
	void AddPet(char* name, Pos pos);
	Pos  GetMousePos();

private:
	hgeGUI*		m_pGUI;
	hgeSprite*	m_pBG;
	C2DCamera*	m_pCamera;
	CAi*		m_pPetAi;


	OBJECTS		m_objs;
	hgeResourceManager* m_pRs;
	HGE*		m_pHge;

};


