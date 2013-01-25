#pragma once
#include "stdafx.h"


struct CompareByY;

class CObject
{
public:
	CObject(hgeResourceManager* rs);
	virtual ~CObject(){m_pHge->Release();}

private:
	// 新建对象ID
	inline UINT NewID(){ static UINT id = 0;return ++id; }

public:
	virtual bool Init() = 0;
	virtual void Render() = 0;
	virtual void Update(float) = 0;
	virtual void Cleanup() = 0;

public:
	// 获取对象ID
	inline UINT		GetID() const	{	return m_uID;	}
	// 获取对象名称
	inline char*	GetName() const	{	return m_name;	}
	// 获取对象位置
	inline Pos*		GetPos() 		{	return &m_pos;	}
	// 获取区域
	inline hgeRect* GetRect() 		{	return &m_rect;	}
	// 设置对象ID
	inline void		SetID(UINT id)				{	m_uID = id;		}
	// 设置对象名称
	inline void		SetName(char* name)			{	m_name = name;	}
	// 设置对象位置
	inline void		SetPos(const Pos& pos)		{	m_pos = pos;	}
	// 设置区域
	inline void		SetRect(const hgeRect& rect){	m_rect = rect;	}

	friend CompareByY;

protected:
	UINT	  m_uID;		// 对象ID
	char*	  m_name;		// 对象名称
	Pos		  m_pos;		// 位置
	hgeRect	  m_rect;		// 区域范围
	float	  m_width,m_height;

	hgeResourceManager*	m_pRs;

protected:
	static HGE* m_pHge;
};

struct CompareByY
{
	CompareByY(){}
	bool operator()(CObject* lhs, CObject *rhs)const
	{return lhs->m_pos.y < rhs->m_pos.y;}
};


struct RendFunc
{
	RendFunc(){}
	void operator()(CObject *obj)const
	{obj->Render();}
};

struct UpdateFunc
{
	UpdateFunc(float _dt){dt = _dt;}
	void operator()(CObject *obj)const
	{obj->Update(dt);}
	float dt;
};


struct CleanFunc
{
	CleanFunc(){}
	void operator()(CObject *obj)const
	{obj->Cleanup();Delete(obj);}
};










