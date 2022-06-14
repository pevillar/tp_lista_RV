#include <stdio.h>
#include <stdlib.h>


typedef struct nombreStruct {
    struct nombreStruct *siguiente;
    int valor;
} Nodo;

int tamanio = 0;

/**
 * Inicializa un Nodo con su valor pasado como parametro, y 'siguiente'
 * referenciando a 'NULL'.
 * @param valor
 * @return
 */
Nodo *crearNodo(int valor){
    Nodo *nodo = (Nodo*) malloc(sizeof (Nodo));
    nodo->valor = valor;
    nodo->siguiente = NULL;
    return nodo;
}

/**
 * Agrega un nuevo elemento de tipo 'Nodo' a la lista ordenado de forma
 * creciente segun su valor introducido.
 * @param lista
 * @param valor
 */
void agregar(Nodo **lista, int valor){
    Nodo *nuevoNodo = crearNodo(valor);
    Nodo *cursor = *lista;
    if ((cursor == NULL) || (valor < cursor->valor)){
        nuevoNodo->siguiente = *lista;
        *lista = nuevoNodo;
    } else {
        while ((cursor->siguiente != NULL) && (valor > cursor->siguiente->valor)){
            cursor = cursor->siguiente;
        }
        if (cursor->siguiente != NULL){
            nuevoNodo->siguiente = cursor->siguiente;
        }
        cursor->siguiente = nuevoNodo;
    }
    tamanio++;
}

/**
 * Se obtiene el elemento en la posicion pasada como parametro.
 * @param lista
 * @param posicion: debe estar entre los valores 1 y tamanio de la lista
 * @return: nodo en la posicion (parametro)
 */
Nodo obtenerElemento(Nodo **lista, int posicion){
    Nodo *nodo = *lista;
    if(posicion>0 && posicion<=tamanio){
        for (int i = 0; i < (posicion - 1); ++i) {
            nodo = nodo->siguiente;
        }
        return *nodo;
    }
}

/**
 * Se obtiene el elemento con el valor pasado como parametro.
 * @param lista
 * @param valor: valor del nodo a buscar.
 * @return: nodo en la posicion (parametro)
 */
Nodo obtenerElementoPorValor(Nodo **lista, int valor){
    Nodo *nodo = *lista;
    while(nodo->valor != valor){
        nodo = nodo->siguiente;
    }
    return *nodo;
}

/**
 * Elimina el elemento en la posicion pasada como parametro
 * @param lista
 * @param posicion: entre los valores 1 y 'tamanio' de lista
 */
void borrarXElemento(Nodo *lista, int posicion) {
    Nodo *nodo = lista;
    Nodo *aEliminar;
    if(posicion>0 && posicion<=tamanio){
        for (int i = 0; i < (posicion - 1); ++i) {
            nodo = nodo->siguiente;
        }
        aEliminar = nodo->siguiente;
        nodo->siguiente = nodo->siguiente->siguiente;
        free(aEliminar);
    }
    tamanio--;
}

void imprimir(Nodo *lista) {
    while (lista != NULL) {
        printf("%d - ", lista->valor);
        lista = lista->siguiente;
    }
    printf("\n");
}
