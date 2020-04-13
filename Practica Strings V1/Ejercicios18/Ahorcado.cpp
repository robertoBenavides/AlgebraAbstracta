#include "Ahorcado.h"
#include <iostream>
#include <iomanip>
void Ahorcado::messageerror()
{
	cout << "no"<<endl;
}

void Ahorcado::messageacierto()
{
	cout << "si"<<endl;
}

void Ahorcado::messagewon()
{
	cout << "Felicidades!!! Adivino mi palabra. Desea jugar otra vez? si/no"<<endl;
}

void Ahorcado::messagelose()
{
	cout << "perdiste jajaja :V. Desea jugar otra vez? si/no" << endl;
}

void Ahorcado::drawmen()
{
	if (this->errores != 0) {
		if(this->errores>=1)
			cout << setw(5) << "" << setw(1) << "o" << setw(5) << "" << endl;
		if (this->errores >= 2)
			cout << setw(5) << right << ((this->errores >= 3) ? "/" : "") << setw(1) << "|"  << setw(5) << left << ((this->errores >= 4) ? "\\" : "")  << endl;
		if (this->errores >= 5)
			cout << setw(5) << "" << setw(1) <<  "|" << setw(5) << "" << endl;
		if (this->errores >= 6)
			cout << setw(5) << right << "/" << setw(1) << "" << setw(5) << left << ((this->errores >= 7) ? "\\" : "")<< endl;
	}
	
}

bool Ahorcado::find(string a)
{
	return this->palabra.find(a)!=-1;
}

void Ahorcado::replaceinguess(string letra)
{
	for (int i = 0; i < this->palabra.size(); i++) {
		if (this->palabra[i] == letra[0]) {
			this->guess[i] = letra[0];
		}
	}
}

void Ahorcado::showGuess()
{
	cout << this->guess << endl;
}

void Ahorcado::askRestart()
{
	string a;
	cin >> a;
	if (a.compare("no")==0) this->restart = false;
	if (a.compare("si")==0) this->restart = true;
	if (this->restart) {
		pickWord();
		this->win = false;
		this->lose = false;
		this->errores = 0;
		this->guess = string(this->palabra.size(), '*');
	}

}

void Ahorcado::pickWord()
{
	int pos = rand() % 10;
	this->palabra=this->palabras[pos];
}

Ahorcado::Ahorcado(vector<string> palabras)
{
	this->palabras = palabras;
	pickWord();
	this->guess = string(palabra.size(), '*');
}

void Ahorcado::play()
{
	
	while (this->restart){
		cout << "adivine la palabra:    " << this->guess << endl;
		while (intentos != errores && !win) {
			string l;
			cin >> l;
			if (l.size() == 1) {
				if (this->find(l)) {
					this->replaceinguess(l);
					this->messageacierto();
				}
				else {
					this->messageerror();
					this->errores++;
				}
			}
			else {
				if (this->find(l)) {
					this->win = true;
					this->guess = l;
				}
				else {
					this->messageerror();
					this->errores++;
				}
			}
			if (this->guess.compare(this->palabra) == 0) {
				this->win = true;
			}
			this->drawmen();
			this->showGuess();
		}
		if (this->intentos == this->errores) this->lose = true;
		if (this->win) messagewon();
		if (this->lose) messagelose();
		this->askRestart();
	}
}
