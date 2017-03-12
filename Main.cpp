#include "Pieza.h"
#include "PiezaAmarilla.h"
#include "PiezaVerde.h"
#include "PiezaAzul.h"
#include "PiezaRoja.h"

#include <string>
#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

void imprimirMatriz(char**, int);
char** inicializarMatriz(int);
int tirarDado1();
int tirarDado2();
int tirarDado3();
int tirarDado4();

int main()
{
	int size = 15;
	srand(time(NULL));
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


	int x1 = pieza1 -> getPosX();
	int y1 = pieza1 -> getPosY();
	int x2 = pieza2 -> getPosX();
	int y2 = pieza2 -> getPosY();
	int vuelta1 = 0;
	int vuelta2 = 0;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == pieza1 -> getPosX() && j == pieza1 -> getPosY())
				mat[i][j] = '1';
			else if (i == pieza2 -> getPosX() && j == pieza2 -> getPosY())
				mat[i][j] = '2';
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
			else if (i == 0 || i == 14|| j == 0 || j == 14)
				mat[i][j] = 'x';
			else
				mat[i][j] = ' ';
		}		
	}
	imprimirMatriz(mat, size);

	cout << endl;
	bool continueP = true;
	string ganador;

	int dice1;
	int dice2;
	int cont1 = 0, cont2 = 0;
	int win1 = 0, win2 = 0;
	string stop;
