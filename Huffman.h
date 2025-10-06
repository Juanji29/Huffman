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
#include "Nodo.h"// Modificación en Huffman.h


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

    //Obtener los códigos de Huffman desde el árbol
    static void obtenerCodigos(Nodo* raiz, string codigo, vector<pair<char, string>> &codigos) {
        if (!raiz) return;

        if (raiz->caracter != '\0') {
            codigos.push_back({raiz->caracter, codigo});
        }

        obtenerCodigos(raiz->izquierda, codigo + "0", codigos);
        obtenerCodigos(raiz->derecha, codigo + "1", codigos);
    }

    //Dibujar Arbol

    static void dibujarArbol(Nodo* nodo, const std::string& prefijo = "", bool esDerecha = false, bool esRaiz = true) {
        if (!nodo) return;
        // Dibuja primero la derecha (1)
        dibujarArbol(nodo->derecha, prefijo + "        ", true, false);

        std::cout << prefijo;
        if (!esRaiz) {
            std::cout << (esDerecha ? "┌──1─ " : "└──0─ ");
        }

        if (!nodo->izquierda && !nodo->derecha) {
            std::cout << nodo->caracter << std::endl;
        } else {
            std::cout << "*" << std::endl;
        }
        // Dibuja la izquierda (0)
        dibujarArbol(nodo->izquierda, prefijo + "        ", false, false);
    }


    // Para imprimir los códigos después:
    static void imprimirCodigos(Nodo* raiz) {
        vector<pair<char, string>> codigos;
        obtenerCodigos(raiz, "", codigos);
        for (const auto &par : codigos) {
            cout << par.first << " -> " << par.second << endl;
        }
    }
};

#endif
