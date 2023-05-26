#include "NodoEstudiante.h"

NodoEstudiante::NodoEstudiante(string cod, string nom, string dir, string sex)
    : Nodo(cod), nombre(nom), direccion(dir), sexo(sex), siguiente(nullptr), anterior(nullptr) {}