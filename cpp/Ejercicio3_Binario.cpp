#include <iostream>
#include <algorithm> // util para std::max
using namespace std;

// Asumiendo la estructura Nodo del Ejercicio 2
struct Nodo {
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;
    Nodo(int v) : valor(v), izquierdo(nullptr), derecho(nullptr) {}
};

int calcularAltura(Nodo* raiz) {
    // Si el nodo es nulo, la altura es 0
    if (raiz == nullptr) return 0;

    // Calculamos la altura de cada subárbol
    int alturaIzq = calcularAltura(raiz->izquierdo);
    int alturaDer = calcularAltura(raiz->derecho);

    // La altura del árbol es el mayor entre los dos lados más 1 (por el nodo actual)
    return 1 + max(alturaIzq, alturaDer);
}

int main() {
    Nodo* raiz = new Nodo(1);
    raiz->derecho = new Nodo(2);
    raiz->derecho->izquierdo = new Nodo(3);
    
    cout << "--- Prueba Ejercicio 3 ---" << endl;
    cout << "Altura esperada: 3" << endl;
    cout << "Altura calculada: " << calcularAltura(raiz) << endl;
    cout << "Altura de arbol nulo (esperado 0): " << calcularAltura(nullptr) << endl;

    return 0;
}
