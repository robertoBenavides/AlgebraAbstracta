#pragma once
#include <string>
using namespace std;
class vigenere3f
{
public:
	string abecedario = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
	vigenere3f(string);
	string cifrado(string);
	string descifrado(string);
	string newclave(string);
private:
	string  clave;
};

