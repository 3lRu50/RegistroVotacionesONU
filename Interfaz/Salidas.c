#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <Logica/Logica.h>

void encabezado(void){
    system("cls");
    printf("Ministerio de Relaciones Exteriores.\n");
    printf("Votaci\242n contra el bloqueo estadounidense.\n\n");
}





int pedirEntero(int limInferior, int limSuperior){

    char cadena[TAM_ARR_CHAR];
    int numero;
    bool numeroValido = false;


    do{

        fgets(cadena, sizeof(cadena), stdin);
        fflush(stdin);

        cadena[ strcspn(cadena, "\n") ] = '\0';

        //se toma 11 ya que con ints de 4bytes el largo es de 10 dígitos
        //en este programa solo es útil para que el usuario no ingrese 0 una cant inmensa y luego ingrese un número diferente de 0, para el caso de que tenga solo ceros va a tomar el 0
        if( strlen(cadena) >= 11 )
            printf("\aERROR: debe ingresar un numero de a lo sumo 10 d\241gitos.\n");

        else if( esEntero(cadena) ){
            numero = atoi(cadena);

            if( limInferior <= numero && numero <= limSuperior )
                numeroValido = true;

            else if(limInferior == limSuperior)
                printf("\aERROR: el \243nico valor que puede ingresar es %d.\n", limInferior);
            else
                printf("\aERROR: debe ingresar un valor entre %d y %d.\n", limInferior, limSuperior);

        }
        else
            printf("\aERROR: debe ingresar un n\243mero entero.\n");


        if(!numeroValido) printf("Int\202ntelo nuevamente: ");

    }while(!numeroValido);


    return numero;
}











bool validarNombrePais( DatosPaises paises[], char cadena[], int cantPaises, int maxLetras){

    int tamanio = strlen(cadena);
    bool sonSiglas = tamanio <= 3 ? true : false;
    bool valido = false;




    if( tamanio < 2 )
        printf("\aERROR: debe ingresar al menos 2 caracteres.\n\n");

    else if( tieneSimbolos(cadena, tamanio) )
        printf("\aERROR: la cadena solo puede tener letras (omita la tildes en may\243sculas).\n\n");

    else if( tamanio > maxLetras )
        printf("\aERROR: debe ingresar a lo sumo %d caracteres.\n\n", maxLetras);

    else if( sonSiglas && !esTodoMayuscula(cadena, tamanio) )
        printf("\aERROR: si ingresa menos de 4 caracteres se consideran siglas y deben ser escritas en may\243scula.\n\n");

    else if( !sonSiglas && !cadenaNormalizada(cadena, tamanio) )
        printf("\aERROR: debe usar may\243scula despu\202s de los espacios y min\243sculas en el resto del nombre.\n\n");

    else if( seHaIngresadoElPais(paises, cadena, cantPaises ) )
        printf("\aERROR: ya ha ingresado este pa\241s.\n\n");

    else valido = true;


    return valido;
}



















bool pedirNombre( DatosPaises paises[], int cantPaises, int pais, int maxLetras ){

    bool nuevoNombre;
    bool nombreValido = false;
    char entrada[TAM_ARR_CHAR+4];




    do{
        nombreValido = true;

        printf("\nPa\241s %d: ", pais+1);
        fgets(entrada, sizeof(entrada), stdin);
        fflush(stdin);

        entrada[ strcspn(entrada, "\n") ] = '\0';

        if( !strcmp(entrada, "FINAL") )
            nuevoNombre = false;

        else if( validarNombrePais(paises, entrada, cantPaises, maxLetras) ){
            nuevoNombre = true;
            strcpy( paises[pais].nombre, entrada );
        }

        else nombreValido = false;

    }while(!nombreValido);


    return nuevoNombre;
}
















bool tomarDecision(void){
    bool decision;
    bool decisionValida;
    char cadena[TAM_ARR_CHAR];

    do{
        decisionValida = true;
        printf("Decisi\242n: ");

        gets(cadena);
        fflush(stdin);

        if( !strcmp(cadena, "SI") )
            decision = true;
        else if( !strcmp(cadena, "NO") )
            decision = false;

        else{
            decisionValida = false;
            printf("\aERROR: solo puede ingresar SI o NO.\n\n");
        }

    }while(!decisionValida);


    return decision;
}









void tiposDeVotos(void){

    printf("Tipos de votos:\n");
    printf("\t 1 --> A favor\n");
    printf("\t 0 --> Abstenci\242n\n");
    printf("\t-1 --> En Contra\n\n\n\n");

}





void tomarVotosAnio( DatosPaises paises[], int cantPaises, int anio ){

    int i;

    encabezado();
    tiposDeVotos();

    printf("\n\nIntroduzca los votos del a\244o %d:\n\n", anio + ANIO_INICIO);

    for(i = 0; i < cantPaises; i++){
        printf("%*s: ", TAM_ARR_CHAR, paises[i].nombre);

        paises[i].votos[anio] = pedirEntero(-1, 1);
    }

}






void tomarVotosPais( DatosPaises paises[], int cantAnios, int pais){

    int i;

    encabezado();
    tiposDeVotos();

    printf("\n\nIntroduzca los votos de %s hasta %d:\n\n", paises[pais].nombre, cantAnios + ANIO_INICIO-1);

    for(i = 0; i < cantAnios; i++){
        printf("\t%d: ", i+ANIO_INICIO);

        paises[pais].votos[i] = pedirEntero(-1, 1);
    }

}




















int tomarVotos( DatosPaises paises[], int cantPaises ){
    int i;
    bool seguir = true;

    for(i = 0; i < MAX_ANIOS && seguir; i++){
        encabezado();

        tomarVotosAnio(paises, cantPaises, i);

        printf("\n\nDesea ingresar votos para %d (SI o NO)?\n", ANIO_INICIO+1 + i);
        seguir = tomarDecision();
    }


    return i;
}




















