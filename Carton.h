#ifndef CARTON_H_INCLUDED
#define CARTON_H_INCLUDED
#define COLUMNA 5

struct CartonE;

typedef struct CartonE *Carton;

//PRE: El tamaño que ingresa el usuario debe ser mayor a cero
//POST: Se devuelve un entero
int elegirCantidadDeCartones();

int busquedaSecuencial(int v[], int tam, int buscar);

//PRE:La matriz tiene que estar definida y cargado el numero aleatorio
//POST:Retorna -1 si el numero aletorio no esta repetido en el carton o la posicion del numero repetido
int verifica(int m[][COLUMNA],int ren,int numAl);                                                           //funciones de la bolsa
void cargarVectorConAleatoriosSinRepetir(int v[], int tam, int mini,int maxi);

//PRE:La matriz de la estructura carton tiene que estar definida
//POST:Se inicializan los cartones en 0 y retona la matriz
Carton inicializarCarton(int cantidadDeCartones,Carton c1);

//PRE:mini y maxi deben mandarse por parametro
//POST:Se retorna un numero entre 1 y 90
int aleatorioEntre(int mini, int maxi);
//-----------sets---------------

//PRE:La matriz de la estructura carton tiene que estar definido y los numeros deben ser mayor a cero, y menor a 91
//POST:Se sobreescribe el carton con numeros elegido por el usuario, entre 1 y 90 y retorna la matriz
Carton generarCartonPersonalizado(Carton c1,int ren);

//PRE:Los numeros deben ser mayor a cero, y menor a 91, srand(time(0)) y #include <time.h> deben estar en el main
//POST:Se sobreescribe el carton con numeros aleatorios, entre 1 y 90 y retorna la matriz
Carton generarCarton(Carton c1,int ren, int mini, int maxi);                                                         //funciones de los cartones
Carton setCarton(Carton c1,int ren,int col, int n);
//-------------get----------------

//PRE:La matriz de la estructura carton tiene que estar definida
//POST:Se muestran los cartones
void mostrarCarton(Carton c1,int ren);
int getCarton(Carton c1,int ren,int col);
//----------Funciones de la partida-------------

//PRE:El carton y la bolsa deben estar previamente cargados
//POST: Recorre el cartón y si el número coincide con la bolsa es reemplazado por 0
Carton verificarNumero(Carton c1,int ren,int n[],int pos);

//PRE:El carton debe estar cargado
//POST:Recorre las lineas y devuelve 1 si una suma da 0
int cantaLinea(Carton c1,int ren);

//PRE:El carton debe estar cargado
//POST:Recorre las columnas y devuelve 1 si una suma da 0
int cantaColumna(Carton c1,int ren);

//PRE:El carton debe estar cargado
//POST:Recorre todo el cartón devuelve 1 si una suma da 0
int cantaBingo(Carton c1,int ren);




#endif // CARTON_H_INCLUDED
