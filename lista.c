#include <stdio.h>
#include <stdlib.h>


typedef struct nombreStruct {
    struct nombreStruct *siguiente;
    int valor;
} Nodo;

int tamanio = 0;

/**
 * Agrega un nuevo elemento de tipo 'Nodo' a la lista.
 * @param lista
 * @param valor
 */
void agregar(Nodo **lista, int valor) {
    if(valor != NULL){
        Nodo *nuevoNodo = malloc(sizeof(Nodo));
        nuevoNodo->valor = valor;
        if (tamanio == 0){
            nuevoNodo->siguiente = NULL;
            *lista = nuevoNodo;
        }else{
            nuevoNodo->siguiente = *lista;
            *lista = nuevoNodo;
        }
        tamanio++;
    }
}

/**
 * Se obtiene el elemento en la posicion pasada como parametro.
 * @param lista
 * @param posicion: debe estar entre los valores 1 y 'tamanio' de la lista
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

void borrarPrimerElemento(Nodo *lista) {
    if (lista->siguiente != NULL) {
        *lista = *lista->siguiente;
        tamanio--;
    }
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
int main() {
    Nodo *lista = NULL;

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
    }



    /*
    BorrarPrimerElemento(&lista);
    imprimir(lista);
    agregar(&lista, 1);
    agregar(&lista, 5);
    agregar(&lista, 6);
    agregar(&lista, 7);
    agregar(&lista, 8);
    imprimir(lista);
    printf("el tamanio de la lista es de %i \n", tamanio);
    borrarPrimerElemento(&lista);
    imprimir(lista);
    printf("el tamanio de la lista es de %i \n", tamanio);
    Nodo nodo = obtenerElemento(2,lista);
    printf("el valor de la lista en la posicion 3 es %i.\n",nodo.valor);
    borrarXElemento(&lista, 2);
    imprimir(lista);*/
    return 0;
}