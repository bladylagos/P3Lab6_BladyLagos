#ifndef CASILLABUSCAMINAS_H
#define CASILLABUSCAMINAS_H
#include "BuscaMinas.h"

class CasillaBuscaMinas
{
	public:
		CasillaBuscaMinas();
		~CasillaBuscaMinas();
		void reservarMemoria(int n);
		void liberar();
		void redimensionar(int n);
    	void add(const BuscaMinas &nuevo);
    	void eliminar(const BuscaMinas &nuevo);
    	int estaEnLista(const BuscaMinas &punto);
    	BuscaMinas & getPunto(int pos);
    	inline int getNumPunto(){ 
		return Bomba; 
		}
	private:
		BuscaMinas * lista;
		int Bomba;
		bool descubierta;
		char display;
		bool marcada;
};

#endif