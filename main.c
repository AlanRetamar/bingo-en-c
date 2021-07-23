#include <stdio.h>
#include <stdlib.h>
#include "Jugador.h"
#include "Carton.h"
#include <windows.h>
#include <time.h>



int main()
{
    srand(time(0));
    int bolsa[90];
    int pos=0;
    cargarVectorConAleatoriosSinRepetir(bolsa,90,1,90);

    struct Jugador *jugador1;
    struct Jugador *pc;

    jugador1 = crearJugadorPorTeclado();

    pc = crearPc();

    mostrarJugador(jugador1);

    int cantDeCart = elegirCantidadDeCartones();

    menuPrincipal(jugador1,pc,cantDeCart);

    do{
        jugada(jugador1,pc,3,cantDeCart,bolsa,pos);
        jugada(pc,jugador1,3,cantDeCart,bolsa,pos);
        mostrarEvolucion(jugador1,pc,bolsa,pos,cantDeCart);
        pos=pos+1;
    } while(getBingo(jugador1) != 1 && getBingo(pc) != 1);

    mostrarDatosDePartida(jugador1,pc,(pos-1));
    escribirJugadores(jugador1,pc);
    destruirJugador(jugador1);
    destruirJugador(pc);
    return 0;
}
