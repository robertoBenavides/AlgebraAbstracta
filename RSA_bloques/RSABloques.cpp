#include "RSABloques.h"
#include <sstream>
RSABloques::RSABloques(ZZ p, ZZ q)
{
	this->p = p;
	this->q = q;
	n = p * q;
	piN = (p - 1) * (q - 1);
	picE();
	d = inv(e, piN);
	cerr << e << endl;
	cerr << n << endl;
	cerr << piN << endl;
	cerr << d << endl;

}

RSABloques::RSABloques(ZZ p, ZZ q, ZZ e)
{
	this->p = p;
	this->q = q;
	n = p * q;
	piN = (p - 1) * (q - 1);
	this->e = e;
	d = inv(e, piN);
	cerr << e << endl;
	cerr << n << endl;
	cerr << piN << endl;
	cerr << d << endl;

}

string RSABloques::cifrar(string mensaje)
{
	string cifrado;
	string aux;

	for (int i = 0; i < mensaje.length(); i++) {
		int pos = abecedario.find(mensaje[i]);
		aux +=fixTam( to_string(pos),conv<int>(msv));
	}
	ZZ tamN = ZZ(zToString(n).length());
	ZZ sizeblock = tamN - 1;
	//fix size ending with w value
	ZZ sobra = mod(ZZ(aux.length()), sizeblock);
	string t;
	t = zToString(sobra);
	if (sobra != ZZ(0)) {
		ZZ falta = sizeblock - sobra;
		t = zToString(falta);
		ZZ paso = ZZ(lsl.length());
		t = zToString(paso);
		if (mod(falta, paso) == 0) {
			while (falta != ZZ(0)) {
				aux += lsl;
				falta -= paso;
			}
		}
		else {
			ZZ missing = paso - mod(falta, paso);
			falta-= mod(falta, paso);
			int a;
			conv(a,missing);
			string last = string(1,lsl[0]);
			while (falta > ZZ(0)) {
				aux += lsl;
				falta -= paso;
			}
			aux += string(lsl.begin(), lsl.begin() + a);
		}
	}

	string::iterator ini = aux.begin();
	while (ini != aux.end()) {
		int blocksize = conv<int>(sizeblock);
		string bloque(ini, ini + blocksize);
		ZZ data(INIT_VAL, bloque.c_str());
		ZZ expo = exponenciacion(data, e, n);
		int nTam = conv<int>(tamN);
		cifrado += fixTam(zToString(expo),nTam);
		ini += blocksize;
	}
	return cifrado;






	
	return cifrado;
}

string RSABloques::descifrar(string mensaje)
{
	string descifrado, inicio;
	int tamN = zToString(n).length();
	int blocksize = tamN - 1;
	string::iterator ini = mensaje.begin();
	while (ini != mensaje.end()) {
		string bloque = string(ini, ini + tamN);
		ZZ data(INIT_VAL, bloque.c_str());
		string valdata = zToString(data);
		ZZ expo = exponenciacion(data, d, n);
		valdata = zToString(expo);
		int tam = zToString(expo).length();
		inicio += (tam<blocksize)? string(blocksize-tam,'0')+ zToString(expo) : zToString(expo);
		ini += tamN;
	}
	int mostsignificantValue = to_string(abecedario.length() - 1).length();
	ini = inicio.begin();
	string::iterator fin = inicio.end();
	ZZ sobra = mod(ZZ(inicio.length()), ZZ(mostsignificantValue));
	if ( sobra!= ZZ(0)) {
		int s;
		conv(s, sobra);
		fin = fin - s;
	}
	while (ini != fin) {
		string val = string(ini, ini + mostsignificantValue);
		int conve=stoi(val);
		descifrado += abecedario[conve];
		ini += mostsignificantValue;
	}

	int i = descifrado.length() - 1;
	while (descifrado[i] == 'w'&& i>0) {
		descifrado.erase(i);
		i--;
	}


	
	return descifrado;
}

string RSABloques::zToString(const ZZ& z) {
	stringstream buffer;
	buffer <<  z;
	return buffer.str();
}

void RSABloques::picE()
{
	do {
		e = RandomBnd(piN);
		if (e < ZZ(2)) {
			e += 2;
		}
	} while (mcd(e, piN) != ZZ(1));
}

ZZ RSABloques::mcd(ZZ a, ZZ b)
{
	ZZ r = mod(a, b);
	while (r != 0) {
		a = b;
		b = r;
		r = mod(a, b);
	}
	return b;
}

ZZ RSABloques::mod(ZZ a, ZZ b)
{
	ZZ c = a - (a / b) * b;
	return (c < ZZ(0)) ? c + b : c;
}

ZZ RSABloques::exponenciacion(ZZ a, ZZ m, ZZ n)
{
	ZZ eleb = a;
	ZZ resultado(1);
	if (mod(m, ZZ(2)) == ZZ(1)) {
		resultado = mod(eleb, n);
		eleb = mod(eleb, n);
	}
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

ZZ RSABloques::inv(ZZ a, ZZ b)
{
	ZZ Zn = b;
	vector<vector<ZZ>> data;
	ZZ a0 = a, b0 = b, gcd = ZZ(1), c0 = gcd;
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

string RSABloques::fixTam(string cifrado, int tam)
{
	int falta = tam - cifrado.length();
	return (falta>=0)?string(falta,'0')+cifrado:cifrado;
}
