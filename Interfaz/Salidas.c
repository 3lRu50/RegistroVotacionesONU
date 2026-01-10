#include <stdio.h>
#include <stdlib.h>
#include "Logica/Logica.h"

void encabezado(void){
    printf("Ministerio de Relaciones Exteriores.\n");
    printf("Votaci\242n contra el bloqueo estadounidense.\n\n");
}





int pedirEntero(int limInferior, int limSuperior){

    char cadena[150];
    int numero;
    bool numeroValido = false;


    do{
        printf("Elecci\242n: ");

        gets(cadena);
        fflush(stdin);

        if( esEntero(cadena) ){
            numero = atoi(cadena);

            if( limInferior <= numero && numero <= limSuperior )
                numeroValido = true;
            else if(limInferior == limSuperior)
                printf("ERROR: el \243nico valor que puede ingresar es %d.\n\n", limInferior);
            else
                printf("ERROR: debe ingresar un valor entre %d y %d.\n\n", limInferior, limSuperior);
        }
        else
            printf("ERROR: debe ingresar un n\243mero entero.\n\n");



    }while(!numeroValido);

    return numero;
}








int pedirPais( DatosPaises paises[], int cantPaises ){
    int i;

    for(i = 0; i < cantPaises; i++)
        printf("%3d. %s\n", i+1, paises[i].nombre);
    printf("\n\n");


    return pedirEntero(1, cantPaises) - 1;
}













void resultadoReporteCantidades(int aFavor, int enContra, int abstenciones){
    printf("\tA favor: %d\n", aFavor);
    printf("\tEn contra: %d\n", enContra);
    printf("\tAbstenciones: %d\n\n", abstenciones);
}








void resultadoReporteListas( DatosPaises paises[], int salidas[], int cantSalidas, int reporte ){
    int i;

    if( !cantSalidas )          printf("\nNo se encontraron pa\241ses que cumplan con las condiciones de este reporte.\n");
    else {
        if(reporte == 2)        printf("\nPa\241%s con al menos un voto en contra de la resoluci\242n:\n", cantSalidas > 1 ? "ses" : "s");
        else if(reporte == 3)   printf("\nPa\241%s con mayor cantidad de votos a favor (%d):\n", cantSalidas > 1 ? "ses" : "s", paises[salidas[0]].total.aFavor );

        for(i = 0; i < cantSalidas; i++){
            printf("%3d. %s ", i+1,       paises[ salidas[i] ].nombre);

            if(reporte == 2)
                printf("%d ve%s\n", paises[ salidas[i] ].total.enContra,   paises[ salidas[i] ].total.enContra > 1 ? "ces" : "z");
            else
                printf("\n");
        }

        printf("\n");
    }
}









void mostrarTablaPaises( DatosPaises paises[], int cantPaises, int cantAnios ){

    int i, j;

    //variables para abreviar
    bool extremoSup;
    bool extremoDer;
    bool extremoIzq;


    for(i = -1; i < cantPaises; i++){
        extremoSup = i == -1;

        for(j = -1; j < cantAnios; j++){
            extremoIzq = j == -1;
            extremoDer = j == cantAnios-1;

            if(extremoIzq && extremoSup) printf("%-20s", "\n\nPa\241ses");
            else if(extremoSup) printf("%-12d", 1992+j);
            else if(extremoIzq) printf("%-18s",paises[i].nombre);

            else if(!paises[i].votos[j]) printf("%-12s", "Abstenci\242n");
            else if(paises[i].votos[j] == 1) printf("%-12s", "A favor");
            else printf("%-12s", "En contra");

            if(extremoDer) printf("\n");
        }
    }


}







void mostrarTablaAnios( DatosTotalVotos totales[], int cantAnios ){

    int i, j;


    printf("%-15s", "\n\nA\244os");

    for(i = 0; i < 4; i++){

        if(i == 1)      printf("%-12s ", "A favor");
        else if(i == 2) printf("%-12s ", "En contra");
        else if(i == 3) printf("%-12s ", "Abstenciones");

        for(j = 0; j < cantAnios; j++){

            if(!i)          printf("%5d ", 1992+j);
            else if(i == 1) printf("%5d ", totales[j].aFavor);
            else if(i == 2) printf("%5d ", totales[j].enContra);
            else            printf("%5d ", totales[j].abstenciones);


        }
        printf("\n");
    }

}









