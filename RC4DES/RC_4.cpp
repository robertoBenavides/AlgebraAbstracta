#include "RC_4.h"

RC_4::RC_4(int tamBits)
{
	this->tamBits = tamBits;
	s=vector<ZZ>(tamBits);
	for (int i = 0; i < tamBits; i++) {
		s[i] = i;
	}

	//int tamk = tamBits;
	///*tamk =(mod(ZZ(tamk),ZZ(2))==0)?tamk:tamk+1;*/
	vector<ZZ> k(5);
	int i = 0;
	while (i < k.size()) {
		time_t now = time(0);
		long tiempo = now;
		ZZ ramusage = getUsedRam();
		k[i] =ZZ(GetCPULoad()) * ramusage + ZZ(tiempo);
		i++;
		Sleep(93);
	}

	ZZ f = ZZ(0);
	for (int i = 0; i < k.size(); i++) {
		int ki = mod(i, k.size());
		f = mod(mod(f, ZZ(tamBits)) + mod(s[i], ZZ(tamBits)) + mod(k[ki], ZZ(tamBits)), ZZ(tamBits));
		int fi = conv<int>(f);
		change(s[i], s[fi]);
	}
	secuenciaCifrante();
}

float RC_4::CalculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
	static unsigned long long _previousTotalTicks = 0;
	static unsigned long long _previousIdleTicks = 0;

	unsigned long long totalTicksSinceLastTime = totalTicks - _previousTotalTicks;
	unsigned long long idleTicksSinceLastTime = idleTicks - _previousIdleTicks;


	float ret = 1.0f - ((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime) / totalTicksSinceLastTime : 0);

	_previousTotalTicks = totalTicks;
	_previousIdleTicks = idleTicks;
	return ret;
}

unsigned long long RC_4::FileTimeToInt64(const FILETIME& ft)
{
	return (((unsigned long long)(ft.dwHighDateTime)) << 32) | ((unsigned long long)ft.dwLowDateTime);
}

float RC_4::GetCPULoad()
{

	FILETIME idleTime, kernelTime, userTime;
	return GetSystemTimes(&idleTime, &kernelTime, &userTime) ? CalculateCPULoad(FileTimeToInt64(idleTime), FileTimeToInt64(kernelTime) + FileTimeToInt64(userTime)) : -1.0f;
}

ZZ RC_4::getUsedRam()
{
	MEMORYSTATUSEX memInfo;
	memInfo.dwLength = sizeof(MEMORYSTATUSEX);
	GlobalMemoryStatusEx(&memInfo);
	PROCESS_MEMORY_COUNTERS pmc;
	GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc));
	DWORDLONG physMemUsed = memInfo.ullTotalPhys - memInfo.ullAvailPhys;
	string data = to_string(physMemUsed);
	return ZZ(INIT_VAL, data.c_str());
}

void RC_4::change(ZZ& a, ZZ& b)
{
	ZZ c = a;
	a = b;
	b = c;
}

ZZ RC_4::mod(ZZ a, ZZ b)
{
	ZZ c = a - (a / b) * b;
	return (c < ZZ(0)) ? c + b : c;
}

int RC_4::mod(int a, int b)
{
	int c = a - (a / b) * b;
	return (c < ZZ(0)) ? c + b : c;
}
string RC_4::zToString(const ZZ& z) {
	stringstream buffer;
	buffer << z;
	return buffer.str();
}
string RC_4::tobin(ZZ s)
{
	string bin;
	while (s != 0) {
		bin += to_string(conv<int>(mod(s,ZZ(2))));
		s /= 2;
	}
	return bin;
}

void RC_4::secuenciaCifrante()
{
	int i = 0, f = 0;
	int tam=8;
	while (tam) {
		i = conv<int>(mod(ZZ(i) + 1, ZZ(tamBits)));
		f = conv<int>(mod(ZZ(f) + s[i], ZZ(tamBits)));
		change(s[i], s[f]);
		ZZ t = mod(s[i] + s[f], ZZ(tamBits));
		string a = tobin(t);
		if (a.length() < 8) {
			a = string(8 - a.length(), '0') + a;
		}
		Or.push_back(a);
		tam--;
	}
}

string RC_4::getSecuenciabitxbit()
{
	string sec;
	for (string a : Or) {
		sec += a;
	}
	return sec;
}
