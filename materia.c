#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Materia {
    struct Materia *siguienteMateria;
    char *nombre;
    int cantDeAprobados;
    int cantDeEstudiantes;
    int cantDeEstudiantesRendieron;
    double notas;
    int numero;
} Materia;

int tamanioMateria = 0;

/**
 * Devuelve la materia correspondiente al 'id' de la materia.
 * @param listaMateria
 * @param valor
 * @return
 */
Materia *obtenerElementoPorValor(Materia **listaMateria, int valor){
    Materia *materia = *listaMateria;
    while(materia->numero < valor && materia->siguienteMateria != NULL){
        materia = materia->siguienteMateria;
    }
    if(materia->numero == valor){
        return materia;
    }
    return NULL;
}

/**
 * Devuelve la materia con el nombre pasado como parametro.
 * @param listaMateria
 * @param nombre
 * @return
 */
Materia *obtenerMateriaPorNombre(Materia **listaMateria, char *nombre){
    Materia *materia = *listaMateria;
    while((materia->siguienteMateria != NULL)
          && strcmp(materia->nombre, nombre) != 0){
        materia = materia->siguienteMateria;
    }
    if (strcmp(materia->nombre, nombre) != 0) {
        return NULL;
    } else {
        return materia;
    }
}

/**
 * Inicializa una materia con los valores por defecto.
 * @param nombre
 * @param numero
 * @return
 */
Materia *crearMateria(char *nombre, int numero){
    Materia *materia = (Materia*) malloc(sizeof (Materia));
    materia -> notas = 0;
    materia -> numero = numero;
    materia -> cantDeAprobados = 0;
    materia -> cantDeEstudiantes = 0;
    materia -> cantDeEstudiantesRendieron = 0;
    materia -> siguienteMateria = NULL;
    materia -> nombre = nombre;
    return materia;
}

/**
 * Se agregan los datos a la materia correspondiente.
 * @param materia
 * @param nombre
 * @param numero
 */
void cargarDatosMateria(Materia **materia, char * nombre, int numero){
    Materia  *nuevoMateria = crearMateria(nombre, numero);
    Materia  *cursor = *materia;
    if ((cursor == NULL) || (numero < cursor->numero)){
        nuevoMateria->siguienteMateria = *materia;
        *materia = nuevoMateria;
    } else {
        while ((cursor->siguienteMateria != NULL) && (numero > cursor->siguienteMateria->numero)){
            cursor = cursor->siguienteMateria;
        }
        if (cursor->siguienteMateria != NULL){
            nuevoMateria->siguienteMateria = cursor->siguienteMateria;
        }
        cursor->siguienteMateria = nuevoMateria;
    }
    tamanioMateria++;
}

/**
 * Se agrega la materia a la lista de materias haciendo las
 * comprobaciones necesarias.
 * @param materia
 * @param nombre
 * @param numero
 */
void agregarMateria(Materia **materia, char * nombre, int numero){
    if(*materia != NULL){
        Materia *pruebaNombre = obtenerMateriaPorNombre(materia, nombre);
        Materia *pruebaNumero = obtenerElementoPorValor(materia,numero);
        if(pruebaNombre == NULL && pruebaNumero == NULL){
            cargarDatosMateria(materia, nombre, numero);
        }else{
            printf("Error al cargar los datos de la materia.\n"
                   "Revisar sino exite una materia con este mismo nombre o con este ID.\n");
        }
    }else{
        cargarDatosMateria(materia, nombre, numero);
    }
}

/**
 * Imprime por pantalla el promedio de estudiantes que aprobaron la materia.
 * @param materia
 */
void obtenerPromedioDeAprobados(Materia *materia){
    double promedioDeAprobados = (materia->cantDeAprobados*100.0)/materia->cantDeEstudiantesRendieron;
    printf("El promedio de aprobacion es del %.2f%\n", promedioDeAprobados);
}

/**
 * Imprime por pantalla la nota promedio de la materia
 * @param materia
 */
void obtenerNotaPromedio(Materia *materia){
    double notaPromedio = (materia->notas*10.0)/(materia->cantDeEstudiantesRendieron*10.0);
    printf("La nota promedio en es %.2f\n", notaPromedio);
}

/**
 * Imprime por pantalla todas la mataerias cargadas al sistema.
 * @param listaMateria
 */
void imprimirMaterias(Materia *listaMateria) {
    while (listaMateria != NULL) {
        printf("%d - %s\n", listaMateria->numero, listaMateria->nombre);
        listaMateria = listaMateria->siguienteMateria;
    }
}