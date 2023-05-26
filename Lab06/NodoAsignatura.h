#pragma once

#include "Nodo.h"
#include "NodoEstudiante.h"
#include <iostream>
#include <string>

using namespace std;

class NodoAsignatura : public Nodo 
{
public:
    string descripcion;
    int cantidad;
    NodoAsignatura* siguiente;
    NodoEstudiante* pestudiante;

    NodoAsignatura(string cod, string desc, int cant);
};