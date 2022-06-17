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

/**
 * Verifica que el dni tenga 8 digitos.
 * @param dni
 * @return
 */
int ComprobarDni(int *dni) {
    //lenInt devuelve 1 si el numero es negativo
    if(lenInt(*dni) == 8){
        return 1;
    }
    printf("el dni tiene un valor invalido\nRecuerde que el DNI cuenta con 8 numeros. Ingrese el dni: ");
    scanf("%i", dni);
    return 0;
}

/**
 * Comprueba si el anio es o no bisiesto.
 * @param anio
 * @return
 */
int bisiento(int *anio){
    if ( *anio % 4 == 0 && *anio % 100 != 0 || *anio % 400 == 0 )  {
        return 1;
    }else{
        return 0;
    }
}

/**
 * Verifica el dia sea correcta dependiendo el mes.
 * @param mes
 * @param dia
 * @param anio
 * @return
 */
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

/**
 * Verifica la fecha de nacimiento ingresada.
 * @param fechaActual
 * @param anio
 * @param mes
 * @param dia
 * @return
 */
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
 * Inicializa un Estudiante con todos sus
 * datos y las listas de materias en NULL.
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

/**
 * Devuelve una cadena de caracteres con la fecha de nacimiento.
 * @param anio
 * @param mes
 * @param dia
 * @return
 */
char* obtenerNacimiento( int *anio, int *mes, int *dia){
    char* nacimiento = (char*)calloc(10,sizeof(char));
    char year[5];
    char day[2];
    char month[2];
    sprintf(year, "%i", *anio);
    strcat(nacimiento, year);
    strcat(nacimiento, "-");
    sprintf(month, "%i", *mes);
    strcat(nacimiento, month);
    strcat(nacimiento, "-");
    sprintf(day, "%i", *dia);
    strcat(nacimiento,day);
    return nacimiento;
}

/**
 * Calcula la edad del estudiante.
 * @param fechaActual
 * @param anio
 * @param mes
 * @param dia
 * @return
 */
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
 * creciente segun la edad del mismo.
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

/**
 * Imprime por pantalla los datos de un estudiante.
 * @param estudiante
 */
void imprimirEstudiante(Estudiante *estudiante){
    printf("\nApellido: %s\n", estudiante->apellido);
    printf("Nombre: %s\n", estudiante->nombre);
    printf("edad: %i\n", estudiante->edad);
    printf("dni: %i\n", estudiante->dni);
    printf("fecha de nacimiento: %s\n", estudiante->fechaDeNacimiento);
    printf("------------------------------------------\n");
}

/**
 * Imprime materias en curso del estudiante, es decir, que aun no rindio.
 * @param estudiante
 */
void imprimirMateriasEnCurso(Estudiante *estudiante) {
    printf("\nMaterias Cursando: \n");
    if(estudiante->materiasEnCurso != NULL) {
        imprimirMateriasEstudiante(estudiante->materiasEnCurso);
    }else{
        printf("el estudiante %s %s no esta cursando ninguna materia.\n", estudiante->nombre, estudiante->apellido);
    }
}

void imprimirMateriasAprobadas(Estudiante *estudiante){
    printf("Materias Aprobadas: \n");
    if(estudiante->materiasAprobadas != NULL) {
        imprimirMateriasAprobadasEstudiante(estudiante->materiasAprobadas);
    }else{
        printf("el estudiante %S %S no ha aprobado ninguna materia.", estudiante->nombre, estudiante->apellido);
    }
}

void imprimirTodasLasMaterias(Estudiante *estudiante){
    imprimirMateriasEnCurso(estudiante);
    imprimirMateriasAprobadas(estudiante);
}


/**
 * Imprime todos los datos de cada uno de los estudiantes en la lista.
 * @param lista
 */
void imprimir(Estudiante *lista) {
    while (lista != NULL) {
        imprimirEstudiante(lista);
        lista = lista->siguiente;
    }
    printf("\n");
}

/**
 * Se obtiene el estudiante dentro del rango de edad pasado como parametro.
 * @param lista
 * @param edadMinima
 * @param edadMaxima
 * @return
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

/**
 * Agrega a la lista de materias aprobadas por el estudiante.
 * @param materia
 * @param estudiante
 */
void agregarMateriaAprobada(MateriaEstudiante *materiaAprobada, Estudiante *estudiante) {
    agregarMateriaEstudianteAprobada(&estudiante->materiasAprobadas, materiaAprobada->materia, materiaAprobada->nota, materiaAprobada->intentos);
}

