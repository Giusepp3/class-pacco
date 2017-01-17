#ifndef PILA_H
#define PILA_H
#include <iostream>
#include <cstring>
#include <fstream>
#include "errore.h"
#include "class_pacco.h"

using namespace std;
namespace posta{
	
	typedef pacco T;
	
	struct Nodo; //predichiarazione
	
	struct {
		Nodo* next;
		T elem;
	};
	
	class pila{
		private:
			Nodo* l;
			int sz;
		public:
			pila();
			pila(const int);
			bool push(const T &);
			bool pop(T &);
			bool top(t &) const;
			bool empty(){return sz==0;}
			bool full(){return false;}
			void leggi_bin(const char*)throw(err);
			void salva_bin(const char*)const throw(err);
			void leggi_txt(const char*)throw(err);
			void salva_txt(const char*)const throw(err);
			
	};
	
	
	
	
	
	
}

#endif //PILA_H
