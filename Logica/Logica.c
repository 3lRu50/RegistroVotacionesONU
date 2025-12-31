#include "Datos.h"
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>


bool esEntero(char cadena[]){

    bool valido = true;
    int i;
    int tamanio = strlen(cadena);


    if( cadena[0] == '-' || isdigit(cadena[0]) ){

        for(i = 1; i < tamanio && valido; i++)
            if( !isdigit(cadena[i]) )
                valido = false;

    }else valido = false;

    return valido;
}









void inicializarAutomatico( DatosPaises paises[], char nombresPaises[][18], int cantPaises, int anios ){

    int i, j;
    char nombres[][18] = { "Cuba", "Usa", "Rusia", "Israel", "Alemania", "Japon", "Francia", "Hungr\241a", "Mali", "Congo" };


    srand( time(NULL) );

    for(i = 0; i < cantPaises; i++){
        strcpy(nombresPaises[i], nombres[i]);//nombres

        for(j = 0; j < anios; j++)//votos
            paises[i].votos[j] = rand() % 3 - 1;
    }
}








void contarTiposVotosPais( DatosPaises paises, int cantAnios, int* aFavor, int* enContra, int* abstenciones ){
    int i;
    int voto;

    for(i = 0; i < cantAnios; i++){
        voto = paises.votos[i];

        if( !voto ) (*abstenciones)++;
        else if( voto == 1) (*aFavor)++;
        else (*enContra)++;
    }

}









int encontrarHanVotadoContra( DatosPaises paises[], char nombresPaises[][18], char conVotosEnContra[][18], int cantPaises, int cantAnios ){

    int i, j;
    int cantPaisesEnContra = 0;
    bool enContra;

    for(i = 0; i < cantPaises; i++){
        enContra = false;

        for(j = 0; j < cantAnios && !enContra; j++)

            if( paises[i].votos[j] == -1 ) {
                enContra = true;

                strcpy( conVotosEnContra[ cantPaisesEnContra++ ], nombresPaises[i] );
            }
    }


    return cantPaisesEnContra;
}











int encontrarMasFavor( DatosPaises paises[], char nombresPaises[][18], char conMayorCantFavor[][18], int cantPaises, int cantAnios ){

    int i, j;
    int vecesMayorEncontrado = 0;       //veces que se repite el mayor (en caso de empate)
    int cantFavorUnPais;                //contador de cuántos votos a favor tiene un país
    int mayor = 0;                      //mayor cantidad por un país

    for(i = 0; i < cantPaises; i++){
        cantFavorUnPais = 0;

        for(j = 0; j < cantAnios; j++)
            if( paises[i].votos[j] == 1 ) cantFavorUnPais++;

        if(mayor < cantFavorUnPais){
            mayor = cantFavorUnPais;
            vecesMayorEncontrado = 1;
            strcpy( conMayorCantFavor[ 0 ], nombresPaises[i] );
        }

        else if(mayor > 0 && mayor == cantFavorUnPais)
            strcpy( conMayorCantFavor[ vecesMayorEncontrado++ ], nombresPaises[i] );

    }



    return vecesMayorEncontrado;
}







void contarVotosEnAnio( DatosPaises paises[], int anio, int cantPaises, int* aFavor, int* enContra, int* abstenciones ){

    int i;
    int voto;

    for(i = 0; i < cantPaises; i++){
        voto = paises[i].votos[anio];

        if( !voto ) (*abstenciones)++;
        else if( voto == 1) (*aFavor)++;
        else (*enContra)++;
    }

}