/**
 * Inscribir un estudiante a una materia.
 * @param materia
 * @param estudiante
 */
void anotarEstudianteAMateria(Materia *materia, Estudiante *estudiante) {
    if(estudiante->materiasEnCurso != NULL){
        MateriaEstudiante *materiaPruebaCurso =  obtenerMateriaEstudiantePorNombre(&estudiante->materiasEnCurso, materia->nombre);
        if(estudiante->materiasAprobadas != NULL){
            MateriaEstudiante *materiaPruebaAprobada = obtenerMateriaEstudiantePorNombre(&estudiante->materiasAprobadas, materia->nombre);
            if(materiaPruebaAprobada == NULL && materiaPruebaCurso == NULL){
                agregarMateriaEstudiante(&estudiante->materiasEnCurso, materia);
            }else{
                if(materiaPruebaAprobada != NULL && materiaPruebaCurso != NULL){
                    printf("Error");
                }else if(materiaPruebaCurso == NULL){
                    printf("No podes anotarte a %s, porque ya la aprobaste.\n", materia->nombre);
                }else{
                    printf("No podes anotarte a %s, porque ya la estas cursando.\n", materia->nombre);
                }
            }
        }else{
            if(materiaPruebaCurso == NULL){
                agregarMateriaEstudiante(&estudiante->materiasEnCurso, materia);
            } else{
                printf("No podes anotarte a %s, porque ya la estas cursando.\n", materia->nombre);
            }
        }
    } else{
        agregarMateriaEstudiante(&estudiante->materiasEnCurso, materia);
    }
}

/**
 * Se agrega del estudiante en la materia correspondiente.
 * @param nombreMateria
 * @param estudiante
 * @param nota
 */
void cargarNotaAMateria(char *nombreMateria, Estudiante *estudiante, double nota) {
    if(estudiante->materiasEnCurso != NULL){
        MateriaEstudiante *materiaBuscada = obtenerMateriaEstudiantePorNombre(&estudiante->materiasEnCurso, nombreMateria);
        if(materiaBuscada != NULL){
            cargarNota(materiaBuscada, nota);
            if(materiaBuscada->intentos <= 3 && materiaBuscada->aprobado == 1){
                agregarMateriaAprobada(materiaBuscada, estudiante);
                if (estudiante->materiasEnCurso->siguienteMateriaEstudiante == NULL) {
                    estudiante->materiasEnCurso = NULL;
                }else{
                    borrarMateriaEstudiantePorNombre(estudiante->materiasEnCurso, materiaBuscada->materia->nombre);
                }
            }else if(materiaBuscada->intentos == 3){
                printf("Ya no te quedan intentos para cursar %s. Vuelve a intentarlo de nuevo.\n", nombreMateria);
                if (estudiante->materiasEnCurso->siguienteMateriaEstudiante == NULL) {
                    estudiante->materiasEnCurso = NULL;
                }else{
                    borrarMateriaEstudiantePorNombre(estudiante->materiasEnCurso, materiaBuscada->materia->nombre);
                }
            }
        }else{
            printf("La materia: %s, no la esta cursando el estudiante.\n", nombreMateria);
        }
    }else{
        printf("El estudiante %s %s no esta cursando ninguna materia.", estudiante->nombre, estudiante->apellido);
    }
}

/**
 * Elimina el primer estudiante de la lista.
 * @param listaNombre
 */
void borrarPrimerEstudianteEdad(Estudiante *listaNombre) {
    if (listaNombre->siguiente != NULL) {
        *listaNombre = *listaNombre->siguiente;
        tamanio--;
    } else {
        listaNombre = NULL;
        tamanio--;
    }
}

/**
 * Compara alfabeticamente los nombres completos de dos estudiantes.
 * @param estudiante1
 * @param estudiante2
 * @return
 */
int compararNombres(Estudiante *estudiante1, Estudiante *estudiante2){
    if (strcmp(estudiante1->apellido, estudiante2->apellido) == 0){
        return strcmp(estudiante1->nombre, estudiante2->nombre);
    } else {
        return strcmp(estudiante1->apellido, estudiante2->apellido);
    }
}

/**
 * Elimina el estudiante con el nombre correspondiente.
 * @param listaNombre
 * @param nombre
 * @param apellido
 */
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