
// -------------------
// MENuS
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
        cout << "Seleccione una opcion: "; cin >> op;
        switch (op) 
		{
            case 1: insertarProceso(); break;
            case 2: buscarProceso(); break;
            case 3: eliminarProceso(); break;
            case 4: modificarPrioridad(); break;
            case 5: cout << "Saliendo del Gestor de Procesos..." << '\n'; break;
            default: cout << "Opcion invalida." << '\n';
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
        cout << "Seleccione una opcion: "; cin >> op;
        switch (op) {
            case 1: asignarBloqueMemoria(); break;
            case 2: liberarBloqueMemoria(); break;
            case 3: estadoMemoria(); break;
            case 4: cout << "Saliendo del Gestor de Memoria..." << '\n'; break;
            default: cout << "Opcion invalida." << '\n';
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
        cout << "Seleccione una opcion: "; cin >> op;
        switch (op) 
		{
            case 1: {
                int id, prio;
                cout << "Ingrese ID del proceso: "; cin >> id;
                cout << "Ingrese prioridad (mayor n?mero = mayor prioridad): "; cin >> prio;
                encolarProcesoPrioridad(id, prio);
                break;
            }
            case 2: ejecutarProceso(); break;
            case 3: mostrarColaPrioritaria(); break;
            case 4: cout << "Saliendo del Planificador de CPU..." << '\n'; break;
            default: cout << "Opcion invalida." << "\n";
        }
    } while (op != 4);
}

int main() 
{
    setlocale(LC_CTYPE, "Spanish");
    int opcion;
    do {
        cout << "\n===== SISTEMA DE GESTI?N DE PROCESOS =====" << '\n';
        cout << "1. Gestor de Procesos" << '\n';
        cout << "2. Gestor de Memoria" << '\n';
        cout << "3. Planificador de CPU" << '\n';
        cout << "4. Salir" << '\n';
        cout << "Seleccione una opcion: "; cin >> opcion;
        switch (opcion) 
		{
            case 1: gestorDeProcesos(); break;
            case 2: gestorDeMemoria(); break;
            case 3: planificadorCPU(); break;
            case 4: cout << "Saliendo del sistema..." << '\n'; break;
            default: cout << "Opcion invalida." << '\n';
        }
    } while (opcion != 4);
    return 0;
}
