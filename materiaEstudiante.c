#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "materia.c"


typedef struct MateriaEstudiante {
    struct MateriaEstudiante *siguienteMateriaEstudiante;
    Materia *materia;
    int aprobado;
    int nota;
} MateriaEstudiante;

int tamanioMateriaEstudiante = 0;

/**
 * Inicializa un Nodo con su valor pasado como parametro, y 'siguiente'
 * referenciando a 'NULL'.
 * @param valor
 * @return
 */
MateriaEstudiante *crearMateriaEstudiante(Materia *materia){
    MateriaEstudiante *nuevaMateria = (MateriaEstudiante*) malloc(sizeof (MateriaEstudiante));
    nuevaMateria -> nota = -1;
    nuevaMateria -> aprobado = -1;
    nuevaMateria -> siguienteMateriaEstudiante = NULL;
    nuevaMateria -> materia = materia;
    return nuevaMateria;
}

/**
 * Agrega un nuevo elemento de tipo 'Nodo' a la lista ordenado de forma
 * creciente segun su valor introducido.
 * @param materiaEstudiante
 * @param nombre
 */
void agregarMateriaEstudiante(MateriaEstudiante **materiaEstudiante, Materia *materia ){
    MateriaEstudiante  *nuevoMateria = crearMateriaEstudiante(materia);
    nuevoMateria->siguienteMateriaEstudiante = *materiaEstudiante;
    *materiaEstudiante = nuevoMateria;
    tamanioMateriaEstudiante++;
}

/**
 * Se obtiene la primer materia en la listaMateria con el materia pasado como parametro.
 * @param listaMateria
 * @param valor: valor del nodo a buscar.
 * @return: nodo en la posicion (parametro)
 */
MateriaEstudiante *obtenerMateriaEstudiantePorNombre(MateriaEstudiante **listaMateria, char *nombre){
    MateriaEstudiante *materia = *listaMateria;
    while((materia->siguienteMateriaEstudiante != NULL)
          && strcmp(materia->materia->nombre, nombre) != 0){
        materia = materia->siguienteMateriaEstudiante;
    }
    if (strcmp(materia->materia->nombre, nombre) != 0) {
        printf("La materia: %s, no existe en la listaMateria.\n", nombre);
        return NULL;
    } else {
        return materia;
    }
}

void borrarPrimeraMateriaEstudiante(MateriaEstudiante *listaNombre) {
    if (listaNombre->siguienteMateriaEstudiante != NULL) {
        *listaNombre = *listaNombre->siguienteMateriaEstudiante;
        tamanioMateriaEstudiante--;
    } else {
        listaNombre = NULL;
        tamanioMateriaEstudiante--;
    }
}


void borrarMateriaEstudiantePorNombre(MateriaEstudiante *listaNombre, char *nombre) {
    if (strcmp(listaNombre->materia->nombre, nombre) == 0){
        borrarPrimeraMateria(listaNombre);
    } else {
        MateriaEstudiante *estudiante = listaNombre;
        MateriaEstudiante *aEliminar;
        while ((estudiante->siguienteMateriaEstudiante != NULL)
               && (strcmp(estudiante->siguienteMateriaEstudiante->materia->nombre, nombre) != 0)) {
            estudiante = estudiante->siguienteMateriaEstudiante;
        }
        if (strcmp(estudiante->materia->nombre, nombre) != 0) {
            printf("El materia: %s, no existe en la listaNombre.\n", nombre);
        } else {
            aEliminar = estudiante->siguienteMateriaEstudiante;
            estudiante->siguienteMateriaEstudiante = estudiante->siguienteMateriaEstudiante->siguienteMateriaEstudiante;
            free(aEliminar);
            tamanioMateriaEstudiante--;
        }
    }
}

void imprimirMateriasEstudiante(MateriaEstudiante *listaMateria) {
    while (listaMateria != NULL) {
        printf("%s\n", listaMateria->materia->nombre);
        if(listaMateria->nota == -1){
            printf("El alumno esta cursando la materia\n");
        }else{
            printf("Nota: %i\n", listaMateria->nota);
            if(listaMateria->aprobado == 1){
                printf("El alumno ha aprobado la materia");
            }else{
                printf("El alumno ha desaprobado la materia");
            }
        }
        listaMateria = listaMateria->siguienteMateriaEstudiante;
    }
    printf("\n");
}

int main(){


    Materia *listaMaterias = NULL;
    agregarMateria(&listaMaterias, "Sistema De Representaciones", 0);

    MateriaEstudiante *listaMateriasEstudiante = NULL;
    agregarMateriaEstudiante(&listaMateriasEstudiante, listaMaterias);

    imprimirMateriasEstudiante(listaMateriasEstudiante);

    return 0;
}