#include <stdbool.h>
#include "Logica/Datos.h"


bool esEntero(char cadena[]);
void inicializarAutomatico( DatosPaises votos[], char paises[][18], int cantPaises, int anios );
void contarTiposVotosPais( DatosPaises pais, int cantAnios, int* aFavor, int* enContra, int* abstenciones );
int encontrarHanVotadoContra( DatosPaises paises[], char nombresPaises[][18], char conVotosEnContra[][18], int cantPaisesEnContra, int cantAnios );
int encontrarMasFavor( DatosPaises paises[], char nombresPaises[][18], char conMayorCantFavor[][18], int cantPaises, int cantAnios );
void contarVotosEnAnio( DatosPaises paises[], int anio, int cantPaises, int* aFavor, int* enContra, int* abstenciones );
