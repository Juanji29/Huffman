#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <bitset>
#include "Huffman.h"
using namespace std;

int main() {

    // Logica para solicitar una cadena de mas de 30 caracteres
    string cadena;
    cout << "Ingrese una cadena de más de 30 caracteres: " << endl;
    while (true) {
         getline(cin, cadena);
         if (cadena.length() > 30) {
             break;
         }else {
             cout << "La cadena es muy corta, debe ser de mas de 30 caracteres.\n" << "Tu cadena contiene: " << cadena.length()<< " caracteres"<< endl;
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


    // Obtener códigos de Huffman
    vector<pair<char, string>> codigos;
    Huffman::obtenerCodigos(raiz, "", codigos);



    // Imprimir códigos Huffman
    cout << "Codigos Huffman:\n";
    for (const auto &par : codigos) {
        cout << par.first << " -> " << par.second << endl;
    }

    //Dibujar Arbol
    Huffman::dibujarArbol(raiz, "", false, true);



    //Huffman Canonico
    cout << "\nCodigos Canonicos:\n";
    //Ordenar por longitud
    sort(codigos.begin(), codigos.end(), [](const pair<char, string> &a, const pair<char, string> &b) {
        return a.second.length() < b.second.length();
    });

    //Generar códigos canónicos
    vector<pair<char, string>> codigosCanonicos;
    int codigoActual = 0;
    int longitudAnterior = 0;

    for (const auto &par : codigos) {
        int longitud = par.second.length();
        if (longitud != longitudAnterior) {
            codigoActual <<= (longitud - longitudAnterior);
            longitudAnterior = longitud;
        }
        // Convertir el código actual a binario con longitud adecuada
        string canonico = bitset<32>(codigoActual).to_string().substr(32 - longitud);
        codigosCanonicos.push_back({par.first, canonico});
        codigoActual++;
    }

    // Imprimir los códigos canónicos
    for (const auto &par : codigosCanonicos) {
        cout << par.first << " -> " << par.second << endl;
    }


    //Códigos canónicos
    map<char, string> mapaCanonico;
    for (const auto &par : codigosCanonicos) {
        mapaCanonico[par.first] = par.second;
    }

    // Comprimir la cadena
    string comprimida;
    for (char c : cadena) {
        comprimida += mapaCanonico[c];
    }

    cout << "\nCadena comprimida (canónica): " << comprimida << endl;
    cout << "\nTamaño original: " << cadena.length() * 8 << " bits" << endl;
    cout << "Tamaño comprimido: " << comprimida.length() << " bits" << endl;
    float ratio = (float)comprimida.length()/ (float)(cadena.length() * 8);
    cout << "Tasa de compresión: " << ratio << endl;
    cout << "Reducción de tamaño: " << (1 - ratio) * 100 << "%" << endl;

    return 0;
}