#include "Vigener.h"
Vigener::Vigener(string key)
{
    clave = key;
}

string Vigener::cifrado(string mensaje)
{
    string nclave = newclave(mensaje);
    string coded;
 
    for (int i = 0; i < mensaje.size(); i++) {
        int pos1, pos2;
        pos1 = abecedario.find(mensaje[i]);
        pos2 = abecedario.find(nclave[i]);

        int finalpos = pos1 + pos2;
        if (finalpos > abecedario.size()-1) {
            finalpos = finalpos % (abecedario.size());
        }
        if (finalpos >(abecedario.size() - 1)) finalpos -= (abecedario.size()-1);
        coded += abecedario.at(finalpos);
    }

    return coded;
}

string Vigener::descifrado(string mensaje)
{
    string nclave = newclave(mensaje);
    string coded;

    for (int i = 0; i < mensaje.size(); i++) {
        int pos1, pos2;
        pos1 = abecedario.find(mensaje[i]);
        pos2 = abecedario.find(nclave[i]);

        int finalpos = pos1 - pos2;
        int tam = abecedario.size() - 1;
        if (finalpos >tam) {
            finalpos = finalpos % tam;
        }
        if (finalpos < 0) finalpos += (abecedario.size());
        coded += abecedario.at(finalpos);
    }
    return coded;
}

string Vigener::newclave(string mensaje)
{
    string newclave;
    if (clave.size() < mensaje.size()) {
        int times = mensaje.size() / clave.size();
        int sobra = mensaje.size() % clave.size();
        while (times != 0) {
            newclave += clave;
            times--;
        }
        newclave += string(clave.begin(), clave.begin() + sobra);
    }
    else {
        newclave = string(clave.begin(), clave.begin() + (mensaje.size() - clave.size()));
    }
    return newclave;
}
