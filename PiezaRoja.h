#include "Pieza.h"
#include <string>
#ifndef PIEZAROJA_H
#define PIEZAROJA_H

using namespace std;

class PiezaRoja : public Pieza 
{

	private:

	public:
		PiezaRoja();
		PiezaRoja(int, int, string);
		~PiezaRoja();
		virtual string getColor();
		virtual void setColor(string);

};

#endif