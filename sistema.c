#include <stdio.h>
#include "estudiantePorNombre.c"

void darDeAltaEstudiante(Estudiante **lista, EstudiantePorNombre **listaNombre, char* nombre, char* apellido, int anio, int mes, int dia, int dni) {
    Estudiante *nuevoEstudiante = agregar(lista, nombre, apellido, anio, mes, dia, dni);
    agregarPorNombre(listaNombre,nuevoEstudiante, nombre, apellido);
}

void imprimirEstudiantes(Estudiante *lista) {
    imprimirListaPorNombre(lista);
}

Estudiante *buscarEstudiantePorNombreCompleto(EstudiantePorNombre *listaNombre, char *nombre, char *apellido) {
    EstudiantePorNombre *estudianteN = obtenerEstudianteNombreCompleto(&listaNombre, nombre, apellido);
    if(estudianteN == NULL){
        printf("No existe el estudiante: %s %s, en el sistema.\n", nombre, apellido);
        return NULL;
    }else{
        return estudianteN->estudianteEdad;
    }
}

Estudiante *buscarEstudiantePorNombre(EstudiantePorNombre *listaNombre, char *nombre) {
    EstudiantePorNombre *estudianteN = obtenerEstudiantePorNombre(&listaNombre, nombre);
    if(estudianteN == NULL){
        printf("No existe el estudiante de nombre: %s, en el sistema.\n", nombre);
        return NULL;
    }else{
        return estudianteN->estudianteEdad;
    }
}

Estudiante *buscarEstudiantePorApellido(EstudiantePorNombre *listaNombre, char *apellido) {
    EstudiantePorNombre *estudianteN = obtenerEstudiantePorApellido(&listaNombre, apellido);
    if(estudianteN == NULL){
        printf("No existe el estudiante de apellido: %s, en el sistema.\n", apellido);
        return NULL;
    }else{
        return estudianteN->estudianteEdad;
    }}

void buscarEstudiantePorRangoEdad(Estudiante **lista, int edadMinima, int edadMaxima) {
    obtenerEstudiantePorRangoDeEdad(lista, edadMinima, edadMaxima);
}

void obtenerCantidadDeEstudiantes(){
    if(tamanio == 1){
        printf("Hay un estudiante cargado en el sistema.\n");
    }else{
        printf("Hay %i estudiantes cargados en el sistema.\n", tamanio);
    }
}

void listarMaterias(Materia *listaMaterias) {
    imprimirMaterias(listaMaterias);
}

void cargarMateria(Materia **materia, char *nombre, int numero){
    agregarMateria(materia,nombre, numero);
}

void obtenerEstadisticas(Materia *materia){
    if(materia->cantDeEstudiantesRendieron == 0){
        printf("Nadie a rendido esta materia todavia\n");
    }else{
        obtenerPromedioDeAprobados(materia);
        obtenerNotaPromedio(materia);
    }
}

