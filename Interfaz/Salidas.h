#include <stdio.h>
#include <stdbool.h>
#include "Logica/Datos.h"

void encabezado(void);
int pedirEntero(int limInferior, int limSuperior);
int pedirPais( char nombresPaises[][18], int cantPaises );
void mostrarTiposVotosPais(char pais[], int cantAnios, int aFavor, int enContra, int abstenciones);
void mostrarHanVotadoContra( char nombresPaises[][18], bool votosEnContra[], int cantPaises );
void mostrarTabla( DatosPaises paises[], char nombresPaises[][18], int cantPaises, int cantAnios );
