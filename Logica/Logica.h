#include <stdbool.h>
#include "Logica/Datos.h"

//validación números
bool esEntero(char cadena[]);

//validación letras
bool tieneSimbolos(char cadena[], int longitud);
bool cadenaNormalizada(char cadena[], int tamanio);
bool seHaIngresadoPais(DatosPaises paises[], char pais[], int cantPaises);
bool todoMayuscula(char cadena[], int tamanio);



//inicialización
void inicializarAutomatico( DatosPaises paises[], int cantPaises, int anios );

//actualización
void actualizarPaises(DatosPaises paises[], int cantFija, int cantLibre);
void actualizarAnios(DatosPaises paises[], DatosTotalVotos totalesAnios[], int cantFija, int cantLibre);

//reportes
int encontrarHanVotadoContra( DatosPaises paises[], int posSalidas[], int cantPaises);
int encontrarMasAFavor( DatosPaises paises[], int salidas[], int cantPaises );


