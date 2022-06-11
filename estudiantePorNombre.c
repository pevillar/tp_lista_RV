#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct EstudiantePorNombre {
    struct EstudiantePorNombre *siguiente;
    int dni;
    char *apellido;
    char *nombre;

} EstudiantePorNombre;

int tamanioDeNombres = 0;

/**
 * Comprueba que el numero de dni tenga 8 dígitos.
 * @param dni
 * @return
 */
int comprobarDni(int dni) {
    if ((dni >= 10000000) && (dni < 100000000)) {
        return 0;
    }
    return -1;
}

/**
 * Inicializa un Nodo de estudiante con sus datos pasados como parametro,
 * y 'siguiente' referenciando a 'NULL'.
 * @param
 * @return
 */
EstudiantePorNombre *crearNodo(char *nombre, char *apellido, int dni){
    EstudiantePorNombre *estudiante = (EstudiantePorNombre*) malloc(sizeof(EstudiantePorNombre));
    estudiante->nombre = nombre;
    estudiante->apellido = apellido;
    estudiante->dni = dni;
    estudiante->siguiente = NULL;
    return estudiante;
}

/**
 * Compara alfabeticamente los nombres completos de los estudiantes pasados
 * como parámetro, primero compara apellidos, y si son iguales compara los
 * nombres.
 * @param apellido1
 * @param nombre1
 * @param apellido2
 * @param nombre2
 * @return un valor menor a 0 si el primer nombre es menor alfabeticamente,
 * mayor a 0 si el primer nombre es mayor, o 0 si ambos nombres son iguales.
 */
int compararNombreCompleto(EstudiantePorNombre *estudiante1, EstudiantePorNombre *estudiante2){
    if (strcmp(estudiante1->apellido, estudiante2->apellido) == 0){
        return strcmp(estudiante1->nombre, estudiante2->nombre);
    } else {
        return strcmp(estudiante1->apellido, estudiante2->apellido);
    }
}

/**
 * Crea y agrega un nuevo elemento de tipo 'EstudiantePorNombre' a la lista
 * ordenado de forma creciente segun sus datos introducidos.
 * @param lista
 * @param apellido
 * @param nombre
 * @param dni
 */
