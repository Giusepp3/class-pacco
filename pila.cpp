#include "pila.h"

using namespace std;

namespace posta{
	
	pila::pila(){
		l=0;
		sz=0;
	}
	
	pila::pila(const int dim){
		l = 0;
		sz = dim;
	}
	
	bool pila::push(const T & elem){
		if(!full()){
		Nodo* node = new Nodo;
		node->elem=elem;
		node->next = l;
		l=q;
		sz++;
		}
		
		return !full();
		
	}
	
	bool pila::pop(T & elem){
		if(empty()) return false;
		Nodo* node = l;
		elem = l->elem;
		l=l->next; //aggiorno la testa della lista
		delete node; //elimino la testa precedente
		return true;
 	}
 	
 	bool pila::top(T & elem)const{
 		elem=l->elem;
 		return true;
	 }
	 
	 







}
