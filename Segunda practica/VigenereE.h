#pragma once
#include <string>
using namespace std;
class VigenereE
{
public:
	string abecedario = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
	VigenereE(string);
	string cifrado(string);
	string descifrado(string);
	string newclave(string);
private:
	string  clave;
	string addWord(string);
	string deleteword(string);
};

