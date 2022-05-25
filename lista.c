#include <stdio.h>
#include <stdlib.h>


typedef struct Nodo {
    struct Nodo *siguiente;
    int valor;
} Nodo;

int tamanio = 0;

void agregar(Nodo **lista, int valor) {
    if(valor != NULL){
        Nodo *nuevoNodo = malloc(sizeof(Nodo));
        nuevoNodo->valor = valor;
        if (tamanio == 0){
            nuevoNodo->siguiente = NULL;
            *lista = nuevoNodo;
        }else{
            Nodo *iterador = lista;
            int cargado = 0;
            while(cargado != 1){
                if(iterador->siguiente == NULL && iterador->valor<valor){
                    nuevoNodo->siguiente = NULL;
                    iterador->siguiente = nuevoNodo;
                    cargado = 1;
                }
                else if(iterador->valor>valor){
                    nuevoNodo->siguiente = iterador;
                    lista = nuevoNodo;
                    cargado = 1;
                }//se puede juntar sao 1 y 3?
                else if(iterador->siguiente->valor>valor){
                    nuevoNodo->siguiente = iterador->siguiente;
                    iterador->siguiente = nuevoNodo;
                    cargado = 1;
                }
                else if(iterador->siguiente->valor<valor){
                    iterador = iterador->siguiente;
                }
                else{
                    printf("Este caso para agregar no a sido contemplado");
                }
            }
        }
        tamanio++;
    }
}

Nodo obtenerElemento(Nodo *lista, int posicion){
    Nodo *nodo = lista;
    if(posicion>0 && posicion<tamanio){
        for (int i = 0; i < posicion; ++i) {
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
        for (int i = 0; i < posicion; ++i) {
            nodo = nodo->siguiente;
        }
        nodo->siguiente = nodo->siguiente->siguiente;
    }else if(posicion == 0){
        BorrarPrimerElemento(lista);
    }
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
    int valor;

    Nodo nodoRecuperado;

    /*while (opcion != 7){
        printf("elije una opcion para usar la lista: \n");
        printf("1. Cargar elemento\n");
        printf("2. Borrar primer elemento\n");
        printf("3. Borrar elemento en la posicion X\n");
        printf("4. Ver tamanio\n");
        printf("5. Imprimir Lista\n");
        printf("6. Obtener un elemeneto de la lista\n");
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
                    printf("\nEl elemento a sido cargardo\n");
                }
                break;
            case 2:
                BorrarPrimerElemento(&lista);
                printf("El Primer Elemento asido borrado\n");
                break;
            case 3:
                printf("Cual es la posicion del elemento a Borrar: ");
                scanf("%i", &valor);
                BorrarXElemento(&lista, valor);
                fflush(stdin);
                break;
            case 4:
                printf("El taminio de la lista actualmente es %i\n", tamanio);
                break;
            case 5:
                imprimir(lista);
                break;
            case 6:
                printf("Cual es la posicion del elemento a obtener: ");
                scanf("%i", &valor);
                nodoRecuperado = obtenerElemento(lista, valor);
                printf("el valor del nodo es de %i \n", nodoRecuperado.valor);
                fflush(stdin);
                break;
            case 7:
                break;
            default:
                printf("No hay ninguna operacion para el numero %i \n", opcion);
                break;
        }
    }*/




    BorrarPrimerElemento(&lista);
    imprimir(lista);
    agregar(&lista, 4);
    agregar(&lista, 6);
    agregar(&lista, 5);
    agregar(&lista, 3);
    agregar(&lista, 8);
    imprimir(lista);
    printf("el tamanio de la lista es de %i \n", tamanio);
    BorrarPrimerElemento(&lista);
    imprimir(lista);
    printf("el tamanio de la lista es de %i \n", tamanio);
    Nodo nodo = obtenerElemento(2,lista);
    printf("el valor de la lista en la posicion 3 es %i.\n",nodo.valor);//problemas con el valor
    imprimir(lista);
    BorrarXElemento(&lista, 2);
    imprimir(lista);
    return 0;
}