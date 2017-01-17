#include "class_pacco.h"

using namespace std;

using namespace posta;

int main() {
	
	pacco p_txt(9070,52.2,"Via Manzoni 123");
	pacco p_bin=p_txt;
	pacco p3;
	cin >> p3;
	
	p_txt=p_bin=p3;

	return 0;
}
