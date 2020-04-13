#include "Cesar.h"

int Cesar::pospick(int pos, bool direction=true)
{
	if (direction) direction = clocklike;
	else direction = !clocklike;
	int postomove=key;
	if (key > alfabeto.size()-1) {
		postomove = key % (alfabeto.size()-1);
	}

	int newpos;
	if (direction) {
		newpos = pos - postomove;
		if (newpos < 0) newpos += (alfabeto.size());
	}
	else {
		newpos = pos + postomove;
		if (newpos > (alfabeto.size()-1)) newpos -= (alfabeto.size());
	}
	return newpos;
}

string Cesar::cifrado(string mensaje)
{
	string newmessage = "";
	for (char a : mensaje)
	{
		if (alfabeto.find(a)==string::npos)newmessage += a;
		else {
			int pos = alfabeto.find(a);
			pos = pospick(pos);
			newmessage += alfabeto.at(pos);
		}

	}
	return newmessage;
}

string Cesar::descifrado(string mensaje)
{
	string newmessage = "";
	for (char a : mensaje)
	{
		if (alfabeto.find(a) == string::npos)newmessage += a;
		else {
			int pos = alfabeto.find(a);
			pos = pospick(pos,false);
			newmessage += alfabeto.at(pos);
		}
	}
	return newmessage;
}

Cesar::Cesar()
{
	key = 3;
	clocklike = false;
}

Cesar::Cesar(int key)
{
	this->key = key;
	clocklike = false;
}

Cesar::Cesar(int key , bool clocklike)
{
	this->key=key;
	this->clocklike=clocklike;
}
