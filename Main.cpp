#include "Pieza.h"
#include "PiezaAmarilla.h"
#include "PiezaVerde.h"
#include "PiezaAzul.h"
#include "PiezaRoja.h"

#include <string>
#include <iostream>

using namespace std;

void imprimirMatriz(int**, int);
int** inicializarMatriz(int);

int main()
{
	char** mat = NULL;
	mat = inicializarMatriz(15);

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {

		}
	}
	return 0;
}

void imprimirMatriz(char** mat, int size){
	for(int i = 0; i < 3; i++)
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
		matriz[i] = new char['o'];
	}
	return matriz;
}
