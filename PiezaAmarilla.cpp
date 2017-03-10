#include "PiezaAmarilla.h"

PiezaAmarilla::PiezaAmarilla()
{
	posx = 0;
	posy = 0;
	color = "";
}

PiezaAmarilla::PiezaAmarilla(int pPosx, int pPosy, string pColor) : Pieza(pPosx, pPosy, pColor)
{
}

string PiezaAmarilla::getColor()
{
	return color;
}

void PiezaAmarilla::setColor(string pColor)
{
	color = pColor;
}

PiezaAmarilla::~PiezaAmarilla()
{

}
