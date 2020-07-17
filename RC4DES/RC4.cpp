
#include <iostream>
#include <string>
#include "DES.h"
#include <ctime>

using namespace std;
//Obtencion de datos del CPU

int main()
{
	unsigned t0, t1;
	int a,c=10;
	cin >> a;
	while (c) {
		t0 = clock();
		DES d(a);
		t1 = clock();
		cout<< (double(t1 - t0) / CLOCKS_PER_SEC)<<endl;
		cerr << d.getNumber()<<endl;
		c--;
	}
	return 0;
}

