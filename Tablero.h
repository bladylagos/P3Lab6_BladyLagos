#ifndef TABLERO_H
#define TABLERO_H
#define EASY 8
#define NORMAL 16
#define HARD 30
#define EASY_B 10
#define NORMAL_B 40
#define HARD_B 99

#include "CasillaBuscaMinas.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
class Tablero{
	public:
    Tablero(int diff = 0);
    ~Tablero();
    void rellenaBombas(int fila_inicial, int columna_inicial);
    void calcularBombas(int f, int c);
    void mostrarTableroOculto() const;
    void mostrarTableroVisible() const;
    void mostrarBombas() const;
    bool desvelarCasilla(int f, int c);
    void colocarBandera(int f, int c);
    void quitarBandera(int f, int c);
    void revelarCeros(int f, int c);
    bool haGanado();
    inline int getFila() const{ 
	return filas; 
	}
    inline int getColumna() const { 
	return columnas; 
	}
	
	private:
    char** oculto;
    bool** visible;
    int columnas, filas;
    int descubiertas;
    int n_bombas;
    CasillaBuscaMinas banderas; 
    void reservarMemoria(int diff); // 0-> facil , 1 -> normal, 2-> dificil
    void liberar();
    void hacerVisible(int f, int c);

};

#endif