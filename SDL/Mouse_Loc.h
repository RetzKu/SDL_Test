#pragma once
class Mouse_Loc
{
public:
	Mouse_Loc(int x, int y) { x = _x, y = _y; }
	Mouse_Loc();
	~Mouse_Loc();

	void Collision();

	void y(int y){_y = y;}
	void x(int x){_x = x;}
	void Box();

private:
	int _y;
	int _x;
};

