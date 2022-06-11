#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
 * Estudiante:
 * Nombre
 * fecha de nacimiento (fecha de nacimiento)
 * Dni (8 digitos)
 * lista Materias a cursar. (listas enlazadas)
 * lista Materias aprobadas. (listas enlazadas)
 * todasMateriasCursadas() [printf de primero aprobadas y después a cursar] (ver de imprimir )
 * próximo estudiante nombre
*/

typedef struct Estudiante {
    struct Estudiante *siguiente;
    int dni;
    char* nombre;
    int edad;
    char* fechaDeNacimiento;

} Estudiante;

int tamanio = 0;

int ComprobarDni(int *dni);
int lenInt(int dni);
int comprobarNacimiento(int *anio, int *mes, int *dia);
int comprobarDia(int *mes, int *dia, int *anio);
int bisiento(int *anio);
void imprimirEstudiante(Estudiante *estudiante);


/**
 * Inicializa un Nodo con su valor pasado como parametro, y 'siguiente'
 * referenciando a 'NULL'.
 * @param valor
 * @return
 */
Estudiante *crearEstudiante(char* nombre, int edad, int dni, char* nacimiento){
    Estudiante *estudiante = (Estudiante*) malloc(sizeof(Estudiante));
    estudiante->nombre = nombre;
    estudiante->edad = edad;
    estudiante->dni = dni;
    estudiante->fechaDeNacimiento = nacimiento;
    estudiante->siguiente = NULL;
    return estudiante;
}

int ComprobarDni(int *dni) {
    //lenInt devuelve 1 si el numero es negativo
    if(lenInt(*dni) == 8){
        return 1;
    }
    printf("el dni tiene un valor invalido\n ingrese el dni: ");
    scanf("%i", dni);
    return 0;
}
//no se usa un puntero devido a que el valor del entero se va cambiando para encontra el len
int lenInt(int integer){
    int count = 0;
    while(integer>10){
        integer /= 10;
        count++;
    }
    count ++;
    return count;
}


char* obtenerNacimiento( int *anio, int *mes, int *dia){
    char* nacimiento = (char*)calloc(10,sizeof(char));
    char year[5];
    char day[2];
    char month[2];
    sprintf(day, "%i", *dia);
    strcat(nacimiento, day);
    strcat(nacimiento, "-");
    sprintf(month, "%i", *mes);
    strcat(nacimiento, month);
    strcat(nacimiento, "-");
    sprintf(year, "%i", *anio);
    strcat(nacimiento,year);
    return nacimiento;
}

/**
 * Agrega un nuevo elemento de tipo 'Nodo' a la lista ordenado de forma
 * creciente segun su valor introducido.
 * @param lista
 * @param edad
 */
void agregar(Estudiante **lista, char* nombre,  int anio, int mes, int dia, int dni){
    //juntar comprobaciones de nacimiento y dni cuando funcione
    while(comprobarNacimiento(&anio, &mes, &dia)==0);
    while(ComprobarDni(&dni) == 0);
    char *nacimiento = obtenerNacimiento(&anio, &mes, &dia);
    time_t fecha = time(NULL);
    int edad = (localtime(&fecha)->tm_year)+1900-anio;
    Estudiante *nuevoEstudiante = crearEstudiante(nombre, edad, dni, nacimiento);
    Estudiante *cursor = *lista;

    if ((cursor == NULL) || (edad < cursor->edad)){
        nuevoEstudiante->siguiente = *lista;
        *lista = nuevoEstudiante;
    } else {
        while ((cursor->siguiente != NULL) && (edad > cursor->siguiente->edad)){
            cursor = cursor->siguiente;
        }
        if (cursor->siguiente != NULL){
            nuevoEstudiante->siguiente = cursor->siguiente;
        }
        cursor->siguiente = nuevoEstudiante;
    }
    tamanio++;
}

int comprobarNacimiento(int *anio, int *mes, int *dia) {
    if(*anio<1950 || *anio>2004){
        printf("El a%co esta mal escrito", 164 );
        scanf("%i", anio);
        return 0;
    }
    if(*mes<=0 || *mes>12){
        printf("El mes esta mal escrito");
        scanf("%i", mes);
        return 0;
    }
    if(comprobarDia(mes,dia,anio) == 0){
        printf("El dia esta mal escrito");
        scanf("%i", dia);
        return 0;
    }
    return 1;
}

