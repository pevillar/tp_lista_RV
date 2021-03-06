#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "estudiantePorNombre.c"
#include "datosParaSimular.c"

/**
 * Crea un nuevo estudiante y lo agrega al sistema.
 * @param lista
 * @param listaNombre
 * @param nombre
 * @param apellido
 * @param anio
 * @param mes
 * @param dia
 * @param dni
 */
void darDeAltaEstudiante(Estudiante **lista, EstudiantePorNombre **listaNombre, char *nombre, char *apellido, int anio, int mes, int dia, int dni) {
    char *nombreCopia = (char*) malloc(50*sizeof(char));
    strcpy(nombreCopia,nombre);
    char *apellidoCopia = (char*) malloc(50*sizeof(char));
    strcpy(apellidoCopia,apellido);
    Estudiante *nuevoEstudiante = agregar(lista, nombreCopia, apellidoCopia, anio, mes, dia, dni);
    agregarPorNombre(listaNombre,nuevoEstudiante, nombreCopia, apellidoCopia);
}

/**
 * Imprime el nombre completo de cada estudiante cargado en el sistema.
 * @param lista
 */
void imprimirEstudiantes(EstudiantePorNombre *lista) {
    imprimirListaPorNombre(lista);
}

/**
 * Devuelve el estudiante con el nombre correspondiente.
 * @param listaNombre
 * @param nombre
 * @param apellido
 * @return
 */
Estudiante *buscarEstudiantePorNombreCompleto(EstudiantePorNombre *listaNombre, char *nombre, char *apellido) {
    EstudiantePorNombre *estudianteN = obtenerEstudianteNombreCompleto(&listaNombre, nombre, apellido);
    if(estudianteN == NULL){
        printf("No existe el estudiante: %s %s, en el sistema.\n", nombre, apellido);
        return NULL;
    }else{
        return estudianteN->estudianteEdad;
    }
}

/**
 * Borrra un estudiante del sistema.
 * @param listaPorEdad
 * @param listaPorNombre
 * @param nombre
 * @param apellido
 */
void eliminarUnEstudiante(Estudiante *listaPorEdad, EstudiantePorNombre *listaPorNombre, char *nombre, char *apellido){
    borrarEstudiantePorNombreEdad(listaPorEdad, nombre, apellido);
    borrarEstudiantePorNombre(listaPorNombre, nombre, apellido);
}

/**
 * Devuelve el/los estudiante/s en el rango de edad establecido.
 * @param lista
 * @param edadMinima
 * @param edadMaxima
 */
void buscarEstudiantePorRangoEdad(Estudiante **lista, int edadMinima, int edadMaxima) {
    obtenerEstudiantePorRangoDeEdad(lista, edadMinima, edadMaxima);
}

/**
 * Devuelve la cantidad de estudiantes cargados en el sistema.
 */
void obtenerCantidadDeEstudiantes(){
    if(tamanio == 1){
        printf("Hay un estudiante cargado en el sistema.\n");
    }else{
        printf("Hay %i estudiantes cargados en el sistema.\n", tamanio);
    }
}

/**
 * Imprime por consola todas la materias existentes en el sistema.
 * @param listaMaterias
 */
void listarMaterias(Materia *listaMaterias) {
    if(listaMaterias != NULL){
        imprimirMaterias(listaMaterias);
    }else{
        printf("No hay materias cargadas en el sistema");
    }
}

/**
 * Agrega una materia al sistema.
 * @param materia
 * @param nombre
 * @param numero
 */
void cargarMateria(Materia **materia, char *nombre, int numero){
    char *nombreCopia = (char*) malloc(60*sizeof(char));
    strcpy(nombreCopia,nombre);
    agregarMateria(materia,nombreCopia, numero);
}

/**
 * Imprime el promedio de aprovados y la nota promedio de una materia.
 * @param materia
 */
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

/**
 * Cambia los guines '-' por espacios ' '.
 * @param nombreSinEspacios
 */
void ponerEspacios(char *nombreSinEspacios){
    int tamanio = strlen(nombreSinEspacios);
    for(int i = 0; i<tamanio; i++){
        if(nombreSinEspacios[i] == '-'){
            nombreSinEspacios[i] = ' ';
        }
    }
}

