#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    char nombre[50];
    int valor;
    time_t fechaDeNacimiento;

} Estudiante;

int tamanio = 0;

/**
 * Inicializa un Nodo con su valor pasado como parametro, y 'siguiente'
 * referenciando a 'NULL'.
 * @param valor
 * @return
 */
Estudiante *crearNodo(int dni){
    Estudiante *estudiante = (Estudiante*) malloc(sizeof(Estudiante));
    estudiante->dni = dni;
    estudiante->siguiente = NULL;
    return estudiante;
}

/**
 * Agrega un nuevo elemento de tipo 'Nodo' a la lista ordenado de forma
 * creciente segun su valor introducido.
 * @param lista
 * @param valor
 */
void agregar(Estudiante **lista, int valor){
    Estudiante *nuevoEstudiante = crearNodo(valor);
    Estudiante *cursor = *lista;
    if ((cursor == NULL) || (valor < cursor->valor)){
        nuevoEstudiante->siguiente = *lista;
        *lista = nuevoEstudiante;
    } else {
        while ((cursor->siguiente != NULL) && (valor > cursor->siguiente->valor)){
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
 * Se obtiene el elemento con el valor pasado como parametro.
 * @param lista
 * @param valor: valor del nodo a buscar.
 * @return: nodo en la posicion (parametro)
 */
Estudiante obtenerElementoPorValor(Estudiante **lista, int valor){
    Estudiante *estudiante = *lista;
    while(estudiante->valor != valor){
        estudiante = estudiante->siguiente;
    }
    return *estudiante;
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

void imprimir(Estudiante *lista) {
    while (lista != NULL) {
        printf("%d - ", lista->valor);
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

    printf("1era impresion, lista vacia: ");
    imprimir(lista);
    agregar(&lista, 1);
    agregar(&lista, 8);
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
    printf("el valor de la lista en la posicion 5 es %i.\n",estu.valor);
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
    printf("El valor de la lista en la posicion 2 es %i.\n",estu1.valor);
    borrarXElemento(&lista, 6);
    printf("7ma impresion borrando 6: ");
    imprimir(lista);

    agregar(&lista, 10);
    printf("8va impresion agregando 10: ");
    imprimir(lista);

    Estudiante estu2 = obtenerElementoPorValor(&lista, 10);
    printf("el valor de la lista con valor 10 es %i \n", estu2.valor);

    return 0;
}