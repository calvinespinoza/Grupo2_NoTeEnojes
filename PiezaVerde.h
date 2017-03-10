#pragma once
#include "Pieza.h"

using namespace std;

class PiezaVerde : public Pieza {
private:


public:
	PiezaVerde();
	PiezaVerde(int, int, string);

	virtual string getColor();
	virtual void setColor(string);

	~PiezaVerde ();
};
