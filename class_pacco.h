#ifndef PACCO_H
#define PACCO_H
#include <iostream>
#include <cstring>
#include <fstream>
#include "errore.h"

using namespace std;

namespace posta{

	class pacco{
		private:
			int codice;
			float peso;
			char* indirizzo;
			void set_cod(const int);
			void set_pes(const float);
			void set_ind(const char*);
			void read(istream & in);
			void print(ostream & of)const;
			void w_ind(ofstream & of)const;
		public:
			pacco();
			pacco(const int, const float, const char*);
			pacco(const pacco &);
			pacco& operator=(const pacco &);
			void save_bin(const char*)const throw(err);
			void save_txt(const char*)const throw(err);
			int get_cod()const{return codice;}
			float get_pes()const{return peso;}
			char* get_ind()const{return indirizzo;}
			friend istream & operator>>(istream & in, pacco &);
			friend ostream & operator<<(ostream & os, const pacco &);
			void edit_package(const int cod, const float f, const char* ind); //le funzioni set sono private, questa consente di modificare il pacco
			void read_txt(const char*)throw(err);
			void read_bin(const char*)throw(err);
	};
	
	
	
	
	
}

#endif //PACCO_H
