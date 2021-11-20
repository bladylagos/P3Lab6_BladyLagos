#include <iostream>
#include "CasillaBuscaMinas.h"
#include "Tablero.h"
#include "BuscaMinas.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int menu();

using namespace std;

int main() {//int argc, char** argv

	int opcion = menu();
	while (opcion != 2){
		switch (opcion){
			case 1:{	
				int dificultad = -1;
				int fila = 0, columna = 0;

				do
				{
					
					cout << "* * * * * * Seleccione La Dificultad * * *  *" << endl;
					cout << "*	1. Facil			    *" << endl;
					cout << "*	2. Normal			    *" << endl;
					cout << "*	3. Dificil			    *" << endl;
					cout << "* * * * * * * * * * * * * * * * * * * * * * *"<< endl;		
					cin >> dificultad;
					
				} while (dificultad != 1 && dificultad != 2 && dificultad != 3);
			

				Tablero jugar(dificultad - 1);
				jugar.mostrarTableroOculto();
				cout << "Elije la fila y columna a desvelar\nFila: ";
				cin >> fila;
				cout << "Columna: ";
				cin >> columna;
				jugar.rellenaBombas(fila, columna);
				jugar.mostrarTableroVisible();
				jugar.desvelarCasilla(fila, columna);
				jugar.mostrarTableroOculto();
			
				do
				{
				while (fila >= 0 && fila < jugar.getFila() && columna >=0 && columna < jugar.getColumna()){
					cout << "Elije la fila y columna a desvelar\nFila: ";
					cin >> fila;
					cout << "Columna: ";
					cin >> columna;
					if (fila >= 0 && fila < jugar.getFila() && columna >= 0 && columna < jugar.getColumna()) {
						jugar.mostrarTableroVisible();
						jugar.desvelarCasilla(fila, columna);
						jugar.mostrarTableroOculto();
					}	
				}

				} while (jugar.desvelarCasilla(fila, columna) && !jugar.haGanado());
			
				CasillaBuscaMinas lista;
				BuscaMinas aux;
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 5; j++) {
						aux.setX(i); aux.setY(j);
						lista.add(aux);
					}
				}

				for (int i = 0; i < lista.getNumPunto(); i++)
					cout << lista.getPunto(i).getX() << " " << lista.getPunto(i).getY() << endl;
					cout << endl << endl;
					
				break;
			}
		}
		cout <<endl; 
		opcion = menu(); 		
	}		
	return 0;
}

int menu(){
	int opcion = 0; 
	while (opcion != 2){
		cout << "\n";
		cout << "* * * * *  * * MENU * * * * * * *" <<endl;
		cout << "*	1) Jugar 		*"<<endl;
		cout << "*	2) Salir      		*" <<endl; 
		cout << "* * * * * * * * * * * * * * * * *" <<endl; 
		cout << " Ingrese la opcion que desee: " <<endl; 
		cin>> opcion; 
		cout << "\n";
		if (opcion == 2){
			cout << "\n";
			cout << "Ha elegido salir del sistema" <<endl; 
		}else if (opcion > 0 && opcion < 2){
			break; 
		}
	}
	return opcion; 
}