#include <stdio.h>
#include <stdlib.h>
#include "Logica/Logica.h"

void encabezado(void){
    printf("Ministerio de Relaciones Exteriores.\n");
    printf("Votaci\242n contra el bloqueo estadounidense (hasta 2025).\n\n");
}





int pedirEntero(int limInferior, int limSuperior){

    char cadena[150];
    int numero;
    bool numeroValido = false;


    do{
        printf("Elecci\242n: ");

        gets(cadena);

        if( esEntero(cadena) ){
            numero = atoi(cadena);

            if( limInferior <= numero && numero <= limSuperior )
                numeroValido = true;
            else
                printf("ERROR: debe ingresar un valor entre %d y %d\n\n", limInferior, limSuperior);
        }
        else
            printf("ERROR: debe ingresar un n\243mero entero.\n\n");



    }while(!numeroValido);

    return numero;
}








int pedirPais( char nombresPaises[][18], int cantPaises ){
    int i;

    for(i = 0; i < cantPaises; i++)
        printf("%d. %s\n", i+1, nombresPaises[i]);
    printf("\n\n");


    return pedirEntero(1, cantPaises) - 1;
}













void mostrarTiposVotosPais(char pais[], int cantAnios, int aFavor, int enContra, int abstenciones){
    system("cls");
    encabezado();
    printf("\nVotos de %s en %d a\244os:\n", pais, cantAnios);
    printf("\tA favor: %d\n", aFavor);
    printf("\tEn contra: %d\n", enContra);
    printf("\tAbstenciones: %d\n\n", abstenciones);
}








void mostrarHanVotadoContra( char nombresPaises[][18], bool votosEnContra[], int cantPaises ){
    int i;
    printf("\n\nPaises que al menos han votado una vez en contra de la resoluci\242n.\n");

    for(i = 0; i < cantPaises; i++)
        if( votosEnContra[i] )
            printf("%d. %s\n", i+1, nombresPaises[i]);

    printf("\n");

}









void mostrarTabla( DatosPaises paises[], char nombresPaises[][18], int cantPaises, int cantAnios ){

    int i, j;

    bool extremoSup;
    bool extremoDer;
    bool extremoIzq;


    for(i = -1; i < cantPaises; i++){
        extremoSup = i == -1;

        for(j = -1; j < cantAnios; j++){
            extremoIzq = j == -1;
            extremoDer = j == cantAnios-1;

            if(extremoIzq && extremoSup) printf("%-20s", "\n\nPa\241ses");
            else if(extremoSup) printf("%-11d", 1992+j);
            else if(extremoIzq) printf("%-18s", nombresPaises[i]);

            //resultpaises[i].votos[j]
            else if(!paises[i].votos[j]) printf("%-11s", "Abstenci\242n");
            else if(paises[i].votos[j] == 1) printf("%-11s", "A favor");
            else printf("%-11s", "En contra");

            if(extremoDer) printf("\n");
        }
    }

}











