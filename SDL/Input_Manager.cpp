#include "Input_Manager.h"




mouse_Pos::mouse_Pos(int x, int y)
{
}

mouse_Pos::~mouse_Pos()
{
	
}


void mouse_Pos::Get_M_Location(int x, int y)
{
	_x = x;
	_y = y;
}
void mouse_Pos::Box(int start_x,int start_y, int Width, int Height)
{
	if (_x > start_x && _y > start_y && _x < Width + start_x && _y < Height + start_y)
	{
		std::cout << "within range: ";
	}
}

