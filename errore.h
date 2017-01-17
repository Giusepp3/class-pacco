#ifndef ERRORE_H
#define ERRORE_H
#include <iostream>
#include <string>

using namespace std;

class err{
	private:
		string errfunc;
		string errmsg;
	public:
		err(const string func, const string msg){errfunc=func; errmsg=msg;}
		
};


#endif //ERRORE_H