int comprobarDia(int *mes, int *dia, int *anio) {
    if(*mes == 2 && *dia<=28){
        return 1;
    }else if(*mes == 2 && *dia == 29 && bisiento(anio) == 1){
        return 1;
    }
    if((*mes == 4 || *mes == 6 || *mes == 9 || *mes == 11) && *dia <= 30){
        return 1;
    }
    if((*mes == 1 || *mes == 3 || *mes == 5 || *mes == 7 || *mes == 8 || *mes == 10 || *mes == 12) && *dia <= 31){
        return 1;
    }
    return 0;
}
int bisiento(int *anio){
    if ( *anio % 4 == 0 && *anio % 100 != 0 || *anio % 400 == 0 )  {
        return 1;
    }else{
        return 0;
    }
}

/**
 * Se obtiene el elemento en la posicion pasada como parametro.
 * @param lista
 * @param posicion: debe estar entre los valores 1 y tamanio de la lista
 * @return: nodo en la posicion (parametro)
 */
Estudiante obtenerElemento(Estudiante **lista, int posicion){
    Estudiante *estudiante = *lista;
    if(posicion>0 && posicion<=tamanio){
        for (int i = 0; i < (posicion - 1); ++i) {
            estudiante = estudiante->siguiente;
        }
        return *estudiante;
    }
}

/**
 * Se obtiene el estudiante con la edad pasada como parametro.
 * @param lista
 * @param edad: edad del estudiante a buscar.
 * @return: nodo en la posicion (parametro)
 */
Estudiante *obtenerEstudiantePorEdad(Estudiante **lista, int edad){
    Estudiante *estudiante = *lista;
    while(estudiante->edad != edad){
        if(estudiante->siguiente == NULL){
            printf("No se encontro al estudiante\n");
            estudiante = NULL;
            break;
        }
        estudiante = estudiante->siguiente;
    }
    return estudiante;
}

/**
 * Se obtiene el elemento con el edad pasado como parametro.
 * @param lista
 * @param edad: edad del estudiante a buscar.
 * @return: nodo en la posicion (parametro)
 */
void *obtenerEstudiantePorRangoDeEdad(Estudiante **lista, int edadMinima, int edadMaxima){
    Estudiante *estudiante = *lista;
    while(estudiante->edad < edadMinima){
        if(estudiante->siguiente == NULL){
            printf("No se encontro un estud    iante en este rango\n");
            estudiante = NULL;
            break;
        }
        estudiante = estudiante->siguiente;
    }
     while(estudiante->edad <= edadMaxima){
         imprimirEstudiante(estudiante);
         printf("\n\n");
         if(estudiante->siguiente == NULL){
             break;
         }
         estudiante = estudiante->siguiente;
     }
}

/**
 * Elimina el elemento en la posicion pasada como parametro
 * @param lista
 * @param posicion: entre los valores 1 y 'tamanio' de lista
 */
void borrarXElemento(Estudiante *lista, int posicion) {
    Estudiante *estudiante = lista;
    Estudiante *aEliminar;
    if(posicion>0 && posicion<=tamanio){
        for (int i = 0; i < (posicion - 1); ++i) {
            estudiante = estudiante->siguiente;
        }
        aEliminar = estudiante->siguiente;
        estudiante->siguiente = estudiante->siguiente->siguiente;
        free(aEliminar);
    }
    tamanio--;
}

void imprimirEstudiante(Estudiante *estudiante){
    printf("\nNombre: %s\n", estudiante->nombre);
    printf("edad: %i\n", estudiante->edad);
    printf("dni: %i\n", estudiante->dni);
    printf("fecha de nacimiento: %s\n", estudiante->fechaDeNacimiento);
}

void imprimir(Estudiante *lista) {
    while (lista != NULL) {
        imprimirEstudiante(lista);
        lista = lista->siguiente;
    }
    printf("\n");
}


