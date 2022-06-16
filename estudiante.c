#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "materiaEstudiante.c"

typedef struct Estudiante {
    struct Estudiante *siguiente;
    MateriaEstudiante *materiasEnCurso;
    MateriaEstudiante *materiasAprobadas;
    int dni;
    char* nombre;
    char* apellido;
    int edad;
    char* fechaDeNacimiento;

} Estudiante;

int tamanio = 0;

//no se usa un puntero devido a que el valor del entero se va cambiando para encontra el len
int lenInt(int integer){
    int count = 0;
    while(integer>10){
        integer /= 10;
        count++;
    }
    count ++;
    return count;
}

int ComprobarDni(int *dni) {
    //lenInt devuelve 1 si el numero es negativo
    if(lenInt(*dni) == 8){
        return 1;
    }
    printf("el dni tiene un valor invalido\nRecuerde que el DNI cuenta con 8 numeros. Ingrese el dni: ");
    scanf("%i", dni);
    return 0;
}

int bisiento(int *anio){
    if ( *anio % 4 == 0 && *anio % 100 != 0 || *anio % 400 == 0 )  {
        return 1;
    }else{
        return 0;
    }
}

int comprobarDia(int *mes, int *dia, int *anio) {
    if(*mes == 2 && *dia<=28){
        return 1;
    }else if(*mes == 2 && *dia == 29 && bisiento(anio) == 1){
        return 1;
    }
    if((*mes == 4 || *mes == 6 || *mes == 9 || *mes == 11) && *dia <= 30){
        return 1;
    }
    if((*mes == 1 || *mes == 3 || *mes == 5 || *mes == 7 || *mes == 8 || *mes == 10 || *mes == 12) && *dia <= 31){
        return 1;
    }
    return 0;
}

int comprobarNacimiento(struct tm *fechaActual, int *anio, int *mes, int *dia) {
    if(*anio<1950 || *anio>fechaActual->tm_year+1900-18){
        printf("El a%co esta mal escrito\nRecuerde que debe de estar entre 1950 y %i. Ingreselo nuevamente: ", 164 , fechaActual->tm_year+1900-18);
        scanf("%i", anio);
        return 0;
    }
    if(*mes<=0 || *mes>12){
        printf("El mes esta mal escrito. Igreselo nuevamente: ");
        scanf("%i", mes);
        return 0;
    }
    if(comprobarDia(mes,dia,anio) == 0){
        printf("El dia esta mal escrito. Ingreselo nuevamente");
        scanf("%i", dia);
        return 0;
    }
    return 1;
}

/**
 * Inicializa un Estudiante con su valor pasado como parametro, y 'siguiente'
 * referenciando a 'NULL'.
 * @param valor
 * @return
 */
Estudiante *crearEstudiante(char* nombre, char* apellido, int edad, int dni, char* nacimiento){
    Estudiante *estudiante = (Estudiante*) malloc(sizeof(Estudiante));
    estudiante->materiasEnCurso = NULL;
    estudiante->materiasAprobadas = NULL;
    estudiante->nombre = nombre;
    estudiante->apellido = apellido;
    estudiante->edad = edad;
    estudiante->dni = dni;
    estudiante->fechaDeNacimiento = nacimiento;
    estudiante->siguiente = NULL;
    return estudiante;
}


char* obtenerNacimiento( int *anio, int *mes, int *dia){
    char* nacimiento = (char*)calloc(10,sizeof(char));
    char year[5];
    char day[2];
    char month[2];
    sprintf(day, "%i", *dia);
    strcat(nacimiento, day);
    strcat(nacimiento, "-");
    sprintf(month, "%i", *mes);
    strcat(nacimiento, month);
    strcat(nacimiento, "-");
    sprintf(year, "%i", *anio);
    strcat(nacimiento,year);
    return nacimiento;
}

int obtenerEdad(struct tm *fechaActual, int *anio,int *mes, int *dia) {
    int edad = fechaActual->tm_year+1900-*anio;
    if(fechaActual->tm_mon+1-*mes<0){
        edad--;
    }else if(fechaActual->tm_mday-*dia<0){
        edad--;
    }
    return edad;
}

/**
 * Agrega un nuevo elemento de tipo 'Estudiante' a la lista ordenado de forma
 * creciente segun su valor introducido.
 * @param lista
 * @param edad
 */
