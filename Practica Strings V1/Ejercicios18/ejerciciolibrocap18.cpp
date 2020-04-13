// ejerciciolibrocap18.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Ahorcado.h"

using namespace std;
string cifrar(string texto,string key,string alf) {
    string::iterator ini, fin;
    ini = texto.begin();
    fin = texto.end();
    for (ini; ini != fin; ini++) {
        int pos = alf.find(*ini);
        *ini = key[pos];
    }
    return texto;
}
string descifrar(string texto,string key, string alf) {
    string::iterator ini, fin;
    ini = texto.begin();
    fin = texto.end();
    for (ini; ini != fin; ini++) {
        int pos = key.find(*ini);
        *ini = alf[pos];
    }
    return texto;
}
void problema18_7() {
    string alfabeto = "abcdefghijklmnopqrstuvwxyz";
    string::iterator it = alfabeto.begin()+13;
    string key= string(it, alfabeto.end())+string(alfabeto.begin(),it);
    cout << alfabeto << endl;
    cout << key<<endl;

    string texto,cifrado,descifrado;
    getline(cin, texto);
    cifrado = cifrar(texto,key, alfabeto);
    cout <<cifrado<<endl;
    descifrado = descifrar(cifrado, key, alfabeto) ;
    cout << descifrado << endl;
}
void problema18_11() {
    string nombre, apellido, completo;
    cin >> nombre;
    cin >> apellido;

    completo = nombre + " " + apellido;
    cout << completo;
}

void replaceall(string word,string letra,string &guess) {
    for (int i = 0; i < word.size(); i++) {
        if (word[i]== letra[0]) {
            guess[i] = letra[0];
        }
    }
}
void problema18_12() {
    vector<string> palabras ={ "yolo","roberto","tarea","fue","coco","pocoyo","ragnar","odin","jesus","julinho" };
    Ahorcado juego(palabras);
    juego.play();
   

}
void problema18_19() {
    string asteriscos = "******";
    string texto;
    getline(cin, texto);
    int pos = texto.size() / 2;
    texto.insert(pos, asteriscos);
    cout << texto;
}
string intercambiar(string t1, string t2, string t3) {
    int pos = t1.find(t2);
    while (pos != -1) {
        string::iterator it = t1.begin() + pos;
        t1.replace(it, it + t2.size(), t3);
        pos = t1.find(t2);
    }
    return t1;
}
void problema18_21() {
    string texto;
    string signos[] = { ";",",","." };

    getline(cin, texto);
    for (int i = 0; i < 3; i++) {
        texto = intercambiar(texto, signos[i], " ");
    }
   /* int tam = texto.size();
    char* data = new char[tam];
    for (int i = 0; i < tam; i++) data[i] = texto[i];
    char* tok = strtok(data," ");

    while (tok != NULL) {
        printf(" %s\n", tok);

        tok = strtok(NULL, " ");
    }*/


}
void problema18_22() {
    string texto;
    getline(cin, texto);
    string::reverse_iterator ini, fin;
    ini = texto.rbegin();
    fin = texto.rend();
    for (ini; ini != fin; ini++) {
        cout << *ini;
    }
}
void problema18_27() {
    vector<string> data = { "g","f","t","i","q","c","d","l" };
    int tam = data.size();
    for (int i = 0; i < tam-2; i++) {
        int minimo = i;
        for (int j = i + 1; j <tam-1; j++) {
            if (data[j] < data[minimo]){
                minimo = j;
            }
        }
        data[i].swap(data[minimo]);
    }

    for (int y = 0; y < tam - 1; y++) {
        cout << data[y] << endl;
    }
}
int main()
{
    problema18_12();
    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
