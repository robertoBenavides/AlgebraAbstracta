#pragma once
#include<string>
#include<vector>
#include<NTL/ZZ.h>
using namespace std;
NTL_CLIENT

class RSA
{
public:
	string abecedario = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
	ZZ n, e;

	RSA(int);
	RSA(ZZ, ZZ);
	RSA(ZZ, ZZ, ZZ);
	string cifrar(string, ZZ er, ZZ nr);
	string descifrar(string, ZZ er = ZZ(-1), ZZ nr = ZZ(-1));
	string cifrarConFirma(string,ZZ,ZZ);
	string descifrarConFirma(string,ZZ,ZZ);

	string fixTam(string, int);

private:
	ZZ p, q, piN, d;
	void picE();
	ZZ pickA(ZZ);
	bool testPrimalidad(ZZ);
	ZZ mcd(ZZ, ZZ);
	ZZ mod(ZZ, ZZ);
	ZZ exponenciacion(ZZ, ZZ, ZZ);
	ZZ inv(ZZ, ZZ);
	string zToString(const ZZ& z);
	ZZ msv = (to_string(abecedario[abecedario.size() - 1]).length() > to_string(abecedario.size() - 1).length()) ? ZZ(to_string(abecedario[abecedario.size() - 1]).length()) : ZZ(to_string(abecedario.size() - 1).length());
	string lsl = to_string(abecedario.find("w"));
	ZZ maxNumber(int);
	ZZ minNumber(int);
	ZZ todec(string s);
	ZZ restoChino(vector<vector<ZZ>>);


	string toposval(string);
	string topvalFromPos(string);

};