int pedirPais( DatosPaises paises[], int cantPaises ){
    int i;

    for(i = 0; i < cantPaises; i++)
        printf("%3d. %s\n", i+1, paises[i].nombre);
    printf("\n\n");

    printf("Pa\241s: ");


    return pedirEntero(1, cantPaises) - 1;
}







int pedirAnio( int cantAnios ){

    if( cantAnios == 1 )
        printf("\n\n\nIngrese el \243nico a\244o registrado (%d).\n\n", ANIO_INICIO);
    else
        printf("\n\n\nIntroduzca un pa\241s entre %d y %d.\n\n", ANIO_INICIO, ANIO_INICIO-1 + cantAnios);

    printf("A\244os: ");
    return pedirEntero(ANIO_INICIO, ANIO_INICIO-1 + cantAnios) - ANIO_INICIO;
}





















void resultadoReporteListas( DatosPaises paises[], int salidas[], int cantSalidas, int reporte ){
    int i;

    if( !cantSalidas )          printf("\nNo se encontraron pa\241ses que cumplan con las condiciones de este reporte.\n");


    else {
        encabezado();
        if(reporte == 2)        printf("\nPa\241%s con al menos un voto en contra de la resoluci\242n:\n", cantSalidas > 1 ? "ses" : "s");
        else if(reporte == 3)   printf("\nPa\241%s con mayor cantidad de votos a favor (%d):\n", cantSalidas > 1 ? "ses" : "s", paises[salidas[0]].total.aFavor );

        for(i = 0; i < cantSalidas; i++){
            printf("%3d. %s ", i+1,       paises[ salidas[i] ].nombre);

            if(reporte == 2)
                printf("%d ve%s\n", paises[ salidas[i] ].total.enContra,   paises[ salidas[i] ].total.enContra > 1 ? "ces" : "z");
            else
                printf("\n");
        }

        printf("\n");
    }
}















void mostrarTablaPaises( DatosPaises paises[], int cantPaises, int cantAnios ){

    int i, j;

    //variables para abreviar
    bool extremoSup;
    bool extremoDer;
    bool extremoIzq;

    encabezado();
    printf("Leyenda:\n");
    printf("\tAbstenci\242n -> Abs\n");
    printf("\tA Favor    -> Fav\n");
    printf("\tEn contra  -> Con\n\n\n");

    for(i = -1; i < cantPaises; i++){
        extremoSup = i == -1;

        for(j = -1; j < cantAnios; j++){
            extremoIzq = j == -1;
            extremoDer = j == cantAnios-1;

            if(extremoIzq && extremoSup) printf("%-20s", "\n\nPa\241ses");
            else if(extremoSup) printf("%-5d", ANIO_INICIO+j);
            else if(extremoIzq) printf("%-*s", TAM_ARR_CHAR+1, paises[i].nombre);

            else if(!paises[i].votos[j]) printf("%-5s", "Abs");
            else if(paises[i].votos[j] == 1) printf("%-5s", "Fav");
            else printf("%-5s", "Con");

            if(extremoDer) printf("\n");
        }
    }

}













void mostrarTablaAnios( DatosTotalVotos totales[], DatosTotalVotos totalesGenerales, int cantAnios ){

    int i, j;

    encabezado();


    printf("%-15s", "\n\nA\244os");

    for(i = 0; i < 4; i++){

        if(i == 1)      printf("%-12s ", "A favor");
        else if(i == 2) printf("%-12s ", "En contra");
        else if(i == 3) printf("%-12s ", "Abstenciones");

        for(j = 0; j < cantAnios; j++){

            if(!i)          printf("%5d", ANIO_INICIO+j);
            else if(i == 1) printf("%5d", totales[j].aFavor);
            else if(i == 2) printf("%5d", totales[j].enContra);
            else            printf("%5d", totales[j].abstenciones);


        }

        if(!i) printf("%-12s ", " TOTAL");
        else if(i == 1) printf(" %5d", totalesGenerales.aFavor);
        else if(i == 2) printf(" %5d", totalesGenerales.enContra);
        else if(i == 3) printf(" %5d", totalesGenerales.abstenciones);


        printf("\n");
    }

}





















//esta función redondea la cantidad de *s con el mayor múltiplo de 5 menor o igual que cada porciento
void resultadoReporteCantidades( DatosTotalVotos votos, int cantVotos ){

    int aFavor = votos.aFavor;
    int enContra = votos.enContra;
    int abstenciones = votos.abstenciones;


    float porcientoAFavor = (float) aFavor / cantVotos *100;
    float porcientoEnContra = (float) enContra / cantVotos *100;
    float porcientoAbstenciones = (float) abstenciones / cantVotos *100;


    printf("\tA favor: %d\n", aFavor);
    printf("\tEn contra: %d\n", enContra);
    printf("\tAbstenciones: %d\n\n", abstenciones);


    int i;
    for(i = 20; 0 < i; i--){

        if(!(i % 2)) printf("%3d|", i*5);
        else printf("   |");

        printf("%20c",   porcientoAFavor >= i*5          ? '*' : ' ');
        printf("%20c",   porcientoEnContra >= i*5        ? '*' : ' ');
        printf("%20c\n", porcientoAbstenciones >= i*5    ? '*' : ' ');
    }


    printf("  0|================================================================\n");
    printf("    %20s%20s%20s\n", "A FAVOR", "EN CONTRA", "ABSTENCIONES");
    printf("     %18.2f%% %18.2f%% %18.2f%%\n", porcientoAFavor, porcientoEnContra, porcientoAbstenciones);

}




