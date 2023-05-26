#pragma once

#include "NodoAsignatura.h"
#include "NodoEstudiante.h"
#include <iostream>
#include <string>

using namespace std;

class Multilista
{
private:
    NodoAsignatura* primero;
    NodoAsignatura* ultimo;


public:
    Multilista();
    bool vacia();
    void insertarDelante(string cod, string nomb, int cant);
    void mostrar();
    void eliminar(string valor);
    NodoAsignatura* buscarAsignatura(string valor);
    void insertarEstudiante(string codAsig, string codEst, string nomb, string dir, string sex);
    void eliminarEstudiante(string valor1, string valor2);
    void mostrarEstudiantes(string valor);
    void mostrarTodo();
    int cantidadEstudiantesAsignatura(string valor);
    int cantidadAsignaturas();
    void mostrarEstudiantesMasculinos();
    void mostrarEstudiantesFemeninos();
};

