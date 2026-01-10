#ifndef DATOS_H
#define DATOS_H


struct datosTotalVotos{
    int aFavor;
    int enContra;
    int abstenciones;
};

typedef struct datosTotalVotos DatosTotalVotos;

struct datosPaises{
    DatosTotalVotos total;

    char nombre[18];
    int votos[50];
};

typedef struct datosPaises DatosPaises;

#endif
