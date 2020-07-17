#pragma once
#include <NTL/ZZ.h>
#include <sstream>
#include <Windows.h>
#include <iostream>
#include <time.h>
#include <vector>
#include "psapi.h"
#include <string>
#define _WIN32_DCOM
#include <comdef.h>
#include <Wbemidl.h>

using namespace std;
NTL_CLIENT
class RC4
{
public:
	int tamBits;
	vector<ZZ> s;
	vector<string> Or;
	RC4(int);
	string getSecuenciabitxbit();
private:
	static float CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks);
	static unsigned long long FileTimeToInt64(const FILETIME& ft);
	float GetCPULoad();
	ZZ getUsedRam();
	void change(ZZ& a, ZZ& b);
	ZZ mod(ZZ a, ZZ b);
	int mod(int a, int b);
	string tobin(ZZ s);
	string zToString(const ZZ& z);
	void secuenciaCifrante();
};
