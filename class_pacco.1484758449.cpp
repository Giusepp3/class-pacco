#include "class_pacco.h"

namespace posta{
	
	
	pacco::pacco(){
		codice = 0;
		peso = 0.0;
		indirizzo = new char[1];
		strcpy(indirizzo,"");

	}
	
	pacco::pacco(const int cod, const float pes, const char* ind){
		codice = cod;
		peso = pes;
		indirizzo = new char [strlen(ind)+1];
		strcpy(indirizzo,ind);
		
	}
	
	pacco::pacco(const pacco & p){
		codice = p.codice;
		peso = p.peso;
		indirizzo = new char[strlen(p.indirizzo)+1];
		strcpy(indirizzo,p.indirizzo);
		
	}
	
	pacco & pacco::operator=(const pacco & p){
		if(this==&p) return *this;
		codice = p.codice;
		peso = p.peso;
		if(indirizzo) delete [] indirizzo;
		indirizzo = new char[strlen(p.indirizzo)+1];
		strcpy(indirizzo,p.indirizzo);
		return *this;
	}
	
	void pacco::set_cod(const int cod){
		codice = cod;
	}
	
	void pacco::set_pes(const float w){
		peso = w;
	}
	
	void pacco::set_ind(const char* ind){
		if(indirizzo) delete [] indirizzo;
		indirizzo = new char[strlen(ind)+1];
		strcpy(indirizzo,ind);
	}
	
	void pacco::edit_package(const int cod=0, const float f=0, const char* ind=""){
		if(cod) set_cod(cod);
		if(f) set_pes(f);
		if(strcmp(ind,"")) set_ind(ind);
		if(cod==0 && f==0 && strcmp(ind,"")==0){
			cout << "Inserire nella funzione i parametri corretti!!";
			//lanciare qui un eccezzione
		}
		
	}
	
	void pacco::print(ostream & os)const{
		os << codice << ' ' << peso << ' ' << indirizzo << ' ';
		
	}
	
	ostream & operator<<(ostream & os, const pacco & p){
		p.print(os);
		return os;
		
	}
	
	void pacco::read(istream & in){
		int buf;
		float buf2;
		char buf3 [600];
		//utilizzo variabili di buffer e le set (funz. private)
		//perchè se voglio implementare un controllo sulla modifica
		//mi basta cambiare le funzioni set
		in >> buf;
		set_cod(buf);
		in >> buf2;
		set_pes(buf2);
		in.ignore();
		in.getline(buf3,599);
		set_ind(buf3);
	}
	
	istream & operator>>(istream & in, pacco & p){
		p.read(in);
		return in;
	}
	
	//salva lo stato del pacco su file di testo
	void pacco::save_txt(const char* filename)const throw(err){
		ofstream of;
		of.open(filename,ios::out |ios::app);
		if(of.fail()) throw err("errore nell'apertura del file ", "posta::pacco::save_txt()");
		of << codice << ' ' << peso << ' ' << ' ' << strlen(indirizzo) << indirizzo << ' ';
		of.close();
	}
	
	
	void pacco::save_bin(const char* filebin)const throw(err){
		ofstream of;
		of.open(filebin, ios::out | ios::app | ios::binary);
		int len = strlen(indirizzo);
		if(of.fail()) throw err("errore nell'apertura del file ", "posta::pacco::save_bin()");
		of.write((char*)&codice,sizeof(codice));
		of.write((char*)&peso,sizeof(peso));
		of.write((char*)&len,sizeof(len));
		of.write(indirizzo,strlen(indirizzo));
	//	w_ind(of);	
		of.close();
		
	}
	
	void pacco::w_ind(ofstream & of)const{
		for(unsigned int i=0; i<strlen(indirizzo);i++){
			of.write((char*)&indirizzo[i],sizeof(indirizzo[i]));
		}
	}
	
	void pacco::read_txt(const char* filename)throw(err){
		ifstream in;
		in.open(filename);
		if(in.fail()) throw err("errore nell'apertura del file", "posta::pacco::read_txt()");
		int cod,len;
		float pes;
		char* ind;
		in >> cod;
		set_cod(cod);
		in >> pes;
		set_pes(pes);
		in >> len;
		ind = new char [len+1];
		in.getline(ind,len);
		set_ind(ind);
		in.close();
	}
	
	void pacco::read_bin(const char* filebin) throw(err){
		ifstream in;
		in.open(filebin, ios::in | ios::binary);
		if(in.fail()) throw err("errore nell'apertura del file", "posta::pacco::read_bin()");
		int cod,len;
		float pes;
		char* ind;
		in.read((char*)&cod,sizeof(cod));
		in.read((char*)&pes,sizeof(pes));
		in.read((char*)&len,sizeof(len));
		ind = new char [len+1];
		in.read(ind,len);
		ind[len]='\0';
		set_cod(cod);
		set_pes(pes);
		set_ind(ind);
		in.close();
	}

	
}
