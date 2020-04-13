#pragma once
#include <string>
#include <vector>
using namespace std;
class Ahorcado
{
private:
	vector<string> palabras;
	string palabra;
	string guess;
	bool lose = false;
	bool win = false;
	bool restart = true;
	int intentos = 7;
	int errores = 0;

	void messageerror();
	void messageacierto();
	void messagewon();
	void messagelose();

	void drawmen();

	bool find(string a);

	void replaceinguess(string a);

	void showGuess();
	void askRestart();
	void pickWord();
public:
	Ahorcado(vector < string>);
	void play();
	
	
};

