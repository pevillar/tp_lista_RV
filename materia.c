#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Materia {
    struct Materia *siguienteMateria;
    char *nombre;
    int cantDeAprobados;
    int cantDeEstudiantes;
    int cantDeEstudiantesRendieron;
    int notas;
    int numero;
} Materia;

int tamanioMateria = 0;

/**
 * Inicializa un Nodo con su valor pasado como parametro, y 'siguiente'
 * referenciando a 'NULL'.
 * @param valor
 * @return
 */
Materia *crearMateria(char *nombre, int numero){
    Materia *materia = (Materia*) malloc(sizeof (Materia));
    materia -> notas = 0;
    materia -> numero = numero;
    materia -> cantDeAprobados = 0;
    materia -> cantDeEstudiantes = 0;
    materia -> cantDeEstudiantesRendieron = 0;
    materia -> siguienteMateria = NULL;
    materia -> nombre = nombre;
    return materia;
}

/**
 * Agrega un nuevo elemento de tipo 'Nodo' a la lista ordenado de forma
 * creciente segun su valor introducido.
 * @param materia
 * @param nombre
 */
void agregarMateria(Materia **materia, char * nombre, int numero){
    Materia  *nuevoMateria = crearMateria(nombre, numero);
    Materia  *cursor = *materia;
    if ((cursor == NULL) || (numero < cursor->numero)){
        nuevoMateria->siguienteMateria = *materia;
        *materia = nuevoMateria;
    } else {
        while ((cursor->siguienteMateria != NULL) && (numero > cursor->siguienteMateria->numero)){
            cursor = cursor->siguienteMateria;
        }
        if (cursor->siguienteMateria != NULL){
            nuevoMateria->siguienteMateria = cursor->siguienteMateria;
        }
        cursor->siguienteMateria = nuevoMateria;
    }
    tamanioMateria++;
}

/**
 * Se obtiene el elemento en la posicion pasada como parametro.
 * @param listaMateria
 * @param posicion: debe estar entre los valores 1 y tamanio de la listaMateria
 * @return: nodo en la posicion (parametro)
 */
Materia obtenerMateria(Materia **listaMateria, int posicion){
    Materia  *materia = *listaMateria;
    if(posicion>0 && posicion<=tamanioMateria){
        for (int i = 0; i < (posicion - 1); ++i) {
            materia = materia->siguienteMateria;
        }
        return *materia;
    }
}

/**
 * Se obtiene el elemento con el valor pasado como parametro.
 * @param listaMateria
 * @param valor: valor del nodo a buscar.
 * @return: nodo en la posicion (parametro)
 */
Materia obtenerElementoPorValor(Materia **listaMateria, int valor){
    Materia *materia = *listaMateria;
    while(materia->numero != valor){
        materia = materia->siguienteMateria;
    }
    return *materia;
}

/**
 * Se obtiene la primer materia en la listaMateria con el materia pasado como parametro.
 * @param listaMateria
 * @param valor: valor del nodo a buscar.
 * @return: nodo en la posicion (parametro)
 */
Materia *obtenerMateriaPorNombre(Materia **listaMateria, char *nombre){
    Materia *materia = *listaMateria;
    while((materia->siguienteMateria != NULL)
          && strcmp(materia->nombre, nombre) != 0){
        materia = materia->siguienteMateria;
    }
    if (strcmp(materia->nombre, nombre) != 0) {
        printf("La materia: %s, no existe en la listaMateria.\n", nombre);
        return NULL;
    } else {
        return materia;
    }
}

void borrarPrimeraMateria(Materia *listaNombre) {
    if (listaNombre->siguienteMateria != NULL) {
        *listaNombre = *listaNombre->siguienteMateria;
        tamanioMateria--;
    } else {
        listaNombre = NULL;
        tamanioMateria--;
    }
}

/**
 * Elimina el elemento en la posicion pasada como parametro
 * @param listaMateria
 * @param posicion: entre los valores 1 y 'tamanio' de listaMateria
 */
void borrarXMateria(Materia *listaMateria, int posicion) {
    Materia *materia = listaMateria;
    Materia *aEliminar;
    if(posicion>0 && posicion<=tamanioMateria){
        for (int i = 0; i < (posicion - 1); ++i) {
            materia = materia->siguienteMateria;
        }
        aEliminar = materia->siguienteMateria;
        materia->siguienteMateria = materia->siguienteMateria->siguienteMateria;
        free(aEliminar);
    }
    tamanioMateria--;
}


void borrarMateriaPorNombre(Materia *listaNombre, char *nombre) {
    if (strcmp(listaNombre->nombre, nombre) == 0){
        borrarPrimeraMateria(listaNombre);
    } else {
        Materia *estudiante = listaNombre;
        Materia *aEliminar;
        while ((estudiante->siguienteMateria != NULL)
               && (strcmp(estudiante->siguienteMateria->nombre, nombre) != 0)) {
            estudiante = estudiante->siguienteMateria;
        }
        if (strcmp(estudiante->nombre, nombre) != 0) {
            printf("El materia: %s, no existe en la listaNombre.\n", nombre);
        } else {
            aEliminar = estudiante->siguienteMateria;
            estudiante->siguienteMateria = estudiante->siguienteMateria->siguienteMateria;
            free(aEliminar);
            tamanioMateria--;
        }
    }
}

void obtenerPromedioDeAprobados(Materia *materia){
    float promedioDeAprobados = (materia->cantDeAprobados*100)/materia->cantDeEstudiantesRendieron;
    printf("El promedio de aprobacion es del %.2f\n", promedioDeAprobados);
}

void obtenerNotaPromedio(Materia *materia){
    float notaPromedio = (materia->notas*100)/materia->cantDeEstudiantesRendieron;
    printf("La nota promedio en es %.2f\n", notaPromedio);
}

void imprimirMaterias(Materia *listaMateria) {
    while (listaMateria != NULL) {
        printf("%d - %s\n", listaMateria->numero, listaMateria->nombre);
        listaMateria = listaMateria->siguienteMateria;
    }
    printf("\n");
}