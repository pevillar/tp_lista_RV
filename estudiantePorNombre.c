#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estudiante.c"


typedef struct EstudiantePorNombre {
    struct EstudiantePorNombre *siguiente;
    Estudiante *estudianteEdad;
    char *apellido;
    char *nombre;

} EstudiantePorNombre;

int tamanioDeNombres = 0;

/**
 * Inicializa un materia de estudiante con sus datos pasados como parametro,
 * y 'siguiente' referenciando a 'NULL'.
 * @param
 * @return
 */
EstudiantePorNombre *crearEstudianteNombre(Estudiante *estudianteEdad, char *nombre, char *apellido){
    EstudiantePorNombre *estudiante = (EstudiantePorNombre*) malloc(sizeof(EstudiantePorNombre));
    estudiante->estudianteEdad = estudianteEdad;
    estudiante->nombre = nombre;
    estudiante->apellido = apellido;
    estudiante->siguiente = NULL;
    return estudiante;
}

/**
 * Compara alfabeticamente los nombres completos de dos estudiantes.
 * @param apellido1
 * @param nombre1
 * @param apellido2
 * @param nombre2
 * @return un valor menor a 0 si el primer materia es menor alfabeticamente,
 * mayor a 0 si el primer materia es mayor, o 0 si ambos nombres son iguales.
 */
int compararNombreCompleto(EstudiantePorNombre *estudiante1, EstudiantePorNombre *estudiante2){
    if (strcmp(estudiante1->apellido, estudiante2->apellido) == 0){
        return strcmp(estudiante1->nombre, estudiante2->nombre);
    } else {
        return strcmp(estudiante1->apellido, estudiante2->apellido);
    }
}

/**
 * Crea y agrega un nuevo elemento de tipo 'EstudiantePorNombre' a la listaNombre
 * ordenado de forma creciente segun sus datos introducidos.
 * @param listaNombre
 * @param apellido
 * @param nombre
 * @param dni
 */
void agregarPorNombre(EstudiantePorNombre **listaNombre, Estudiante *estudianteEdad, char *nombre, char *apellido){
    EstudiantePorNombre *nuevoEstudiante = crearEstudianteNombre(estudianteEdad, nombre, apellido);
    EstudiantePorNombre *cursor = *listaNombre;
    if ((cursor == NULL) ||
        (compararNombreCompleto(nuevoEstudiante, cursor) < 0)){
        nuevoEstudiante->siguiente = *listaNombre;
        *listaNombre = nuevoEstudiante;
    } else {
        while ((cursor->siguiente != NULL) &&
               (compararNombreCompleto(nuevoEstudiante, cursor->siguiente) > 0)){
            cursor = cursor->siguiente;
        }
        if (cursor->siguiente != NULL){
            nuevoEstudiante->siguiente = cursor->siguiente;
        }
        cursor->siguiente = nuevoEstudiante;
    }
    tamanioDeNombres++;
}

/**
 * Devuelve el estudiante con el nombre correspondiente, si este existe en la lista.
 * @param listaNombre
 * @param nombre
 * @param apellido
 * @return
 */
EstudiantePorNombre *obtenerEstudianteNombreCompleto(EstudiantePorNombre **listaNombre, char *nombre, char *apellido) {
    EstudiantePorNombre *estudiante = *listaNombre;
    EstudiantePorNombre *estudianteAAgregar
            = crearEstudianteNombre(estudiante->estudianteEdad, nombre, apellido);
    while((estudiante->siguiente != NULL)
          && compararNombreCompleto(estudiante, estudianteAAgregar) != 0){
        estudiante = estudiante->siguiente;
    }
    if (compararNombreCompleto(estudiante, estudianteAAgregar) != 0) {
        free(estudianteAAgregar);
        return NULL;
    } else {
        free(estudianteAAgregar);
        return estudiante;
    }
}

/**
 * Elilmina el primer estudiante de la lista.
 * @param listaNombre
 */
void borrarPrimerEstudiante(EstudiantePorNombre *listaNombre) {
    if (listaNombre->siguiente != NULL) {
        *listaNombre = *listaNombre->siguiente;
        tamanioDeNombres--;
    } else {
        listaNombre = NULL;
        tamanioDeNombres--;
    }
}

/**
 * Elimina El estudiante con el nombre pasado como parametro.
 * @param listaNombre
 * @param nombre
 * @param apellido
 */
void borrarEstudiantePorNombre(EstudiantePorNombre *listaNombre, char *nombre, char *apellido) {
    EstudiantePorNombre *estudiante = listaNombre;
    EstudiantePorNombre *estudiante2
            = crearEstudianteNombre(estudiante->estudianteEdad, nombre, apellido);
    if (compararNombreCompleto(estudiante, estudiante2) == 0){
        borrarPrimerEstudiante(listaNombre);
    } else {
        EstudiantePorNombre *aEliminar;
        while ((estudiante->siguiente != NULL)
               && (compararNombreCompleto(estudiante->siguiente, estudiante2)) != 0) {
            estudiante = estudiante->siguiente;
        }
        if ((estudiante->siguiente == NULL) ||
            compararNombreCompleto(estudiante->siguiente, estudiante2) != 0) {
            printf("\n");
        } else {
            aEliminar = estudiante->siguiente;
            estudiante->siguiente = estudiante->siguiente->siguiente;
            free(aEliminar);
            tamanioDeNombres--;
        }
    }
    free(estudiante2);
}

/**
 * Imrpime por consola el nombre completo de cada estudiante en la lista.
 * @param listaNombre
 */
void imprimirListaPorNombre(EstudiantePorNombre *listaNombre) {
    while (listaNombre != NULL) {
        printf("%s, %s.\n", listaNombre->apellido, listaNombre->nombre);
        listaNombre = listaNombre->siguiente;
    }
    printf("\n");
}