Estudiante *agregar(Estudiante **lista, char* nombre, char* apellido,  int anio, int mes, int dia, int dni){
    time_t fecha = time(NULL);
    struct tm fechaActual = *localtime(&fecha);
    while(comprobarNacimiento(&fechaActual, &anio, &mes, &dia)==0);
    while(ComprobarDni(&dni) == 0);
    char *nacimiento = obtenerNacimiento(&anio, &mes, &dia);
    int edad = obtenerEdad(&fechaActual,&anio,&mes,&dia);
    Estudiante *nuevoEstudiante = crearEstudiante(nombre, apellido, edad, dni, nacimiento);
    Estudiante *cursor = *lista;

    if ((cursor == NULL) || (edad < cursor->edad)){
        nuevoEstudiante->siguiente = *lista;
        *lista = nuevoEstudiante;
    } else {
        while ((cursor->siguiente != NULL) && (edad > cursor->siguiente->edad)){
            cursor = cursor->siguiente;
        }
        if (cursor->siguiente != NULL){
            nuevoEstudiante->siguiente = cursor->siguiente;
        }
        cursor->siguiente = nuevoEstudiante;
    }
    tamanio++;
    return nuevoEstudiante;
}

void imprimirEstudiante(Estudiante *estudiante){
    printf("\nApellido: %s\n", estudiante->apellido);
    printf("Nombre: %s\n", estudiante->nombre);
    printf("edad: %i\n", estudiante->edad);
    printf("dni: %i\n", estudiante->dni);
    printf("fecha de nacimiento: %s\n", estudiante->fechaDeNacimiento);
    printf("------------------------------------------");
}

void imprimirMateriasEnCurso(Estudiante *estudiante){
    if(estudiante->materiasEnCurso != NULL) {
        printf("\nMaterias Cursando: \n");
        imprimirMateriasEstudiante(estudiante->materiasEnCurso);
    }else{
        printf("el estudiante %S %S no esta cursando ninguna materia.", estudiante->nombre, estudiante->apellido);
    }
}

void imprimirMateriasAprobadas(Estudiante *estudiante){
    if(estudiante->materiasAprobadas != NULL) {
        printf("Materias Aprobadas: \n");
        imprimirMateriasAprobadasEstudiante(estudiante->materiasAprobadas);
    }else{
        printf("el estudiante %S %S no ha aprobado ninguna materia.", estudiante->nombre, estudiante->apellido);
    }
}

void imprimirTodasLasMaterias(Estudiante *estudiante){
    imprimirMateriasEnCurso(estudiante);
    imprimirMateriasAprobadas(estudiante);
}

void imprimir(Estudiante *lista) {
    while (lista != NULL) {
        imprimirEstudiante(lista);
        lista = lista->siguiente;
    }
    printf("\n");
}

/**
 * Se obtiene el elemento en la posicion pasada como parametro.
 * @param lista
 * @param posicion: debe estar entre los valores 1 y tamanio de la lista
 * @return: nodo en la posicion (parametro)
 */
Estudiante obtenerEstudiante(Estudiante **lista, int posicion){
    Estudiante *estudiante = *lista;
    if(posicion>0 && posicion<=tamanio){
        for (int i = 0; i < (posicion - 1); ++i) {
            estudiante = estudiante->siguiente;
        }
        return *estudiante;
    }
}

/**
 * Se obtiene el estudiante con la edad pasada como parametro.
 * @param lista
 * @param edad: edad del estudiante a buscar.
 * @return: nodo en la posicion (parametro)
 */
Estudiante *obtenerEstudiantePorEdad(Estudiante **lista, int edad, int dni){
    Estudiante *estudiante = *lista;
    while(estudiante->edad != edad){
        if(estudiante->siguiente == NULL){
            printf("No se encontro al estudiante\n");
            estudiante = NULL;
            break;
        }
        estudiante = estudiante->siguiente;
    }
    while(estudiante->edad == edad && estudiante->dni != dni){
        if(estudiante->siguiente == NULL){
            printf("No se encontro al estudiante\n");
            estudiante = NULL;
            break;
        }
        estudiante = estudiante->siguiente;
    }
    return estudiante;
}

/**
 * Se obtiene el elemento con el edad pasado como parametro.
 * @param lista
 * @param edad: edad del estudiante a buscar.
 * @return: nodo en la posicion (parametro)
 */
void obtenerEstudiantePorRangoDeEdad(Estudiante **lista, int edadMinima, int edadMaxima){
    Estudiante *estudiante = *lista;
    while(estudiante->edad < edadMinima){
        if(estudiante->siguiente == NULL){
            printf("No se encontro un estudiante en este rango\n");
            estudiante = NULL;
            break;
        }
        estudiante = estudiante->siguiente;
    }
    while(estudiante->edad <= edadMaxima){
        imprimirEstudiante(estudiante);
        printf("\n\n");
        if(estudiante->siguiente == NULL){
            break;
        }
        estudiante = estudiante->siguiente;
    }
}

