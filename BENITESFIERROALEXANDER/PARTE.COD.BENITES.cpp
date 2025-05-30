// -------------------
// GESTOR DE PROCESOS (LISTA ENLAZADA)
// -------------------
//BENITES FIERRO ALEXANDER



struct Proceso 
{
    int id;                // Identificador único del proceso
    string nombre;         // Nombre del proceso
    int prioridad;         // Nivel de prioridad del proceso
    Proceso* siguiente;    // Puntero al siguiente proceso en la lista
};

// Puntero que apunta al primer proceso de la lista (inicialmente vacío)
Proceso* listaProcesos = NULL;

void insertarProceso() 
{
    int id, prioridad;
    string nombre;

    // Solicita datos del proceso al usuario
    cout << "Ingrese ID del proceso: "; cin >> id;
    cout << "Ingrese nombre del proceso: "; cin >> nombre;
    cout << "Ingrese prioridad del proceso: "; cin >> prioridad;

    // Crea un nuevo nodo de tipo Proceso y lo enlaza al inicio de la lista
    Proceso* nuevo = new Proceso{ id, nombre, prioridad, listaProcesos };
    listaProcesos = nuevo;

    // Confirma que el proceso fue insertado
    cout << "Proceso insertado." << '\n';
}

void buscarProceso() {
    int idBuscado;

    // Solicita el ID del proceso a buscar
    cout << "Ingrese ID del proceso a buscar: "; cin >> idBuscado;

    Proceso* p = listaProcesos;

    // Recorre la lista buscando un proceso con el ID especificado
    while (p != NULL) {
        if (p->id == idBuscado) {
            // Si se encuentra, muestra su nombre y prioridad
            cout << "Proceso encontrado: " << p->nombre 
                 << " | Prioridad: " << p->prioridad << '\n';
            return;
        }
        p = p->siguiente; // Avanza al siguiente proceso
    }

    // Si no se encuentra el proceso
    cout << "Proceso no encontrado." << '\n';
}

void eliminarProceso() {
    int idEliminar;

    // Solicita el ID del proceso a eliminar
    cout << "Ingrese ID del proceso a eliminar: "; cin >> idEliminar;

    Proceso* actual = listaProcesos;
    Proceso* anterior = NULL;

    // Recorre la lista buscando el proceso con el ID indicado
    while (actual != NULL) {
        if (actual->id == idEliminar) {
            // Si es el primer proceso de la lista
            if (anterior == NULL)
                listaProcesos = actual->siguiente;
            else
                anterior->siguiente = actual->siguiente;

            // Libera la memoria del proceso eliminado
            delete actual;
            cout << "Proceso eliminado." << '\n';
            return;
        }

        // Avanza al siguiente nodo
        anterior = actual;
        actual = actual->siguiente;
    }

    // Si no se encuentra el proceso
    cout << "Proceso no encontrado." << '\n';
}

void modificarPrioridad() {
    int idMod;

    // Solicita el ID del proceso cuya prioridad se desea modificar
    cout << "Ingrese ID del proceso a modificar: "; cin >> idMod;

    Proceso* p = listaProcesos;

    // Recorre la lista buscando el proceso correspondiente
    while (p != NULL) {
        if (p->id == idMod) {
            // Muestra la prioridad actual
            cout << "Prioridad actual: " << p->prioridad << '\n';

            int nueva;
            // Solicita la nueva prioridad
            cout << "Ingrese nueva prioridad: "; cin >> nueva;

            // Asigna la nueva prioridad al proceso
            p->prioridad = nueva;

            cout << "Prioridad modificada." << '\n';
            return;
        }

        // Avanza al siguiente proceso
        p = p->siguiente;
    }

    // Si no se encuentra el proceso
    cout << "Proceso no encontrado." << '\n';
}

