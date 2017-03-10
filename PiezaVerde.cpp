#include "PiezaVerde.h"

PiezaVerde::PiezaVerde()
{

}

PiezaVerde::PiezaVerde(int pPosx, int pPosy, string pColor)
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
