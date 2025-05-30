// -------------------
// ELABORADO POR PANDAL AQUINO DENIS JESUS
// -------------------

// PLANIFICADOR DE CPU (COLA PRIORITARIA)
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

