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
