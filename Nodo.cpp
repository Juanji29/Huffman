//
// Created by juan on 3/10/25.
//

#include "Nodo.h"
//Constructor
Nodo::Nodo(char car, int fre) {
    caracter = car;
    frecuencia = fre;
    izquierda = nullptr;
    derecha = nullptr;
}

//Getters
char Nodo::getCaracter() const {
    return caracter;
}
int Nodo::getFrecuencia() const {
    return frecuencia;
}
Nodo* Nodo::getIzquierda() const {
    return izquierda;
}
Nodo* Nodo::getDerecha() const {
    return derecha;
}
//Setters
void Nodo::setCaracter(char car) {
    caracter = car;
}
void Nodo::setFrecuencia(int fre) {
    frecuencia = fre;
}
void Nodo::setIzquierda(Nodo* izq) {
    izquierda = izq;
}
void Nodo::setDerecha(Nodo* der) {
    derecha = der;
}
