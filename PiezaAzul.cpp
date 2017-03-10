#include "PiezaAzul.h"

PiezaAzul::PiezaAzul() {
}

PiezaAzul::PiezaAzul(int pposX, int pposY, string pcolor) : Pieza(pposX, pposY, pcolor) {
}

PiezaAzul::~PiezaAzul() {
}

void PiezaAzul::setColor(string pColor)
{
	color = pColor;
}

string PiezaAzul::getColor()
{
	return color;
}