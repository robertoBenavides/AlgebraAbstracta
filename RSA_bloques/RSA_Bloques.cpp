// RSA_Bloques.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <NTL/ZZ.h>
#include "RSABloques.h"
#include <bitset>
using namespace std;
NTL_CLIENT
ZZ mod(ZZ a, ZZ b)
{
	ZZ c = a - (a / b) * b;
	return (c < ZZ(0)) ? c + b : c;
}

ZZ mcd(ZZ a, ZZ b)
{
	ZZ r = mod(a, b);
	while (r != 0) {
		a = b;
		b = r;
		r = mod(a, b);
	}
	return b;
}

int main()
{
	RSABloques rsa(ZZ(31),ZZ(101),ZZ(353));
	
	cout << rsa.descifrar("0686");

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
