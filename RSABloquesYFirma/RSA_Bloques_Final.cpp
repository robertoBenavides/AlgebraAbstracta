// RSA_Bloques_Final.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <ctime>
#include "RSA.h"
using namespace std;
int main()
{
	int option;
	cin >> option;
	if (option == 0) {
		int nbits;
		cin >> nbits;
		RSA receptor(nbits);
		cin >> nbits;
		RSA emisor(nbits);
		//este es un texto para ver si todo funciona como deberia suponiendo que hice algo bien en este codigo
		cout << "-----------------------------------------------------------" << endl;
		string c = emisor.cifrarConFirma("este es un texto para ver si todo funciona como deberia suponiendo que hice algo bien en este codigoF", receptor.e, receptor.n);
		cout<<c <<endl;
		cout << "-----------------------------------------------------------" << endl;
		string d= receptor.descifrarConFirma(c,emisor.e,emisor.n);
		cout << d;
	}
	if (option == 1) {
		ZZ p, q,e1;
		cin >> p >> q>>e1;
		RSA emisor(p,q,e1);
		cout << "n y e del receptor"<<endl;
		ZZ n, e;
		cin >> n >> e;
		cin.ignore();
		cout << "-----------------------------------------------------------" << endl;
		string c = emisor.cifrarConFirma("este es un texto para ver si todo funciona como deberia suponiendo que hice algo bien en este codigo", e, n);
		cout<<c <<endl;
		string a;
		cin >> a;
		cout << "-----------------------------------------------------------" << endl;
		string d= emisor.descifrarConFirma(a,e,n);
		cout << d;
	}
	if (option == 2) {
		int nbits;
		cin >> nbits;
		RSA emisor(nbits);
		cout << "n y e del receptor" << endl;
		ZZ n, e;
		cin >> n >> e;
		cin.ignore();
		string mensaje;
		getline(cin,mensaje);

		string c = emisor.cifrarConFirma(mensaje, e, n);
		cout << c << endl;

		string a;
		cin >> a;
		cout << "-----------------------------------------------------------" << endl;
		string d = emisor.descifrarConFirma(a, e, n);
		cout << d;
	}
	
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
