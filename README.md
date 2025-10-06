# Huffman
Practica 2 Estructura de Datos, Algoritmo de Huffman, y codigos canonicos de huffman
# Proyecto de Compresión con Código Huffman

## 👥 Integrantes del equipo
- **Juan Esteban Jiménez Cardona** - jejimenez1@eafit.edu.co
- **Thomas Bedoya Rendon** - tbedoyar1@eafit.edu.co

---

## Link del vídeo

https://youtu.be/WcU1Gn5d2_M

--

## 🧩 Descripción del proyecto
Este proyecto implementa el **algoritmo de codificación de Huffman**, una técnica de compresión sin pérdida que asigna códigos binarios más cortos a los caracteres más frecuentes.  
El programa construye un árbol de Huffman a partir de las frecuencias de los símbolos, genera los códigos correspondientes y permite codificar texto.  
Fue desarrollado en **C++**, usamos ayuda de IA's como son copilot y chatGPT, haciendo uso de estructuras dinámicas y colas de prioridad para garantizar eficiencia.  

---

## 🧠 Explicación del Huffman Canónico

El Huffman canónico es una variante del algoritmo de Huffman que asigna códigos de manera ordenada y determinista.
Primero, los símbolos se ordenan por la longitud de sus códigos (de menor a mayor) y, en caso de empate, por orden alfabético.
El primer símbolo recibe el código más pequeño (por ejemplo, todos ceros), y los siguientes se generan incrementando el valor binario anterior.
Este enfoque permite reconstruir los códigos únicamente conociendo sus longitudes, reduce el espacio de almacenamiento y mantiene la propiedad de prefijo libre.
Además, facilita la decodificación sin necesidad de reconstruir el árbol original.

---

## Decisiones de diseño
Estructuras de datos: se utilizó una cola de prioridad (min-heap) para obtener eficientemente los dos nodos con menor frecuencia.

Representación del árbol: cada nodo contiene el carácter, su frecuencia y punteros a los nodos hijo izquierdo y derecho.

Generación de códigos: se realiza de forma recursiva, agregando 0 al moverse a la izquierda y 1 al moverse a la derecha.

---

## Como usarlo

1. Ingresar una cadena de texto de mas de 30 caracteres
Ejemplo: "El algoritmo de Huffman comprime datos sin perdida de informacion"

```console
Cadena aceptada: El algoritmo de Huffman comprime datos sin perdida de informacion
 : 9
E: 1
H: 1
a: 5
c: 2
d: 5
e: 4
f: 3
g: 1
i: 6
l: 2
m: 5
n: 4
o: 6
p: 2
r: 4
s: 2
t: 2
u: 1
Codigos Huffman:
i -> 000
o -> 001
n -> 0100
p -> 01010
t -> 01011
g -> 011000
u -> 011001
l -> 01101
c -> 01110
E -> 011110
H -> 011111
e -> 1000
r -> 1001
  -> 101
d -> 1100
s -> 11010
f -> 11011
m -> 1110
a -> 1111
                                ┌──1─ a
                        ┌──1─ *
                                └──0─ m
                ┌──1─ *
                                        ┌──1─ f
                                ┌──1─ *
                                        └──0─ s
                        └──0─ *
                                └──0─ d
        ┌──1─ *
                        ┌──1─  
                └──0─ *
                                ┌──1─ r
                        └──0─ *
                                └──0─ e
*
                                                ┌──1─ H
                                        ┌──1─ *
                                                └──0─ E
                                ┌──1─ *
                                        └──0─ c
                        ┌──1─ *
                                        ┌──1─ l
                                └──0─ *
                                                ┌──1─ u
                                        └──0─ *
                                                └──0─ g
                ┌──1─ *
                                        ┌──1─ t
                                ┌──1─ *
                                        └──0─ p
                        └──0─ *
                                └──0─ n
        └──0─ *
                        ┌──1─ o
                └──0─ *
                        └──0─ i

Codigos Canonicos:
o -> 000
i -> 001
  -> 010
a -> 0110
m -> 0111
d -> 1000
r -> 1001
e -> 1010
n -> 1011
c -> 11000
l -> 11001
t -> 11010
s -> 11011
f -> 11100
p -> 11101
E -> 111100
H -> 111101
u -> 111110
g -> 111111

Cadena comprimida (canónica): 11110011001010011011001111111000100100111010011100001010001010010111101111110111001110001110110101101011000000011111101100100101111010010100001101101000011011010110110011011010111011010100110000011000011001010001010010001101111100000100101110110110000010001011

Tamaño original: 520 bits
Tamaño comprimido: 260 bits
Tasa de compresión: 0.5
Reducción de tamaño: 50%
