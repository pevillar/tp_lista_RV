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

/**
 * Se carga la nota de la materia rendida por el estudiante.
 * Para ello se verifica si el estudiante aun tiene
 * oportunidades para rendirla.
 * @param materiaEstudiante
 * @param nota
 */
void cargarNota(MateriaEstudiante *materiaEstudiante, double nota){
    if (nota >= 0 && nota <= 10) {
        if(materiaEstudiante->nota == -1 && materiaEstudiante->intentos == 0) {
            materiaEstudiante->nota = nota;
            materiaEstudiante->intentos++;
            materiaEstudiante->aprobado = (nota >= 4) ? 1 : 0;
            materiaEstudiante->materia->notas += nota;
            materiaEstudiante->materia->cantDeAprobados += (nota >= 4) ? 1 : 0;
            materiaEstudiante->materia->cantDeEstudiantesRendieron++;
        }else if(materiaEstudiante->nota >= nota && materiaEstudiante->nota < 4 && materiaEstudiante->intentos < 3){
            materiaEstudiante->intentos++;
        }else if(materiaEstudiante->nota < nota && materiaEstudiante->intentos < 3){
            materiaEstudiante->intentos++;
            materiaEstudiante->aprobado = (nota >= 4) ? 1 : 0;
            materiaEstudiante->materia->notas += nota - materiaEstudiante->nota;
            materiaEstudiante->materia->cantDeAprobados += (nota >= 4) ? 1 : 0;
            materiaEstudiante->nota = nota;
        }
    }else {
        printf("la nota no es valida\n");
    }
}

/**
 * Se inicializa una materia con los valores por defecto.
 * Esta estara vinculada con cada estudiante cuante se anote.
 * @param materia
 * @return
 */
MateriaEstudiante *crearMateriaEstudiante(Materia *materia){
    MateriaEstudiante *nuevaMateria = (MateriaEstudiante*) malloc(sizeof (MateriaEstudiante));
    nuevaMateria -> nota = -1.0;
    nuevaMateria -> aprobado = -1;
    nuevaMateria -> intentos = 0;
    nuevaMateria -> siguienteMateriaEstudiante = NULL;
    nuevaMateria -> materia = materia;
    return nuevaMateria;
}

/**
 * Se crea y agrega la materia a la lista de materias.
 * @param materiaEstudiante
 * @param materia
 */
void agregarMateriaEstudiante(MateriaEstudiante **materiaEstudiante, Materia *materia ){
    MateriaEstudiante  *nuevaMateria = crearMateriaEstudiante(materia);
    nuevaMateria->materia->cantDeEstudiantes++;
    nuevaMateria->siguienteMateriaEstudiante = *materiaEstudiante;
    *materiaEstudiante = nuevaMateria;
}

/**
 * Se agrega la materia que ya esta aprovada por el estudiante a la lista.
 * @param materiaEstudiante
 * @param materia
 * @param nota
 * @param intentos
 */
void agregarMateriaEstudianteAprobada(MateriaEstudiante **materiaEstudiante, Materia *materia, double nota, int intentos){
    MateriaEstudiante  *nuevaMateria = crearMateriaEstudiante(materia);
    nuevaMateria->nota = nota;
    nuevaMateria->aprobado = 1;
    nuevaMateria->intentos = intentos;
    nuevaMateria->siguienteMateriaEstudiante = *materiaEstudiante;
    *materiaEstudiante = nuevaMateria;
}

/**
 * Devuelve la materia especificada como parametro.
 * @param listaMateria
 * @param nombre
 * @return
 */
MateriaEstudiante *obtenerMateriaEstudiantePorNombre(MateriaEstudiante **listaMateria, char *nombre){
    MateriaEstudiante *materia = *listaMateria;
    while((materia->siguienteMateriaEstudiante != NULL)
          && strcmp(materia->materia->nombre, nombre) != 0){
        materia = materia->siguienteMateriaEstudiante;
    }
    if (strcmp(materia->materia->nombre, nombre) != 0) {
        return NULL;
    } else {
        return materia;
    }
}

/**
 * Elimina la primera materia en la listaNombre.
 * @param listaNombre
 */
void borrarPrimeraMateriaEstudiante(MateriaEstudiante *listaNombre) {
    if (listaNombre->siguienteMateriaEstudiante != NULL) {
        *listaNombre = *listaNombre->siguienteMateriaEstudiante;
    } else {
        listaNombre = NULL;
    }
}

/**
 * Elimina la materia especificada por 'nombre' de la listaNombre.
 * @param listaNombre
 * @param nombre
 */
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
        }
    }
}

/**
 * Imprime por pantalla todas la materias en curso de un estudiante
 * y las desaprovadas que aun puede rendir.
 * @param listaMateria
 */
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

/**
 * Imprime por pantalla las materias aprobadas por el estudiante.
 * @param listaMateria
 */
void imprimirMateriasAprobadasEstudiante(MateriaEstudiante *listaMateria) {
    while (listaMateria != NULL) {
        printf("%s\n", listaMateria->materia->nombre);
        printf("Nota: %.2f\n", listaMateria->nota);
        listaMateria = listaMateria->siguienteMateriaEstudiante;
    }
    printf("\n");
}