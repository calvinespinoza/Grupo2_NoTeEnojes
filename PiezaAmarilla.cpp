#include "PiezaAmarilla.h"

PiezaAmarilla::PiezaAmarilla()
{

}

PiezaAmarilla::PiezaAmarilla(int pPosx, int pPosy, string pColor)
{
	posx = pPosx;
	posy = pPosy;
	color = pColor;
}
string PiezaAmarilla::getColor()
{
	return color;
}

void PiezaAmarilla::setColor(string pColor)
{
	color = pColor;
}

PiezaAmarilla::~PiezaAmarilla
{

}
