#pragma once
#include "Nodo.h"
#include <iostream>
#include <string>

using namespace std;

class NodoEstudiante : public Nodo
{
public:
    string nombre;
    string direccion;
    string sexo;
    NodoEstudiante* siguiente;
    NodoEstudiante* anterior;

    NodoEstudiante(string cod, string nom, string dir, string sex);
};

