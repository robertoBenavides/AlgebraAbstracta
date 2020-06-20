#pragma once
#include <string>
#include<NTL/ZZ.h>
using namespace std;
NTL_CLIENT
class CifradoRSA
{
public:
	string abecedario = "abcdefghijklmnopqrstuvwxyz -ABCDEFGHIJKLMNOPQRSTUVWXYZ,.0123456789";
	ZZ n, e;
	//CifradoRSA();
	CifradoRSA(ZZ,ZZ);
	ZZ cifrar(string);
	string descifrar(ZZ);

private:
	ZZ p, q,piN,d;
	void picE();
	ZZ mcd(ZZ,ZZ);
	ZZ mod(ZZ, ZZ);
	ZZ exponenciacion(ZZ, ZZ, ZZ);
	ZZ inv(ZZ,ZZ);
};

