// AlgoritmoEuclides.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <ctime>
#include <NTL/ZZ.h>

NTL_CLIENT

ZZ mod(ZZ a, ZZ b) {
    return a - (a / b) * b;
}
ZZ alg1(ZZ a,ZZ b) {
    ZZ r;
    do{
        r= mod(a,b);
        a = b;
        b = r;
    } while (r != ZZ(0));
    return b;
}
ZZ alg2(ZZ a ,ZZ b) {
    ZZ r; 
    do {
        r=mod(a, b);
        if (r > b / 2) r = b - r;
        a = b;
        b = r;
    } while (r != 0);
    return b;
}
ZZ alg3(ZZ a,ZZ b) {
    if (b == 0) return a;
    return alg3(b, mod(a, b));
}
ZZ alg4(ZZ a, ZZ b) {
    if (abs(b) > abs(a))return alg4(b,a);
    if (b == 0) return a;
    if (mod(a, ZZ(2)) == ZZ(0) && mod(b, ZZ(2)) == ZZ(0))return 2*alg4(a / 2, b / 2);
    if (mod(a, ZZ(2))== ZZ(0) && mod(b, ZZ(2))!= ZZ(0))return alg4(a / 2, b );
    if (mod(a, ZZ(2))!= ZZ(0) && mod(b, ZZ(2))== ZZ(0))return alg4(a , b / 2);
    return alg4((abs(a) - abs(b)) / 2, b);
}
ZZ alg5(ZZ a, ZZ b) {
    ZZ g = ZZ(1);
    while (mod(a, ZZ(2))== ZZ(0) && mod(a, ZZ(2)) == ZZ(0)) {
        a = a / 2;
        b = b / 2;
        g = 2 * g;
    }
    while (a != 0) {
        while (mod(a,ZZ(2)) == ZZ(0))
        {
            a = a / 2;
        }
        while (mod(a, ZZ(2)) == ZZ(0))
        {
            b = b / 2;
        }
        ZZ t = abs(a - b) / 2;
        if (a >= b) a = t;
        else b = t;
    }
    return g * b;
}
ZZ alg6(ZZ a, ZZ b) {
    while (a!=b)
    {
        if (a > b) a = a - b;
        else b = b - a;
    }
    return b;
}

int main()
{
    ZZ a, b;
    cin >> a;
    cin >> b;
    double t0 = clock();
        cout<<alg1(a, b)<<endl;
    double t1 = clock();
    double time = ((t1 - t0) / CLOCKS_PER_SEC);
    cout << time;
    t0 = clock();
    cout << alg2(a, b) << endl;
    t1 = clock();
    time = ((t1 - t0) / CLOCKS_PER_SEC);
    cout << time; t0 = clock();
    cout << alg3(a, b) << endl;
    t1 = clock();
    time = ((t1 - t0) / CLOCKS_PER_SEC);
    cout << time; t0 = clock();
    //cout << alg4(a, b) << endl;
    t1 = clock();
    time = ((t1 - t0) / CLOCKS_PER_SEC);
    cout << time; t0 = clock();
    cout << alg5(a, b) << endl;
    t1 = clock();
    time = ((t1 - t0) / CLOCKS_PER_SEC);
    cout << time; t0 = clock();
    cout << alg6(a, b) << endl;
    t1 = clock();
    time = ((t1 - t0) / CLOCKS_PER_SEC);
    cout << time;

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
