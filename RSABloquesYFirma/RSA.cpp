#include "RSA.h"
#include "DES.h"
#include <sstream>
//constructor con generación de numeros de un determinado número de bits
RSA::RSA(int nbits)
{	
	int tamfact = nbits / 2;
	ZZ maxi = maxNumber(tamfact);
	ZZ mini = minNumber(tamfact)+1;
	p = DES(tamfact).getNumber();
	ZZ f;
	ZZ aumento(2);
	bit_and(f, p, 1);
	if (f == ZZ(0)) {
		p++;
	}
	do {
		if (!testPrimalidad(p)) {
			p +=aumento;
		}
		if (p > maxi) {
			p = mini;

		}
	} while (!testPrimalidad(p) );
	cerr << p<<endl;

	q = DES(tamfact).getNumber();
	bit_and(f, q, 1); 
	if (f == ZZ(0)) {
		q++;
	}
	do {
		if (!testPrimalidad(q)) {
			q += aumento;
		}
		if (q > maxi) {
			q = mini;
			
		}
	} while (!testPrimalidad(q));
	cerr << q<<endl;
	
	n = p * q;
	piN = (p - 1) * (q - 1);
	picE();
	d = inv(e, piN);
	cout << "n: " ;
	cerr << n << endl;
	cout << "e: ";
	cerr << e << endl;
}
//constructor para pruevas de selección de E verificando la coprimidad
RSA::RSA(ZZ p, ZZ q)
{
	this->p = p;
	this->q = q;
	n = p * q;
	piN = (p - 1) * (q - 1);
	picE();
	d = inv(e, piN);

	cout << "n: ";
	cerr << n << endl;
	cout << "e: ";
	cerr << e << endl;
}

//constructor de pruebas para 
RSA::RSA(ZZ p, ZZ q, ZZ e)
{
	this->p = p;
	this->q = q;
	n = p * q;
	piN = (p - 1) * (q - 1);
	this->e = e;
	d = inv(e, piN);
	cerr << "n: " << n;
	cerr << "e: " << e;


}

//usado para el test de primalidad de miller.rabin  por el momento desactivado hasta saber una manera más eficiente
ZZ  RSA::pickA(ZZ n) {
	ZZ a;
	do {
		a = DES(NumBits(n - 3)).getNumber();
	} while (a < 3);
	return a;
}
//parte comentada test de mille-rabin
bool RSA::testPrimalidad(ZZ n) {
	ZZ base(8);
	if (exponenciacion(base, n, n) != base) {
		return false;
	}
	return true;
	/*if (n == 2) return true;
	ZZ m = n - 1;
	ZZ k(0);
	ZZ y;
	bit_and(y, m, 1);
	while (y == ZZ(0)) {
		m = RightShift(m, 1);
		k++;
		bit_and(y, m, 1);
	}
	ZZ nk = k;
	ZZ a = pickA(n);
	ZZ bi = exponenciacion(a, m, n);
	if (bi == ZZ(1) || bi == ZZ(n - 1)) {
		return true;
	}
	nk--;
	while (nk != ZZ(0)) {
		ZZ a = pickA(n);
		ZZ bi = exponenciacion(a, m, n);
		if (bi == ZZ(1)) {
			return false;
		}
		if (bi == ZZ(n - 1)) {
			return true;
		}
		nk--;
	}
	return false;*/
}

