#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED
#include "Carton.h"

struct JugadorE;

typedef struct JugadorE *Jugador;

//----------constructor----------
Jugador crearJugadorPorTeclado();

Jugador crearPc();

void mostrarJugador(Jugador j);


//---------Leer y escribir archivos----------

//PRE:Debe crearse un array para guardar los renglones del archivo
//POST:Se muestran los renglones del archivo
void leerPuntajes();

//PRE:El array de jugadores debe estar definido
//POST:Se ordenan los jugadores por puntaje de mayor a menor
void ordenarJugadoresPorPuntaje(Jugador v[], int t);

//PRE:Aux tiene que estar definido y con tamanio
//POST:Transforma un renglon del archivo a un jugador
Jugador charAJugador(char c[], int n);

//PRE:El jugador y la pc deben pasarse por parametro
//POST:Se escriben los datos del jugador o la maquina
void escribirJugadores(Jugador j1, Jugador maquina);


//-----------gets---------------
char* getNombre(Jugador j);

char* getApellido(Jugador j);

float getDni(Jugador j);

int getColumna(Jugador j);

int getLinea(Jugador j);

int getBingo(Jugador j);

float getPuntos(Jugador j);

//-----------sets---------------
void setNombre(Jugador j,char nom[]);

void setDni(Jugador j,float d);

void setColumna(Jugador j,int f);

void setLinea(Jugador j,int f);

void setBingo(Jugador j,int f);

void setPuntos(Jugador j,float n);

//-----------destructor---------------
void destruirJugador(Jugador j);

//PRE:Los jugadores deben haber sido creados y la cantidad de cartones debe haber sido elegida
//POST: Muestra el menú con el que el usuario interactuará
void menuPrincipal(Jugador j1, Jugador maquina, int cantidadDeCartones);
//------FUNCIONES DE LA PARTIDA---------

//PRE:Los jugadores deben tener sus cartones cargados y la bolsa debe estar cargada también.
//POST:Recorre los cartones comparando con la bolsa y verifica si se canta linea,columna o bingo.
void jugada (Jugador j,Jugador oponente,int ren, int cantidadDeCartones,int bolsa[],int pos);

//PRE:Los cartones deben estar cargados.
//POST:Muestra cómo van quedando los cartones tras sus respectivas modificaciones
void mostrarEvolucion(Jugador j,Jugador pc, int bolsa[],int Pos,int CantidadDeCartones);

//PRE:La partida debe haber finalizado
//POST:Hace el calculo de las puntuaciones, guarda en un archivo y hace la impresión final.
void mostrarDatosDePartida(Jugador j,Jugador pc,int pos);


#endif // JUGADOR_H_INCLUDED
