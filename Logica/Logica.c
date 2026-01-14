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


    if( (cadena[0] == '-'  && isdigit(cadena[1])) || isdigit(cadena[0]) ){

        for(i = 1; i < tamanio && valido; i++)
            if( !isdigit(cadena[i]) )
                valido = false;

    }else valido = false;

    return valido;
}




















//////validaciones letras
bool tieneSimbolos(char cadena[], int longitud){
    bool tieneSimbolos = false;             //tiene un simbolo
    int i;



    bool tildeOenie;        //tiene tildeOeñe

    for(i = 0; i < longitud && !tieneSimbolos; i++){

        tildeOenie =  (cadena[i] >= -96 && cadena[i] <= -92) || cadena[i] == -126;

        //De Morgan
        if( !(isalpha(cadena[i]) || isspace(cadena[i]) || tildeOenie) )
            tieneSimbolos = true;
    }

    return tieneSimbolos;
}
    ///los valores (como -92) que uso, los obtuve como sigue:
    ///
    ///char cadena[];
    ///
    ///gets(entrada);
    ///printf("%d ", entrada[0]);













//la idea es ver si la posicion después del espacio es mayúscula
bool cadenaNormalizada(char cadena[], int tamanio){
    int i;
    int posInicioUltiPalabra = 0;


    char *posEspacio = strchr(cadena, ' ');
    bool normalizado = isupper(cadena[0]);



    for(i = 0; i < tamanio && normalizado; i++)

        //comprueba que haya una mayuscula después del espacio
        if( &cadena[i] == posEspacio )
            if( isupper(cadena[i+1]) ){
                posInicioUltiPalabra = i+1;
                posEspacio = strchr( posEspacio+1, ' ');
            }
            else if( !strncmp(&cadena[i+1], "de ", 3) && isupper(cadena[i+4]) ){
                posInicioUltiPalabra = i+1;
                posEspacio = strchr( posEspacio+1, ' ');
            }
            else if( !strncmp(&cadena[i+1], "del ", 4) && isupper(cadena[i+5]) ){
                posInicioUltiPalabra = i+1;
                posEspacio = strchr( posEspacio+1, ' ');
            }
            else if( !strncmp(&cadena[i+1], "y ", 2) && isupper(cadena[i+3]) ){
                posInicioUltiPalabra = i+1;
                posEspacio = strchr( posEspacio+1, ' ');
            }

            else normalizado = false;

        //comprueba si el caracter que no esta en el inicio de la palabra es minuscula
        else if(i != posInicioUltiPalabra && isupper(cadena[i]) )
            normalizado = false;


    return normalizado;
}














bool seHaIngresadoElPais(DatosPaises paises[], char pais[], int cantPaises){
    bool yaIngresado = false;
    int i;

    for(i = 0; i < cantPaises; i++)
        if( !strcmp( paises[i].nombre, pais ) )
            yaIngresado = true;

    return yaIngresado;
}















bool esTodoMayuscula(char cadena[], int tamanio){
    bool siglas = true;
    int i;

    for(i = 0; i < tamanio; i++)
        if( islower(cadena[i]) )
            siglas = false;

    return siglas;
}








void eliminarPais( DatosPaises paises[], int pais, int* ptrCantPaises){

    int i;

    for(i = pais; i < *ptrCantPaises; i++)
        paises[i] = paises[i+1];


    if (*ptrCantPaises == i) (*ptrCantPaises)--;

}












void inicializarAutomatico( DatosPaises paises[], int cantPaises, int anios ){

    int i, j;
    char nombres[15][18] = {
        "Cuba", "USA", "Rusia", "Israel", "Alemania",
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















//recorre filas
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














//recorre columnas
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





