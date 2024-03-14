#include<iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;
};

void insertardatos();
void mostrardatos();
void buscarmenormayorsuma();

Nodo* lista = NULL;

int main() {
    insertardatos();
    insertardatos();
    insertardatos();
    insertardatos();
    insertardatos();

    cout << "Los Numeros Digitados son: ";
    mostrardatos();

    buscarmenormayorsuma();

    return 0;
}

void insertardatos() {
    Nodo* nuevo = new Nodo();

    cout << "Digite el numero a ingresar: ";
    cin >> nuevo->dato;

    if (lista == NULL) {
        lista = nuevo;
        lista->siguiente = NULL;
        lista->anterior = NULL;
    } else {
        Nodo* primero = lista;
        while (primero->siguiente != NULL) {
            primero = primero->siguiente;
        }
        primero->siguiente = nuevo;
        nuevo->anterior = primero;
        nuevo->siguiente = NULL;
    }
}

void mostrardatos() {
    Nodo* primero = lista;
    while (primero != NULL) {
        cout << primero->dato << " ";
        primero = primero->siguiente;
    }
    cout << endl;
}

void buscarmenormayorsuma() {
    Nodo* actual = lista;
    int suma = 0;
    int menor = actual->dato;
    int mayor = actual->dato;

    while (actual != NULL) {
        suma += actual->dato;
        if (actual->dato < menor) {
            menor = actual->dato;
        }
        if (actual->dato > mayor) {
            mayor = actual->dato;
        }
        actual = actual->siguiente;
    }

    cout << "La suma de los numeros ingresados es: " << suma << endl;
    cout << "El menor numero ingresado es: " << menor << endl;
    cout << "El mayor numero ingresado es: " << mayor << endl;
}

