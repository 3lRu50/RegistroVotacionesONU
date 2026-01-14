#include "Interfaz/Salidas.h"
#include "Logica/Logica.h"
#include <stdbool.h>
#include <stdlib.h>




void menuModificarDatos( DatosPaises paises[], int* ptrCantPaises, int* ptrCantAnios, bool* ptrSeInicializo, bool* ptrDatosActualizados ){
    bool atras = false;
    int pais;
    int anio;

    do{
        encabezado();
        printf("Introduzca la opci\242n deseada\n\n");
        printf(" 1. Mostrar tabla de votos\n");
        printf(" 2. Editar nombre de un pa\241s\n");
        printf(" 3. Editar votos de un a\244o\n");
        printf(" 4. Editar voto de un pa\241s en un a\244o determinado\n");
        printf(" 5. Editar votos un pa\241s\n");
        printf(" 6. Eliminar pa\241s\n");
        printf(" 7. Elimina \243ltimo a\244o (%d)\n",        1991 + *ptrCantAnios);
        printf(" 8. A\244adir pa\241s\n");
        printf(" 9. A\244adir a\244o %d\n",                  1992 + *ptrCantAnios);
        printf("10. Atr\240s\n\n");


        printf("Opci\242n: ");

        switch( pedirEntero(1, 10) ){




            //mostrar votos
            case 1:
                    mostrarTablaPaises(paises, *ptrCantPaises, *ptrCantAnios);
                break;




                //cambia nombre
            case 2:
                    printf("\n\nIntroduzca el pa\241s del que desea editar el nombre.\n\n");
                    pais = pedirPais(paises, *ptrCantPaises, true);

                    printf("\n\nIntroduzca el nuevo nombre.\n");
                    tomarNombreUnPais(paises, pais, *ptrCantPaises);

                break;



                //cambiar votos un año
            case 3:
                    anio = pedirAnio(*ptrCantAnios);

                    printf("\n\nEst\240 usted seguro(a) de reescribir los votos de %d (SI o NO)?\n", 1992+anio);
                    if( tomarDecision() ){
                        encabezado();
                        tomarVotosAnio(paises, *ptrCantPaises, anio);
                        *ptrDatosActualizados = false;
                    }


                break;





                //cambia voto específico
            case 4:
                    anio = pedirAnio(*ptrCantAnios);
                    printf("\n\nIntroduzca el pa\241s del que desea modificar el voto.\n\n");
                    pais = pedirPais(paises, *ptrCantPaises, true);

                    printf("\n\nEst\240 usted seguro(a) de reescribir el voto de %s en %d (SI o NO)?\n", paises[pais].nombre, 1992 + anio);
                    if( tomarDecision() ){

                        encabezado();
                        tiposDeVotos();

                        printf("Voto: ");
                        paises[pais].votos[anio] = pedirEntero(-1, 1);
                        *ptrDatosActualizados = false;

                    }else printf("No se ha editado ning\243n valor.\n\n");

                break;


                //editar votos un país
            case 5:
                    printf("\n\nElija el pa\241s que desea editar:\n\n");
                    pais = pedirPais(paises, *ptrCantPaises, true);

                    printf("Est\240 usted seguro(a) de modificar los votos de %s (SI o NO)?\n", paises[pais].nombre );
                    if(tomarDecision()){

                        tomarVotosPais(paises, *ptrCantAnios, pais);
                        *ptrDatosActualizados = false;

                    }else printf("No se realiz\242 ning\243n cambio.\n\n");
                break;







                //eliminar país
            case 6:
                    printf("\n\nIntroduzca el pa\241s que desea eliminar.\n\n");
                    pais = pedirPais(paises, *ptrCantPaises, true);

                    printf("\n\nEst\240 seguro(a) de borrar %s de la base de datos (SI o NO)?\n", paises[pais].nombre);
                    if( tomarDecision() ){

                        eliminarPais(paises, pais, ptrCantPaises);
                        *ptrDatosActualizados = false;
                        printf("\n\nSe elimin\242 el pa\241s con \202xito.\n");

                    } else printf("Se mantuvo el pa\241s %s.\n", paises[pais].nombre);

                break;






                //eliminar año
            case 7:
                    printf("\n\nEst\240 usted seguro(a) de eliminar %d (SI o NO)?\n", 1991 + *ptrCantAnios);
                    if(tomarDecision()){

                        (*ptrCantAnios)--;
                        *ptrDatosActualizados = false;

                    }else  printf("Se mantuvieron los votos de %d.\n", 1991 + *ptrCantAnios);

                break;







                //agregar país nuevo
            case 8:
                if( *ptrCantPaises >= 200 )
                    printf("\aERROR: el programa no admite m\240s de 200 pa\241ses.\n");

                //pide el nombre y si ingresa el centinela no hace nada
                else if( tomarNombreUnPais(paises, *ptrCantPaises, *ptrCantPaises) ){
                    tomarVotosPais( paises, *ptrCantAnios, *ptrCantPaises);

                    if(*ptrSeInicializo) (*ptrCantPaises)++;
                    else *ptrCantPaises = 0;

                    *ptrDatosActualizados = false;
                }

                break;





                //agregar año
            case 9:
                if( *ptrCantAnios >= 50 )
                    printf("\aERROR: el programa no admite m\240s a\244os.\n");

                else{
                    tomarVotosAnio(paises, *ptrCantPaises, (*ptrCantAnios)++ );
                    *ptrDatosActualizados = false;
                }
                break;




            case 10:
                atras = true;
                break;
        }



        system("pause");

        //reconocer cuando falta los datos mínimos
        if( *ptrCantPaises <= 0 || *ptrCantAnios <= 0 ){
            printf("\n\nNo hay datos de pa\241ses.\n\n");
            *ptrSeInicializo = *ptrDatosActualizados = false;
            atras = true;
        }


    }while( !atras );

}




















