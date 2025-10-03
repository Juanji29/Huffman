//
// Created by juan on 3/10/25.
//

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include "Nodo.h"
using namespace std;

// Comparador para priority_queue (min-heap)
struct Comparar {
    bool operator()(Nodo* a, Nodo* b) {
        return a->frecuencia > b->frecuencia;
    }
};

class Huffman {
public:
    // Construir árbol de Huffman a partir de tabla de frecuencias
    static Nodo* construirArbol(const map<char,int> &frecuencia) {
        priority_queue<Nodo*, vector<Nodo*>, Comparar> pq;

        // Crear nodo hoja por cada caracter y meterlo al heap
        for (auto par : frecuencia) {
            pq.push(new Nodo(par.first, par.second));
        }

        // Unir nodos hasta que quede solo uno
        while (pq.size() > 1) {
            Nodo* izq = pq.top(); pq.pop();
            Nodo* der = pq.top(); pq.pop();

            Nodo* padre = new Nodo('\0', izq->frecuencia + der->frecuencia);
            padre->izquierda = izq;
            padre->derecha = der;

            pq.push(padre);
        }

        return pq.top(); // raíz del árbol
    }

    // Imprimir códigos Huffman recorriendo el árbol
    static void imprimirCodigos(Nodo* raiz, string codigo = "") {
        if (!raiz) return;

        // Es hoja si tiene un caracter válido
        if (raiz->caracter != '\0') {
            cout << raiz->caracter << " -> " << codigo << endl;
        }

        imprimirCodigos(raiz->izquierda, codigo + "0");
        imprimirCodigos(raiz->derecha, codigo + "1");
    }
};

#endif
