#ifndef DATOS_H

#define DATOS_H
#define TAM_ARR_CHAR 17
#define MAX_PAISES 200
#define MAX_ANIOS 40
#define MAX_INICI_MANO 15
#define ANIO_INICIO 1992

struct datosTotalVotos{
    int aFavor;
    int enContra;
    int abstenciones;
};

typedef struct datosTotalVotos DatosTotalVotos;

struct datosPaises{
    DatosTotalVotos total;

    char nombre[TAM_ARR_CHAR+1];
    int votos[MAX_ANIOS];
};

typedef struct datosPaises DatosPaises;

#endif
