#pragma once
template<class T> void Delete(T& t)
{
	if (t)
	{
		delete t;
		t = 0;
	}
}

struct Pos
{
	Pos():x(0),y(0){}
	Pos(float _x,float _y):x(_x),y(_y){}
	bool operator == (const Pos& pos)const//Ô¼µÈ
	{
		return (abs(x-pos.x) < 0.1f && abs(y-pos.y) < 0.1f);
	}
	float x;
	float y;
};

