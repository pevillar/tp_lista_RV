#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estudiantePorNombre.c"

void darDeAltaEstudiante(Estudiante **lista, EstudiantePorNombre **listaNombre, char* nombre, char* apellido,  int anio, int mes, int dia, int dni) {
    Estudiante *nuevoEstudiante = agregar(lista, nombre, apellido, anio, mes, dia, dni);
    agregarPorNombre(listaNombre,nuevoEstudiante, nombre, apellido);
}

void imprimirEstudiantes(Estudiante *lista) {
    imprimir(lista);
}

Estudiante *buscarEstudiantePorNombre(EstudiantePorNombre *listaNombre, char *nombre) {
    EstudiantePorNombre *estudianteN = obtenerEstudiantePorNombre(&listaNombre, nombre);
    return estudianteN->estudianteEdad;
}

Estudiante *buscarEstudiantePorApellido(EstudiantePorNombre *listaNombre, char *apellido) {
    EstudiantePorNombre *estudianteN = obtenerEstudiantePorApellido(&listaNombre, apellido);
    return estudianteN->estudianteEdad;
}

void buscarEstudiantePorRangoEdad(Estudiante **lista, int edadMinima, int edadMaxima) {
    obtenerEstudiantePorRangoDeEdad(lista, edadMinima, edadMaxima);
}

void obtenerCantidadDeEstudiantes(){
    printf("Hay %i estudiantes cargados en el sistema.\n", tamanio);
}

int main(){

    Estudiante *lista = NULL;
    EstudiantePorNombre *listaNombre = NULL;

    darDeAltaEstudiante(&lista, &listaNombre, "Pepito", "Guzman", 1989, 10, 5, 45786812);
    darDeAltaEstudiante(&lista,&listaNombre, "Jorge", "Fiel", 1987, 10, 5, 49689238);
    darDeAltaEstudiante(&lista,&listaNombre, "Maria", "Munoz", 1999, 10, 5, 49789823);
    darDeAltaEstudiante(&lista,&listaNombre, "Rocio", "Rodriguez", 2004, 10, 5, 49768923);

    Estudiante *estPrueba = buscarEstudiantePorNombre(listaNombre, "Jorge");
    printf("Jorge: %s\n", estPrueba->apellido);
    estPrueba = buscarEstudiantePorApellido(listaNombre, "Rodriguez");
    printf("Rodriguez: %s\n", estPrueba->nombre);

    buscarEstudiantePorRangoEdad(&lista, 22, 34);
    obtenerCantidadDeEstudiantes();

    //imprimirEstudiantes(lista);
    return 0;
}