cmake_minimum_required(VERSION 3.21)
project(tp_lista_RV)

set(CMAKE_C_STANDARD 11)

add_executable(lista
        lista.c)

add_executable(listaOrdenada
        listaOrdenada.c)

add_executable(estudiante
        estudiante.c)

#add_executable(prueba
#        prueba.c)

add_executable(estudiantePorNombre
        estudiantePorNombre.c)