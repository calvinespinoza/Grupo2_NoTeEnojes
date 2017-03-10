#ifndef PIEZA_H
#define PIEZA_H
#include <string>

using namespace std;

class Pieza
{

	private:
		int posx;
		int posy;
		string color;


	public:
		Pieza();
		Pieza(int, int, string);
		~Pieza();
};

#endif