string RSA::cifrar(string mensaje,ZZ er,ZZ nr)
{
	bool wfirma = (nr == n);//confirmación de accion de firmar
	
	string cifrado;
	string aux;
	if (wfirma) {
		aux=toposval(mensaje);//obtencion del string con las posiciones de cada caracter del mensaje
	}
	else aux = mensaje;

	ZZ tamN = ZZ(zToString(nr).length());
	ZZ sizeblock = tamN - 1;

	//fix size ending with w value
	ZZ sobra = mod(ZZ(aux.length()), sizeblock);
	if (sobra != ZZ(0)) {
		ZZ falta = sizeblock - sobra;
		ZZ paso = ZZ(lsl.length());
		if (mod(falta, paso) == 0) {
			while (falta != ZZ(0)) {
				aux += lsl;
				falta -= paso;
			}
		}
		else {
			ZZ missing = paso - mod(falta, paso);
			falta -= mod(falta, paso);
			int a;
			conv(a, missing);
			while (falta > ZZ(0)) {
				aux += lsl;
				falta -= paso;
			}
			aux += string(lsl.begin(), lsl.begin() + a);
		}
	}

	//exponenciacion y creacion de los bloques del tamaño del N
	string::iterator ini = aux.begin();
	while (ini != aux.end()) {
		int blocksize = conv<int>(sizeblock);
		string bloque(ini, ini + blocksize);
		ZZ data(INIT_VAL, bloque.c_str());
		ZZ expo = exponenciacion(data, er, nr);
		int nTam = conv<int>(tamN);
		cifrado += fixTam(zToString(expo), nTam);
		ini += blocksize;
	}
	
	return cifrado;
}
string RSA::descifrar(string mensaje, ZZ er, ZZ nr)
{
	bool wfirma = nr == ZZ(-1);//confirmacion firma
	if (er == ZZ(-1)) er = d;
	if (nr == ZZ(-1)) nr = n;

	string descifrado, inicio;
	int tamN = zToString(nr).length();
	int blocksize = tamN - 1;
	string::iterator ini = mensaje.begin();
	if (nr == n) {
		while (ini != mensaje.end()) {
			string bloque = string(ini, ini + tamN);
			ZZ data(INIT_VAL, bloque.c_str());

			vector<vector<ZZ>> ecs;
			ecs.push_back({ exponenciacion(mod(data,p),mod(er,p - 1),p),p });
			ecs.push_back({ exponenciacion(mod(data,q),mod(er,q - 1),q),q });

			ZZ expo =restoChino(ecs);
			int tam = zToString(expo).length();
			inicio += (tam < blocksize) ? fixTam(zToString(expo), blocksize)  : zToString(expo);
			ini += tamN;
		}
	}
	else {
		while (ini != mensaje.end()) {
			string bloque = string(ini, ini + tamN);
			ZZ data(INIT_VAL, bloque.c_str());
			ZZ expo = exponenciacion(data, er, nr);
			int tam = zToString(expo).length();
			inicio += (tam < blocksize) ? fixTam(zToString(expo), blocksize) : zToString(expo);
			ini += tamN;
		}
	}
	
	int mostsignificantValue = to_string(abecedario.length() - 1).length();
	ini = inicio.begin();
	/*string::iterator fin = inicio.end();
	ZZ sobra = mod(ZZ(inicio.length()), ZZ(mostsignificantValue));
	if (sobra != ZZ(0)) {
		int s;
		conv(s, sobra);
		fin = fin - s;
	}*/

	//eliminacion de W's para obtener el mensaje
	if (inicio[inicio.length()-1] == lsl[0]) {
		inicio.erase(inicio.end()-1);
	}
	while (string(inicio.end()-2, inicio.end()) == lsl) {
		string::iterator d = inicio.end() - 2;
		inicio.erase(d, inicio.end());
	}

	descifrado = inicio;

	if (!wfirma) {//en caso no sea descifrado de firma
		descifrado = "";
		while (ini != inicio.end()) {
			string val = string(ini, ini + mostsignificantValue);
			int conve = stoi(val);
			descifrado += abecedario[conve];//reemplaza los valores de los indices por su caracter correspondiente
			ini += mostsignificantValue;
		}
	}
	return descifrado;
}
string RSA::cifrarConFirma(string msg, ZZ er, ZZ nr)
{
	return cifrar(cifrar(msg,d,n),er,nr);
}
string RSA::descifrarConFirma(string msg, ZZ er, ZZ nr)
{
	return descifrar(descifrar(msg), er, nr);
}

string RSA::toposval(string mensaje)
{
	string aux;
	for (int i = 0; i < mensaje.length(); i++) {
		int pos = abecedario.find(mensaje[i]);
		aux += fixTam(to_string(pos), conv<int>(msv));
	}
	return aux;
}
string RSA::topvalFromPos(string)
{
	return string();
}


string RSA::zToString(const ZZ& z) {
	stringstream buffer;
	buffer << z;
	return buffer.str();
}
ZZ RSA::maxNumber(int t)
{
	string maxi = string(t,'1');
	return todec(maxi);
}
ZZ RSA::minNumber(int t)
{
	string mini ="1"+string(t-1, '0');
	return todec(mini);
}
ZZ RSA::todec(string s)
{
		ZZ decimal = ZZ(0);
		ZZ val = ZZ(1);
		for (int i = s.size() - 1; i >= 0; i--) {
			if (mod(ZZ(s[i]), ZZ(2)) != ZZ(0)) {
				decimal += val;
			}
			val *= 2;
		}
		return decimal;
}
ZZ RSA::restoChino(vector<vector<ZZ>> ecs)
{		
	ZZ P(1);
	for (int i = 0; i < ecs.size(); i++) {
		ecs[i][0] = mod(ecs[i][0], ecs[i][1]);
		P *= ecs[i][1];
	}
	for (int i = 0; i < ecs.size(); i++) {
		ecs[i].push_back(P / ecs[i][1]);
	}
	ZZ x0(0);
	for (int i = 0; i < ecs.size(); i++) {
		x0 += mod(ecs[i][0], P) * mod(ecs[i][2], P) * mod(inv(ecs[i][2], ecs[i][1]), P);
		x0 = mod(x0, P);
	}
	x0 = mod(x0, P);
	return x0;
}

void RSA::picE()
{
	do {
		e = RandomBnd(piN);
		if (e < ZZ(2)) {
			e += 2;
		}
	} while (mcd(e, piN) != ZZ(1));
}
ZZ RSA::mcd(ZZ a, ZZ b)
{
	ZZ r = mod(a, b);
	while (r != 0) {
		a = b;
		b = r;
		r = mod(a, b);
	}
	return b;
}
ZZ RSA::mod(ZZ a, ZZ b)
{
	ZZ c = a - (a / b) * b;
	return (c < ZZ(0)) ? c + b : c;
}
ZZ RSA::exponenciacion(ZZ a, ZZ m, ZZ n)
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
ZZ RSA::inv(ZZ a, ZZ b)
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
string RSA::fixTam(string cifrado, int tam)
{
	int falta = tam - cifrado.length();
	return (falta >= 0) ? string(falta, '0') + cifrado : cifrado;
}