int main(){

    /*
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
    listarMaterias(listaMaterias);*/
//------------------------------------------------------------------------------------------------------------------------------------------------------------

    Materia *listaDeMaterias = NULL;
    Estudiante *listaEstudiantes = NULL;
    EstudiantePorNombre *listaEstudiantesNombre = NULL;
    Estudiante *estudiantePrueba;
    Materia *materiaPrueba;

    int opcion = 0;

    char nombre[50];
    char apellido[20];
    int anio;
    int mes;
    int dia;
    int dni;

    while(opcion != 12){
        printf("Bienvenido al sistema de estudiante:\nQue deseas hacer?\n");
        printf("1. Crear una materia\n");
        printf("2. Agregar un estudiante\n");
        printf("3. Buscar un estudiante por nombre\n");
        printf("4. Buscar un estudiante por rango de edad\n");
        printf("5. Ver todas las materia\n");
        printf("6. Anotar a un estudiante a una materia\n"); //falta cargar
        printf("7. Cargar la nota de un estudiante\n"); //falta cargar
        printf("8. Imprimir las materias en curso de un estudiante\n");
        printf("9. Ver las estadisticas de una materias\n");
        printf("10. Ver todos los estudiantes\n");
        printf("11 Ver cantidad de estudiantes\n");
        printf("12. Salir\n");
        scanf("%i",&opcion);
        switch (opcion) {
            case 1:
                printf("Nombre de la materia: ");
                scanf("%s",nombre);
                printf("ID de la materia: ");
                scanf("%i",&dni);
                cargarMateria(&listaDeMaterias, *nombre, dni);
                break;
            case 2:
                printf("Primer nombre del estudiante: ");
                scanf("%s",&nombre);
                printf("Apellido (uno solo) del estudiante: ");
                scanf("%s",&apellido);
                printf("fecha de nacimiento (AAAA MM DD)");
                scanf("%i",&anio);
                scanf("%i",&mes);
                scanf("%i",&dia);
                printf("DNI: ");
                scanf("%i",&dni);
                darDeAltaEstudiante(&listaEstudiantes, &listaEstudiantesNombre, nombre, apellido, anio, mes, dia, dni);
                break;
            case 3:
                printf("Nota: escribir primero el nombre luego el apellido cuando sea indicado.\n");
                printf("Escribe el nombre del estudiante: ");
                scanf("%s", &nombre);
                printf("Escribe el apellido del estudiante: ");
                scanf("%s", &apellido);
                estudiantePrueba = buscarEstudiantePorNombreCompleto(listaEstudiantesNombre, nombre, apellido);
                if(estudiantePrueba != NULL){
                    imprimirEstudiante(estudiantePrueba);
                }
                break;
            case 4:
                printf("Escribe el minimo de edad: ");
                scanf("%i",&anio);
                printf("\nEscribe el maximo de edad: ");
                scanf("%i", &mes);
                buscarEstudiantePorRangoEdad(&listaEstudiantes,anio,mes);
                break;
            case 5:
                listarMaterias(listaDeMaterias);
                break;
            case 6:
                printf("Nota: escribir primero el nombre luego el apellido cuando sea indicado.\n");
                printf("Escribe el nombre del estudiante: ");
                scanf("%s", &nombre);
                printf("Escribe el apellido del estudiante: ");
                scanf("%s", &apellido);
                estudiantePrueba = buscarEstudiantePorNombreCompleto(listaEstudiantesNombre, nombre, apellido);
                printf("\nNombre de la materia a anotarse: ");
                scanf("%s", apellido);
                materiaPrueba = obtenerMateriaPorNombre(&listaDeMaterias, apellido);
                anotarMateria(materiaPrueba, estudiantePrueba);
                break;
            case 7:
                printf("Nota: escribir primero el nombre luego el apellido cuando sea indicado.\n");
                printf("Escribe el nombre del estudiante: ");
                scanf("%s", &nombre);
                printf("Escribe el apellido del estudiante: ");
                scanf("%s", &apellido);
                estudiantePrueba = buscarEstudiantePorNombreCompleto(listaEstudiantesNombre, nombre, apellido);
                printf("\nNombre de la materia a anotarse: ");
                scanf("%s", apellido);
                printf("Escribe la nota: ");
                scanf("%i", &dni);
                cargarNotaAMateria(apellido, estudiantePrueba, dni);
                break;
            case 8:
                printf("Nota: escribir primero el nombre luego el apellido cuando sea indicado.\n");
                printf("Escribe el nombre del estudiante: ");
                scanf("%s", &nombre);
                printf("Escribe el apellido del estudiante: ");
                scanf("%s", &apellido);
                estudiantePrueba = buscarEstudiantePorNombreCompleto(listaEstudiantesNombre, nombre, apellido);
                imprimirMateriasCusrsando(estudiantePrueba);
                break;
            case 9:
                printf("Escribe el nombre de la materia que deseas obtener: ");
                scanf("%s", &nombre);
                materiaPrueba = obtenerMateriaPorNombre(&listaDeMaterias, nombre);
                if(materiaPrueba != NULL){
                    obtenerEstadisticas(materiaPrueba);
                }
                break;
            case 10:
                imprimirEstudiantes(listaEstudiantes);
                break;
            case 11:
                obtenerCantidadDeEstudiantes();
                break;
            case 12:
                printf("Gracias por utilizar el sistema\n");
                break;
            default:
                printf("No hay ninguna operacion para el numero %i \n", opcion);
                break;
        }
    }



    return 0;
}