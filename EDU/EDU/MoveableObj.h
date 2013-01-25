#pragma once
#include "Object.h"
#include <hgevector.h>


/*
**可移动物体，根据方向和速度进行移动
*/

class CMoveableObj : public CObject
{
public:
	CMoveableObj(hgeResourceManager* rs);
	virtual ~CMoveableObj();

	virtual bool Init() = 0;
	virtual void Render() = 0;
	virtual void Update(float dt);
	virtual void Cleanup() = 0;

	bool		IsMoving()const			{return	 m_bMoving;}
	float		GetSpeed()const			{return  m_speed;}
	hgeVector*	GetDirVect()			{return  &m_movingDir;}
	void		SetDir(float dir)			{m_movingDir.Rotate(dir-m_movingDir.Angle());}
	void		SetMoveSate(bool isMove)	{m_bMoving = isMove;}

protected:
	hgeVector	m_movingDir;//移动方向向量
	float		m_speed;
	bool		m_bMoving;
};