#pragma once
#include <string>
using namespace std;
class Vigener
{
public:
	string abecedario = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
	Vigener(string);
	string cifrado(string);
	string descifrado(string);
	string newclave(string);
private:
	string  clave;
};

