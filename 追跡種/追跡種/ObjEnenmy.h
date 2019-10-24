#pragma once
#include""
using namespace GameL;

class CObjEnenmy :public CObj
{
public:
	CObjEnenmy() {};
	~CObjEnenmy() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_px;
	float m_py;
	float m_vx;
	float m_vy;
};