// --------------------------------------------------------
// GESTOR DE PROCESOS USANDO LISTA ENLAZADA SIMPLE
// Autor: BENITES FIERRO ALEXANDER
// --------------------------------------------------------

#include <iostream>
using namespace std;

// --------------------------------------------------------
// ESTRUCTURA DEL PROCESO
// Cada nodo contiene: ID, nombre, prioridad y puntero al siguiente proceso
// --------------------------------------------------------
struct Proceso 
{
    int id;                // Identificador único del proceso
    string nombre;         // Nombre del proceso
    int prioridad;         // Nivel de prioridad del proceso (menor valor = más prioridad)
    Proceso* siguiente;    // Puntero al siguiente proceso en la lista
};

// --------------------------------------------------------
// PUNTERO PRINCIPAL DE LA LISTA ENLAZADA
// Inicialmente no hay procesos, por lo tanto es NULL
// --------------------------------------------------------
Proceso* listaProcesos = NULL;

// --------------------------------------------------------
// FUNCIÓN: insertarProceso()
// Descripción: Solicita datos al usuario, crea un nuevo proceso
// y lo inserta al inicio de la lista enlazada.
// --------------------------------------------------------
void insertarProceso() 
{
    int id, prioridad;
    string nombre;

    // Entrada de datos desde el usuario
    cout << "Ingrese ID del proceso: "; cin >> id;
    cout << "Ingrese nombre del proceso: "; cin >> nombre;
    cout << "Ingrese prioridad del proceso: "; cin >> prioridad;

    // Crear un nuevo nodo Proceso y enlazarlo al inicio
    Proceso* nuevo = new Proceso{ id, nombre, prioridad, listaProcesos };

    // Actualizar el inicio de la lista
    listaProcesos = nuevo;

    cout << "? Proceso insertado correctamente.\n";
}

// --------------------------------------------------------
// FUNCIÓN: buscarProceso()
// Descripción: Busca un proceso por su ID y muestra sus datos
// --------------------------------------------------------
void buscarProceso() 
{
    int idBuscado;

    cout << "Ingrese ID del proceso a buscar: "; cin >> idBuscado;

    Proceso* p = listaProcesos;  // Empezar desde el inicio de la lista

    // Recorrer la lista buscando el ID
    while (p != NULL) {
        if (p->id == idBuscado) {
            cout << "?? Proceso encontrado:\n";
            cout << "Nombre: " << p->nombre << " | Prioridad: " << p->prioridad << '\n';
            return;
        }
        p = p->siguiente; // Avanzar al siguiente nodo
    }

    // Si no se encuentra el proceso
    cout << "? Proceso no encontrado.\n";
}

// --------------------------------------------------------
// FUNCIÓN: eliminarProceso()
// Descripción: Elimina un proceso de la lista por su ID
// --------------------------------------------------------
void eliminarProceso() 
{
    int idEliminar;

    cout << "Ingrese ID del proceso a eliminar: "; cin >> idEliminar;

    Proceso* actual = listaProcesos;
    Proceso* anterior = NULL;

    // Recorrer la lista buscando el proceso
    while (actual != NULL) {
        if (actual->id == idEliminar) {
            // Caso: El proceso a eliminar es el primero de la lista
            if (anterior == NULL)
                listaProcesos = actual->siguiente;
            else
                anterior->siguiente = actual->siguiente;

            // Liberar la memoria del nodo eliminado
            delete actual;
            cout << "??? Proceso eliminado correctamente.\n";
            return;
        }

        // Avanzar en la lista
        anterior = actual;
        actual = actual->siguiente;
    }

    // Si no se encuentra el proceso
    cout << "? Proceso no encontrado.\n";
}

// --------------------------------------------------------
// FUNCIÓN: modificarPrioridad()
// Descripción: Permite cambiar la prioridad de un proceso
// buscándolo por su ID
// --------------------------------------------------------
void modificarPrioridad() 
{
    int idMod;

    cout << "Ingrese ID del proceso a modificar: "; cin >> idMod;

    Proceso* p = listaProcesos;

    // Buscar el proceso en la lista
    while (p != NULL) {
        if (p->id == idMod) {
            cout << "Prioridad actual: " << p->prioridad << '\n';

            int nueva;
            cout << "Ingrese nueva prioridad: "; cin >> nueva;

            // Actualizar la prioridad
            p->prioridad = nueva;

            cout << "? Prioridad modificada correctamente.\n";
            return;
        }

        // Avanzar al siguiente proceso
        p = p->siguiente;
    }

    // Si no se encuentra el proceso
    cout << "? Proceso no encontrado.\n";
}

