#include "AI.h"
#include "SceneManager.h"
#include "Utilities.h"
#include <algorithm>

using namespace std;


CSceneManager::CSceneManager() :
m_pBG(0),
m_pCamera(0),
m_pHge(0),
m_pGUI(0)
{
	m_pHge = hgeCreate(HGE_VERSION);
}

bool CSceneManager::Init()
{
	if(m_pHge->Resource_AttachPack("res.dat"))printf("LoadPack Success!\n");
	else printf("LoadPack Fail!Try To Load From File...\n");
	m_pRs = new hgeResourceManager(SCRIPTNAME);
	m_pRs->Precache();
	m_pCamera = new C2DCamera();
	m_pBG = m_pRs->GetSprite("Fence");
	if(!m_pBG)return false;

	m_pGUI = new hgeGUI();
	m_pGUI->SetCursor(m_pRs->GetSprite("Cursor"));

	for(int i = 0;i < 5; i ++)
	{
		AddPet("pachi",Pos(500,300+5*i));
		AddPet("reimu",Pos(500,320+5*i));
		AddPet("youmu",Pos(500,330+5*i));
	}
	CItem* item = new CItem(m_pRs, "item");
	item->Init();
	item->SetPos(Pos(500,200));
	m_objs.push_back(item);

	printf("Init Success!\n");
	return true;
}

void CSceneManager::AddPet(char* name, Pos pos)
{
	m_pPetAi = new CAi();
	CObject* obj = new CPet(m_pRs, name, m_pPetAi);
	obj->Init();
	obj->SetPos(pos);
	m_objs.push_back(obj);
}


void CSceneManager::Cleanup()
{
	for_each(m_objs.begin(), m_objs.end(), CleanFunc());
	Delete(m_pPetAi);
	m_objs.clear();
	Delete(m_pCamera);
	Delete(m_pRs);
}

bool CSceneManager::Update(float dt)
{
	PETS* pets=CPet::GetPets();
	for(PETS_ITR itr = pets->begin();itr != pets->end();itr ++)
	{
		for(PETS_ITR itr2 = itr + 1;itr2 != pets->end();itr2 ++)
		{
			CollisionMove((*itr)->GetPos(),(*itr2)->GetPos(),(*itr)->GetRect(),(*itr2)->GetRect(),dt*50);
		}
	}
	for_each(m_objs.begin(), m_objs.end(), UpdateFunc(dt));
	m_pGUI->Update(dt);

	sort(m_objs.begin(), m_objs.end(), CompareByY());
	return false;
}

Pos  CSceneManager::GetMousePos()
{
	Pos tmp;
	m_pHge->Input_GetMousePos(&tmp.x, &tmp.y);
	m_pCamera->MouseCorrect(&tmp.x, &tmp.y);
	return tmp;
}




//////////////////////////////////////////
//Render
/////////////////////////////////////////
void CSceneManager::Render()
{
	m_pBG->Render((SCREEN_WIDTH-m_pBG->GetWidth())/2, (SCREEN_HEIGHT-m_pBG->GetHeight())/2);
	for_each(m_objs.begin(), m_objs.end(), RendFunc());
	m_pGUI->Render();
	hgeFont* font = m_pRs->GetFont("GameFont");
	font->printf(5, 5, HGETEXT_LEFT, "FPS:%d ", m_pHge->Timer_GetFPS());

	NumRender(font, (*CPet::GetPets())[0]);
}