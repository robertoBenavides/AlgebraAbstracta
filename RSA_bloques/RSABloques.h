#pragma once
#include<string>
#include<vector>
#include<NTL/ZZ.h>
using namespace std;
NTL_CLIENT

class RSABloques
{
public:
	string abecedario = "abcdefghijklmnopqrstuvwxyz -ABCDEFGHIJKLMNOPQRSTUVWXYZ,.0123456789";
	ZZ n, e;
	
	//RSABloques();
	RSABloques(ZZ, ZZ);
	RSABloques(ZZ, ZZ,ZZ);
	string cifrar(string);
	string descifrar(string);
	string fixTam(string,int);

private:
	ZZ p, q, piN, d;
	void picE();
	ZZ mcd(ZZ, ZZ);
	ZZ mod(ZZ, ZZ);
	ZZ exponenciacion(ZZ, ZZ, ZZ);
	ZZ inv(ZZ, ZZ);
	string zToString(const ZZ& z);
	ZZ msv = (to_string(abecedario[abecedario.size() - 1]).length() > to_string(abecedario.size() - 1).length()) ? ZZ(to_string(abecedario[abecedario.size() - 1]).length()) : ZZ(to_string(abecedario.size() - 1).length());
	string lsl = to_string(abecedario.find("w"));
	
};

