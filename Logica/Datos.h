#ifndef DATOS_H
#define DATOS_H

struct datosPaises{
    int aniosAnalizados;
    int votos[34];
    // se toman 34 ya que se han realizado esa cantidad de votaciones de hasta enero de 2026
};

typedef struct datosPaises DatosPaises;

#endif
