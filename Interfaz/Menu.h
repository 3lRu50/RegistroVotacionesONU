#include "Interfaz/Salidas.h"
#include "Logica/Logica.h"

void menuModificarDatos( DatosPaises paises[], int* ptrCantPaises, int* ptrCantAnios, bool* ptrSeInicializo, bool* ptrDatosActualizados);
void menuInicializarDatos(DatosPaises paises[], int* ptrCantPaises, int* ptrCantAnios, bool* ptrSeInicializo, bool* ptrDatosActualizados);
void menuReportes(DatosPaises paises[], DatosTotalVotos totalesAnios[], DatosTotalVotos totalesGenerales, int cantPaises, int cantAnios);
void menu(DatosPaises paises[], DatosTotalVotos totalesAnios[] );
