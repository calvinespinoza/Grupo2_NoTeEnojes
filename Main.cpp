#include "Pieza.h"
#include "PiezaAmarilla.h"
#include "PiezaVerde.h"
#include "PiezaAzul.h"
#include "PiezaRoja.h"

#include <string>
#include <iostream>

using namespace std;

void imprimirMatriz(char**, int);
char** inicializarMatriz(int);
int tirarDado();

int main()
{
	int size = 15;
	char** mat = NULL;
	mat = inicializarMatriz(size);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == 0 || i == 14|| j == 0 || j == 14)
				mat[i][j] = 'x';
			else if (i == 7 && j == 7)
				mat[i][j] = 'o';
			else if (i == 7 && j < 7)
				mat[i][j] = '$';
			else if (i < 7 && j == 7)
				mat[i][j] = '%';
			else if (i == 7 && j > 7)
				mat[i][j] = '/';
			else if (i > 7 && j == 7)
				mat[i][j] = '#';
			else
				mat[i][j] = ' ';
		}
	}


	imprimirMatriz(mat, size);
	return 0;

}

void imprimirMatriz(char** mat, int size){
	for(int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << " " << mat[i][j];
		}
		cout << endl;
	}
}

char** inicializarMatriz(int size){

	char** matriz = new char*[size];

	for (int i = 0; i < size; i++)
	{
		matriz[i] = new char[size];
	}
	return matriz;
}

int tirarDado()
{
	
}
