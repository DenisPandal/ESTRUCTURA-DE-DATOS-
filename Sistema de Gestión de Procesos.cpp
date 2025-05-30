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

// -------------------
// ESTRUCTURA DE COLA FIJA
// -------------------
#define MAX_COLA 5
int cola[MAX_COLA];
int frenteCol = -1;
int finalCol = -1;

bool colaVacia() 
{
    return frenteCol == -1;
}

bool colaLlena() 
{
    return finalCol == MAX_COLA - 1;
}

void encolar(int dato) 
{
    if (colaLlena()) 
	{
        cout << "La cola está llena." << '\n';
    } 
	else 
	{
        if (frenteCol == -1) frenteCol = 0;
        cola[++finalCol] = dato;
        cout << "Encolado: " << dato << '\n';
    }
}

bool buscarEnCola(int valor) 
{
    if (colaVacia()) return false;
    for (int i = frenteCol; i <= finalCol; ++i) 
	{
        if (cola[i] == valor) return true;
    }
    return false;
}

bool actualizarEnCola(int antiguo, int nuevo) 
{
    if (colaVacia()) return false;
    for (int i = frenteCol; i <= finalCol; ++i) 
	{
        if (cola[i] == antiguo) 
		{
            cola[i] = nuevo;
            return true;
        }
    }
    return false;
}

void imprimirCola() 
{
    if (colaVacia()) 
	{
        cout << "La cola está vacía." << '\n';
        return;
    }
    cout << "Cola [frente->final]: ";
    for (int i = frenteCol; i <= finalCol; ++i) 
	{
        cout << cola[i] << ' ';
    }
    cout << '\n';
}

void desencolar() 
{
    if (colaVacia()) 
	{
        cout << "La cola está vacía." << '\n';
    } 
	else 
	{
        cout << "Desencolado: " << cola[frenteCol] << '\n';
        if (frenteCol == finalCol) 
		{
            frenteCol = finalCol = -1;
        } 
		else 
		{
            ++frenteCol;
        }
    }
}

// -------------------
// GESTOR DE PROCESOS (LISTA ENLAZADA)
// -------------------
struct Proceso 
{
    int id;
    string nombre;
    int prioridad;
    Proceso* siguiente;
};
Proceso* listaProcesos = NULL;

void insertarProceso() 
{
    int id, prioridad;
    string nombre;
    cout << "Ingrese ID del proceso: "; cin >> id;
    cout << "Ingrese nombre del proceso: "; cin >> nombre;
    cout << "Ingrese prioridad del proceso: "; cin >> prioridad;
    Proceso* nuevo = new Proceso{ id, nombre, prioridad, listaProcesos };
    listaProcesos = nuevo;
    cout << "Proceso insertado." << '\n';
}

void buscarProceso() {
    int idBuscado;
    cout << "Ingrese ID del proceso a buscar: "; cin >> idBuscado;
    Proceso* p = listaProcesos;
    while (p != NULL) {
        if (p->id == idBuscado) {
            cout << "Proceso encontrado: " << p->nombre 
                 << " | Prioridad: " << p->prioridad << '\n';
            return;
        }
        p = p->siguiente;
    }
    cout << "Proceso no encontrado." << '\n';
}