/**
 * Cammbia los espacios ' ' por guines '-'.
 * @param nombreSinEspacios
 */
void sacarEspacios(char *nombreSinEspacios){
    int tamanio = strlen(nombreSinEspacios);
    for(int i = 0; i<tamanio; i++){
        if(nombreSinEspacios[i] == ' '){
            nombreSinEspacios[i] = '-';
        }
    }
}

/**
 * Se escribe en archivos los datos actuales del sistema si las listas no son nulas.
 * @param listaEstudiantes
 * @param listaEstudiantesNombre
 * @param listaDeMaterias
 * @param estudiantesUbi
 * @param materiasUbi
 * @param materiasEstudiantesUbi
 * @param materiaCargada
 */
void cargarArchivo(Estudiante *listaEstudiantes, EstudiantePorNombre *listaEstudiantesNombre,Materia *listaDeMaterias,
                   char *estudiantesUbi, char *materiasUbi, char *materiasEstudiantesUbi, int materiaCargada){

    char *nombre = (char*) malloc(50*sizeof(char));
    char *apellido = (char*) malloc(50*sizeof(char));
    char *materiaNombre = (char*) malloc(60*sizeof(char));

    EstudiantePorNombre *cursor = listaEstudiantesNombre;

    if(listaEstudiantes != NULL){
        FILE *flujoEstudiante= fopen(estudiantesUbi,"w");

        if(flujoEstudiante == NULL){
            perror("Error en la apertura del archivo");
        }else{
            if(cursor != NULL){
                while(cursor->siguiente != NULL){
                    nombre = cursor->nombre;
                    sacarEspacios(nombre);
                    apellido = cursor->apellido;
                    sacarEspacios(apellido);
                    materiaNombre = cursor->estudianteEdad->fechaDeNacimiento;
                    ponerEspacios(materiaNombre);
                    fprintf(flujoEstudiante, "%s %s %s %i\n", nombre, apellido,materiaNombre, cursor->estudianteEdad->dni);
                    cursor = cursor->siguiente;
                }
                nombre = cursor->nombre;
                sacarEspacios(nombre);
                apellido = cursor->apellido;
                sacarEspacios(apellido);
                materiaNombre = cursor->estudianteEdad->fechaDeNacimiento;
                ponerEspacios(materiaNombre);
                fprintf(flujoEstudiante, "%s %s %s %i", nombre, apellido,materiaNombre, cursor->estudianteEdad->dni);
            }
        }

        fflush(flujoEstudiante);
        fclose(flujoEstudiante);
    }

    if(listaDeMaterias != NULL){
        FILE *flujoMateriaEsc= fopen(materiasUbi,"w");

        if(flujoMateriaEsc == NULL){
            perror("Error en la apertura del archivo");
        }else{
            Materia *cursorMateria = listaDeMaterias;
            if(cursorMateria != NULL){
                while(cursorMateria->siguienteMateria != NULL){
                    materiaNombre = cursorMateria->nombre;
                    sacarEspacios(materiaNombre);
                    fprintf(flujoMateriaEsc, "%s %i\n", materiaNombre, cursorMateria->numero);
                    cursorMateria = cursorMateria->siguienteMateria;
                }
                materiaNombre = cursorMateria->nombre;
                sacarEspacios(materiaNombre);
                fprintf(flujoMateriaEsc, "%s %i", materiaNombre, cursorMateria->numero);
            }
        }

        fflush(flujoMateriaEsc);
        fclose(flujoMateriaEsc);
    }
    if(materiaCargada == 1){
        FILE *flujoMateriaEstudianteEsc= fopen(materiasEstudiantesUbi,"w");

        if(flujoMateriaEstudianteEsc == NULL){
            perror("Error en la apertura del archivo");
        }else{
            cursor = listaEstudiantesNombre;
            if(cursor != NULL) {
                MateriaEstudiante *cursorMateriaEstudianteCursando = cursor->estudianteEdad->materiasEnCurso;
                MateriaEstudiante *cursorMateriaEstudianteAprobadas = cursor->estudianteEdad->materiasAprobadas;
                while (cursor->siguiente != NULL) {
                    if(cursorMateriaEstudianteCursando != NULL){
                        nombre = cursor->nombre;
                        sacarEspacios(nombre);
                        apellido = cursor->apellido;
                        sacarEspacios(apellido);
                        while(cursorMateriaEstudianteCursando->siguienteMateriaEstudiante != NULL){
                            materiaNombre = cursorMateriaEstudianteCursando->materia->nombre;
                            sacarEspacios(materiaNombre);
                            fprintf(flujoMateriaEstudianteEsc, "%s %s %s %.2f %i\n", materiaNombre, nombre, apellido, cursorMateriaEstudianteCursando->nota, cursorMateriaEstudianteCursando->intentos);
                            cursorMateriaEstudianteCursando = cursorMateriaEstudianteCursando->siguienteMateriaEstudiante;
                        }
                        materiaNombre = cursorMateriaEstudianteCursando->materia->nombre;
                        sacarEspacios(materiaNombre);
                        fprintf(flujoMateriaEstudianteEsc, "%s %s %s %.2f %i", materiaNombre, nombre, apellido, cursorMateriaEstudianteCursando->nota, cursorMateriaEstudianteCursando->intentos);
                        if(cursorMateriaEstudianteAprobadas != NULL){
                            fprintf(flujoMateriaEstudianteEsc, "\n");
                            while(cursorMateriaEstudianteAprobadas->siguienteMateriaEstudiante != NULL){
                                materiaNombre = cursorMateriaEstudianteAprobadas->materia->nombre;
                                sacarEspacios(materiaNombre);
                                fprintf(flujoMateriaEstudianteEsc, "%s %s %s %.2f %i\n", materiaNombre, nombre, apellido, cursorMateriaEstudianteAprobadas->nota, cursorMateriaEstudianteAprobadas->intentos);
                                cursorMateriaEstudianteAprobadas = cursorMateriaEstudianteAprobadas->siguienteMateriaEstudiante;
                            }
                            materiaNombre = cursorMateriaEstudianteAprobadas->materia->nombre;
                            sacarEspacios(materiaNombre);
                            fprintf(flujoMateriaEstudianteEsc, "%s %s %s %.2f %i", materiaNombre, nombre, apellido, cursorMateriaEstudianteAprobadas->nota, cursorMateriaEstudianteAprobadas->intentos);
                        }
                    }
                    cursor = cursor->siguiente;
                }
                cursorMateriaEstudianteCursando = cursor->estudianteEdad->materiasEnCurso;
                cursorMateriaEstudianteAprobadas = cursor->estudianteEdad->materiasAprobadas;
                if(cursorMateriaEstudianteCursando != NULL){
                    nombre = cursor->nombre;
                    sacarEspacios(nombre);
                    apellido = cursor->apellido;
                    sacarEspacios(apellido);
                    while(cursorMateriaEstudianteCursando->siguienteMateriaEstudiante != NULL){
                        materiaNombre = cursorMateriaEstudianteCursando->materia->nombre;
                        sacarEspacios(materiaNombre);
                        fprintf(flujoMateriaEstudianteEsc, "%s %s %s %.2f %i\n", materiaNombre, nombre, apellido, cursorMateriaEstudianteCursando->nota, cursorMateriaEstudianteCursando->intentos);
                        cursorMateriaEstudianteCursando = cursorMateriaEstudianteCursando->siguienteMateriaEstudiante;
                    }
                    materiaNombre = cursorMateriaEstudianteCursando->materia->nombre;
                    sacarEspacios(materiaNombre);
                    fprintf(flujoMateriaEstudianteEsc, "%s %s %s %.2f %i", materiaNombre, nombre, apellido, cursorMateriaEstudianteCursando->nota, cursorMateriaEstudianteCursando->intentos);
                    if(cursorMateriaEstudianteAprobadas != NULL) {
                        fprintf(flujoMateriaEstudianteEsc, "\n");
                        while(cursorMateriaEstudianteAprobadas->siguienteMateriaEstudiante != NULL){
                            materiaNombre = cursorMateriaEstudianteAprobadas->materia->nombre;
                            sacarEspacios(materiaNombre);
                            fprintf(flujoMateriaEstudianteEsc, "%s %s %s %.2f %i\n", materiaNombre, nombre, apellido, cursorMateriaEstudianteAprobadas->nota, cursorMateriaEstudianteAprobadas->intentos);
                            cursorMateriaEstudianteAprobadas = cursorMateriaEstudianteAprobadas->siguienteMateriaEstudiante;
                        }
                        materiaNombre = cursorMateriaEstudianteAprobadas->materia->nombre;
                        sacarEspacios(materiaNombre);
                        fprintf(flujoMateriaEstudianteEsc, "%s %s %s %.2f %i", materiaNombre, nombre, apellido, cursorMateriaEstudianteAprobadas->nota, cursorMateriaEstudianteAprobadas->intentos);
                    }
                }
            }
        }
        fflush(flujoMateriaEstudianteEsc);
        fclose(flujoMateriaEstudianteEsc);
    }
}

