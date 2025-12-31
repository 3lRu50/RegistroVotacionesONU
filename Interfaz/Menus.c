#include "Interfaz/Salidas.h"
#include "Logica/Logica.h"
#include <stdbool.h>
#include <stdlib.h>





//devuelve la cantidad de paises ingresados
void menuInicializarDatos(DatosPaises paises[], char nombresPaises[][18], int* ptrCantPaises, int* ptrCantAnios){

    system("cls");

    bool opcionValida;
    int opcion;

    do{
        opcionValida = true;

        encabezado();
        printf("Introduzca c\242mo desea inicializar los datos.\n\n");
        printf("1. Autom\240ticamente\n");
        printf("2. Manualmente\n");
        printf("3. Atr\240s\n\n");

        opcion = pedirEntero(1, 3);


        switch(opcion){
            case 1:
                printf("\n\nIngrese la cantidad de pa\241ses que desea usar (a lo sumo 10): ");
                *cantPaises = pedirEntero(1, 10);

                printf("\n\nIngrese la cantidad de a\244os que desea usar (a lo sumo 34): ");
                *cantAnios = pedirEntero(1,34);

                inicializarAutomatico(paises, nombresPaises, *cantPaises, *cantAnios);
                break;

            case 2:
                printf("IMPLEMENTE");
                //cantPaises = inicializar(paises, nombresPaises);
                break;

            case 3:break;

            default:
                printf("ERROR: opci\242n incorrecta.\n");
                opcionValida = false;
        }


    }while(!opcionValida);

}








void menuReportes(DatosPaises paises[], char nombresPaises[][18], int cantPaises, int cantAnios){

    system("cls");

    bool opcionValida;
    int opcion;
    int pais;
    int anio;

    //tipos de votos posibles
    int aFavor = 0;
    int enContra = 0;
    int abstenciones = 0;

    bool votosEnContra[200] = {0};

    do{
        opcionValida = true;

        encabezado();
        printf("Ingrese el reporte deseado.\n\n");
        printf("1. Cantidad de votos que un pa\241s ha realizado a favor, en contra y cu\240ntas abstenciones\n");
        printf("2. Pa\241ses que han votado en contra y cantidad de veces que lo han hecho\n");
        printf("3. Pa\241s con m\240s votos a favor.\n");
        printf("4. Cantidad de votos a favor, en contra y abstenciones en un a\244o determinado.\n");
        printf("5. Atr\240s\n\n");

        opcion = pedirEntero(1, 5);


        switch(opcion){
            case 1:

                printf("\n\nIntroduzca el pa\241s del que desea ingresar controlar las votaciones.\n\n");
                pais = pedirPais( nombresPaises, cantPaises );

                contarTiposVotosPais( paises[pais], cantAnios, &aFavor, &enContra, &abstenciones );
                mostrarTiposVotosPais( nombresPaises[pais], cantAnios, aFavor, enContra, abstenciones );
                break;

            case 2:
                encontrarHanVotadoContra( paises, votosEnContra, cantPaises, cantPaises );
                mostrarHanVotadoContra( nombresPaises, votosEnContra, cantPaises );
                break;

            case 3:
                printf("IMPLEMENTE");
                encontrarMasFavor( paises, cantPaises, cantAnios );
                mostrarMasFavor( );
                break;

            case 4:
                printf("IMPLEMENTE");
                break;

            case 5: break;

            default:
                printf("ERROR: opci\242n incorrecta.\n");
                opcionValida = false;
        }


    }while(!opcionValida);
}









void menu(DatosPaises paises[], char nombresPaises[][18]){

    int eleccion;
    bool datosActualizados = false;
    int cantPaises = 0;
    int cantAnios = 0;


    do{
        encabezado();

        printf("1. Ingresar votos\n");
        printf("2. Listado de votos\n");
        printf("3. Reportes\n");
        printf("4. Salir\n\n\n");

        eleccion = pedirEntero(1, 4);


        switch (eleccion) {
            case 1:
                menuInicializarDatos( paises, nombresPaises, &cantPaises, &cantAnios );
                system("pause");
                break;


            case 2:
                if( cantPaises )
                    mostrarTabla( paises, nombresPaises, cantPaises, cantAnios );
                else
                    printf("ERROR: inicialice los datos.\n\n");
                system("pause");
                break;


            case 3:
                if( cantPaises )
                    menuReportes( paises, nombresPaises, cantPaises, cantAnios );
                else
                    printf("ERROR: inicialice los datos\n\n");
                system("pause");
                break;

            case 4: break;

            default:
                printf("ERROR: elecci\242n incorrecta.\n\n");
                system("pause");
        }


        system("cls");
    }while( eleccion != 4 );

    printf("Programa desarrollado por Gerardo Fr\242meta Rubio.\n\n");
    system("pause");
}
