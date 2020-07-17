// CribaEratostenes.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <NTL/zz.h>
NTL_CLIENT

ZZ exponenciacion(ZZ a, ZZ m, ZZ n) {
ZZ eleb = a;
ZZ resultado = mod(eleb,n);
m = m/2;
while (m != 0) {
eleb= mod(eleb*eleb, n);
if (mod(m, ZZ(2)) == ZZ(1)) {
resultado = mod(resultado*eleb, n);
}
m = m / 2;
}
return resultado;
}
int main()
{
ZZ a, m, n;
cin >> a >> m >> n;
cerr << exponenciacion(a, m, n);
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
