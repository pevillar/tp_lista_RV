#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "materia.c"


typedef struct MateriaEstudiante {
    struct MateriaEstudiante *siguienteMateriaEstudiante;
    Materia *materia;
    int aprobado;
    double nota;
    int intentos;
} MateriaEstudiante;

int tamanioMateriaEstudiante = 0;

void cargarNota(MateriaEstudiante *materiaEstudiante, double nota){
    if (nota >= 0 && nota <= 10) {
        if(materiaEstudiante->nota == -1 && materiaEstudiante->intentos == 0) {
            materiaEstudiante->nota = nota;
            materiaEstudiante->intentos++;
            materiaEstudiante->aprobado = (nota >= 4) ? 1.0 : 0;
            materiaEstudiante->materia->notas += nota;
            materiaEstudiante->materia->cantDeAprobados += (nota >= 4) ? 1 : 0;
            materiaEstudiante->materia->cantDeEstudiantesRendieron++;
        }else if(materiaEstudiante->nota >= nota && materiaEstudiante->nota < 4 && materiaEstudiante->intentos < 3){
            materiaEstudiante->intentos++;
        }else if(materiaEstudiante->nota < nota && materiaEstudiante->intentos < 3){
            materiaEstudiante->intentos++;
            materiaEstudiante->aprobado = (nota >= 4) ? 1.0 : 0;
            materiaEstudiante->materia->notas += nota - materiaEstudiante->nota;
            materiaEstudiante->materia->cantDeAprobados += (nota >= 4) ? 1.0 : 0;
            materiaEstudiante->nota = nota;
        }
    }else {
        printf("la nota no es valida\n");
    }
}

MateriaEstudiante *crearMateriaEstudiante(Materia *materia){
    MateriaEstudiante *nuevaMateria = (MateriaEstudiante*) malloc(sizeof (MateriaEstudiante));
    nuevaMateria -> nota = -1.0;
    nuevaMateria -> aprobado = -1;
    nuevaMateria -> intentos = 0;
    nuevaMateria -> siguienteMateriaEstudiante = NULL;
    nuevaMateria -> materia = materia;
    return nuevaMateria;
}

void agregarMateriaEstudiante(MateriaEstudiante **materiaEstudiante, Materia *materia ){
    MateriaEstudiante  *nuevaMateria = crearMateriaEstudiante(materia);
    nuevaMateria->materia->cantDeEstudiantes++;
    nuevaMateria->siguienteMateriaEstudiante = *materiaEstudiante;
    *materiaEstudiante = nuevaMateria;
    tamanioMateriaEstudiante++;
}

void agregarMateriaEstudianteAprobada(MateriaEstudiante **materiaEstudiante, Materia *materia, double nota, int intentos){
    MateriaEstudiante  *nuevaMateria = crearMateriaEstudiante(materia);
    nuevaMateria->nota = nota;
    nuevaMateria->aprobado = 1;
    nuevaMateria->intentos = intentos;
    nuevaMateria->siguienteMateriaEstudiante = *materiaEstudiante;
    *materiaEstudiante = nuevaMateria;
}

MateriaEstudiante *obtenerMateriaEstudiantePorNombre(MateriaEstudiante **listaMateria, char *nombre){
    MateriaEstudiante *materia = *listaMateria;
    while((materia->siguienteMateriaEstudiante != NULL)
          && strcmp(materia->materia->nombre, nombre) != 0){
        materia = materia->siguienteMateriaEstudiante;
    }
    if (strcmp(materia->materia->nombre, nombre) != 0) {
        printf("La materia: %s, no existe en el sistema.\n", nombre);
        return NULL;
    } else {
        return materia;
    }
}

void borrarPrimeraMateriaEstudiante(MateriaEstudiante *listaNombre) {
    MateriaEstudiante *aEliminar = listaNombre->siguienteMateriaEstudiante;
    if (listaNombre->siguienteMateriaEstudiante != NULL) {
        *listaNombre = *listaNombre->siguienteMateriaEstudiante;
    } else {
        listaNombre = NULL;
    }
    free(aEliminar);
    tamanioMateriaEstudiante--;
}


void borrarMateriaEstudiantePorNombre(MateriaEstudiante *listaNombre, char *nombre) {
    MateriaEstudiante *materiaEstudiante = listaNombre;
    if (strcmp(materiaEstudiante->materia->nombre, nombre) == 0){
        borrarPrimeraMateriaEstudiante(listaNombre);
    } else {
        MateriaEstudiante *aEliminar;
        while ((materiaEstudiante->siguienteMateriaEstudiante != NULL)
               && (strcmp(materiaEstudiante->siguienteMateriaEstudiante->materia->nombre, nombre)) != 0) {
            materiaEstudiante = materiaEstudiante->siguienteMateriaEstudiante;
        }
        if ((materiaEstudiante->siguienteMateriaEstudiante == NULL) ||
            strcmp(materiaEstudiante->siguienteMateriaEstudiante->materia->nombre, nombre) != 0) {
            printf("\n");
        } else {
            aEliminar = materiaEstudiante->siguienteMateriaEstudiante;
            materiaEstudiante->siguienteMateriaEstudiante = materiaEstudiante->siguienteMateriaEstudiante->siguienteMateriaEstudiante;
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
            printf("Nota: %.2f\n", listaMateria->nota);
            if(listaMateria->aprobado == 0){
                printf("El alumno ha desaprobado la materia\n");
                int intentosRestantes = 3 - listaMateria->intentos;
                if(intentosRestantes == 1){
                    printf("Le queda un intento!!\n");
                }else{
                    printf("Le quedan %i intentos\n", intentosRestantes);
                }
            }
        }
        listaMateria = listaMateria->siguienteMateriaEstudiante;
    }
    printf("\n");
}

void imprimirMateriasAprobadasEstudiante(MateriaEstudiante *listaMateria) {
    while (listaMateria != NULL) {
        printf("%s\n", listaMateria->materia->nombre);
        printf("Nota: %.2f\n", listaMateria->nota);
        listaMateria = listaMateria->siguienteMateriaEstudiante;
    }
    printf("\n");
}