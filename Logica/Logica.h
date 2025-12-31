#include <stdbool.h>
#include "Logica/Datos.h"


bool esEntero(char cadena[]);
void inicializarAutomatico( DatosPaises votos[], char paises[][18], int cantPaises, int anios );
void contarTiposVotosPais( DatosPaises pais, int cantAnios, int* aFavor, int* enContra, int* abstenciones );
void encontrarHanVotadoContra( DatosPaises paises[], bool votosEnContra[], int cantPaises, int cantAnios );
