#include "DES.h"

DES::DES(int numbits)
{
	tamnumber = numbits;
	string p;
	for (int i : pc1) {
		p += k[i-1];
	}
	string c0(p.begin(), p.begin() + p.length() / 2);
	string d0(p.begin() + p.length() / 2, p.end());
	number=generateNumber(c0,d0);
}

ZZ DES::getNumber()
{
	return number;
}

void DES::corrimientoIzq(string& number)
{
	int a = 0;
	while (a != dsp[posdes]) {
		number += number[0];
		number.erase(number.begin(), number.begin() + 1);
		a++;
	}
}

void DES::corrimientoDer(string& number)
{
	int a = 0;
	while (a != dsp[posdes]) {
		number = number[number.length() - 1] + number;
		number.erase(number.length() - 1);
		a++;
	}
}

void DES::corrimientos(string& c0, string& d0)
{
	corrimientoIzq(c0);
	corrimientoDer(d0);
	mod(posdes+1,dsp.size());
}
ZZ DES::generateNumber(string& c0, string& d0)
{
	string kn;
	while (kn.length() < tamnumber) {
		corrimientos(c0, d0);
		string p = c0 + d0;
		for (int i : pc1) {
			kn += k[i - 1];
		}
	}
	kn = (kn.length() > tamnumber) ? string(kn.begin()+(kn.length() - tamnumber),kn.end()): kn;
	if (string(1, kn[0]) == "0") {
		kn[0] = '1';
	}
	return todec(kn);
}
int DES::mod(int a, int b)
{
	int c = a - (a / b) * b;
	return (c < ZZ(0)) ? c + b : c;
}
ZZ DES::mod(ZZ a, ZZ b)
{
	ZZ c = a - (a / b) * b;
	return (c < ZZ(0)) ? c + b : c;
}
ZZ DES::todec(string s)
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
