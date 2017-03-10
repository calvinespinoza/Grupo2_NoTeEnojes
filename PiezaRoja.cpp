#include "PiezaRoja.h"

PiezaRoja::PiezaRoja() {
}

PiezaRoja::PiezaRoja(int pposX, int pposY, string pcolor) : Pieza(pposX, pposY, pcolor) {
}

PiezaRoja::~PiezaRoja() {
}

void PiezaRoja::setColor(string pColor)
{
	color = pColor;
}

string PiezaRoja::getColor()
{
	return color;
}