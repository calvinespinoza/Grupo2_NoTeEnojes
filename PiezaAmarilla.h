#pragma once
#include "Pieza.h"

using namespace std;

class PiezaAmarilla : public Pieza {
private:


public:
	PiezaAmarilla();
	PiezaAmarilla(int, int, string);

	virtual string getColor();
	virtual void setColor(string);

	~PiezaAmarilla ();
};
