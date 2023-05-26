#include "Multilista.h"

Multilista::Multilista() : primero(nullptr), ultimo(nullptr) {}

bool Multilista::vacia()
{
	return primero == nullptr;
}

void Multilista::insertarDelante(string cod, string nomb, int cant)
{
    NodoAsignatura* nodo = new NodoAsignatura(cod, nomb, cant);
    if (vacia()) {
        nodo->siguiente = nodo;
        primero = nodo;
        ultimo = nodo;
    }
    else {
        nodo->siguiente = primero;
        ultimo->siguiente = nodo;
        primero = nodo;
    }
}

void Multilista::mostrar()
{
    NodoAsignatura* p = primero;
    if (vacia())
        cout << "La multilista esta vacia." << endl;
    else {
        do {
            cout << endl << "Codigo: " << p->codigo << endl;
            cout << "Descripcion: " << p->descripcion << endl;
            cout << "Cantidad de horas: " << p->cantidad << endl;
            p = p->siguiente;
        } while (p != primero);
    }
}

void Multilista::eliminar(string valor)
{
    if (vacia()) {
        cout << "La multilista esta vacia. No se puede eliminar." << endl;
        return;
    }

    NodoAsignatura* anterior = nullptr;
    NodoAsignatura* actual = primero;

    while (actual != nullptr) {
        if (actual->codigo == valor)
            break;
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == nullptr) {
        std::cout << "No se encontro el codigo en la multilista." << std::endl;
        return;
    }

    if (actual == primero && actual == ultimo) {
        delete actual;
        primero = nullptr;
        ultimo = nullptr;
    }
    else if (actual == primero) {
        primero = actual->siguiente;
        ultimo->siguiente = primero;
        delete actual;
    }
    else if (actual == ultimo) {
        anterior->siguiente = primero;
        ultimo = anterior;
        delete actual;
    }
    else {
        anterior->siguiente = actual->siguiente;
        delete actual;
    }

    std::cout << "Se elimino el codigo de la multilista." << std::endl;
}

NodoAsignatura* Multilista::buscarAsignatura(string valor)
{
    if (vacia()) {
        cout << "La multilista esta vacia." << endl;
        return nullptr;
    }

    NodoAsignatura* p = primero;

    do {
        if (p->codigo == valor)
            return p;
        p = p->siguiente;
    } while (p != primero);

    cout << "No se encontro el codigo en la multilista." << endl;
    return nullptr;
}

void Multilista::insertarEstudiante(string codAsig, string codEst, string nomb, string dir, string sex)
{
    NodoAsignatura* asignatura = buscarAsignatura(codAsig);
    if (asignatura == nullptr) {
        cout << "No se encontro la asignatura en la multilista." << endl;
        return;
    }

    NodoEstudiante* nuevoEstudiante = new NodoEstudiante(codEst, nomb, dir, sex);
    if (asignatura->pestudiante == nullptr) {
        asignatura->pestudiante = nuevoEstudiante;
        nuevoEstudiante->siguiente = nuevoEstudiante;
    }
    else {
        NodoEstudiante* ultimoEstudiante = asignatura->pestudiante;
        while (ultimoEstudiante->siguiente != asignatura->pestudiante)
            ultimoEstudiante = ultimoEstudiante->siguiente;
        nuevoEstudiante->siguiente = asignatura->pestudiante;
        ultimoEstudiante->siguiente = nuevoEstudiante;
    }
    cout << "Estudiante insertado correctamente en la asignatura." << endl;
}

void Multilista::eliminarEstudiante(string valor1, string valor2)
{
    NodoAsignatura* asignatura = buscarAsignatura(valor1);
    if (asignatura == nullptr) {
        cout << "No se encontro la asignatura en la multilista." << endl;
        return;
    }

    NodoEstudiante* anterior = nullptr;
    NodoEstudiante* actual = asignatura->pestudiante;

    while (actual != nullptr) {
        if (actual->codigo == valor2)
            break;
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == nullptr) {
        cout << "No se encontro el estudiante en la asignatura." << endl;
        return;
    }

    if (actual == asignatura->pestudiante && actual->siguiente == asignatura->pestudiante) {
        delete actual;
        asignatura->pestudiante = nullptr;
    }
    else if (actual == asignatura->pestudiante) {
        asignatura->pestudiante = actual->siguiente;
        NodoEstudiante* ultimoEstudiante = asignatura->pestudiante;
        while (ultimoEstudiante->siguiente != actual)
            ultimoEstudiante = ultimoEstudiante->siguiente;
        ultimoEstudiante->siguiente = asignatura->pestudiante;
        delete actual;
    }
    else {
        anterior->siguiente = actual->siguiente;
        delete actual;
    }
    cout << "Se elimino el estudiante de la asignatura." << endl;
}

