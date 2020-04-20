#include "VigenereE.h"
VigenereE::VigenereE(string key)
{
    clave = key;
}

string VigenereE::cifrado(string mensaje)
{
    mensaje = addWord(mensaje);
    string nclave = newclave(mensaje);
    string coded;

    for (int i = 0; i < mensaje.size(); i++) {
        int pos1, pos2;
        pos1 = abecedario.find(mensaje[i]);
        pos2 = abecedario.find(nclave[i]);

        int finalpos = pos1 + pos2;
        if (finalpos > abecedario.size() - 1) {
            finalpos = finalpos % (abecedario.size());
        }
        if (finalpos > (abecedario.size() - 1)) finalpos -= (abecedario.size() - 1);
        coded += abecedario.at(finalpos);
    }

    return coded;
}

string VigenereE::descifrado(string mensaje)
{
    string nclave = newclave(mensaje);
    string coded;

    for (int i = 0; i < mensaje.size(); i++) {
        int pos1, pos2;
        pos1 = abecedario.find(mensaje[i]);
        pos2 = abecedario.find(nclave[i]);

        int finalpos = pos1 - pos2;
        int tam = abecedario.size() - 1;
        if (finalpos > tam) {
            finalpos = finalpos % tam;
        }
        if (finalpos < 0) finalpos += (abecedario.size());
        coded += abecedario.at(finalpos);
    }
    coded=deleteword(coded);
    return coded;
}

string VigenereE::newclave(string mensaje)
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

string VigenereE::addWord(string mensaje)
{
    int times=mensaje.size() / 10;
    int postoinsert = 0;
    while (times != 0) {
        postoinsert += 9;
        times--;
        mensaje.insert(postoinsert, "AQUI");
        postoinsert += 4;
        
    }
    int mult4=mensaje.size()%4;
    if (mult4 != 0) {
        mensaje += "W";
        mult4--;
    }
    return mensaje;
}

string VigenereE::deleteword(string mensaje)
{
    int forw = 3,lastpos;
    lastpos = mensaje.size()-1;
    while (forw != 0) {
        if (mensaje[lastpos] != 'W')
            forw = 0;
        else
            forw--;
    }
    mensaje = string(mensaje.begin(), mensaje.begin() + lastpos);

    //deleting aqui
    int pos=9;
    while (pos < mensaje.size()) {
        mensaje.erase(pos, 4);
        pos += 9;
    }
    
    return mensaje;
}