void agregarPorNombre(EstudiantePorNombre **lista, char *apellido, char *nombre, int dni){
    EstudiantePorNombre *nuevoEstudiante = crearNodo(nombre, apellido, dni);
    EstudiantePorNombre *cursor = *lista;
    if ((cursor == NULL) ||
    (compararNombreCompleto(nuevoEstudiante, cursor) < 0)){
        nuevoEstudiante->siguiente = *lista;
        *lista = nuevoEstudiante;
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
 * Se obtiene el estudiante en la posicion pasada como parametro.
 * @param lista
 * @param posicion: debe estar entre los valores 1 y tamanioDeNombres de la lista
 * @return: nodo en la posicion
 */
EstudiantePorNombre *obtenerEstudiante(EstudiantePorNombre **lista, int posicion){
    EstudiantePorNombre *estudiante = *lista;
    if(posicion>0 && posicion <= tamanioDeNombres){
        for (int i = 0; i < (posicion - 1); ++i) {
            estudiante = estudiante->siguiente;
        }
        return estudiante;
    }
}

/**
 * Se obtiene el primer estudiante en la lista con el nombre pasado como parametro.
 * @param lista
 * @param valor: valor del nodo a buscar.
 * @return: nodo en la posicion (parametro)
 */
EstudiantePorNombre *obtenerEstudiantePorNombre(EstudiantePorNombre **lista, char *nombre){
    EstudiantePorNombre *estudiante = *lista;
    while((estudiante->siguiente != NULL)
    && strcmp(estudiante->nombre, nombre) != 0){
        estudiante = estudiante->siguiente;
    }
    if (strcmp(estudiante->nombre, nombre) != 0) {
        printf("El nombre: %s, no existe en la lista.\n", nombre);
        return NULL;
    } else {
        return estudiante;
    }
}

/**
 * Se obtiene el primer estudiante en la lista con el apellido pasado como
 * parametro.
 * @param lista
 * @param apellido
 * @return primer estudiante en la lista con el apellido pasado como
 * parametro.
 */
EstudiantePorNombre *obtenerEstudiantePorApellido(EstudiantePorNombre **lista, char *apellido){
    EstudiantePorNombre *estudiante = *lista;
    while((estudiante->siguiente != NULL)
          && strcmp(estudiante->apellido, apellido) != 0){
        estudiante = estudiante->siguiente;
    }
    if (strcmp(estudiante->apellido, apellido) != 0) {
        printf("El apellido: %s, no existe en la lista.\n", apellido);
        return NULL;
    } else {
        return estudiante;
    }
}

void borrarPrimerEstudiante(EstudiantePorNombre *lista) {
    if (lista->siguiente != NULL) {
        *lista = *lista->siguiente;
        tamanioDeNombres--;
    } else {
        lista = NULL;
        tamanioDeNombres--;
    }
}

/**
 * Elimina el estudiante en la posicion pasada como parametro
 * @param lista
 * @param posicion: entre los valores 1 y 'tamanioDeNombres' de lista
 */
void borrarEstudiantePorPosicion(EstudiantePorNombre *lista, int posicion) {
    EstudiantePorNombre *estudiante = lista;
    EstudiantePorNombre *aEliminar;
    if ((posicion - 1) == 0) {
        borrarPrimerEstudiante(lista);
    } else if(posicion>0 && posicion <= tamanioDeNombres){
        for (int i = 0; i < (posicion - 2); ++i) {
            estudiante = estudiante->siguiente;
        }
        aEliminar = estudiante->siguiente;
        estudiante->siguiente = estudiante->siguiente->siguiente;
        free(aEliminar);
    }
    tamanioDeNombres--;
}

void borrarEstudiantePorNombre(EstudiantePorNombre *lista, char *nombre) {
    if (strcmp(lista->nombre, nombre) == 0){
        borrarPrimerEstudiante(lista);
    } else {
        EstudiantePorNombre *estudiante = lista;
        EstudiantePorNombre *aEliminar;
        while ((estudiante->siguiente != NULL)
        && (strcmp(estudiante->siguiente->nombre, nombre) != 0)) {
            estudiante = estudiante->siguiente;
        }
        if (strcmp(estudiante->nombre, nombre) != 0) {
            printf("El nombre: %s, no existe en la lista.\n", nombre);
        } else {
            aEliminar = estudiante->siguiente;
            estudiante->siguiente = estudiante->siguiente->siguiente;
            free(aEliminar);
            tamanioDeNombres--;
        }
    }
}

void borrarEstudiantePorApellido(EstudiantePorNombre *lista, char *apellido) {
    if (strcmp(lista->apellido, apellido) == 0) {
        borrarPrimerEstudiante(lista);
    } else {
        EstudiantePorNombre *estudiante = lista;
        EstudiantePorNombre *aEliminar;
        while((estudiante->siguiente != NULL)
        && (strcmp(estudiante->siguiente->apellido, apellido) != 0)){
            estudiante = estudiante->siguiente;
        }
        if (strcmp(estudiante->apellido, apellido) != 0) {
            printf("El apellido: %s, no existe en la lista.\n", apellido);
        } else {
            aEliminar = estudiante->siguiente;
            estudiante->siguiente = estudiante->siguiente->siguiente;
            free(aEliminar);
            tamanioDeNombres--;
        }
    }
}

void imprimirListaPorNombre(EstudiantePorNombre *lista) {
    while (lista != NULL) {
        printf("%s, %s.\n", lista->apellido, lista->nombre);
        lista = lista->siguiente;
    }
    printf("\n");
}