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
		l=node;
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
	 
	 
	 void pila::salva_bin(const char* filebin)const throw(err){
	 	Nodo* temp;
	 	temp=l;
	 	while(temp){
	 		temp->elem.save_bin(filebin);
	 		temp=temp->next;
		 }
	 }


	void pila::leggi_bin(const char* filebin) throw(err){
		T e;
		while(!full()){
			e.read_bin(filebin);
			push(e);
		}
		
	}




}
