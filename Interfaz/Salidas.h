#include <stdio.h>
#include <stdbool.h>
#include "Logica/Datos.h"

void encabezado(void);

//validación
bool validarNombrePais( DatosPaises paises[], char cadena[], int cantPaises, int maxLetras);

//solicitar datos
int pedirEntero(int limInferior, int limSuperior);
int pedirPais( DatosPaises paises[], int cantPaises );
int pedirAnio( int cantAnios );
int pedirNombresPaises( DatosPaises paises[], int maxLetras );
int tomarVotos( DatosPaises paises[], int cantPaises );
void tomarVotosAnio( DatosPaises paises[], int ptrCantPaises, int anio );
void tomarVotosPais( DatosPaises paises[], int cantAnios, int pais);
bool tomarNombreUnPais( DatosPaises paises[], int pais, int cantPaises );
bool tomarDecision(void);

//reportes
void resultadoReporteCantidades(int aFavor, int enContra, int abstenciones);
void resultadoReporteListas( DatosPaises paises[], int salidas[], int cantSalidas, int reporte );

//tablas
void mostrarTablaPaises( DatosPaises paises[], int cantPaises, int cantAnios );
void mostrarTablaAnios( DatosTotalVotos totales[], int cantAnios);



void tiposDeVotos(void);