void Multilista::mostrarEstudiantes(string valor)
{
    NodoAsignatura* asignatura = buscarAsignatura(valor);
    if (asignatura == nullptr)
        return;

    cout << "Estudiantes de la asignatura " << asignatura->descripcion << ":" << endl;

    if (asignatura->pestudiante == nullptr) {
        cout << "No hay estudiantes registrados en esta asignatura." << endl;
        return;
    }

    NodoEstudiante* estudiante = asignatura->pestudiante;
    do {
        cout << "Codigo: " << estudiante->codigo << endl;
        cout << "Nombre: " << estudiante->nombre << endl;
        cout << "Direccion: " << estudiante->direccion << endl;
        cout << "Sexo: " << estudiante->sexo << endl;
        cout << endl;
        estudiante = estudiante->siguiente;
    } while (estudiante != asignatura->pestudiante);
}

void Multilista::mostrarTodo()
{
    if (vacia()) {
        cout << "La multilista esta vacia." << endl;
        return;
    }

    NodoAsignatura* p = primero;

    do {
        cout << "Codigo: " << p->codigo << endl;
        cout << "Descripcion: " << p->descripcion << endl;
        cout << "Cantidad de horas: " << p->cantidad << endl;
        cout << "Estudiantes: " << endl;

        if (p->pestudiante == nullptr) {
            cout << "No hay estudiantes registrados en esta asignatura." << endl;
        }
        else {
            NodoEstudiante* estudiante = p->pestudiante;
            do {
                cout << "   Codigo: " << estudiante->codigo << endl;
                cout << "   Nombre: " << estudiante->nombre << endl;
                cout << "   Direccion: " << estudiante->direccion << endl;
                cout << "   Sexo: " << estudiante->sexo << endl;
                cout << endl;
                estudiante = estudiante->siguiente;
            } while (estudiante != p->pestudiante);
        }

        p = p->siguiente;
    } while (p != primero);
}

int Multilista::cantidadEstudiantesAsignatura(string valor)
{
    int cantidadEstudiantes = 0;
    NodoAsignatura* p;
    NodoEstudiante* q;
    p = buscarAsignatura(valor);
    if (p == NULL) {
        cout << "No existe esa asignatura" << endl;
    }
    else {
        q = p->pestudiante;
        if (q == NULL) {
            cout << "No hay estudiantes en esta asignatura" << endl;
        }
        else {
            NodoEstudiante* temp = q;
            do {
                cantidadEstudiantes++;
                temp = temp->siguiente;
            } while (temp != q);
        }
    }
    return cantidadEstudiantes;
}

int Multilista::cantidadAsignaturas()
{
    int contador = 0;

    if (vacia())
        return contador;

    NodoAsignatura* p = primero;

    do {
        contador++;
        p = p->siguiente;
    } while (p != primero);

    return contador;
}

void Multilista::mostrarEstudiantesMasculinos()
{
    if (vacia()) {
        cout << "La multilista esta vacia." << endl;
        return;
    }

    NodoAsignatura* p = primero;

    do {
        cout << "Estudiantes masculinos de la asignatura " << p->descripcion << ":" << endl;

        if (p->pestudiante == nullptr) {
            std::cout << "No hay estudiantes registrados en esta asignatura." << endl;
        }
        else {
            NodoEstudiante* estudiante = p->pestudiante;
            do {
                if (estudiante->sexo == "M") {
                    cout << "Codigo: " << estudiante->codigo << endl;
                    cout << "Nombre: " << estudiante->nombre << endl;
                    cout << "Direccion: " << estudiante->direccion << endl;
                    cout << "Sexo: " << estudiante->sexo << endl;
                    cout << endl;
                }
                estudiante = estudiante->siguiente;
            } while (estudiante != p->pestudiante);
        }

        p = p->siguiente;
    } while (p != primero);
}

void Multilista::mostrarEstudiantesFemeninos()
{
    if (vacia()) {
        cout << "La multilista esta vacia." << endl;
        return;
    }

    NodoAsignatura* p = primero;

    do {
        cout << "Estudiantes femeninos de la asignatura " << p->descripcion << ":" << endl;

        if (p->pestudiante == nullptr) {
            std::cout << "No hay estudiantes registrados en esta asignatura." << endl;
        }
        else {
            NodoEstudiante* estudiante = p->pestudiante;
            do {
                if (estudiante->sexo == "F") {
                    cout << "Codigo: " << estudiante->codigo << endl;
                    cout << "Nombre: " << estudiante->nombre << endl;
                    cout << "Direccion: " << estudiante->direccion << endl;
                    cout << "Sexo: " << estudiante->sexo << endl;
                    cout << endl;
                }
                estudiante = estudiante->siguiente;
            } while (estudiante != p->pestudiante);
        }

        p = p->siguiente;
    } while (p != primero);
}

