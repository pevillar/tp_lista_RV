#include <stdio.h>
#include <stdlib.h>


typedef struct nombreStruct {
    struct nombreStruct *siguiente;
    int valor;
} Nodo;

int tamanio = 0;

Nodo *crearNodo(int valor){
    Nodo *nodo = (Nodo*) malloc(sizeof (Nodo));
    nodo->valor = valor;
    nodo->siguiente = NULL;
    return nodo;
}

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

Nodo obtenerElemento(Nodo **lista, int posicion){
    Nodo *nodo = *lista;
    if(posicion>0 && posicion<tamanio){
        for (int i = 0; i < (posicion - 1); ++i) {
            nodo = nodo->siguiente;
        }
        return *nodo;
    }
}

void BorrarPrimerElemento(Nodo *lista) {
    if (lista->siguiente != NULL) {
        *lista = *lista->siguiente;
        tamanio--;
    }
}

void BorrarXElemento(Nodo *lista, int posicion) {
    Nodo *nodo = lista;
    if(posicion>0 && posicion<tamanio){
        for (int i = 0; i < (posicion - 1); ++i) {
            nodo = nodo->siguiente;
        }
        nodo->siguiente = nodo->siguiente->siguiente;
    }
}

void imprimir(Nodo *lista) {
    while (lista != NULL) {
        printf("%d - ", lista->valor);
        lista = lista->siguiente;
    }
    printf("\n");
}

int obtenerTamanio(){
    return tamanio;
}

int main(){
    Nodo *lista = NULL;

    imprimir(lista);
    agregar(&lista, 1);
    agregar(&lista, 8);
    agregar(&lista, 2);
    agregar(&lista, 4);
    agregar(&lista, 3);
    agregar(&lista, 5);
    imprimir(lista);
    printf("el tamanio de la lista es de %i \n", tamanio);
    agregar(&lista, 7);
    agregar(&lista, 6);
    imprimir(lista);
    printf("el tamanio de la lista es de %i \n", tamanio);
    BorrarPrimerElemento(&lista);
    imprimir(lista);

    printf("Obtener elemento\n");
    Nodo nodo = obtenerElemento(&lista,2);
    printf("el valor de la lista en la posicion 2 es %i.\n",nodo.valor);
    printf("4ta impresion:");
    imprimir(lista);

    agregar(&lista, 1);
    printf("5ta impresion agregando 1: ");
    imprimir(lista);

    printf("el tamanio de la lista es de %i \n", tamanio);
    //Nodo nodo = obtenerElemento(&lista,2);
    //printf("el valor de la lista en la posicion 2 es %i.\n",nodo.valor);
    BorrarXElemento(&lista, 2);
    printf("6ta impresion borrando 2: ");
    imprimir(lista);
}