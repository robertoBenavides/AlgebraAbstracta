#include "vigenere3f.h"

vigenere3f::vigenere3f(string key)
{
    clave = key;
}

string vigenere3f::cifrado(string mensaje)
{
    string nclave = newclave(mensaje);
    string coded;

    for (int i = 0; i < mensaje.size(); i++) {
        int pos1, pos2;
        if (abecedario.find(mensaje[i]) == string::npos) coded += mensaje[i];
        else {
            pos1 = abecedario.find(mensaje[i]);
            pos2 = abecedario.find(nclave[i]);

            int finalpos = pos1 + pos2;
            if (finalpos > abecedario.size() - 1) {
                finalpos = finalpos % (abecedario.size());
            }
            if (finalpos > (abecedario.size() - 1)) finalpos -= (abecedario.size() - 1);
            coded += abecedario.at(finalpos);
        }
    }

    return coded;
}

string vigenere3f::descifrado(string mensaje)
{
    string coded;

    for (int i = 0; i < mensaje.size(); i++) {
        int pos1, pos2;
        if (abecedario.find(mensaje[i]) == string::npos) coded += mensaje[i];
        else {
            pos1 = abecedario.find(mensaje[i]);
            if (i < clave.size())
                pos2 = abecedario.find(clave[i]);
            else {
                int newpos = i - clave.size();
                pos2 = abecedario.find(coded[newpos]);
            }


            int finalpos = pos1 - pos2;
            int tam = abecedario.size() - 1;
            if (finalpos > tam) {
                finalpos = finalpos % tam;
            }
            if (finalpos < 0) finalpos += (abecedario.size());
            coded += abecedario.at(finalpos);
        }
    }
    return coded;
}

string vigenere3f::newclave(string mensaje)
{
    string newclave;
    if (clave.size() < mensaje.size()) {
        int missing = mensaje.size() - clave.size();
        newclave += clave + string(mensaje.begin(), mensaje.begin() + missing);
    }
    
    return newclave;
}
