#include "Interfaz/Salidas.h"
#include "Logica/Logica.h"
#include <stdbool.h>
#include <stdlib.h>




void menuInicializacionManual( DatosPaises paises[], int* ptrCantPaises, int* ptrCantAnios, bool* ptrSeInicializo, bool* ptrDatosActualizados){
        bool atras = false;

        do{
            system("cls");
            encabezado();
            printf("Introduzca la opci\242n deseada.\n\n");
            printf("1. Ingresar datos\n");
            printf("2. Mostrar tabla de votos\n");
            printf("3. Editar nombre de un pa\241s\n");
            printf("4. Editar votos de un a\244o\n");
            printf("5. Editar voto de un pa\241s en un a\244o determinado\n");
            printf("6. Eliminar pa\241s.\n");
            printf("7. Atr\240s\n\n");


            printf("Opci\242n: ");

            switch( pedirEntero(1, 7) ){
                case 1:
                    if( *ptrSeInicializo ){
                        printf("Si vuelve a inicializar los datos estos se sobreescribir\240n.\n");
                        printf("Desea hacerlo (SI o NO)?\n\n");
                    }



                    if(!*ptrSeInicializo || tomarDecision()){

                        *ptrCantPaises = pedirNombresPaises(paises, 17);

                        if(*ptrCantPaises > 0){
                            *ptrCantAnios = tomarVotos(paises, *ptrCantPaises);
                            *ptrSeInicializo = true;
                        }
                        else
                            *ptrSeInicializo = false;
                            *ptrDatosActualizados = false;
                    }
                    break;


                case 2:
                    if(!*ptrSeInicializo)
                        printf("ERROR: primero debe inicializar los datos.\n\n");
                    else
                        mostrarTablaPaises(paises, *ptrCantPaises, *ptrCantAnios);

                    system("pause");
                    break;



                case 3:
                    printf("IMPLEMENTE\n");
                    break;
                case 4:
                    printf("IMPLEMENTE\n");
                    break;
                case 5:
                    printf("IMPLEMENTE\n");
                    break;

                case 6:
                    printf("IMPLEMENTE\n");
                    break;

                case 7:
                    atras = true;
                    break;
            }

        }while( !atras );


        if( *ptrCantAnios <= 0 || *ptrCantPaises <= 0 ){
            *ptrSeInicializo = false;
            *ptrDatosActualizados = false;
            printf("No existen los datos.\n\n");
        }

}











void menuInicializarDatos(DatosPaises paises[], int* ptrCantPaises, int* ptrCantAnios, bool* ptrSeInicializo, bool* ptrDatosActualizados){

        system("cls");
        encabezado();
        printf("Introduzca c\242mo desea inicializar los datos.\n\n");
        printf("1. Autom\240ticamente\n");
        printf("2. Manualmente\n");
        printf("3. Atr\240s\n\n");


        printf("Opci\242n: ");


        switch( pedirEntero(1, 3) ){
            case 1:
                if( *ptrSeInicializo ){
                    printf("\n\nSi vuelve a inicializar los datos estos se sobreescribir\240n.\n");
                    printf("Desea hacerlo?\n\n");
                }

                if( !*ptrSeInicializo || tomarDecision() ){

                    printf("\n\nIngrese la cantidad de pa\241ses que desea usar (a lo sumo 15): ");
                    *ptrCantPaises = pedirEntero(1, 15);

                    printf("\n\nIngrese la cantidad de a\244os que desea usar (a lo sumo 50): ");
                    *ptrCantAnios = pedirEntero(1,50);

                    inicializarAutomatico(paises, *ptrCantPaises, *ptrCantAnios);
                    *ptrSeInicializo = true;
                    *ptrDatosActualizados = false;
                }

                break;

            case 2:
                menuInicializacionManual(paises, ptrCantPaises, ptrCantAnios, ptrSeInicializo, ptrDatosActualizados);
                break;

            case 3:break;
        }


}








void menuReportes(DatosPaises paises[], DatosTotalVotos totalesAnios[], int cantPaises, int cantAnios){

    system("cls");

    bool atras = false;
    int pais;                           //pais que desea analizar en el reporte
    int anio;

    ///salidas
    int salidas[200] = {0};
    int cantSalidas;


    do{

        encabezado();
        printf("Ingrese el reporte deseado.\n\n");
        printf("1. Cantidad de votos que un pa\241s ha realizado a favor, en contra y cu\240ntas abstenciones.\n");
        printf("2. Pa\241s o pa\241ses que han votado en contra y cantidad de veces que lo han hecho.\n");
        printf("3. Pa\241s o pa\241ses con m\240s votos a favor.\n");
        printf("4. Cantidad de votos a favor, en contra y abstenciones en un a\244o determinado.\n");
        printf("5. Atr\240s.\n\n");

        printf("Opci\242n: ");

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
                printf("A\244o: ");
                anio = pedirEntero(1992, 1992 + cantAnios - 1) - 1992;

                printf("\nVotos en %d:\n", anio + 1992);
                resultadoReporteCantidades( totalesAnios[anio].aFavor , totalesAnios[anio].enContra, totalesAnios[anio].abstenciones );
                break;

            case 5:
                atras = true;
                break;
        }

        if( !atras ){
            system("pause");
            system("cls");
        }

    }while(!atras);

}









void menu( DatosPaises paises[], DatosTotalVotos totalesAnios[] ){

    bool datosInicializados = false;
    bool totalesActualizados = false;
    bool seguir = true;

    int cantPaises;
    int cantAnios;


    do{

        encabezado();

        printf("1. Ingresar votos\n");
        printf("2. Actualizar datos de tablas\n");
        printf("3. Listado por pa\241ses\n");
        printf("4. Listado de a\244os\n");
        printf("5. Reportes\n");
        printf("6. Salir\n\n\n");

        printf("Opci\242n: ");

        switch (pedirEntero(1, 6)) {
            case 1:
                menuInicializarDatos(paises, &cantPaises, &cantAnios, &datosInicializados, &totalesActualizados);
                totalesActualizados = false;
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
                break;



            case 3:
                if( datosInicializados )
                    mostrarTablaPaises(paises, cantPaises, cantAnios);
                else
                    printf("ERROR: actualice los datos.\n\n");

                break;

            case 4:
                if( totalesActualizados )
                    mostrarTablaAnios(totalesAnios, cantAnios);
                else
                    printf("ERROR: actualice los datos\n\n");
                break;

            case 5:
                if( totalesActualizados )
                    menuReportes(paises, totalesAnios, cantPaises, cantAnios);
                else
                    printf("ERROR: actualice los datos\n\n");
                break;

            case 6:
                seguir = false;
                break;
        }
        system("pause");
        system("cls");
    }while( seguir );

    printf("Programa desarrollado por Gerardo Fr\242meta Rubio.\n\n");
    system("pause");
}
