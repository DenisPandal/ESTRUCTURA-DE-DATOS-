// -------------------
// ELABORADO POR PANDAL AQUINO DENIS JESUS
// -------------------

// GESTOR DE MEMORIA (PILA)
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
