#include <iostream>
#include <string>
using namespace std;

// -------------------
// ESTRUCTURA DE PILA
// -------------------
struct NodoPila 
{
    int valor;
    NodoPila* siguiente;
};

NodoPila* crearPila() 
{
    return NULL;
}

void insertarEnPila(NodoPila*& cima, int valor) 
{
    NodoPila* nuevo = new NodoPila;
    nuevo->valor = valor;
    nuevo->siguiente = cima;
    cima = nuevo;
    cout << "Insertado en pila: " << valor << '\n';
}

bool buscarEnPila(NodoPila* cima, int valor) 
{
    NodoPila* actual = cima;
    while (actual != NULL) 
	{
        if (actual->valor == valor) return true;
        actual = actual->siguiente;
    }
    return false;
}

bool actualizarEnPila(NodoPila* cima, int antiguo, int nuevo) 
{
    NodoPila* actual = cima;
    while (actual != NULL) 
	{
        if (actual->valor == antiguo) 
		{
            actual->valor = nuevo;
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

void imprimirPila(NodoPila* cima) 
{
    if (cima == NULL) 
	{
        cout << "La pila está vacía." << '\n';
        return;
    }
    cout << "Pila [tope->base]: ";
    for (NodoPila* p = cima; p != NULL; p = p->siguiente) 
	{
        cout << p->valor << ' ';
    }
    cout << '\n';
}

void liberarPila(NodoPila*& cima) 
{
    while (cima != NULL) 
	{
        NodoPila* temp = cima;
        cima = cima->siguiente;
        delete temp;
    }
}


