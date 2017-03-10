#include "PiezaVerde.h"

PiezaVerde::PiezaVerde()
{
	posx = 0;
	posy = 0;
	color = "";
}

PiezaVerde::PiezaVerde(int pPosx, int pPosy, string pColor) : Pieza(pPosx, pPosy, pColor)
{
	posx = pPosx;
	posy = pPosy;
	color = pColor;
}
string PiezaVerde::getColor()
{
	return color;
}

void PiezaVerde::setColor(string pColor)
{
	color = pColor;
}

PiezaVerde::~PiezaVerde
{

}
