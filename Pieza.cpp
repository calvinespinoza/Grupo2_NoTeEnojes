#include "Pieza.h"

Pieza::Pieza()
{
	posx = 0;
	posy = 0;
	color = "";
}

Pieza::Pieza(int pPosx, int pPosy, string pColor)
{
	posx = pPosx;
	posy = pPosy;
	color = pColor;
}

int Pieza::getPosX()
{
	return posx;
}

int Pieza::getPosY()
{
	return posy;
}

/*string Pieza::getColor()
{
	return color;
}*/

void Pieza::setPosX(int pPosx)
{
	posx = pPosx;
}

void Pieza::setPosY(int pPosy)
{
	posy = pPosy;
}

/*void Pieza::setColor(string pColor)
{
	color = pColor;
}*/

Pieza::~Pieza()
{
	
}
