#include <stdio.h>
#include <stdbool.h>
#include "Logica/Datos.h"

void encabezado(void);

//solicitar datos
int pedirEntero(int limInferior, int limSuperior);
int pedirPais( DatosPaises paises[], int cantPaises );

//reportes
void resultadoReporteCantidades(int aFavor, int enContra, int abstenciones);
void resultadoReporteListas( DatosPaises paises[], int salidas[], int cantSalidas, int reporte );

//tablas
void mostrarTablaPaises( DatosPaises paises[], int cantPaises, int cantAnios );
void mostrarTablaAnios( DatosTotalVotos totales[], int cantAnios);
