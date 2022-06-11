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


int main(){
    Nodo *lista = NULL;

    int opcion = 0;
    int valor = 0;
/*
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
    Nodo nodo = obtenerElemento(&lista,5);
    printf("el valor de la lista en la posicion 5 es %i.\n",nodo.valor);
    printf("5ta impresion, con valor obtenido: ");
    imprimir(lista);
    printf("Obtener elemento fuera de rango: ");
    nodo = obtenerElemento(&lista,7);
    printf("el valor de la lista en la posicion 5 es %i.\n",nodo);

    agregar(&lista, 1);
    printf("6ta impresion agregando 1: ");
    imprimir(lista);

    printf("El tamanio de la lista es de %i \n", tamanio);
    Nodo nodoDos = obtenerElemento(&lista,2);
    printf("El valor de la lista en la posicion 2 es %i.\n",nodo.valor);
    borrarXElemento(&lista, 6);
    printf("7ma impresion borrando 6: ");
    imprimir(lista);

    agregar(&lista, 10);
    printf("8va impresion agregando 10: ");
    imprimir(lista);

    Nodo nodo2 = obtenerElementoPorValor(&lista, 10);
    printf("el valor de la lista con valor 10 es %i \n", nodo2.valor);

    return 0;
}