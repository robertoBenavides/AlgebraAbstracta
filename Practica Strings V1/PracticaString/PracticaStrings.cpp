// PracticaStrings.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <istream>
#include <fstream>

using namespace std;
void problema1() {
	string data="esto es un texto";
	const char *dataarr = data.c_str();
	string newdata(dataarr);
	cout << data<<endl;
	cout <<dataarr <<endl;
	cout <<newdata <<endl;
}
void problema2() {
	string data = "esta es la data   ";
	cout << data.capacity()<<endl;
	cout << data.size() << endl;
}
void problema3() {
	locale loc;
	string data = "esto ES un texto";
	string mayus;
	for each(char a in data) {
		mayus+= static_cast<char>(toupper(static_cast<int> (a)));
	}
	cout << mayus<<endl;
	string minus;
	for each(char a in data) {
		minus += static_cast<char>(tolower(static_cast<int> (a)));
	} 
	cout << minus<<endl;
}
void problema4() {
	int n1, n2;
	cout << "primer numero:";
	cin >> n1;
	cout <<"segundo numero:";
	cin >> n2;
	string concat = to_string(n1) + to_string(n2);
	cout <<concat<<endl;
	int doble = stoi(concat) * 2;
	cout << doble;
}
void problema5() {
    string text = string(100,'a');
    cout << text.size()<<endl;
    cout << text;
}
void problema6() {
	string cadena = "Yo desaprobe el curso de Algebra Abstracta";
	int pos= cadena.find("desaprobe");
	string::iterator first = cadena.begin() + pos;
	string::iterator second = first+3;
	cadena.erase(first, second);
	cout << cadena;
}
int repeticiones(string texto,string word) {
	int pos = texto.find(word);
	int cantidad=0;
	while (pos != -1) {
		string::iterator it = texto.begin() + pos;
		texto.erase(it, it + word.size());
		cantidad++;
		pos = texto.find(word);
	}
	return cantidad;
}
void problema7() {
	string texto;
	getline(cin, texto);
	string word;
	cin >> word;
	int cantidad = repeticiones(texto,word);
	cout << cantidad;
}
void problema8() {
	string texto;
	getline(cin, texto);
	string::iterator ini = texto.begin();
	for (ini; ini != texto.end(); ini++)
		cout << *ini << endl;
}
void problema9() {
	bool firstcorrect = false;
	string primer, segundo;
	while (!firstcorrect) {
		cin >> primer;
		if (primer.size() % 2==0) {
			firstcorrect = true;
		}
	}
	cin >> segundo;

	primer.insert(primer.size() / 2,segundo);
	cout << primer;
}
string intercambiar(string t1, string t2, string t3) {
	int pos = t1.find(t2);
	while (pos != -1) {
		string::iterator it = t1.begin() + pos;
		t1.replace(it, it + t2.size(),t3);
		pos = t1.find(t2);
	}
	return t1;
}
void problema10() {
	string t1, t2, t3;
	getline(cin, t1);
	getline(cin, t2);
	getline(cin, t3);
	cout << intercambiar(t1, t2, t3);
}
string mayor(string a, string b) {

	for (int i = 0; i < a.size(); i++) {
		if (static_cast<int>(a[i]) > static_cast<int>(b[i])) return a;
		else if (static_cast<int>(a[i]) != static_cast<int>(b[i])) return b;
	}
	return b;
}
void problema11() {
	string texto1, texto2;
	cin >> texto1;
	cin >> texto2;
	int iterate;
	if (texto1.size() > texto2.size())	cout<<mayor(texto2, texto1);
	else cout<<mayor(texto1, texto2);


}
void createTxt(string name) {
	ofstream file(name);
	int a;
	cin >> a;
	while (a >= 1) {
		file << (rand() % 1000 + 1)<<endl;
		a--;
	}
	if(a!=0) file << (rand() % 1000 + 1);
	file.close();

}
void readTxt(string name) {
	
	ifstream file(name);
	string line = "";
	while (!file.eof()) {
		file >> line;
		cout << line<<endl;
	}
	file.close();
}
void problema12() {
	
	createTxt("numeros.txt");

}
void problema13() {
	readTxt("numeros.txt");
}
int main()
{
	problema12();
	problema13();
	int a; cin >> a;
    return 0;
}

