#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jugador.h"

struct JugadorE
{

  float dni;
  char nombre[40];
  char apellido[40];
  Carton cartones[3];
  int Bingo;
  int Columna;
  int Linea;
  float puntos;
};

Jugador crearJugadorPorTeclado()
{

  Jugador j1 = malloc(sizeof(struct JugadorE));

  printf("\nIngrese el nombre:");
  fflush(stdin);
  gets(j1->nombre);
  printf("\nIngrese el apellido:");
  fflush(stdin);
  gets(j1->apellido);
  printf("\nIngrese el dni:");
  scanf("%f", &j1->dni);
  j1->puntos = 0;
  j1->Bingo = 0;
  j1->Linea = 0;
  j1->Columna = 0;

  return j1;
};

Jugador crearPc()
{

  Jugador pc = malloc(sizeof(struct JugadorE));

  strcpy(pc->nombre, "pc");

  pc->dni = 1111;

  pc->puntos = 0;

  return pc;
}

void leerPuntajes()
{

  Jugador jugadores[100];

  int contadorDeJugadores = 0;

  FILE *leer = NULL;

  leer = fopen("jugadores.txt", "r");

  if (leer == NULL)
  {

    printf("\nTodavia no jugo ninguna partida\n");
  }

  else
  {

    while (!feof(leer))
    {

      char aux[40] = " ";

      fgets(aux, 40, leer);

      jugadores[contadorDeJugadores] = charAJugador(aux, 40);

      contadorDeJugadores++;
    }

    fclose(leer);
  }

  int i;

  ordenarJugadoresPorPuntaje(jugadores, contadorDeJugadores);

  for (i = 0; i < contadorDeJugadores; i++)
  {

    if (jugadores[i]->puntos != 0)
    {

      printf("%s -----> Puntaje:%.2f\n", jugadores[i]->nombre, jugadores[i]->puntos);
    }
  }
}

Jugador charAJugador(char c[], int n)
{

  Jugador j = malloc(sizeof(struct JugadorE));

  int posDelPrimerPuntoYComa = -1;

  int i;

  for (i = 0; i < n; i++)
  {
    if (c[i] == ';')
    {
      posDelPrimerPuntoYComa = i;
    }
  }

  char auxNombre[40] = " ";
  char auxPuntaje[40] = " ";

  for (i = 0; i < posDelPrimerPuntoYComa; i++)
  {

    auxNombre[i] = c[i];
  }

  for (i = posDelPrimerPuntoYComa + 1; i < n; i++)
  {

    auxPuntaje[i - posDelPrimerPuntoYComa - 1] = c[i];
  }

  strcpy(j->nombre, auxNombre);
  j->puntos = atof(auxPuntaje);

  return j;
};

void ordenarJugadoresPorPuntaje(Jugador v[], int t)
{

  Jugador aux;

  int i, j;

  for (i = 0; i < t; i++)
  {

    for (j = 0; j < t - 1; j++)
    {

      if (v[j]->puntos < v[j + 1]->puntos)
      {

        aux = v[j];
        v[j] = v[j + 1];
        v[j + 1] = aux;
      }
    }
  }
}

void escribirJugadores(Jugador j1, Jugador maquina)
{

  FILE *escribir = fopen("jugadores.txt", "a");

  if (j1->puntos >= maquina->puntos)
  {

    fprintf(escribir, "%s %s;%.2f\n", j1->nombre, j1->apellido, j1->puntos);
  }
  else
  {
    fprintf(escribir, "%s;%.2f\n", maquina->nombre, maquina->puntos);
  }

  fclose(escribir);
}

void mostrarJugador(Jugador j)
{

  printf("\nNombre: %s\nApellido: %s\nDni: %.0f", j->nombre, j->apellido, j->dni);
}
//gets
char *getNombre(Jugador j)
{

  return j->nombre;
}

char *getApellido(Jugador j)
{

  return j->apellido;
}

float getDni(Jugador j)
{

  return j->dni;
}

int getColumna(Jugador j)
{

  return j->Columna;
}

int getLinea(Jugador j)
{

  return j->Linea;
}

int getBingo(Jugador j)
{

  return j->Bingo;
}

float getPuntos(Jugador j)
{

  return j->puntos;
}

//sets
void setNombre(Jugador j, char nom[])
{

  strcpy(j->nombre, nom);
}

void setDni(Jugador j, float d)
{

  j->dni = d;
}

void setColumna(Jugador j, int f)
{

  j->Columna = f;
}

void setLinea(Jugador j, int f)
{

  j->Linea = f;
}

void setBingo(Jugador j, int f)
{

  j->Bingo = f;
}

void setPuntos(Jugador j, float n)
{

  j->puntos = n;
}
//destructor
void destruirJugador(Jugador j)
{

  free(j);
}

