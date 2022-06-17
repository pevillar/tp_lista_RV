##Sistema de estudiantes | TP Final AyP3
###Integrantes
Ignacio Nahuel Robledo Izu<br>
Pedro Liniel Villar

###Resolución
Para la realización de este trabajo se utililzaron los conceptos aprendidos
a lo largo de la cursada de la materia.
* Utilizamos estructuras para
los estudiantes y las materias
* implementamos una lista enlazada de estudiantes
que estan ordenados por nombre y otra ordenados por edad
* adaptamos la lilsta enlazada para cada tipo de materia
* trabajamos con punteros siempre que fuera necesario y posible para ocupar el
mínimo de memoria y no causar problemas
* imprimir datos por pantalla.

Otros conceptos que no vimos en la materia:
* trabajar con la libreria 'time.h'
* trabajar con un switch y fgets() para que el usuario interactue 
con el sistema

Con solo introducir algunos datos por consola, ell usuario del programa
podrá utilizar las siguientes funciones:
* Crear y listar estudiantes
* Buscar estudiantes por nombre
* Buscar estudiantes por rango de edad
* Crear y listar materias
* Anotarse en una materia
* Rendir una materia <br><br>

#####Puntos extras
Además implementamos algunos puntos extras para que el sistema sea mas completo,
así el usuario tambien puede:
* eliminar algun estudiante del sistema
* obtener estadísticas de cada materia (promedio de aprobados, y
nota promedio)
* obtener las materias en curso y las aprobadas de un estudiante especifico
* crear un caso de prueba que carga al sistema 500 estudiantes y los anota a
materias y con notas aleatorias
* asegurarse que se realizan comprobaciones de los datos ingresados.

Entre las comprobaciones trabajamos en las relacionadas con la
carga de datos y otras más conceptuales. Por ejemplo:
* comprueba que las fechas de nacimiento ingresadas en el sistema sean correctas
* que el número de dni esté en un rango adecuado
* las materias tienen un id unico
* un estudiante tiene 3 oportunidades para rendir la misma materia antes de 
volver a cursarla.