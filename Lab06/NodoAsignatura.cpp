#include "NodoAsignatura.h"

NodoAsignatura::NodoAsignatura(string cod, string desc, int cant)
    : Nodo(cod), descripcion(desc), cantidad(cant), siguiente(nullptr), pestudiante(nullptr) {}