void menuPrincipal(Jugador j1, Jugador maquina, int cantidadDeCartones)
{

  int opcion = 0;

  int renglon = 3;

  int min = 1;

  int max = 90;

  int i;

  do
  {

    printf("\n\n\t\t\t\t -----Bienvenidos-----\n");
    printf("\n\n\t\t\t\t1-Cargar carton Personalizado(eligiendo los numeros)\n");
    printf("\n\n\t\t\t\t2-Cargar carton Cualquiera(aleatorio)\n");
    printf("\n\n\t\t\t\t3-Ver ranking de puntajes\n");
    printf("\n\n\t\t\t\t4-Salir\n");
    printf("\n\n\t\t\t\tIngrese una opcion: ");
    scanf("%d", &opcion);
    system("cls");

    switch (opcion)
    {

    case 1: //--->Generar cartones Personalizados

      for (i = 0; i < cantidadDeCartones; i++)
      {

        j1->cartones[i] = inicializarCarton(cantidadDeCartones, j1->cartones[i]);

        printf("\nIngrese los numeros para el carton %d\n\n", i + 1);
        j1->cartones[i] = generarCartonPersonalizado(j1->cartones[i], renglon);

        maquina->cartones[i] = generarCarton(maquina->cartones[i], renglon, min, max);
      }

      printf("\n\t\tCartones del jugador");
      for (i = 0; i < cantidadDeCartones; i++)
      {
        printf("\n\t\t------------------------      Carton %d       ---------------------\n", i + 1);
        mostrarCarton(j1->cartones[i], renglon);
      }

      printf("\n\t\tCartones de la maquina");
      for (i = 0; i < cantidadDeCartones; i++)
      {
        printf("\n\t\t------------------------      Carton %d       ---------------------\n", i + 1);
        mostrarCarton(maquina->cartones[i], renglon);
      }

      break;

    case 2: //--->Generar cartones Aleatorios

      for (i = 0; i < cantidadDeCartones; i++)
      {
        j1->cartones[i] = generarCarton(j1->cartones[i], renglon, min, max);
        maquina->cartones[i] = generarCarton(maquina->cartones[i], renglon, min, max);
      }
      printf("\nCartones del jugador");
      for (i = 0; i < cantidadDeCartones; i++)
      {
        printf("\n\t\t------------------------      Carton %d       ---------------------\n", i + 1);
        mostrarCarton(j1->cartones[i], renglon);
      }

      printf("\nCartones de la maquina");
      for (i = 0; i < cantidadDeCartones; i++)
      {
        printf("\n\t\t------------------------      Carton %d       ---------------------\n", i + 1);
        mostrarCarton(maquina->cartones[i], renglon);
      }
      break;

    case 3:
      leerPuntajes();

      break;

    case 4:
      printf("\nGracias por jugar!!!\n\n");
      return 0;

    default:
      printf("\nERROR, por favor, ingrese una de las opciones:\n");
    }

  } while (opcion != 1 && opcion != 2);

  if (opcion == 1 || opcion == 2)
  {

    do
    {

      printf("\n\n\t\t\t\t1-Cargar carton Personalizado(eligiendo los numeros)\n");
      printf("\n\n\t\t\t\t2-Cargar carton Cualquiera(aleatorio)\n");
      printf("\n\n\t\t\t\t3-Ver ranking de puntajes\n");
      printf("\n\n\t\t\t\t4-Jugar\n");
      printf("\n\n\t\t\t\tIngrese una opcion: ");
      scanf("%d", &opcion);
      system("cls");

      switch (opcion)
      {

      case 1: //--->Generar cartones Personalizados

        for (i = 0; i < cantidadDeCartones; i++)
        {

          j1->cartones[i] = inicializarCarton(cantidadDeCartones, j1->cartones[i]);

          printf("\nIngrese los numeros para el carton %d\n\n", i + 1);
          j1->cartones[i] = generarCartonPersonalizado(j1->cartones[i], renglon);

          maquina->cartones[i] = generarCarton(maquina->cartones[i], renglon, min, max);
        }

        printf("\n\t\tCartones del jugador");
        for (i = 0; i < cantidadDeCartones; i++)
        {
          printf("\n\t\t------------------------      Carton %d       ---------------------\n", i + 1);
          mostrarCarton(j1->cartones[i], renglon);
        }

        printf("\n\t\tCartones de la maquina");
        for (i = 0; i < cantidadDeCartones; i++)
        {
          printf("\n\t\t------------------------      Carton %d       ---------------------\n", i + 1);
          mostrarCarton(maquina->cartones[i], renglon);
        }

        break;

      case 2: //--->Generar cartones Aleatorios

        for (i = 0; i < cantidadDeCartones; i++)
        {
          j1->cartones[i] = generarCarton(j1->cartones[i], renglon, min, max);
          maquina->cartones[i] = generarCarton(maquina->cartones[i], renglon, min, max);
        }
        printf("\nCartones del jugador");
        for (i = 0; i < cantidadDeCartones; i++)
        {
          printf("\n\t\t------------------------      Carton %d       ---------------------\n", i + 1);
          mostrarCarton(j1->cartones[i], renglon);
        }

        printf("\nCartones de la maquina");
        for (i = 0; i < cantidadDeCartones; i++)
        {
          printf("\n\t\t------------------------      Carton %d       ---------------------\n", i + 1);
          mostrarCarton(maquina->cartones[i], renglon);
        }
        break;

      case 3:
        leerPuntajes();

        break;

      case 4: //Jugar

        break;

      default:
        printf("\nERROR, por favor, ingrese una de las opciones:\n");
      }
    } while (opcion != 4);
  }
}