void menuInicializarDatos(DatosPaises paises[], int* ptrCantPaises, int* ptrCantAnios, bool* ptrSeInicializo, bool* ptrDatosActualizados){

    encabezado();
    printf("Introduzca c\242mo desea inicializar los datos.\n\n");
    printf("1. Autom\240ticamente\n");
    printf("2. Manualmente\n");
    printf("3. Modificar datos\n");
    printf("4. Atr\240s\n\n");


    printf("Opci\242n: ");


    switch( pedirEntero(1, 4) ){
        case 1:
            if( *ptrSeInicializo ){
                printf("\n\nSi vuelve a inicializar los datos estos se sobreescribir\240n.\n");
                printf("Desea hacerlo (SI o NO)?\n\n");
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

            //ingresar datos manualmente (reescribir)
        case 2:
            if( *ptrSeInicializo ){
                printf("\n\nSi vuelve a inicializar los datos, estos se sobreescribir\240n.\n");
                printf("Si no ingresa ning\243n nombre, todos los datos se borrar\240n.\n");
                printf("Desea hacerlo (SI o NO)?\n\n");
            }


            if(!*ptrSeInicializo || tomarDecision()){

                *ptrCantPaises = pedirNombresPaises(paises, 17);

                if(*ptrCantPaises > 0){
                    *ptrCantAnios = tomarVotos(paises, *ptrCantPaises);
                    *ptrSeInicializo = true;
                }
                else *ptrSeInicializo = false;

                //si entra borra datos sí o sí
                *ptrDatosActualizados = false;
            }
            break;


        case 3:
            if(*ptrSeInicializo)
                menuModificarDatos(paises, ptrCantPaises, ptrCantAnios, ptrSeInicializo, ptrDatosActualizados);
            else {
                printf("\aERROR: debe inicializar los datos.\n\n");
                system("pause");
            }
            break;

        case 4:break;
    }


}








void menuReportes(DatosPaises paises[], DatosTotalVotos totalesAnios[], DatosTotalVotos totalesGenerales, int cantPaises, int cantAnios){

    bool atras = false;
    int pais;                           //pais que desea analizar en el reporte
    int anio;

    ///salidas
    int salidas[200] = {0};
    int cantSalidas;


    do{

        encabezado();
        printf("Ingrese el reporte deseado\n\n");
        printf("1. Cantidad de votos que un pa\241s ha realizado a favor, en contra y cu\240ntas abstenciones\n");
        printf("2. Pa\241s o pa\241ses que han votado en contra y cantidad de veces que lo han hecho\n");
        printf("3. Pa\241s o pa\241ses con m\240s votos a favor\n");
        printf("4. Cantidad de votos a favor, en contra y abstenciones en un a\244o determinado\n");
        printf("5. Resumen general de un pa\241s\n");
        printf("6. Atr\240s\n\n");

        printf("Opci\242n: ");

        switch( pedirEntero(1, 6) ){
            case 1:
                printf("\n\nIntroduzca el pa\241s del que desea controlar las votaciones.\n\n");
                pais = pedirPais( paises, cantPaises, true );

                encabezado();
                printf("\nVotos de %s:\n", paises[pais].nombre);
                resultadoReporteCantidades( paises[pais].total, cantAnios );
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
    
                encabezado();
                printf("\nVotos en %d:\n", anio + 1992);
                resultadoReporteCantidades( totalesAnios[anio], cantPaises );
                break;
    
            case 5:
                encabezado();
                printf("Resumen de votos a lo largo de los a\244os.\n\n");
                resultadoReporteCantidades( totalesGenerales, cantPaises*cantAnios );
                break;

            case 6:
                atras = true;
                break;
        }



        if( !atras ) system("pause");


    }while(!atras);

}









void menu( DatosPaises paises[], DatosTotalVotos totalesAnios[] ){

    DatosTotalVotos totalesGenerales;
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
                    actualizarAnios(paises, totalesAnios, &totalesGenerales, cantPaises, cantAnios);

                    printf("Se actualizaron los totales.\n\n");
                    totalesActualizados = true;
                }
                else
                    printf("\aERROR: inicialice los datos.\n\n");
                system("pause");
                break;



            case 3:
                if( datosInicializados )
                    mostrarTablaPaises(paises, cantPaises, cantAnios);
                else
                    printf("\aERROR: inicialice los datos.\n\n");
                system("pause");
                break;


            case 4:
                if( totalesActualizados )
                    mostrarTablaAnios(totalesAnios, totalesGenerales, cantAnios);
                else
                    printf("\aERROR: actualice los datos.\n\n");
                system("pause");
                break;


            case 5:
                if( totalesActualizados )
                    menuReportes(paises, totalesAnios, totalesGenerales, cantPaises, cantAnios);
                else
                    printf("\aERROR: actualice los datos.\n\n");
                system("pause");
                break;


            case 6:
                seguir = false;
                system("pause");
                break;
        }

    }while( seguir );

    system("cls");
    printf("Programa desarrollado por Gerardo Fr\242meta Rubio, IF12, Cujae (2025 - 2026).\n\n");
    system("pause");
}