int main(){

    Materia *listaDeMaterias = NULL;
    Estudiante *listaEstudiantes = NULL;
    EstudiantePorNombre *listaEstudiantesNombre = NULL;
    Estudiante *estudiantePrueba;
    Materia *materiaPrueba;

    int opcion = 0;

    char *nombre = (char*) malloc(50*sizeof(char));
    char *apellido = (char*) malloc(50*sizeof(char));
    char *materiaNombre = (char*) malloc(60*sizeof(char));
    char *estudiantesUbi = "../estudiates.txt";
    char *materiasUbi = "../materias.txt";
    char *materiasEstudiantesUbi = "../materiasEstudiantes.txt";
    int anio;
    int mes;
    int dia;
    int dni;
    double nota;
    int id;
    char *notaChar = (char*) malloc(50*sizeof(char));
    int intententos;
    int materiaCargada = 0;
    FILE *flujo;

    while(opcion != 17){
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
        printf("9. Imprimir todas las materias cursadas y en curso de un estudiante\n");
        printf("10. Ver las estadisticas de una materia\n");
        printf("11. Ver todos los estudiantes\n");
        printf("12. Ver cantidad de estudiantes\n");
        printf("13. Cargar sistema de prueba\n");
        printf("14. Borrar estudiante\n");
        printf("15. Leer Datos\n");
        printf("16. Guardar Datos\n");
        printf("17. Salir\n");
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
                    if(materiaPrueba == NULL){
                        printf("La materia: %s, no existe en el sistema.\n", nombre);
                    }
                    if (estudiantePrueba != NULL && materiaPrueba != NULL) {
                        int cantEstudiantes = materiaPrueba->cantDeEstudiantes;
                        anotarEstudianteAMateria(materiaPrueba, estudiantePrueba);
                        if(cantEstudiantes != materiaPrueba->cantDeEstudiantes){
                            printf("El estudiante %s %s se anoto a %s.\n", estudiantePrueba->nombre, estudiantePrueba->apellido, materiaPrueba->nombre);
                            materiaCargada = 1;
                        }
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
                printf("Nombre de la materia a rendir: ");
                pedirDatoConFgets(materiaNombre);
                convertirAMinuscula(materiaNombre);
                printf("Escribe la nota: ");
                scanf("%i", &nota);
                if(listaEstudiantesNombre != NULL){
                    estudiantePrueba = buscarEstudiantePorNombreCompleto(listaEstudiantesNombre, nombre, apellido);
                    if(estudiantePrueba != NULL){
                        cargarNotaAMateria(materiaNombre, estudiantePrueba, nota);
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
                printf("Nota: escribir primero el nombre, luego el apellido cuando sea indicado.\n");
                printf("Escribe el nombre del estudiante: ");
                getc(stdin);
                pedirDatoConFgets(nombre);
                printf("Escribe el apellido del estudiante: ");
                pedirDatoConFgets(apellido);
                if(listaEstudiantesNombre != NULL){
                    estudiantePrueba = buscarEstudiantePorNombreCompleto(listaEstudiantesNombre, nombre, apellido);
                    if(estudiantePrueba != NULL){
                        imprimirTodasLasMaterias(estudiantePrueba);
                    }
                }else{
                    printf("Todavia no hay ningun estudiante cargado en el sistema");
                }
                break;
            case 10:
                printf("Escribe el nombre de la materia que deseas obtener (ej: Algebra I): ");
                fgetc(stdin);
                pedirDatoConFgets(materiaNombre);
                convertirAMinuscula(materiaNombre);
                if(listaDeMaterias != NULL) {
                    materiaPrueba = obtenerMateriaPorNombre(&listaDeMaterias, materiaNombre);
                    if (materiaPrueba != NULL) {
                        obtenerEstadisticas(materiaPrueba);
                    } else{
                        printf("La materia: %s, no existe en el sistema.\n", nombre);
                    }
                }else{
                    printf("Todavia no hay ninguna materia cargada en el sistema.\n");
                }
                break;
            case 11:
                if(listaEstudiantesNombre != NULL){
                    imprimirEstudiantes(listaEstudiantesNombre);
                } else{
                    printf("Todavia no hay ningun estudiante cargado en el sistema.\n");
                }
                break;
            case 12:
                obtenerCantidadDeEstudiantes();
                break;
            case 13:
                for (int i = 0; i < 500; ++i) {
                    anio = 1977 + rand() % (2004 - 1977 + 1);
                    mes = 1 + rand() % 12;
                    dia = 1 + rand() % 25;
                    dni = 45000000 + rand() % (45155444 - 45000000 + 1);
                    darDeAltaEstudiante(&listaEstudiantes, &listaEstudiantesNombre,
                                        nombres[i], apellidos[i], anio, mes,
                                        dia, dni);
                }
                for (int i = 0; i < 45; ++i) {
                    cargarMateria(&listaDeMaterias, arregloMaterias[i], i + 1);
                }
                for (int i = 0; i < 100; ++i) {
                    estudiantePrueba = buscarEstudiantePorNombreCompleto(listaEstudiantesNombre, nombres[i], apellidos[i]);
                    for (int j = 0; j < 10; ++j) {
                        materiaPrueba = obtenerMateriaPorNombre(&listaDeMaterias, arregloMaterias[j]);
                        anotarEstudianteAMateria(materiaPrueba, estudiantePrueba);
                        if (j < 7) {
                            nota = rand() % 10;
                            cargarNotaAMateria(arregloMaterias[j], estudiantePrueba, nota);
                        }
                    }
                }
                for (int i = 100; i < 200; ++i) {
                    estudiantePrueba = buscarEstudiantePorNombreCompleto(listaEstudiantesNombre, nombres[i], apellidos[i]);
                    for (int j = 0; j < 17; ++j) {
                        materiaPrueba = obtenerMateriaPorNombre(&listaDeMaterias, arregloMaterias[j]);
                        anotarEstudianteAMateria(materiaPrueba, estudiantePrueba);
                        if (j < 13) {
                            nota = rand() % 10;
                            cargarNotaAMateria(arregloMaterias[j], estudiantePrueba, nota);
                        }
                    }
                }
                for (int i = 200; i < 300; ++i) {
                    estudiantePrueba = buscarEstudiantePorNombreCompleto(listaEstudiantesNombre, nombres[i], apellidos[i]);
                    for (int j = 0; j < 25; ++j) {
                        materiaPrueba = obtenerMateriaPorNombre(&listaDeMaterias, arregloMaterias[j]);
                        anotarEstudianteAMateria(materiaPrueba, estudiantePrueba);
                        if (j < 23) {
                            nota = rand() % 10;
                            cargarNotaAMateria(arregloMaterias[j], estudiantePrueba, nota);
                        }
                    }
                }
                for (int i = 300; i < 400; ++i) {
                    estudiantePrueba = buscarEstudiantePorNombreCompleto(listaEstudiantesNombre, nombres[i], apellidos[i]);
                    for (int j = 0; j < 30; ++j) {
                        materiaPrueba = obtenerMateriaPorNombre(&listaDeMaterias, arregloMaterias[j]);
                        anotarEstudianteAMateria(materiaPrueba, estudiantePrueba);
                        if (j < 27) {
                            nota = rand() % 10;
                            cargarNotaAMateria(arregloMaterias[j], estudiantePrueba, nota);
                        }
                    }
                }
                for (int i = 400; i < 500; ++i) {
                    estudiantePrueba = buscarEstudiantePorNombreCompleto(listaEstudiantesNombre, nombres[i], apellidos[i]);
                    for (int j = 0; j < 41; ++j) {
                        materiaPrueba = obtenerMateriaPorNombre(&listaDeMaterias, arregloMaterias[j]);
                        anotarEstudianteAMateria(materiaPrueba, estudiantePrueba);
                        if (j < 39) {
                            nota = rand() % 10;
                            cargarNotaAMateria(arregloMaterias[j], estudiantePrueba, nota);
                        }
                    }
                }
                materiaCargada = 1;
                break;
            case 14:
                printf("Nota: escribir primero el nombre, luego el apellido cuando sea indicado.\n");
                printf("Escribe el nombre del estudiante: ");
                getc(stdin);
                pedirDatoConFgets(nombre);
                printf("Escribe el apellido del estudiante: ");
                pedirDatoConFgets(apellido);
                if(listaEstudiantesNombre != NULL){
                    if (listaEstudiantesNombre->siguiente == NULL) {
                        listaEstudiantesNombre = NULL;
                        listaEstudiantes = NULL;
                    }else{
                        eliminarUnEstudiante(listaEstudiantes, listaEstudiantesNombre, nombre, apellido);
                    }
                }
                break;
            case 15:
                printf("Recorda que primero hay que guardar los datos para poder leerlos.");
                flujo= fopen(estudiantesUbi,"r");
                if(flujo == NULL){
                    perror("Error en la apertura del archivo");
                } else{
                    while(feof(flujo) == 0){

                        fscanf(flujo, "%s %s %i %i %i %i",nombre, apellido, &anio, &mes, &dia, &dni);
                        ponerEspacios(nombre);
                        ponerEspacios(apellido);
                        darDeAltaEstudiante(&listaEstudiantes, &listaEstudiantesNombre, nombre, apellido, anio, mes, dia, dni);
                    }
                }
                fclose(flujo);

                FILE *flujoMateria= fopen(materiasUbi,"r");
                if(flujoMateria == NULL){
                    perror("Error en la apertura del archivo");
                }else{
                    while(feof(flujoMateria) == 0){
                        fscanf(flujoMateria, "%s %i",materiaNombre, &id);
                        ponerEspacios(materiaNombre);
                        cargarMateria(&listaDeMaterias, materiaNombre,id);
                    }
                }
                fclose(flujoMateria);

                FILE *flujoMateriaEstudiante= fopen(materiasEstudiantesUbi,"r");
                if(flujoMateriaEstudiante == NULL){
                    perror("Error en la apertura del archivo");
                }else{
                    while(feof(flujoMateriaEstudiante) == 0){

                        fscanf(flujoMateriaEstudiante, "%s %s %s %s %i",materiaNombre, nombre, apellido, notaChar, &intententos);
                        ponerEspacios(materiaNombre);
                        ponerEspacios(nombre);
                        ponerEspacios(apellido);
                        nota = atof(notaChar);
                        estudiantePrueba = buscarEstudiantePorNombreCompleto(listaEstudiantesNombre, nombre, apellido);
                        materiaPrueba = obtenerMateriaPorNombre(&listaDeMaterias, materiaNombre);
                        if(estudiantePrueba != NULL && materiaPrueba != NULL){
                            anotarEstudianteAMateria(materiaPrueba, estudiantePrueba);
                            if(nota>-1 && intententos>0 && intententos<3){
                                cargarNotaAMateria(materiaNombre, estudiantePrueba, nota);
                                if(nota < 4){
                                    obtenerMateriaEstudiantePorNombre(&estudiantePrueba->materiasEnCurso, materiaNombre)->intentos = intententos;
                                }else{
                                    obtenerMateriaEstudiantePorNombre(&estudiantePrueba->materiasAprobadas, materiaNombre)->intentos = intententos;
                                }
                            }
                        }
                    }
                }
                fclose(flujoMateriaEstudiante);
                break;
            case 16:
                cargarArchivo(listaEstudiantes, listaEstudiantesNombre, listaDeMaterias,estudiantesUbi, materiasUbi, materiasEstudiantesUbi, materiaCargada);
                printf("Se guardaron los datos.\n");
                break;
            case 17:
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