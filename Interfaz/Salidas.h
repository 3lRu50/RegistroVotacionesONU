#include <stdio.h>
#include <stdbool.h>
#include "Logica/Datos.h"

void encabezado(void);
int pedirEntero(int limInferior, int limSuperior);
int pedirPais( char nombresPaises[][18], int cantPaises );
void resultadoReporteCantidades(char pais[], int anio, int aFavor, int enContra, int abstenciones, int reporte);
void resultadoReporteListas( char salidaReporte[][18], int cantPaisesSalida, int reporte );
void mostrarTabla( DatosPaises paises[], char nombresPaises[][18], int cantPaises, int cantAnios );
