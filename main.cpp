#include <iostream>
#include <map>
#include <string>
#include "Huffman.h"
using namespace std;

int main() {

    // Logica para solicitar una cadena de mas de 30 caracteres
    string cadena;
    while (true) {
        getline(cin, cadena);
        if (cadena.length() > 30) {
            break;
        }else {
            cout << "La cadena es muy corta" << endl;
        }
    }
    cout << "Cadena aceptada: " << cadena << endl;

    //Contar la frecuencia de cada caracter en la cadena
    map <char, int> frecuencia;
    for (char c : cadena) {
        frecuencia[c]++;
    }
    // Mostrar la frecuencia de cada caracter
    for (auto par : frecuencia) {
        cout << par.first << ": " << par.second << endl;
    }


    // Construir árbol de Huffman
    Nodo* raiz = Huffman::construirArbol(frecuencia);

    // Imprimir códigos Huffman
    cout << "Codigos Huffman:\n";
    Huffman::imprimirCodigos(raiz);

    return 0;
}