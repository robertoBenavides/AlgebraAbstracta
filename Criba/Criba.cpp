#include "Criba.h"
#include <iostream>
void Criba::setPrimos(int d)
{
	/*int i = 0;
	while(i<numeros.size()){
			if (isPrimo(numeros[i][0])) {
				numeros[i][1] = 1;
			}
			else {
				numeros[i][1] = 2;
			}

		i++;
	}*/
}

bool Criba::isPrimo(int num)
{
	if (num == 2) {
		return true;
	}

	for (int a:primos) {
		if (a * a > num) {
			return true;
		}
		if (mod(num, a) == 0) return false;
	}
	/*if (numero != 0 && numero > primos[primos.size() - 1]) {
		for (int i = numero; i < num; i++) {
			if (mod(num, i) == 0) return false;
		}
	}*/
	return true;
}

int Criba::mod(int a, int b)
{
	int c= a-(a/b)*b;
	return (c < 0) ? c += b : c;
}

Criba::Criba(int a)
{
	for (int i = 2; i <= a; i++) {
		if (isPrimo(i)) {
			primos.push_back(i);
		}
		else {
			numero = i;
		}
		/*numeros.push_back({ i,0 });*/

	}
	setPrimos(a);
}

vector<int> Criba::getPrimos()
{
	vector<int> prim;
	for (int a : primos) {
		prim.push_back(a);
	}
	return prim;
}

void Criba::print()
{
	for (int a : primos) {
			cout << a << " ";
	}
	cout << endl;
}
