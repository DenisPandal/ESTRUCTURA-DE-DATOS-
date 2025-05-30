Proceso SistemaDeGestionDeProcesos
    Definir opcion Como Entero
    Repetir
        Escribir "===== MENÚ PRINCIPAL ====="
        Escribir "1. Gestor de Procesos"
        Escribir "2. Planificador de CPU"
        Escribir "3. Gestor de Memoria"
        Escribir "4. Salir"
        Escribir "Seleccione una opción: "
        Leer opcion
		
        Segun opcion Hacer
            Caso 1:
                GestorDeProcesos()
            Caso 2:
                PlanificadorCPU()
            Caso 3:
                GestorDeMemoria()
            Caso 4:
                Escribir "Saliendo del sistema..."
            De Otro Modo:
                Escribir "Opción inválida. Intente de nuevo."
        FinSegun
    Hasta Que opcion = 4
FinProceso

SubProceso GestorDeProcesos
    Definir subopcion, id, prioridad Como Entero
    Definir nombre, estado Como Cadena
	
    Escribir "=== Gestor de Procesos ==="
    Escribir "1. Insertar proceso"
    Escribir "2. Eliminar proceso"
    Escribir "3. Buscar proceso"
    Escribir "4. Modificar prioridad"
    Escribir "5. Volver al menú principal"
    Leer subopcion
	
    Segun subopcion Hacer
        Caso 1:
            Escribir "Ingrese ID del proceso: "; Leer id
            Escribir "Ingrese nombre del proceso: "; Leer nombre
            Escribir "Ingrese prioridad: "; Leer prioridad
            Escribir "Ingrese estado: "; Leer estado
            Escribir "(Proceso insertado en lista enlazada)"
        Caso 2:
            Escribir "Ingrese ID del proceso a eliminar: "; Leer id
            Escribir "(Proceso eliminado si existe)"
        Caso 3:
            Escribir "Ingrese ID del proceso a buscar: "; Leer id
            Escribir "(Mostrar información si existe)"
        Caso 4:
            Escribir "Ingrese ID del proceso a modificar: "; Leer id
            Escribir "Ingrese nueva prioridad: "; Leer prioridad
            Escribir "(Prioridad actualizada si proceso existe)"
        Caso 5:
            Escribir "Regresando al menú..."
        De Otro Modo:
            Escribir "Opción inválida"
    FinSegun
FinSubProceso

SubProceso PlanificadorCPU
    Definir subopcion, id, prioridad Como Entero
    Definir nombre Como Cadena
	
    Escribir "=== Planificador de CPU ==="
    Escribir "1. Encolar proceso"
    Escribir "2. Ejecutar proceso (desencolar)"
    Escribir "3. Ver cola de procesos"
    Escribir "4. Volver al menú principal"
    Leer subopcion
	
    Segun subopcion Hacer
        Caso 1:
            Escribir "Ingrese ID: "; Leer id
            Escribir "Ingrese nombre: "; Leer nombre
            Escribir "Ingrese prioridad: "; Leer prioridad
            Escribir "(Proceso encolado según prioridad)"
        Caso 2:
            Escribir "(Proceso con mayor prioridad ejecutado)"
        Caso 3:
            Escribir "(Mostrar cola actual de procesos)"
        Caso 4:
            Escribir "Regresando al menú..."
        De Otro Modo:
            Escribir "Opción inválida"
    FinSegun
FinSubProceso

SubProceso GestorDeMemoria
    Definir subopcion, id_memoria Como Entero
	
    Escribir "=== Gestor de Memoria ==="
    Escribir "1. Asignar memoria (push)"
    Escribir "2. Liberar memoria (pop)"
    Escribir "3. Ver estado de la memoria"
    Escribir "4. Volver al menú principal"
    Leer subopcion
	
    Segun subopcion Hacer
        Caso 1:
            Escribir "Ingrese ID del bloque a asignar: "; Leer id_memoria
            Escribir "(Memoria asignada usando push en pila)"
        Caso 2:
            Escribir "(Último bloque de memoria liberado)"
        Caso 3:
            Escribir "(Mostrar estado actual de la pila de memoria)"
        Caso 4:
            Escribir "Regresando al menú..."
        De Otro Modo:
            Escribir "Opción inválida"
    FinSegun
FinSubProceso