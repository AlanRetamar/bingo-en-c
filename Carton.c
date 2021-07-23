#include <stdio.h>
#include <stdlib.h>
#include "Jugador.h"
#include "Carton.h"


struct CartonE{

      int matriz[3][COLUMNA];

};

int getCarton(Carton c1,int ren,int col){

    return c1->matriz[ren][col];

}

Carton setCarton(Carton c1,int ren,int col,int n){

    c1->matriz[ren][col]=n;
    return c1;
}

int elegirCantidadDeCartones(){

    int cantidad=0;
    printf("\n\nCon cuantos cartones desea jugar: 1, 2 o 3\n");
    scanf("%d",&cantidad);
    do{
        if(cantidad<1){
            printf("Tiene que jugar con 1 carton como minimo\n");
            printf("Ingrese la cantidad de cartones con los que va a jugar: ");
            scanf("%d",&cantidad);
        }
        else if(cantidad>3){
            printf("Tiene que jugar con 3 cartones como maximo\n");
            printf("Ingrese la cantidad de cartones con los que va a jugar: ");
            scanf("%d",&cantidad);
        }
    }
    while(cantidad<1 || cantidad>3);
    return cantidad;
}

Carton inicializarCarton(int cantidadDeCartones, Carton c1){

    int ren = 3;

    c1 = malloc(sizeof(struct CartonE));

    int c=0;
    int r=0;

        for(r=0; c<COLUMNA; c++){
            for(r=0; r<ren; r++){
                c1->matriz[r][c] = 0;
            }
        }

    return c1;
}

Carton generarCarton(Carton c1,int ren, int mini, int maxi){

    int c=0;
    int r=0;
    int banderaNumerosSinRepetir=0;
    int numeroAleatorio=aleatorioEntre(mini, maxi);

    c1 = malloc(sizeof(struct CartonE));

    for(c=0; c<COLUMNA; c++){
        for(r=0; r<ren; r++){
            do{
               numeroAleatorio = aleatorioEntre(mini, maxi);//Se guarda el numero aleatorio
               banderaNumerosSinRepetir = verifica(c1->matriz,ren,numeroAleatorio);
            }while(banderaNumerosSinRepetir != -1);//--->Mientras se repitan numeros
                                                   //que cargue un nuevo numero
                                                   //el valor de banderaNumerosSinRepetir puede ser 0 o -1
           c1->matriz[r][c]=numeroAleatorio; //En el while verifica que no se repitan numeros y recien despues asigna el numero a la matriz
        }
    }

    return c1;
}
void mostrarCarton(Carton c1,int ren){

    int c=0;
    int r=0;
    for(r=0; r<ren; r++){
        for(c=0; c<COLUMNA; c++){
            if (c1->matriz[r][c]==0){
                printf("\t\t[X] ");
            }else
            printf("\t\t[%d] ",c1->matriz[r][c]);
        }
        printf("\n");
    }
}
Carton generarCartonPersonalizado(Carton c1, int ren){

    int c;
    int r;
    int numeroNuevo = 0;
    int resultadoBusqueda = 0;


   for ( c = 0; c<COLUMNA; c++){
        for ( r = 0; r <ren; r++)
        {
           printf("\nIngrese un numero en la pos[%d][%d]: ", c+1,r+1);
           scanf("%d", &numeroNuevo);

           //mostrarCarton(m,ren);
        do{


            resultadoBusqueda = verifica(c1->matriz, ren, numeroNuevo); //Si nos da la posicion ---> -1 es por que no estaba repetido el numero en el carton
            if(resultadoBusqueda != -1 ){//Si el numero es distinto de -1 es porque el numero esta en el carton
                printf("\nEs un numero repetido, ingrese otro numero: ");
                scanf("%d", &numeroNuevo);
                if(numeroNuevo < 1 || numeroNuevo > 90){
                   printf("\nError, el numero tiene que ser entre 1 y 90, ingrese otro numero: ");
                   scanf("%d", &numeroNuevo);
                }
            }
             else if(numeroNuevo < 1 || numeroNuevo > 90){
                printf("\nError, el numero tiene que ser entre 1 y 90, ingrese otro numero: ");
                scanf("%d", &numeroNuevo);
                resultadoBusqueda = verifica(c1->matriz, ren, numeroNuevo);
                    if(resultadoBusqueda != -1 ){
                    printf("\nEs un numero repetido, ingrese otro numero: ");
                    scanf("%d", &numeroNuevo);
                    }
            }
        }while(resultadoBusqueda!=-1 || (numeroNuevo < 1 || numeroNuevo > 90));//Mientras el numero sea repetido o sea menor a 1 o mayor a 90
        c1->matriz[r][c] = numeroNuevo;
        }
    }

    return c1;
}

