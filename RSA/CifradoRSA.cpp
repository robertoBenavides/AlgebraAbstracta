#include "CifradoRSA.h"
#include <vector>


CifradoRSA::CifradoRSA(ZZ p, ZZ q)
{
	this->p = p;
	this->q = q;
	n = p * q;
	piN = (p-1) * (q-1);
	picE();
	d = inv(e,piN);
}

ZZ CifradoRSA::cifrar(string mensaje)
{
	ZZ cifrado;
	//for (auto a : mensaje) {
		cifrado = exponenciacion( ZZ(abecedario.find(mensaje)),e,n);
		cerr << "cif val expo" << cifrado;
	//}
	return cifrado;
}

string CifradoRSA::descifrar(ZZ mensaje)
{
	int pos;
	ZZ expo = exponenciacion(mensaje, d, n);
	/*cerr <<"desc val expo"<< expo;
	cout << endl;*/
	conv(pos, expo);
	return string(1,abecedario[pos]);
}

void CifradoRSA::picE()
{
	do {
		
		e = RandomBnd(piN) + 1;
	} while (mcd(e, piN) != ZZ(1));
}

ZZ CifradoRSA::mcd(ZZ a, ZZ b)
{
	ZZ r = mod(a, b);
	while (r != 0) {
		a = b;
		b = r;
		r = mod(a, b);
	}
	return b;
}

ZZ CifradoRSA::mod(ZZ a, ZZ b)
{
	ZZ c = a - (a / b) * b;
	return (c < ZZ(0)) ? c + b : c;
}

ZZ CifradoRSA::exponenciacion(ZZ a , ZZ m , ZZ n)
{
	ZZ eleb = a;
	ZZ resultado = mod(eleb, n);
	m = m / 2;
	while (m != 0) {
		eleb = mod(eleb * eleb, n);
		if (mod(m, ZZ(2)) == ZZ(1)) {
			resultado = mod(resultado * eleb, n);
		}
		m = m / 2;
	}
	return resultado;
}

ZZ CifradoRSA::inv(ZZ a, ZZ b)
{
		ZZ Zn = b;
		vector<vector<ZZ>> data;
		ZZ a0 = a, b0 = b, gcd =ZZ(1), c0 = gcd;
		ZZ q, r;

		do {

			q = a / b;
			r = mod(a, b);
			vector<ZZ> par = { a,q,b,r };
			a = b;
			b = r;
			if (r != 0) data.push_back(par);
		
		} while (r != 0);
		/*for (vector<ZZ> v : data) {
			for (ZZ a : v) {
				cout << a << " ";
			}
			cout << endl;
		}*/

		int tam = data.size();
		ZZ xd = ZZ(1), yd = -data[tam - 1][1];
		for (int i = tam - 1; i > 0; i--) {
			
			ZZ aux = yd;
			yd = yd * -data[i - 1][1] + xd;
			xd = aux;
		}

		ZZ a1 = a0, b1 = b0, c1 = c0;
		
		ZZ x0, x1, y0, y1;
		x0 = c1 * xd;
		y0 = c1 * yd;
		return mod(x0, Zn);
}
