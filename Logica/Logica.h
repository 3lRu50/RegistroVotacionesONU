#include <stdbool.h>
#include "Logica/Datos.h"

//validación
bool esEntero(char cadena[]);

//inicialización
void inicializarAutomatico( DatosPaises paises[], int cantPaises, int anios );

//actualización
void actualizarPaises(DatosPaises paises[], int cantFija, int cantLibre);
void actualizarAnios(DatosPaises paises[], DatosTotalVotos totalesAnios[], int cantFija, int cantLibre);

//reportes
int encontrarHanVotadoContra( DatosPaises paises[], int posSalidas[], int cantPaises);
int encontrarMasAFavor( DatosPaises paises[], int salidas[], int cantPaises );


