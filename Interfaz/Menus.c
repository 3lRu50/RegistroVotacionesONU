#include "Interfaz/Salidas.h"
#include "Logica/Logica.h"
#include <stdbool.h>
#include <stdlib.h>





bool menuInicializarDatos(DatosPaises paises[], int* ptrCantPaises, int* ptrCantAnios){

    system("cls");

    bool opcionValida;
    bool seInicializo = false;
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
                printf("\n\nIngrese la cantidad de pa\241ses que desea usar (a lo sumo 15): ");
                *ptrCantPaises = pedirEntero(1, 15);
                //////cambiar que no sea manual lo maximos
                printf("\n\nIngrese la cantidad de a\244os que desea usar (a lo sumo 50): ");
                *ptrCantAnios = pedirEntero(1,50);

                inicializarAutomatico(paises, *ptrCantPaises, *ptrCantAnios);
                seInicializo = true;
                break;

            case 2:
                printf("IMPLEMENTE");
                //////////cantPaises = inicializar(paises);
                seInicializo = true;
                break;

            case 3:break;
        }

    }while(!opcionValida);

    return seInicializo;
}








void menuReportes(DatosPaises paises[], DatosTotalVotos totalesAnios[], int cantPaises, int cantAnios){

    system("cls");

    bool opcionValida;                  //bandera que termina el bucle si ingresa un reporte correcto
    int pais;                           //pais que desea analizar en el reporte
    int anio;

    ///salidas
    int salidas[200] = {0};
    int cantSalidas;


    do{
        opcionValida = true;

        encabezado();
        printf("Ingrese el reporte deseado.\n\n");
        printf("1. Cantidad de votos que un pa\241s ha realizado a favor, en contra y cu\240ntas abstenciones.\n");
        printf("2. Pa\241s o pa\241ses que han votado en contra y cantidad de veces que lo han hecho.\n");
        printf("3. Pa\241s o pa\241ses con m\240s votos a favor.\n");
        printf("4. Cantidad de votos a favor, en contra y abstenciones en un a\244o determinado.\n");
        printf("5. Atr\240s.\n\n");


        switch( pedirEntero(1, 5) ){
            case 1:
                printf("\n\nIntroduzca el pa\241s del que desea controlar las votaciones.\n\n");
                pais = pedirPais( paises, cantPaises );

                printf("\nVotos de %s:\n", paises[pais].nombre);
                resultadoReporteCantidades( paises[pais].total.aFavor, paises[pais].total.enContra, paises[pais].total.abstenciones);
                break;

            case 2:
                cantSalidas = encontrarHanVotadoContra( paises, salidas, cantPaises );
                resultadoReporteListas( paises, salidas, cantSalidas, 2 );
                break;

            case 3:
                cantSalidas = encontrarMasAFavor( paises, salidas, cantPaises );
                resultadoReporteListas( paises, salidas, cantSalidas, 3 );
                break;

            case 4:
                printf("\n\nIntroduzca el a\244o del que desea controlar las votaciones (1992 - %d).\n\n", 1992 + cantAnios - 1);
                anio = pedirEntero(1992, 1992 + cantAnios - 1) - 1992;

                printf("\nVotos en %d:\n", anio + 1992);
                resultadoReporteCantidades( totalesAnios[anio].aFavor , totalesAnios[anio].enContra, totalesAnios[anio].abstenciones );
                break;

            case 5: break;
        }


    }while(!opcionValida);
}









void menu( DatosPaises paises[], DatosTotalVotos totalesAnios[] ){

    bool datosInicializados = false;
    bool totalesActualizados = false;
    int eleccion;

    int cantPaises = 0;
    int cantAnios = 0;


    do{

        encabezado();

        printf("1. Ingresar votos\n");
        printf("2. Actualizar datos de tablas\n");
        printf("3. Listado por pa\241ses\n");
        printf("4. Listado de a\244os\n");
        printf("5. Reportes\n");
        printf("6. Salir\n\n\n");

        eleccion = pedirEntero(1, 6);


        switch (eleccion) {
            case 1:
                datosInicializados = menuInicializarDatos(paises, &cantPaises, &cantAnios);
                totalesActualizados = false;
                system("pause");
                break;




            case 2:
                if( datosInicializados ){
                    actualizarPaises(paises, cantPaises, cantAnios);
                    actualizarAnios(paises, totalesAnios, cantPaises, cantAnios);

                    printf("Se actualizaron los totales.\n\n");
                    totalesActualizados = true;
                }
                else
                    printf("ERROR: inicialice los datos\n\n");
                system("pause");
                break;



            case 3:
                if( datosInicializados )
                    mostrarTablaPaises(paises, cantPaises, cantAnios);
                else
                    printf("ERROR: actualice los datos.\n\n");
                system("pause");
                break;

            case 4:
                if( totalesActualizados )
                    mostrarTablaAnios(totalesAnios, cantAnios);
                else
                    printf("ERROR: actualice los datos\n\n");
                system("pause");
                break;

            case 5:
                if( totalesActualizados )
                    menuReportes(paises, totalesAnios, cantPaises, cantAnios);
                else
                    printf("ERROR: actualice los datos\n\n");
                system("pause");
                break;

            case 6: break;
        }

        system("cls");
    }while( eleccion != 6 );

    printf("Programa desarrollado por Gerardo Fr\242meta Rubio.\n\n");
    system("pause");
}
