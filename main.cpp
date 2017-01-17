#include "class_pacco.h"
#include "pila.h"

using namespace std;

using namespace posta;

int main() {
	
	pila P(5);
	pacco p1,p2,p3,p4,p5;
	pacco p;
	cin >> p1 >> p2 >> p3 >> p4 >> p5;
	P.push(p1);
	P.push(p2);
	P.push(p3);
	P.push(p4);
	P.push(p5);
	
	P.salva_bin("filetest.bin");
	
	
	
	

	return 0;
}
