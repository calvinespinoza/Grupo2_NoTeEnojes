#include "Pieza.h"
#include "PiezaAmarilla.h"
#include "PiezaVerde.h"
#include "PiezaAzul.h"
#include "PiezaRoja.h"

#include <string>
#include <iostream>
#include <random>

using namespace std;

void imprimirMatriz(char**, int);
char** inicializarMatriz(int);
int tirarDado();

int main()
{
	int size = 15;
	int opcion1 = 0, opcion2 = 0;
	char** mat = NULL;
	mat = inicializarMatriz(size);

	Pieza* pieza1;
	Pieza* pieza2;

	do {
		cout << "JUGADOR 1" << endl
		<< "Elegir color de tu pieza: " << endl
		<< "1. Azul\n2. Rojo\n3. Verde\n4. Amarillo\n";
		cin >> opcion1;
	} while(opcion1 < 1 || opcion1 > 4);

	bool ask = false;
	do {
		cout << "JUGADOR 2" << endl
		<< "Elegir color de tu pieza: " << endl;
		if (opcion1 == 1)
		{
			pieza1 = new PiezaAzul(14, 14, "Azul");
			cout << "1. Rojo\n2. Verde\n3. Amarillo\n";
			cin >> opcion2;
			if (opcion2 == 1)
			{
				pieza2 = new PiezaRoja(0, 14, "Roja");
			}
			else if (opcion2 == 2)
			{
				pieza2 = new PiezaVerde(0, 0, "Verde");
			}
			else if (opcion2 == 3)
			{
				pieza2 = new PiezaAmarilla(14, 0, "Amarillo");
			}
			else
			{
				ask = true;
			}

		}
		else if (opcion1 == 2)
		{
			pieza1 = new PiezaRoja(0, 14, "Roja");
			cout << "1. Azul\n2. Verde\n3. Amarillo\n";
			cin >> opcion2;
			if (opcion2 == 1)
			{
				pieza2 = new PiezaAzul(14, 14, "Azul");
			}
			else if (opcion2 == 2)
			{
				pieza2 = new PiezaVerde(0, 0, "Verde");
			}
			else if (opcion2 == 3)
			{
				pieza2 = new PiezaAmarilla(14, 0, "Amarillo");
			}
			else
			{
				ask = true;
			}
		}
		else if (opcion1 == 3)
		{
			pieza1 = new PiezaVerde(0, 0, "Verde");
			cout << "1. Azul\n2. Rojo\n3. Amarillo\n";
			cin >> opcion2;
			if (opcion2 == 1)
			{
				pieza2 = new PiezaAzul(14, 14, "Azul");
			}
			else if (opcion2 == 2)
			{
				pieza2 = new PiezaRoja(0, 14, "Roja");
			}
			else if (opcion2 == 3)
			{
				pieza2 = new PiezaAmarilla(14, 0, "Amarillo");
			}
			else
			{
				ask = true;
			}
		} else if (opcion1 == 4)
		{
			pieza1 = new PiezaAmarilla(14, 0, "Amarillo");
			cout << "1. Azul\n2. Rojo\n3. Verde\n";
			cin >> opcion2;
			if (opcion2 == 1)
			{
				pieza2 = new PiezaAzul(14, 14, "Azul");
			}
			else if (opcion2 == 2)
			{
				pieza2 = new PiezaRoja(0, 14, "Roja");
			}
			else if (opcion2 == 3)
			{
				pieza2 = new PiezaVerde(0, 0, "Verde");
			}
			else
			{
				ask = true;
			}
		}

	} while(ask);


	int one = pieza1 -> getPosX();
	int two = pieza1 -> getPosY();
	int three = pieza2 -> getPosX();
	int four = pieza2 -> getPosY();

	string uno = pieza1 -> getColor();

	cout << one << endl << two << endl << three << endl << four << endl;

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
			else if (i == pieza1 -> getPosX() && j == pieza1 -> getPosY())
				mat[i][j] = '1';
			else if (i == pieza2 -> getPosX() && j == pieza2 -> getPosY())
				mat[i][j] = '2';
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
	int resp;

	srand(time(NULL));
    resp = rand() % 6 + 1;
    cout << "El numero que salio es: " << resp << "!\n";

	return resp;
}