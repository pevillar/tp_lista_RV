#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estudiante.c"
#include "estudiantePorNombre.c"

int main(){

    EstudiantePorNombre *lista = NULL;

    agregarPorNombre(&lista, "Guzman", "Pepito", 4578612);
    agregarPorNombre(&lista, "Fiel", "Jorge", 49678923);
    agregarPorNombre(&lista, "Munoz", "Maria", 49678923);
    agregarPorNombre(&lista, "Rodriguez", "Rocio", 49678923);

    imprimirListaPorNombre(lista);
    return 0;
}