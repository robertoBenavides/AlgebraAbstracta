#pragma once
#include <string>
using namespace std;
class Cesar
{
private:
	int key;
	bool clocklike;
	int pospick(int,bool);
public:
	string cifrado(string);
	string descifrado(string);
	Cesar();
	Cesar(int);
	Cesar(int, bool);
	string alfabeto = "abcdefghijklmnopqrstuvwxyz";

};

