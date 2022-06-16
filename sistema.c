#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "estudiantePorNombre.c"
#include "datosParaSimular.c"

void darDeAltaEstudiante(Estudiante **lista, EstudiantePorNombre **listaNombre, char *nombre, char *apellido, int anio, int mes, int dia, int dni) {
    char *nombreCopia = (char*) malloc(50*sizeof(char));
    strcpy(nombreCopia,nombre);
    char *apellidoCopia = (char*) malloc(50*sizeof(char));
    strcpy(apellidoCopia,apellido);
    Estudiante *nuevoEstudiante = agregar(lista, nombreCopia, apellidoCopia, anio, mes, dia, dni);
    agregarPorNombre(listaNombre,nuevoEstudiante, nombreCopia, apellidoCopia);
}

void imprimirEstudiantes(EstudiantePorNombre *lista) {
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
    if (estudianteN == NULL) {
        printf("No existe el estudiante de nombre: %s, en el sistema.\n", nombre);
        return NULL;
    } else {
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
    }
}

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
    if(listaMaterias != NULL){
        imprimirMaterias(listaMaterias);
    }else{
        printf("No hay materias cargadas en el sistema");
    }
}

void cargarMateria(Materia **materia, char *nombre, int numero){
    char *nombreCopia = (char*) malloc(60*sizeof(char));
    strcpy(nombreCopia,nombre);
    agregarMateria(materia,nombreCopia, numero);
}

void obtenerEstadisticas(Materia *materia){
    if(materia->cantDeEstudiantesRendieron == 0){
        printf("Nadie ha rendido esta materia todavia\n");
    }else{
        obtenerPromedioDeAprobados(materia);
        obtenerNotaPromedio(materia);
    }
}
/**
 * Usa la funcion 'fgets()' para pedir un dato por consola y elimina
 * el '\n' que se genera el final de la cadena.
 * @param dato: variable que almacena el dato introducido por consola.
 */
void pedirDatoConFgets(char *dato) {
    fgets(dato, 60, stdin);
    if ((strlen(dato) > 0) && (dato[strlen(dato) - 1] == '\n')) {
        dato[strlen(dato) - 1] = '\0';
    }
}

/**
 * Convierte todas los caracteres de 'cadena' a minuscula.
 * @param cadena: una cadena de caracteres.
 */
void convertirAMinuscula(char *cadena) {
    for (int indice = 0; cadena[indice] != '\0'; ++indice){
        cadena[indice] = tolower(cadena[indice]);
    }
}

