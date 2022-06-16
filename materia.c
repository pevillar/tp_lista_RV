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
 *
 * @param materia
 * @param nombre
 * @param numero
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
 *
 * @param listaMateria
 * @param posicion
 * @return
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
 *
 * @param listaMateria
 * @param valor
 * @return
 */
Materia obtenerElementoPorValor(Materia **listaMateria, int valor){
    Materia *materia = *listaMateria;
    while(materia->numero != valor){
        materia = materia->siguienteMateria;
    }
    return *materia;
}

/**
 *
 * @param listaMateria
 * @param nombre
 * @return
 */
Materia *obtenerMateriaPorNombre(Materia **listaMateria, char *nombre){
    Materia *materia = *listaMateria;
    while((materia->siguienteMateria != NULL)
          && strcmp(materia->nombre, nombre) != 0){
        materia = materia->siguienteMateria;
    }
    if (strcmp(materia->nombre, nombre) != 0) {
        printf("La materia: %s, no existe en el sistema.\n", nombre);
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
            printf("La materia: %s, no existe en el sistema.\n", nombre);
        } else {
            aEliminar = estudiante->siguienteMateria;
            estudiante->siguienteMateria = estudiante->siguienteMateria->siguienteMateria;
            free(aEliminar);
            tamanioMateria--;
        }
    }
}

void obtenerPromedioDeAprobados(Materia *materia){
    float promedioDeAprobados = (materia->cantDeAprobados*100)*1.0/materia->cantDeEstudiantesRendieron;
    printf("El promedio de aprobacion es del %.2f\n", promedioDeAprobados);
}

void obtenerNotaPromedio(Materia *materia){
    float notaPromedio = (materia->notas*100)*1.0/materia->cantDeEstudiantesRendieron;
    printf("La nota promedio en es %.2f\n", notaPromedio);
}

void imprimirMaterias(Materia *listaMateria) {
    while (listaMateria != NULL) {
        printf("%d - %s\n", listaMateria->numero, listaMateria->nombre);
        listaMateria = listaMateria->siguienteMateria;
    }
}