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









void encontrarHanVotadoContra( DatosPaises paises[], bool votosEnContra[], int cantPaises, int cantAnios ){

    int i, j;


    memset(votosEnContra, false, cantPaises);

    for(i = 0; i < cantPaises; i++)
        for(j = 0; j < cantAnios && !votosEnContra[i]; j++)
            if( paises[i].votos[j] == -1 ) votosEnContra[i] = true;


}











