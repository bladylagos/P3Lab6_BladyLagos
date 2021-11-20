#include "CasillaBuscaMinas.h"
#include <iostream>
using namespace std;

void CasillaBuscaMinas::reservarMemoria(int n) {
    liberar();
    if (n > 0) {
        lista = new BuscaMinas [n];
        Bomba = n;
    } else {
        lista = nullptr;
        Bomba = 0;
    }
}
void CasillaBuscaMinas::liberar() {
    if (lista != nullptr) {
        delete [] lista;
    }
    lista = nullptr;
    Bomba = 0;
}

void CasillaBuscaMinas::redimensionar(int n) {
    if (n > Bomba) {
        BuscaMinas * nuevo = new BuscaMinas [n];
        for (int i = 0; i < Bomba; i++)
            nuevo[i] = lista[n];
        delete [] lista;
        lista = nuevo;
        Bomba = n;
    }
}

CasillaBuscaMinas::CasillaBuscaMinas() {
    reservarMemoria(0);
}

CasillaBuscaMinas::~CasillaBuscaMinas() {
    liberar();
}

void CasillaBuscaMinas::add(const BuscaMinas& nuevo) {
    if (estaEnLista(nuevo) == -1) {
        redimensionar(Bomba + 1);
        lista[Bomba - 1] = nuevo;
        cout << "añadidos hasta ahora" << endl;
        for (int i = 0; i < Bomba; i++)
            cout << lista[i].getX() << lista[i].getY() << endl;
    }
}

void CasillaBuscaMinas::eliminar(const BuscaMinas& nuevo) {
    int pos = estaEnLista(nuevo);
    if (pos != -1) {
        BuscaMinas * nuevo = new BuscaMinas [Bomba - 1];
        for (int i = pos; i < Bomba - 1; i++)
            lista[i] = lista[i++];
        for (int i = 0; i < Bomba - 1; i++)
            nuevo[i] = lista[i];
        delete [] lista;
        lista = nuevo;
        Bomba--;
    }
}

int CasillaBuscaMinas::estaEnLista(const BuscaMinas& punto) {
    int posicion = -1;
    for (int i = 0; i < Bomba && posicion == -1; i++) {
        /*if (getPunto(i) == punto){
		
		} */  
		 posicion = i;
    }
    return posicion;
}

BuscaMinas & CasillaBuscaMinas::getPunto(int pos){
    BuscaMinas backup;
    backup.setX(0); backup.setY(0);
    if (pos >= 0 && pos < Bomba) {
        backup.setX(lista[pos].getX()); 
        backup.setY(lista[pos].getY());
    }
    else
        return backup;
}