int aleatorioEntre(int mini, int maxi){
        //mini = 1, maxi = 90
        int resultado = 0;
        resultado  =  mini + rand()%(maxi - mini +1);// 1 + rand()%(90 - 1 +1)
        return resultado;
}

int busquedaSecuencial(int v[], int tam, int buscar){
        int pos = -1;
        int i;

        for ( i = 0; i<tam; i++){
            if ( v[i]==buscar){
                pos = i;
            }
        }
    return pos;
}

void cargarVectorConAleatoriosSinRepetir(int v[], int tam, int mini,int maxi){
     int numeroNuevo = 0;
     int resultadoBusqueda = 0 ;

     int i;

    for ( i = 0; i<tam; i++){
        do{
        numeroNuevo = aleatorioEntre(mini, maxi);
        resultadoBusqueda = busquedaSecuencial(v, tam, numeroNuevo);
        }while(resultadoBusqueda!=-1);
        v[i]= numeroNuevo;
    }
}

int verifica(int m[][COLUMNA],int ren,int numAl){
    int i=0;
    int r=0;
    int pos = -1;
    for(i=0; i<COLUMNA; i++){
        for(r=0; r<ren; r++){
            if(numAl==m[r][i]){ //--->Si hay numeros repetidos retorna pos = r
               pos = r;
            }
        }
    }
    return pos; //--->Si no hay numeros repetidos retorna pos = -1
}

Carton verificarNumero(Carton c1,int ren,int n[],int pos){
    int i,j;
    for (i=0;i<ren;i++){
        for (j=0;j<COLUMNA;j++){                        //recorre el cartón y si el numero que salió coincide
            if (c1->matriz[i][j]== n[pos]){                 //coloca un 0 en la posición
                c1->matriz[i][j]=0;
            }
        }
    }
    return c1;
}

int cantaLinea(Carton c1,int ren){
    int canta=0;
    int totalLinea=0;
    int i,j;
    for (i=0;i<ren;i++){                    //si la suma de alguna linea es 0
        for (j=0;j<COLUMNA;j++){            //devuelve 1
            totalLinea=totalLinea+c1->matriz[i][j];
        }
        if(totalLinea==0){
            canta=1;
        }
        totalLinea=0;
    }
    return canta;
}

int cantaColumna(Carton c1,int ren){
    int canta=0;
    int totalColumna=0;
    int i,j;
    for (i=0;i<COLUMNA;i++){                //si la suma de alguna columna es 0
        for (j=0;j<ren;j++){                //devuelve 1
            totalColumna=totalColumna+c1->matriz[j][i];
        }
        if (totalColumna==0){
            canta=1;
        }
        totalColumna=0;
    }
    return canta;
}

int cantaBingo(Carton c1,int ren){
    int canta=0;
    int total=0;
    int i,j;
    for (i=0;i<COLUMNA;i++){            //si la suma de todo el cartón es 0
        for (j=0;j<ren;j++){            //devuelve 1
            total=total+c1->matriz[j][i];
        }
    }
    if (total==0){
        canta=1;
    }
    return canta;
}