void agregarMateriaAprobada(MateriaEstudiante *materiaAprobada, Estudiante *estudiante) {
    agregarMateriaEstudianteAprobada(&estudiante->materiasAprobadas, materiaAprobada->materia, materiaAprobada->nota, materiaAprobada->intentos);
}

void anotarEstudianteAMateria(Materia *materia, Estudiante *estudiante) {
    agregarMateriaEstudiante(&estudiante->materiasEnCurso, materia);
}

void cargarNotaAMateria(char *nombreMateria, Estudiante *estudiante, int nota) {
    if(estudiante->materiasEnCurso != NULL){
        MateriaEstudiante *materiaBuscada = obtenerMateriaEstudiantePorNombre(&estudiante->materiasEnCurso, nombreMateria);
        if(materiaBuscada != NULL){
            cargarNota(materiaBuscada, nota);
            if(materiaBuscada->intentos <= 3 && materiaBuscada->aprobado == 1){
                agregarMateriaAprobada(materiaBuscada, estudiante);
                borrarMateriaEstudiantePorNombre(estudiante->materiasEnCurso, materiaBuscada->materia->nombre);
            }else if(materiaBuscada->intentos == 3){
                borrarMateriaEstudiantePorNombre(estudiante->materiasEnCurso, materiaBuscada->materia->nombre);
            }
        }
    }else{
        printf("El estudiante %s %s no esta cursando ninguna materia.", estudiante->nombre, estudiante->apellido);
    }
}

/**
 * Elimina el elemento en la posicion pasada como parametro
 * @param lista
 * @param posicion: entre los valores 1 y 'tamanio' de lista
 */
void borrarXEstudiante(Estudiante *lista, int posicion) {
    Estudiante *estudiante = lista;
    Estudiante *aEliminar;
    if(posicion>0 && posicion<=tamanio){
        for (int i = 0; i < (posicion - 1); ++i) {
            estudiante = estudiante->siguiente;
        }
        aEliminar = estudiante->siguiente;
        estudiante->siguiente = estudiante->siguiente->siguiente;
        free(aEliminar);
    }
    tamanio--;
}

/**
 * Elimina el elemento en la posicion pasada como parametro
 * @param lista
 * @param posicion: entre los valores 1 y 'tamanio' de lista
 */
void borrarEstudiantePorEdad(Estudiante *lista, int edad, int dni) {
    Estudiante *estudiante = lista;
    Estudiante *aEliminar;
    while(estudiante->siguiente->edad<edad){
        if(estudiante->siguiente == NULL){
            printf("No se encontro al estudiante\n");
            break;
        }
        estudiante = estudiante->siguiente;
    }
    while(estudiante->siguiente->edad == edad && estudiante->siguiente->dni != dni){
        if(estudiante->siguiente == NULL){
            printf("No se encontro al estudiante\n");
            break;
        }
        estudiante = estudiante->siguiente;
    }
    aEliminar = estudiante->siguiente;
    estudiante->siguiente = estudiante->siguiente->siguiente;
    free(aEliminar);
    tamanio--;
}

void borrarPrimerEstudianteEdad(Estudiante *listaNombre) {
    if (listaNombre->siguiente != NULL) {
        *listaNombre = *listaNombre->siguiente;
        tamanio--;
    } else {
        listaNombre = NULL;
        tamanio--;
    }
}

int compararNombres(Estudiante *estudiante1, Estudiante *estudiante2){
    if (strcmp(estudiante1->apellido, estudiante2->apellido) == 0){
        return strcmp(estudiante1->nombre, estudiante2->nombre);
    } else {
        return strcmp(estudiante1->apellido, estudiante2->apellido);
    }
}

void borrarEstudiantePorNombreEdad(Estudiante *listaNombre, char *nombre, char *apellido) {
    Estudiante *estudiante = listaNombre;
    Estudiante *estudiante2
            = crearEstudiante(nombre, apellido, 20, 45781369, "2-4-2002");
    if (compararNombres(estudiante, estudiante2) == 0){
        borrarPrimerEstudianteEdad(listaNombre);
    } else {
        Estudiante *aEliminar;
        while ((estudiante->siguiente != NULL)
               && (compararNombres(estudiante->siguiente, estudiante2)) != 0) {
            estudiante = estudiante->siguiente;
        }
        if ((estudiante->siguiente == NULL) ||
            compararNombres(estudiante->siguiente, estudiante2) != 0) {
            printf("El estudiante: %s %s, no existe en el sistema.", nombre, apellido);
        } else {
            aEliminar = estudiante->siguiente;
            estudiante->siguiente = estudiante->siguiente->siguiente;
            free(aEliminar);
            tamanio--;
        }
    }
    free(estudiante2);
}