void eliminarProceso() {
    int idEliminar;
    cout << "Ingrese ID del proceso a eliminar: "; cin >> idEliminar;
    Proceso* actual = listaProcesos;
    Proceso* anterior = NULL;
    while (actual != NULL) {
        if (actual->id == idEliminar) {
            if (anterior == NULL)
                listaProcesos = actual->siguiente;
            else
                anterior->siguiente = actual->siguiente;
            delete actual;
            cout << "Proceso eliminado." << '\n';
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    cout << "Proceso no encontrado." << '\n';
}

void modificarPrioridad() {
    int idMod;
    cout << "Ingrese ID del proceso a modificar: "; cin >> idMod;
    Proceso* p = listaProcesos;
    while (p != NULL) {
        if (p->id == idMod) {
            cout << "Prioridad actual: " << p->prioridad << '\n';
            int nueva;
            cout << "Ingrese nueva prioridad: "; cin >> nueva;
            p->prioridad = nueva;
            cout << "Prioridad modificada." << '\n';
            return;
        }
        p = p->siguiente;
    }
    cout << "Proceso no encontrado." << '\n';
}

// -------------------
// GESTOR DE MEMORIA (PILA)
// -------------------
NodoPila* pilaMemoria = crearPila();

void asignarBloqueMemoria() {
    int id;
    cout << "Ingrese ID del proceso al que asignar memoria: "; cin >> id;
    insertarEnPila(pilaMemoria, id);
    cout << "Bloque asignado." << '\n';
}

void liberarBloqueMemoria() {
    if (pilaMemoria == NULL) {
        cout << "No hay bloques para liberar." << '\n';
    } else {
        cout << "Bloque liberado del proceso: " << pilaMemoria->valor << '\n';
        NodoPila* temp = pilaMemoria;
        pilaMemoria = pilaMemoria->siguiente;
        delete temp;
    }
}

void estadoMemoria() {
    imprimirPila(pilaMemoria);
}

// -------------------
// PLANIFICADOR DE CPU (COLA PRIORITARIA)
// -------------------
struct NodoCPU 
{
    int id;
    int prioridad;
    NodoCPU* siguiente;
};
NodoCPU* colaCPU = NULL;

void encolarProcesoPrioridad(int id, int prio) 
{
    NodoCPU* nuevo = new NodoCPU{ id, prio, NULL };
    if (colaCPU == NULL || colaCPU->prioridad < prio) 
	{
        nuevo->siguiente = colaCPU;
        colaCPU = nuevo;
    } 
	else 
	{
        NodoCPU* p = colaCPU;
        while (p->siguiente != NULL && p->siguiente->prioridad >= prio)
            p = p->siguiente;
        nuevo->siguiente = p->siguiente;
        p->siguiente = nuevo;
    }
    cout << "Proceso encolado." << '\n';
}

void ejecutarProceso() 
{
    if (colaCPU == NULL) 
	{
        cout << "No hay procesos en cola." << '\n';
    } 
	else 
	{
        cout << "Ejecutando proceso: " << colaCPU->id 
             << " | Prioridad: " << colaCPU->prioridad << '\n';
        NodoCPU* tmp = colaCPU;
        colaCPU = colaCPU->siguiente;
        delete tmp;
    }
}

void mostrarColaPrioritaria() 
{
    if (colaCPU == NULL) 
	{
        cout << "Cola vacía." << '\n';
    } 
	else 
	{
        cout << "Cola de procesos (prioridad descendente):" << '\n';
        for (NodoCPU* p = colaCPU; p != NULL; p = p->siguiente) 
		{
            cout << "Proceso: " << p->id 
                 << " | Prioridad: " << p->prioridad << '\n';
        }
    }
}

// -------------------
// MENÚS
// -------------------

void gestorDeProcesos() 
{
    int op;
    do {
        cout << "\n===== GESTOR DE PROCESOS =====" << '\n';
        cout << "1. Insertar proceso" << '\n';
        cout << "2. Buscar proceso" << '\n';
        cout << "3. Eliminar proceso" << '\n';
        cout << "4. Modificar prioridad" << '\n';
        cout << "5. Salir" << '\n';
        cout << "Seleccione una opción: "; cin >> op;
        switch (op) 
		{
            case 1: insertarProceso(); break;
            case 2: buscarProceso(); break;
            case 3: eliminarProceso(); break;
            case 4: modificarPrioridad(); break;
            case 5: cout << "Saliendo del Gestor de Procesos..." << '\n'; break;
            default: cout << "Opción inválida." << '\n';
        }
    } while (op != 5);
}

void gestorDeMemoria() 
{
    int op;
    do {
        cout << "\n===== GESTOR DE MEMORIA =====" << '\n';
        cout << "1. Asignar bloque de memoria" << '\n';
        cout << "2. Liberar bloque de memoria" << '\n';
        cout << "3. Ver estado de la memoria" << '\n';
        cout << "4. Salir" << '\n';
        cout << "Seleccione una opción: "; cin >> op;
        switch (op) {
            case 1: asignarBloqueMemoria(); break;
            case 2: liberarBloqueMemoria(); break;
            case 3: estadoMemoria(); break;
            case 4: cout << "Saliendo del Gestor de Memoria..." << '\n'; break;
            default: cout << "Opción inválida." << '\n';
        }
    } while (op != 4);
}

void planificadorCPU() 
{
    int op;
    do {
        cout << "\n===== PLANIFICADOR DE CPU =====" << '\n';
        cout << "1. Encolar proceso" << '\n';
        cout << "2. Ejecutar proceso" << '\n';
        cout << "3. Mostrar cola de procesos" << '\n';
        cout << "4. Salir" << '\n';
        cout << "Seleccione una opción: "; cin >> op;
        switch (op) 
		{
            case 1: {
                int id, prio;
                cout << "Ingrese ID del proceso: "; cin >> id;
                cout << "Ingrese prioridad (mayor número = mayor prioridad): "; cin >> prio;
                encolarProcesoPrioridad(id, prio);
                break;
            }
            case 2: ejecutarProceso(); break;
            case 3: mostrarColaPrioritaria(); break;
            case 4: cout << "Saliendo del Planificador de CPU..." << '\n'; break;
            default: cout << "Opción inválida." << "\n";
        }
    } while (op != 4);
}

int main() 
{
    setlocale(LC_CTYPE, "Spanish");
    int opcion;
    do {
        cout << "\n===== SISTEMA DE GESTIÓN DE PROCESOS =====" << '\n';
        cout << "1. Gestor de Procesos" << '\n';
        cout << "2. Gestor de Memoria" << '\n';
        cout << "3. Planificador de CPU" << '\n';
        cout << "4. Salir" << '\n';
        cout << "Seleccione una opción: "; cin >> opcion;
        switch (opcion) 
		{
            case 1: gestorDeProcesos(); break;
            case 2: gestorDeMemoria(); break;
            case 3: planificadorCPU(); break;
            case 4: cout << "Saliendo del sistema..." << '\n'; break;
            default: cout << "Opción inválida." << '\n';
        }
    } while (opcion != 4);
    return 0;
}
