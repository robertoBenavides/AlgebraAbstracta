#pragma once
#include <vector>
#include "RC_4.h"
using namespace std;
class DES
{
public:
	int tamnumber;
	string k = RC_4(255).getSecuenciabitxbit();	
	DES(int);
	ZZ getNumber();
private:
	ZZ number;
	vector<int> pc1 = { 57,49,41,33,25,17,9,1,58,50,42,34,26,18,
						10,2,59,51,43,35,27,19,11,3,60,52,44,36,
						63,55,47,39,31,23,15,7,62,54,46,38,30,22,
						14,6,61,53,45,37,29,21,13,5,28,20,12,4 };
	vector<int> pc2 = { 14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,
						4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,
						30,40,51,45,33,48,44,49,39,56,34,53,46,42,
						50,36,29,32 };
	vector<int> dsp = { 1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1 };
	int posdes = 0;
	void corrimientoIzq(string&);
	void corrimientoDer(string&);
	void corrimientos(string&, string&);
	ZZ generateNumber(string&, string&);
	int mod(int a, int b);
	ZZ mod(ZZ a, ZZ b);
	ZZ todec(string s);
};