int main(){
    Estudiante *lista = NULL;
/*
    int opcion = 0;
    int valor = 0;

    while (opcion != 7){
        printf("elije una opcion para usar la lista: \n");
        printf("1. Cargar elemento\n");
        printf("2. Borrar primer elemento\n");
        printf("3. Borrar elemento en la posicion X\n");
        printf("4. Ver tamanio\n");
        printf("5. Imprimir Lista\n");
        printf("6. Obtener un elemento de la lista\n");
        printf("7. salir\n");
        scanf("%i", &opcion);
        fflush(stdin);
        switch (opcion) {
            case 1:
                printf("Cual es el valor del elemento: ");
                scanf("%i", &valor);
                agregar(&lista, valor);
                fflush(stdin);
                if(&lista->valor != 0 || &lista->valor != valor){
                    printf("\nEl elemento ha sido cargado\n");
                }
                break;
            case 2:
                borrarPrimerElemento(&lista);
                printf("El primer elemento ha sido borrado\n");
                break;
            case 3:
                printf("Cual es la posicion del elemento a borrar: ");
                scanf("%i", &valor);
                borrarXElemento(&lista, valor);
                fflush(stdin);
                break;
            case 4:
                printf("El tamanio de la lista actualmente es %i\n", tamanio);
                break;
            case 5:
                imprimir(lista);
                break;
            case 6:
                printf("Cual es la posicion del elemento a obtener: ");
                scanf("%i", &valor);
                Nodo nodo = obtenerElemento(&lista, valor);
                printf("El valor de la lista en la posicion %i es %i."
                       "\n", valor, nodo.valor);
                fflush(stdin);
                break;
            case 7:
                break;
            default:
                printf("No hay ninguna operacion para el numero %i \n", opcion);
                break;
        }
    }*/
//agregar(Estudiante **lista, char* nombre,  int anio, int mes, int dia, int dni)
    printf("1era impresion, lista vacia: ");
    imprimir(lista);
    agregar(&lista, "Miguel", 2001, 12, 4, 43870524);
    agregar(&lista, "Antonio", 2002, 12, 4, 43870544);
    agregar(&lista, "Alberto", 1971, 12, 4, 43870544);
    agregar(&lista, "Laura", 2000, 8, 4, 43870544);
    agregar(&lista, "Ramiro", 1999, 12, 4, 43870544);
    agregar(&lista, "Antonela", 2000, 12, 4, 43870544);
    imprimirEstudiante(lista);
    Estudiante* juan = obtenerEstudiantePorEdad(&lista, 22);
    if(juan != NULL){
        printf("el nombre de %s tiene 22 a%cos.\n\n\n",juan->nombre, 164 );
    }
    obtenerEstudiantePorRangoDeEdad(&lista, 21, 50);
    printf("-------------------------------");
    imprimir(lista);
    /*agregar(&lista, 8);
    agregar(&lista, 2);
    agregar(&lista, 4);
    agregar(&lista, 3);
    agregar(&lista, 5);

    printf("2da impresion, lista con 6 elementos: ");
    imprimir(lista);
    printf("El tamanio de la lista es de %i \n", tamanio);
    agregar(&lista, 7);
    agregar(&lista, 6);

    printf("3era impresion, lista de 1 a 8: ");
    imprimir(lista);
    printf("El tamanio de la lista es de %i \n", tamanio);

    //borrarPrimerElemento(&lista);
    //printf("4ta impresion, borrando primer elemento: ");
    //imprimir(lista);

    printf("Obtener elemento: ");
    Estudiante estu = obtenerElemento(&lista,5);
    printf("el valor de la lista en la posicion 5 es %i.\n",estu.edad);
    printf("5ta impresion, con valor obtenido: ");
    imprimir(lista);
    printf("Obtener elemento fuera de rango: ");
    estu = obtenerElemento(&lista,7);
    printf("el valor de la lista en la posicion 5 es %i.\n",estu);

    agregar(&lista, 1);
    printf("6ta impresion agregando 1: ");
    imprimir(lista);

    printf("El tamanio de la lista es de %i \n", tamanio);
    Estudiante estu1 = obtenerElemento(&lista,2);
    printf("El valor de la lista en la posicion 2 es %i.\n",estu1.edad);
    borrarXElemento(&lista, 6);
    printf("7ma impresion borrando 6: ");
    imprimir(lista);

    agregar(&lista, 10);
    printf("8va impresion agregando 10: ");
    imprimir(lista);

    Estudiante estu2 = obtenerEstudiantePorEdad(&lista, 10);
    printf("el valor de la lista con valor 10 es %i \n", estu2.edad);*/

    return 0;
}