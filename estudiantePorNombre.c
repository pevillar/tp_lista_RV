#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct EstudiantePorNombre {
    struct EstudiantePorNombre *siguiente;
    int dni;
    char *apellido;
    char *nombre;

} EstudiantePorNombre;

int tamanio = 0;

/**
 * Inicializa un Nodo de estudiante con sus datos pasados como parametro,
 * y 'siguiente' referenciando a 'NULL'.
 * @param valor
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
        (compararNombreCompleto(nuevoEstudiante, cursor) > 0)){
            cursor = cursor->siguiente;
        }
        if (cursor->siguiente != NULL){
            nuevoEstudiante->siguiente = cursor->siguiente;
        }
        cursor->siguiente = nuevoEstudiante;
    }
    tamanio++;
}

/**
 * Se obtiene el estudiante en la posicion pasada como parametro.
 * @param lista
 * @param posicion: debe estar entre los valores 1 y tamanio de la lista
 * @return: nodo en la posicion
 */
EstudiantePorNombre *obtenerEstudiante(EstudiantePorNombre **lista, int posicion){
    EstudiantePorNombre *estudiante = *lista;
    if(posicion>0 && posicion<=tamanio){
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
    while(strcmp(estudiante->nombre, nombre) != 0){
        estudiante = estudiante->siguiente;
    }
    return estudiante;
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
    while(strcmp(estudiante->apellido, apellido) != 0){
        estudiante = estudiante->siguiente;
    }
    return estudiante;
}

/**
 * Elimina el estudiante en la posicion pasada como parametro
 * @param lista
 * @param posicion: entre los valores 1 y 'tamanio' de lista
 */
void borrarEstudiantePorPosicion(EstudiantePorNombre *lista, int posicion) {
    EstudiantePorNombre *estudiante = lista;
    EstudiantePorNombre *aEliminar;
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

void borrarEstudiantePorNombre(EstudiantePorNombre *lista, char *nombre) {
    EstudiantePorNombre *estudiante = lista;
    EstudiantePorNombre *aEliminar;
    while(strcmp(estudiante->nombre, nombre) != 0){
        estudiante = estudiante->siguiente;
    }
    aEliminar = estudiante->siguiente;
    estudiante->siguiente = estudiante->siguiente->siguiente;
    free(aEliminar);
    tamanio--;

}void borrarEstudiantePorApellido(EstudiantePorNombre *lista, char *apellido) {
    EstudiantePorNombre *estudiante = lista;
    EstudiantePorNombre *aEliminar;
    while(strcmp(estudiante->apellido, apellido) != 0){
        estudiante = estudiante->siguiente;
    }
    aEliminar = estudiante->siguiente;
    estudiante->siguiente = estudiante->siguiente->siguiente;
    free(aEliminar);
    tamanio--;
}

void imprimirListaPorNombre(EstudiantePorNombre *lista) {
    while (lista != NULL) {
        printf("%s, %s.\n", lista->apellido, lista->nombre);
        lista = lista->siguiente;
    }
    printf("\n");
}


int main(){
    EstudiantePorNombre *lista = NULL;

    char *nombre = "Fabricio";
    char *apellido = "Vitaller";
    char *nombre2 = "Gonzalo";
    char *apellido2 = "Vitaller";
    char *nombre3 = "Gabriela";
    char *apellido3 = "Hughens";
    char *nombre4 = "Laura";
    char *apellido4 = "Gascon";

//    EstudiantePorNombre *fab = crearNodo(nombre, apellido, 46258741);
//    EstudiantePorNombre *gon = crearNodo(nombre2, apellido2, 46358741);
//
//    printf("%s, %s y %s, %s.",
//           fab->apellido, fab->nombre, gon->apellido, gon->nombre);

    agregarPorNombre(&lista, apellido, nombre, 46258741);
    agregarPorNombre(&lista, apellido2, nombre2, 46259741);
    agregarPorNombre(&lista, apellido3, nombre3, 40654789);
    agregarPorNombre(&lista, apellido4, nombre4, 50789214);

    imprimirListaPorNombre(lista);

    EstudiantePorNombre *estudianteP = obtenerEstudiante(&lista, 3);
    printf("Obtener estudiante en la posicion 3: %s, %s.\n",
           estudianteP->apellido, estudianteP->nombre);

    estudianteP = obtenerEstudiantePorNombre(&lista, "Gabriela");
    printf("Obtener un estudiante por nombre 'Gabriela' : %s, %s.\n",
           estudianteP->apellido, estudianteP->nombre);

    estudianteP = obtenerEstudiantePorApellido(&lista, "Gascon");
    printf("Obtener un estudiante por apellido 'Gascon' : %s, %s.\n",
           estudianteP->apellido, estudianteP->nombre);

    printf("Imprimir todos los 4 estudiantes.\n");
    imprimirListaPorNombre(lista);
//aca empiezan los problemas
    borrarEstudiantePorPosicion(lista, 1);
    printf("Imprimir estudiantes menos posicicion 1:\n");
    imprimirListaPorNombre(lista);

    borrarEstudiantePorNombre(lista, "Gabriela");
    printf("Imprimir estudiantes menos Gabriela\n");
    imprimirListaPorNombre(lista);

    borrarEstudiantePorApellido(lista, "Vitaller");
    printf("Imprimir estudiantes menos Fabricio\n");
    imprimirListaPorNombre(lista);



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
                agregarPorNombre(&lista, valor);
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
                imprimirListaPorNombre(lista);
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

//    printf("1era impresion, lista vacia: ");
//    imprimirListaPorNombre(lista);
//    agregarPorNombre(&lista, 1);
//    agregarPorNombre(&lista, 8);
//    agregarPorNombre(&lista, 2);
//    agregarPorNombre(&lista, 4);
//    agregarPorNombre(&lista, 3);
//    agregarPorNombre(&lista, 5);
//
//    printf("2da impresion, lista con 6 elementos: ");
//    imprimirListaPorNombre(lista);
//    printf("El tamanio de la lista es de %i \n", tamanio);
//    agregarPorNombre(&lista, 7);
//    agregarPorNombre(&lista, 6);
//
//    printf("3era impresion, lista de 1 a 8: ");
//    imprimirListaPorNombre(lista);
//    printf("El tamanio de la lista es de %i \n", tamanio);
//
//    //borrarPrimerElemento(&lista);
//    //printf("4ta impresion, borrando primer elemento: ");
//    //imprimirListaPorNombre(lista);
//
//    printf("Obtener elemento: ");
//    EstudiantePorNombre estu = obtenerElemento(&lista, 5);
//    printf("el valor de la lista en la posicion 5 es %i.\n",estu.edad);
//    printf("5ta impresion, con valor obtenido: ");
//    imprimirListaPorNombre(lista);
//    printf("Obtener elemento fuera de rango: ");
//    estu = obtenerElemento(&lista,7);
//    printf("el valor de la lista en la posicion 5 es %i.\n",estu);
//
//    agregarPorNombre(&lista, 1);
//    printf("6ta impresion agregando 1: ");
//    imprimirListaPorNombre(lista);
//
//    printf("El tamanio de la lista es de %i \n", tamanio);
//    EstudiantePorNombre estu1 = obtenerElemento(&lista, 2);
//    printf("El valor de la lista en la posicion 2 es %i.\n",estu1.edad);
//    borrarXElemento(&lista, 6);
//    printf("7ma impresion borrando 6: ");
//    imprimirListaPorNombre(lista);
//
//    agregarPorNombre(&lista, 10);
//    printf("8va impresion agregando 10: ");
//    imprimirListaPorNombre(lista);
//
//    EstudiantePorNombre estu2 = obtenerElementoPorNombre(&lista, 10);
//    printf("el valor de la lista con valor 10 es %i \n", estu2.edad);

    return 0;
}