void jugada(Jugador j, Jugador oponente, int ren, int cantidadDeCartones, int bolsa[], int pos)
{
  int i;
  for (i = 0; i < cantidadDeCartones; i++)
  {
    verificarNumero(j->cartones[i], ren, bolsa, pos);
    if (oponente->Linea != 1)
    {
      j->Linea = cantaLinea(j->cartones[i], ren);
    }
    if (oponente->Columna != 1)
    {
      j->Columna = cantaColumna(j->cartones[i], ren);
    }
    if (j->Bingo != 1 && oponente->Bingo != 1)
    {
      j->Bingo = cantaBingo(j->cartones[i], ren);
    }
  }
}
void mostrarEvolucion(Jugador j, Jugador pc, int bolsa[], int Pos, int CantidadDeCartones)
{
  printf("--------------------------------------------------------------------------------------------\n");
  printf("Ha salido el numero %d\n", bolsa[Pos]);
  int i;
  for (i = 0; i < CantidadDeCartones; i++)
  {
    if (i == 0)
    {
      printf("--------------------------------------------------------------------------------------------\n");
      printf("\nCarton del jugador");
    }
    printf("\n\t\t------------------------      Carton %d       ---------------------\n", (i + 1));
    mostrarCarton(j->cartones[i], 3);
  }
  for (i = 0; i < CantidadDeCartones; i++)
  {
    if (i == 0)
    {
      printf("\nCarton de la pc");
    }
    printf("\n\t\t------------------------      Carton %d       ---------------------\n", (i + 1));
    mostrarCarton(pc->cartones[i], 3);
  }
}

void mostrarDatosDePartida(Jugador j, Jugador pc, int pos)
{
  float Plinea = 0;
  float pcolumna = 0;
  float pbingo = 0;
  //Variables para el calculo de puntos.
  float Pclinea = 0;
  float pccolumna = 0;
  float pcbingo = 0;

  printf("--------------------------------------------------------------------------------------------\n");
  if (j->Bingo == 1)
  {
    printf("El jugador ha cantado Bingo, han tenido que salir %d numeros de la bolsa\n", pos);
    if (pos < 30)
    {
      pbingo = pbingo + 70 * 2;
    }
    else if (pos >= 30 && pos <= 50)
    {
      pbingo = pbingo + 70 * 1.7;
    }
    else if (pos > 49 && pos < 71)
    {
      pbingo = pbingo + 70 * 1.5;
    }
    else if (pos > 70)
    {
      pbingo = pbingo + 70;
    }
  }

  else if (pc->Bingo == 1)
  {
    printf("La pc ha cantado Bingo, han tenido que salir %d numeros de la bolsa\n", pos);
    if (pos < 30)
    {
      pcbingo = pcbingo + 70 * 2;
    }
    else if (pos >= 30 && pos <= 50)
    {
      pcbingo = pcbingo + 70 * 1.7;
    }
    else if (pos > 49 && pos < 71)
    {
      pcbingo = pcbingo + 70 * 1.5;
    }
    else if (pos > 70)
    {
      pcbingo = pcbingo + 70;
    }
  }

  if (j->Linea == 1)
  {
    printf("El jugador ha cantado linea\n");
    Plinea = Plinea + 20;
  }
  else if (pc->Linea == 1)
  {
    printf("La pc ha cantado linea\n");
    Pclinea = Pclinea + 20;
  }
  if (j->Columna == 1)
  {
    printf("El jugador ha cantado columna\n");
    pcolumna = pcolumna + 10;
  }
  else if (pc->Columna == 1)
  {
    printf("La pc ha cantado columna\n");
    pccolumna = pccolumna + 10;
  }
  printf("--------------------------------------------------------------------------------------------\n");
  j->puntos = pbingo + Plinea + pcolumna;
  pc->puntos = pcbingo + Pclinea + pccolumna;

  printf("\nPuntaje del Jugador:%2.f", j->puntos);
  printf("\nPuntaje de PC:%2.f", pc->puntos);

  if (j->puntos > pc->puntos)
  {
    printf("\n\nFELICIDADES HAS GANADO!!!");
  }
  else
  {
    printf("\n\nHa ganado la PC, mejor suerte la proxima");
  }
  printf("\n--------------------------------------------------------------------------------------------\n");
}
