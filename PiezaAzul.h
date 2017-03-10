#include "Pieza.h"
#include <string>
#ifndef PIEZAAZUL_H
#define PIEZAAZUL_H

using namespace std;

class PiezaAzul : public Pieza 
{

	private:

	public:
		PiezaAzul();
		PiezaAzul(int, int, string);
		~PiezaAzul();
		virtual string getColor();
		virtual void setColor(string);

};

#endif