#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estudiantePorNombre.c"
#include "materia.c"

void darDeAltaEstudiante(Estudiante **lista, EstudiantePorNombre **listaNombre, char* nombre, char* apellido, int anio, int mes, int dia, int dni) {
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

void listarMaterias(Materia *listaMaterias) {
    imprimirMaterias(listaMaterias);
}

void cargarMateria(Materia **materia, char *nombre, int numero){
    agregarMateria(materia,nombre, numero);
}

int main(){

    Estudiante *lista = NULL;
    EstudiantePorNombre *listaNombre = NULL;

    darDeAltaEstudiante(&lista, &listaNombre, "Pepito", "Guzman", 1989, 10, 5, 45786812);
    darDeAltaEstudiante(&lista,&listaNombre, "Jorge", "Fiel", 1987, 10, 5, 49689238);
    darDeAltaEstudiante(&lista,&listaNombre, "Julio", "Fiel", 1987, 10, 5, 49689248);
    darDeAltaEstudiante(&lista,&listaNombre, "Abril", "Gomez", 1987, 10, 5, 49689258);
    darDeAltaEstudiante(&lista,&listaNombre, "Azul", "Perez", 1987, 10, 5, 49689268);
    darDeAltaEstudiante(&lista,&listaNombre, "Maria", "Munoz", 1999, 10, 5, 49789823);
    darDeAltaEstudiante(&lista,&listaNombre, "Rocio", "Rodriguez", 2004, 10, 5, 49768923);

    Estudiante *estPrueba = buscarEstudiantePorNombre(listaNombre, "Jorge");
    printf("Jorge: %s\n", estPrueba->apellido);
    estPrueba = buscarEstudiantePorApellido(listaNombre, "Rodriguez");
    printf("Rodriguez: %s\n", estPrueba->nombre);

    buscarEstudiantePorRangoEdad(&lista, 22, 34);
    printf("El estudiante %s %s fue encontrado\n", obtenerEstudiantePorEdad(&lista, 35,49689258 )->nombre,obtenerEstudiantePorEdad(&lista, 35,49689258 )->apellido);
    obtenerCantidadDeEstudiantes();

    imprimirEstudiantes(lista);

    borrarEstudiantePorEdad(&lista, 35, 49689258);

    Estudiante *estPrueba1= obtenerEstudiantePorEdad(&lista, 35,49689258 );
    if(estPrueba1 != NULL) {
        printf("El estudiante %s %s fue encontrado\n",obtenerEstudiantePorEdad(&lista, 35,49689258)->nombre, obtenerEstudiantePorEdad(&lista, 35,49689258)->apellido);
    }

    Materia *listaMaterias = NULL;
    cargarMateria(&listaMaterias, "Sistema De Representaciones", 1);
    cargarMateria(&listaMaterias, "Analisis", 3);
    cargarMateria(&listaMaterias, "Algoritmos y programacion", 2);
    cargarMateria(&listaMaterias, "Algebra", 4);

    printf("La materia Algebra es la numero %i \n",obtenerMateriaPorNombre(&listaMaterias, "Algebra")->numero);

    listarMaterias(listaMaterias);



    return 0;
}
