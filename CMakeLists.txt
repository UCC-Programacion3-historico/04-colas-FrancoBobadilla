cmake_minimum_required(VERSION 3.2)
project(04_Cola)

set(CMAKE_CXX_STANDARD 11)

# Agrego todos los test.
add_subdirectory(test)

set(SOURCE_FILES_01 Ej-01/main.cpp Cola/Cola.h Cola/Nodo.h Cola/Pila.h)
add_executable(Ej-01 ${SOURCE_FILES_01})

set(SOURCE_FILES_02 Ej-02/main.cpp)
add_executable(Ej-02 ${SOURCE_FILES_02})

set(SOURCE_FILES_03 Ej-03/main.cpp Ej-03/NodoPrior.h Ej-03/ColaPrior.h)
add_executable(Ej-03 ${SOURCE_FILES_03})

set(SOURCE_FILES_04 Ej-04/main.cpp)
add_executable(Ej-04 ${SOURCE_FILES_04})

set(SOURCE_FILES_05 Ej-05/main.cpp)
add_executable(Ej-05 ${SOURCE_FILES_05})
