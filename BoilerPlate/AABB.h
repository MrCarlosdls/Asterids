#pragma once

#include <iostream>

class AABB
{
public:
	//CTOR
	AABB();
	AABB(int x, int y, int width, int heigth);

	//COLLITION TEST FUNTION 
	bool isIntersecting(AABB* rhs);

	//GETTERS
	int GetX();
	int GetY();
	int GetWidth();
	int GetHeight();

	//FUNTIONS FOR DRAWING THE AABB
	int GetMinX();
	int GetMinY();
	int GetMaxX();
	int GetMaxY();
	
	//SETTERS
	int SetX(int value);
	int SetY(int value);

	//UPDATE FUNTION FOR AABB
	void Update(int x, int y);

private:
	//MEMBERS 
	int m_x;
	int m_y;
	int m_width;
	int m_height;
};