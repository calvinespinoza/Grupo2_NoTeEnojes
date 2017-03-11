#ifndef PIEZA_H
#define PIEZA_H
#include <string>

using namespace std;

class Pieza
{

	protected:
		int posx;
		int posy;
		string color;


	public:
		Pieza();
		Pieza(int, int, string);
		~Pieza();
		int getPosX();
		int getPosY();
		virtual string getColor() = 0;
		void setPosX(int);
		void setPosY(int);
		virtual void setColor(string) = 0;
};

#endif
