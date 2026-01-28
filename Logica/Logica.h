#include <stdbool.h>
#include <Logica/Datos.h>

//validación números
bool esEntero(char cadena[]);

//validación letras
bool tieneSimbolos(char cadena[], int longitud);
bool cadenaNormalizada(char cadena[], int tamanio);
bool seHaIngresadoElPais(DatosPaises paises[], char pais[], int cantPaises);
bool esTodoMayuscula(char cadena[], int tamanio);


void eliminarPais( DatosPaises paises[], int pais, int* ptrCantPaises);


//inicialización
void inicializarAutomatico( DatosPaises paises[], int cantPaises, int anios );

//actualización
void actualizarPaises(DatosPaises paises[], int cantFija, int cantLibre);
void actualizarAnios(DatosPaises paises[], DatosTotalVotos totalesAnios[], DatosTotalVotos *totalesGenerales, int cantFija, int cantLibre);

//reportes
int encontrarHanVotadoContra( DatosPaises paises[], int posSalidas[], int cantPaises);
int encontrarMasAFavor( DatosPaises paises[], int salidas[], int cantPaises );