//	while (win1 < 4 && win2 < 4) {
		continueP = true;
		while (continueP == true) {
			cout << "JUGADOR 1: " << win1 << endl;
			cout << "JUGADOR 2: " << win2 << endl;
			cout << "JUGADOR 1\nIngrese una letra para seguir: " << endl;
			cin >> stop;
			dice1 = rand() % 6 + 1;
			cout << "DADO 1: El numero que salio es: " << dice1 << "!\n";
			dice2 = rand() % 6 + 1;
			cout << "DADO 2: El numero que salio es: " << dice2 << "!\n";
			if ((dice1 == 6 && dice2 == 6 && cont1 == 0) || (dice1 == 1 && dice2 == 1 && cont1 == 0) || cont1 > 0) {
				cont1++;
				if (cont1 > 1) {
					for (int k = 0; k < (dice1 + dice2); k++) {
						if (x1 == 0 && (y1 > 0 || y1 == 14)) { //Izquierda
							if(y1 == 7) {
								mat[x1][y1] = 'x';
								y1--;
								pieza1 -> setPosY(y1);
								mat[x1][y1] = '1';
								vuelta1++;
							} else {
								mat[x1][y1] = 'x';
								y1--;
								pieza1 -> setPosY(y1);
								mat[x1][y1] = '1';
							}
						} else if ((x1 == 0 || x1 < 14) && y1 == 0){ //Abajo
							if (x1 == 7)
							{
								mat[x1][y1] = 'x';
								x1++;
								pieza1 -> setPosX(x1);
								mat[x1][y1] = '1';
								vuelta1++;
							} else {
								mat[x1][y1] = 'x';
								x1++;
								pieza1 -> setPosX(x1);
								mat[x1][y1] = '1';
							}
						} else if (x1 == 14 && (y1 == 0 || y1 < 14)){ //Derecha
							if (y1 == 7)
							{
								mat[x1][y1] = 'x';
								y1++;
								pieza1 -> setPosY(y1);
								mat[x1][y1] = '1';
								vuelta1++;
							} else {
								mat[x1][y1] = 'x';
								y1++;
								pieza1 -> setPosY(y1);
								mat[x1][y1] = '1';
							}
						} else if ((x1 == 14 || x1 > 0) && y1 == 14){ //Arriba
							if (x1 == 7)
							{
								mat[x1][y1] = 'x';
								x1--;
								pieza1 -> setPosX(x1);
								mat[x1][y1] = '1';
								vuelta1++;
							} else {
								mat[x1][y1] = 'x';
								x1--;
								pieza1 -> setPosX(x1);
								mat[x1][y1] = '1';
							}
						}

						if (pieza1 -> getColor() == "Azul") {
							if (x1 == 7 && vuelta1 == 4)
							{
								mat[x1][y1] = '/';
								y1--;
								pieza1 -> setPosY(y1);
								mat[x1][y1] = '1';
								if (x1 == 7 && y1 == 7)
								{
									k = dice1 + dice2;
									continueP = false;
									ganador = "El ganador es el jugador 1, con el color: " + pieza1 -> getColor() + "\n";
									win1++;
								}
							}
						}
						if (pieza1 -> getColor() == "Roja") {
							if (y1 == 7 && vuelta1 == 4)
							{
								mat[x1][y1] = '%';
								x1++;
								pieza1 -> setPosX(x1);
								mat[x1][y1] = '1';
								if (x1 == 7 && y1 == 7)
								{
									k = dice1 + dice2;
									continueP = false;
									ganador = "El ganador es el jugador 1, con el color: " + pieza1 -> getColor() + "\n";
									win1++;
								}
							}
						}
						if (pieza1 -> getColor() == "Verde") {
							if (x1 == 7 && vuelta1 == 4)
							{
								mat[x1][y1] = '$';
								y1++;
								pieza1 -> setPosY(y1);
								mat[x1][y1] = '1';
								if (x1 == 7 && y1 == 7)
								{
									k = dice1 + dice2;
									continueP = false;
									ganador = "El ganador es el jugador 1, con el color: " + pieza1 -> getColor() + "\n";
									win1++;
								}
							}
						}
						if (pieza1 -> getColor() == "Amarillo") {
							if (y1 == 7 && vuelta1 == 4)
							{
								mat[x1][y1] = '#';
								x1--;
								pieza1 -> setPosX(x1);
								mat[x1][y1] = '1';
								if (x1 == 7 && y1 == 7)
								{
									k = dice1 + dice2;
									continueP = false;
									ganador = "El ganador es el jugador 1, con el color: " + pieza1 -> getColor() + "\n";
									win1++;
								}
							}
						}
					}
				}
			} else {
				cout << endl << "DEBE SACAR SEIS O UNOS DOBLES" << endl << "NO HUBO MOVIMIENTO" << endl;
			}
				imprimirMatriz(mat, size);

				cout << "JUGADOR 1: " << win1 << endl;
				cout << "JUGADOR 2: " << win2 << endl;
			cout << "JUGADOR 2\nIngrese una letra para seguir: " << endl;
			cin >> stop;
			dice1 = rand() % 6 + 1;
			cout << "DADO 1: El numero que salio es: " << dice1 << "!\n";
			dice2 = rand() % 6 + 1;
			cout << "DADO 2: El numero que salio es: " << dice2 << "!\n";
			if ((dice1 == 6 && dice2 == 6 && cont2 == 0) || (dice1 == 1 && dice2 == 1 && cont2 == 0) || cont2 > 0) {
				cont2++;
				if (cont2 > 1) {
					for (int k = 0; k < (dice1 + dice2); k++) {
						if (x2 == 0 && (y2 > 0 || y2 == 14)) { //Izquierda
							if(y2 == 7) {
								mat[x2][y2] = 'x';
								y2--;
								pieza2 -> setPosY(y2);
								mat[x2][y2] = '2';
								vuelta2++;
							} else {
								mat[x2][y2] = 'x';
								y2--;
								pieza2 -> setPosY(y2);
								mat[x2][y2] = '2';
							}
						} else if ((x2 == 0 || x2 < 14) && y2 == 0){ //Abajo
			 				if (x2 == 7)
							{
								mat[x2][y2] = 'x';
								x2++;
								pieza2 -> setPosX(x2);
								mat[x2][y2] = '2';
								vuelta2++;
							} else {
								mat[x2][y2] = 'x';
								x2++;
								pieza2 -> setPosX(x2);
								mat[x2][y2] = '2';
							}
						} else if (x2 == 14 && (y2 == 0 || y2 < 14)){ //Derecha
							if (y2 == 7)
							{
								mat[x2][y2] = 'x';
								y2++;
								pieza2 -> setPosY(y2);
								mat[x2][y2] = '2';
								vuelta2++;
							} else {
								mat[x2][y2] = 'x';
								y2++;
								pieza2 -> setPosY(y2);
								mat[x2][y2] = '2';
							}
						} else if ((x2 == 14 || x2 > 0) && y2 == 14){ //Arriba
							if (x2 == 7)
							{
								mat[x2][y2] = 'x';
								x2--;
								pieza2 -> setPosX(x2);
								mat[x2][y2] = '2';
								vuelta2++;
							} else {
								mat[x2][y2] = 'x';
								x2--;
								pieza2 -> setPosX(x2);
								mat[x2][y2] = '2';
							}
						}
						if (pieza2 -> getColor() == "Roja")
						{
							if (y2 == 7 && vuelta2 == 4)
							{
								mat[x2][y2] = '%';
								x2++;
								pieza2 -> setPosX(x2);
								mat[x2][y2] = '2';
								if (x2 == 7 && y2 == 7)
								{
									k = dice1 + dice2;
									continueP = false;
									ganador = "El ganador es el jugador 1, con el color: " + pieza2 -> getColor() + "\n";
									win2++;
								}
							}
						}
						if (pieza2 -> getColor() == "Verde")
						{
							if (x2 == 7 && vuelta2 == 4)
							{
								mat[x2][y2] = '$';
								y2++;
								pieza2 -> setPosY(y2);
								mat[x2][y2] = '2';
								if (x2 == 7 && y2 == 7)
								{
									k = dice1 + dice2;
									continueP = false;
									ganador = "El ganador es el jugador 1, con el color: " + pieza2 -> getColor() + "\n";
									win2++;
								}
							}
						}
						if (pieza2 -> getColor() == "Amarillo") {
							if (y2 == 7 && vuelta2 == 4)
							{
								mat[x2][y2] = '#';
								x2--;
								pieza2 -> setPosX(x2);
								mat[x2][y2] = '2';
								if (x2 == 7 && y2 == 7)
								{
									k = dice1 + dice2;
									continueP = false;
									ganador = "El ganador es el jugador 1, con el color: " + pieza2 -> getColor() + "\n";
									win2++;
								}
							}
						}
						if (pieza2 -> getColor() == "Azul")
						{
							if (x2 == 7 && vuelta2 == 4)
							{
								mat[x2][y2] = '/';
								y2--;
								pieza2 -> setPosY(y2);
								mat[x2][y2] = '2';
								if (x2 == 7 && y2 == 7)
								{
									k = dice1 + dice2;
									continueP = false;
									ganador = "El ganador es el jugador 1, con el color: " + pieza2 -> getColor() + "\n";
									win2++;
								}
							}
						}



					}
				}

			}

			else {
				cout << endl << "DEBE SACAR SEIS O UNOS DOBLES" << endl << "NO HUBO MOVIMIENTO" << endl;
			}

			imprimirMatriz(mat, size);
		//}
}
cout << ganador;
	//Fin while juego


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

int tirarDado1()
{
	int resp;

	srand(time(NULL));
	resp = rand() % 6 + 1;
	cout << "El numero que salio es: " << resp << "!\n";

	return resp;
}

int tirarDado2()
{
	int resp;

	srand(time(NULL));
	resp = rand() % 6 + 1;
	cout << "El numero que salio es: " << resp << "!\n";

	return resp;
}

int tirarDado3()
{
	int resp;

	srand(time(NULL));
	resp = rand() % 6 + 1;
	cout << "El numero que salio es: " << resp << "!\n";

	return resp;
}

int tirarDado4()
{
	int resp;

	srand(time(NULL));
	resp = rand() % 6 + 1;
	cout << "El numero que salio es: " << resp << "!\n";

	return resp;
}
