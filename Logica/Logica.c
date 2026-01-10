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









void inicializarAutomatico( DatosPaises paises[], int cantPaises, int anios ){

    int i, j;
    char nombres[15][18] = {
        "Cuba", "Usa", "Rusia", "Israel", "Alemania",
        "Jap\242n", "Francia", "Hungr\241a", "Mali", "Congo",
        "Corea del Norte", "Corea del Sur", "Chile", "Argentina", "China"
    };


    srand( time(NULL) );

    for(i = 0; i < cantPaises; i++){
        strcpy( paises[i].nombre, nombres[i] );//nombres

        for(j = 0; j < anios; j++)//votos
            paises[i].votos[j] = rand() % 3 - 1;
    }

}












void actualizarPaises(DatosPaises paises[], int cantPaises, int cantAnios){

    int aFavor, enContra, abstenciones;
    int voto;
    int i, j;


    for(i = 0; i < cantPaises; i++){
        aFavor = enContra = abstenciones = 0;

        for(j = 0; j < cantAnios; j++){
            voto = paises[i].votos[j];

            //discriminar entre tipos de votos
            if(voto == 1)           aFavor++;
            else if(voto == -1)     enContra++;
            else if( !voto )        abstenciones++;
        }

        paises[i].total.aFavor = aFavor;
        paises[i].total.enContra = enContra;
        paises[i].total.abstenciones = abstenciones;
    }

}



void actualizarAnios(DatosPaises paises[], DatosTotalVotos totalesAnios[], int cantPaises, int cantAnios){

    int aFavor, enContra, abstenciones;
    int voto;
    int i, j;


    for(i = 0; i < cantAnios; i++){
        aFavor = enContra = abstenciones = 0;

        for(j = 0; j < cantPaises; j++){
            voto = paises[j].votos[i];

            //discriminar entre tipos de votos
            if(voto == 1)           aFavor++;
            else if(voto == -1)     enContra++;
            else if( !voto )        abstenciones++;
        }

        totalesAnios[i].aFavor = aFavor;
        totalesAnios[i].enContra = enContra;
        totalesAnios[i].abstenciones = abstenciones;
    }

}














int encontrarHanVotadoContra( DatosPaises paises[], int salidas[], int cantPaises ){

    int i;
    int cantPaisesEnContra = 0;


    for(i = 0; i < cantPaises; i++)
        if( paises[i].total.enContra )
            salidas[ cantPaisesEnContra++ ] = i;


    return cantPaisesEnContra;
}













int encontrarMasAFavor( DatosPaises paises[], int salidas[], int cantPaises ){

    int i;
    int vecesMayorEncontrado = 0;                 //veces que se repite el mayor (en caso de empate)
    int mayor = 0;                                //mayor cantidad de votos a favor por un país


    for(i = 0; i < cantPaises; i++)
        if( paises[i].total.aFavor > mayor ){
            mayor = paises[i].total.aFavor;
            salidas[0] = i;
            vecesMayorEncontrado = 1;
        }
        else if( paises[i].total.aFavor == mayor && mayor > 0 )
            salidas[ vecesMayorEncontrado++ ] = i;


    return vecesMayorEncontrado;
}