int main(){

/*Estudiante *lista = NULL;
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
    imprimirEstudiantes(listaNombre);
    borrarEstudiantePorEdad(lista, 35, 49689258);
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

    char *nombre = (char*) malloc(50*sizeof(char));
    char *apellido = (char*) malloc(50*sizeof(char));
    char *materiaNombre = (char*) malloc(60*sizeof(char));
    int anio;
    int mes;
    int dia;
    int dni;

    /*
    nombre = "Jose";
    apellido = "Muñoz";
    anio = 2003;
    mes = 2;
    dia = 5;
    dni = 43874800;
  darDeAltaEstudiante(&listaEstudiantes, &listaEstudiantesNombre,  nombre, apellido, anio, mes, dia, dni);
    nombre = "puerto";
    apellido = "julio";
    anio = 1980;
    mes = 1;
    dia = 12;
    dni = 12345678;
    darDeAltaEstudiante(&listaEstudiantes, &listaEstudiantesNombre, nombre, apellido, anio, mes, dia, dni);
    estudiantePrueba = buscarEstudiantePorNombreCompleto(listaEstudiantesNombre, "miguel", apellido);
    imprimir(estudiantePrueba);*/

    while(opcion != 13){
        printf("Bienvenido al sistema de estudiante:\nQue deseas hacer?\n"
               "Nota: para el uso correcto de la consola, evitar tildes y utilizar 'ni'\n"
               "para escribir por ejemplo: 'seniales'.\n");
        printf("1. Crear una materia\n");
        printf("2. Agregar un estudiante\n");
        printf("3. Buscar un estudiante por nombre\n");
        printf("4. Buscar un estudiante por rango de edad\n");
        printf("5. Ver todas las materias\n");
        printf("6. Anotar un estudiante a una materia\n");
        printf("7. Cargar la nota de un estudiante\n");
        printf("8. Imprimir las materias en curso de un estudiante\n");
        printf("9. Ver las estadisticas de una materia\n");
        printf("10. Ver todos los estudiantes\n");
        printf("11. Ver cantidad de estudiantes\n");
        printf("12. Cargar sistema de prueba\n");
        printf("13. Salir\n");
        scanf("%i",&opcion);
        switch (opcion) {
            case 1:
                printf("Nombre de la materia (ej: Fisica I): ");
                getc(stdin);
                pedirDatoConFgets(materiaNombre);
                convertirAMinuscula(materiaNombre);
                printf("ID de la materia: ");
                scanf("%i",&dni);
                cargarMateria(&listaDeMaterias, materiaNombre, dni);
                break;
            case 2:
                printf("Nota: escribir primero el nombre, luego el apellido cuando sea indicado.\n");
                printf("Escribe el nombre del estudiante: ");
                getc(stdin);
                pedirDatoConFgets(nombre);
                printf("Escribe el apellido del estudiante: ");
                pedirDatoConFgets(apellido);
                printf("Escribe la fecha de nacimiento (AAAA MM DD):");
                scanf("%i",&anio);
                scanf("%i",&mes);
                scanf("%i",&dia);
                printf("Escribe el DNI: ");
                scanf("%i",&dni);
                darDeAltaEstudiante(&listaEstudiantes, &listaEstudiantesNombre, nombre, apellido, anio, mes, dia, dni);
                break;
            case 3:
                printf("Nota: escribir primero el nombre, luego el apellido cuando sea indicado.\n");
                printf("Escribe el nombre del estudiante: ");
                getc(stdin);
                pedirDatoConFgets(nombre);
                printf("Escribe el apellido del estudiante: ");
                pedirDatoConFgets(apellido);
                if(listaEstudiantesNombre != NULL) {
                    estudiantePrueba = buscarEstudiantePorNombreCompleto(listaEstudiantesNombre, nombre, apellido);
                    if (estudiantePrueba != NULL) {
                        imprimirEstudiante(estudiantePrueba);
                    }
                } else{
                    printf("Todavia no hay ningun estudiante cargado en el sistema.\n");
                }
                break;
            case 4:
                printf("Escribe el minimo de edad: ");
                scanf("%i",&anio);
                printf("Escribe el maximo de edad: ");
                scanf("%i", &mes);
                printf("\n");
                if(listaEstudiantes != NULL){
                    buscarEstudiantePorRangoEdad(&listaEstudiantes,anio,mes);
                }else{
                    printf("Todavia no hay ningun estudiante cargado en el sistema.\n");
                }
                break;
            case 5:
                listarMaterias(listaDeMaterias);
                break;
            case 6:
                printf("Nota: escribir primero el nombre, luego el apellido cuando sea indicado.\n");
                printf("Escribe el nombre del estudiante: ");
                getc(stdin);
                pedirDatoConFgets(nombre);
                printf("Escribe el apellido del estudiante: ");
                pedirDatoConFgets(apellido);
                printf("Nombre de la materia a anotarse: ");
                pedirDatoConFgets(materiaNombre);
                convertirAMinuscula(materiaNombre);
                if(listaEstudiantesNombre != NULL && listaDeMaterias != NULL) {
                    estudiantePrueba = buscarEstudiantePorNombreCompleto(listaEstudiantesNombre, nombre, apellido);
                    materiaPrueba = obtenerMateriaPorNombre(&listaDeMaterias, materiaNombre);
                    if (estudiantePrueba != NULL && materiaPrueba != NULL) {
                        anotarEstudianteAMateria(materiaPrueba, estudiantePrueba);
                    }
                } else if(listaEstudiantesNombre == NULL){
                    printf("Todavia no hay ningun estudiante cargado en el sistema.\n");
                } else{
                    printf("Todavia no hay ninguna materia cargada en el sistema.\n");
                }
                break;
            case 7:
                printf("Nota: escribir primero el nombre, luego el apellido cuando sea indicado.\n");
                printf("Escribe el nombre del estudiante: ");
                getc(stdin);
                pedirDatoConFgets(nombre);
                printf("Escribe el apellido del estudiante: ");
                pedirDatoConFgets(apellido);
                printf("Nombre de la materia a anotarse: ");
                pedirDatoConFgets(materiaNombre);
                convertirAMinuscula(materiaNombre);
                printf("Escribe la nota: ");
                scanf("%i", &dni);
                if(listaEstudiantesNombre != NULL){
                    estudiantePrueba = buscarEstudiantePorNombreCompleto(listaEstudiantesNombre, nombre, apellido);
                    if(estudiantePrueba != NULL){
                        cargarNotaAMateria(materiaNombre, estudiantePrueba, dni);
                    }
                }else{
                    printf("Todavia no hay ningun estudiante cargado en el sistema.\n");
                }
                break;
            case 8:
                printf("Nota: escribir primero el nombre, luego el apellido cuando sea indicado.\n");
                printf("Escribe el nombre del estudiante: ");
                getc(stdin);
                pedirDatoConFgets(nombre);
                printf("Escribe el apellido del estudiante: ");
                pedirDatoConFgets(apellido);
                if(listaEstudiantesNombre != NULL){
                    estudiantePrueba = buscarEstudiantePorNombreCompleto(listaEstudiantesNombre, nombre, apellido);
                    if(estudiantePrueba != NULL){
                        imprimirMateriasEnCurso(estudiantePrueba);
                    }
                }else{
                    printf("Todavia no hay ningun estudiante cargado en el sistema");
                }
                break;
            case 9:
                printf("Escribe el nombre de la materia que deseas obtener (ej: Algebra I): ");
                fgetc(stdin);
                pedirDatoConFgets(materiaNombre);
                convertirAMinuscula(materiaNombre);
                if(listaDeMaterias != NULL) {
                    materiaPrueba = obtenerMateriaPorNombre(&listaDeMaterias, materiaNombre);
                    if (materiaPrueba != NULL) {
                        obtenerEstadisticas(materiaPrueba);
                    }
                }else{
                    printf("Todavia no hay ninguna materia cargada en el sistema.\n");
                }
                break;
            case 10:
                if(listaEstudiantesNombre != NULL){
                    imprimirEstudiantes(listaEstudiantesNombre);
                } else{
                    printf("Todavia no hay ningun estudiante cargado en el sistema.\n");
                }
                break;
            case 11:
                obtenerCantidadDeEstudiantes();
                break;
            case 12:
                for (int i = 0; i < 164; ++i) {
                    darDeAltaEstudiante(&listaEstudiantes, &listaEstudiantesNombre,
                                        nombres[i], apellidos[i], anios[i], meses[i],
                                        dias[i], dnis[i]);
                }
                for (int i = 0; i < 45; ++i) {
                    cargarMateria(&listaDeMaterias, arregloMaterias[i], i + 1);
                }
                break;
            case 13:
                printf("Gracias por utilizar el sistema.\n");
                break;
            default:
                printf("No hay ninguna operacion para el numero %i.\n", opcion);
                break;
        }
        printf("\n");
    }

    return 0;
}