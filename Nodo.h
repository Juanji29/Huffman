//
// Created by juan on 3/10/25.
//

#ifndef HOFFMAN_NODO_H
#define HOFFMAN_NODO_H


class Nodo {
public:
    char caracter;
    int frecuencia;
    Nodo *izquierda;
    Nodo *derecha;
//Constructor
    Nodo(char caracter, int frecuencia);

//Getters
    char getCaracter() const;
    int getFrecuencia() const;
    Nodo* getIzquierda() const;
    Nodo* getDerecha() const;
//Setters
    void setCaracter(char caracter);
    void setFrecuencia(int frecuencia);
    void setIzquierda(Nodo* izquierda);
    void setDerecha(Nodo* derecha);
};


#endif //HOFFMAN_NODO_H