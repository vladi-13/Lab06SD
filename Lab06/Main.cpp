#include <iostream>
#include <string>
#include "Multilista.h"

using namespace std;

int main() {
    Multilista multilista;
    int opc;
    string cod, nombre, codest, nombreest, direst, sexo;
    int cant;
    string c, c1;

    do {
        system("cls");
        cout << "LISTA DE ASIGNATURAS" << endl;
        cout << "Seleccione la opcion a realizar" << endl;
        cout << "1.- Insertar una asignatura" << endl;
        cout << "2.- Eliminar una asignatura" << endl;
        cout << "3.- Mostrar toda la lista de asignaturas" << endl;
        cout << "4.- Insertar un estudiante en una asignatura" << endl;
        cout << "5.- Eliminar un estudiante" << endl;
        cout << "6.- Mostrar todos los estudiantes de una asignatura" << endl;
        cout << "7.- Mostrar toda la multilista" << endl;
        cout << "8.- Cantidad de estudiantes en una determinada asignatura" << endl;
        cout << "9.- Cuantas asignaturas se imparten" << endl;
        cout << "10.- Mostrar todos los estudiantes del sexo masculino" << endl;
        cout << "11.- Mostrar todos los estudiantes del sexo femenino" << endl;
        cout << "12.- Salir" << endl;
        cout << "Opcion (1-12): ";
        cin >> opc;

        switch (opc) {
        case 1:
            cod = "";
            nombre = "";
            cant = 0;
            cout << "Ingrese los datos de la asignatura:" << endl;
            cout << "Codigo o siglas de la asignatura: ";
            cin >> cod;
            cin.ignore();
            cout << "Nombre de la asignatura: ";
            getline(cin, nombre);
            cout << "Cantidad de horas: ";
            cin >> cant;
            multilista.insertarDelante(cod, nombre, cant);
            cout << "Presione una tecla para continuar";
            cin.ignore();
            cin.ignore();
            break;

        case 2:
            cout << "Ingrese el codigo de la asignatura a eliminar: ";
            cin >> c;
            multilista.eliminar(c);
            cout << "Presione una tecla para continuar";
            cin.ignore();
            cin.ignore();
            break;

        case 3:
            multilista.mostrar();
            cout << "Presione una tecla para continuar";
            cin.ignore();
            cin.ignore();
            break;

        case 4:
            cout << "Ingrese los datos de la asignatura y del estudiante:" << endl;
            cout << "Codigo o siglas de la asignatura: ";
            cin >> cod;
            cout << "Identificador del estudiante: ";
            cin >> codest;
            cout << "Nombre del estudiante: ";
            cin >> nombreest;
            cin.ignore();
            cout << "Direccion del estudiante: ";
            getline(cin, direst);
            cout << "Sexo del estudiante(M/F): ";
            cin >> sexo;
            multilista.insertarEstudiante(cod, codest, nombreest, direst, sexo);
            cout << "Presione una tecla para continuar";
            cin.ignore();
            cin.ignore();
            break;

        case 5:
            cout << "Ingrese el codigo de la asignatura que cursa el estudiante: ";
            cin >> c;
            cout << "Ingrese el codigo del estudiante: ";
            cin >> c1;
            multilista.eliminarEstudiante(c, c1);
            cout << "Presione una tecla para continuar";
            cin.ignore();
            cin.ignore();
            break;

        case 6:
            cout << "Ingrese el codigo de la asignatura para mostrar sus estudiantes: ";
            cin >> c;
            multilista.mostrarEstudiantes(c);
            cout << "Presione una tecla para continuar";
            cin.ignore();
            cin.ignore();
            break;

        case 7:
            multilista.mostrarTodo();
            cout << "Presione una tecla para continuar";
            cin.ignore();
            cin.ignore();
            break;

        case 8:
            cout << "Ingrese el codigo de la asignatura para obtener la cantidad de estudiantes: ";
            cin >> c;
            cout << "Cantidad de estudiantes en la asignatura " << c << ": " << multilista.cantidadEstudiantesAsignatura(c) << endl;
            cout << "Presione una tecla para continuar";
            cin.ignore();
            cin.ignore();
            break;

        case 9:
            cout << "Cantidad de asignaturas impartidas: " << multilista.cantidadAsignaturas() << endl;
            cout << "Presione una tecla para continuar";
            cin.ignore();
            cin.ignore();
            break;

        case 10:
            cout << "Estudiantes del sexo masculino:" << endl;
            multilista.mostrarEstudiantesMasculinos();
            cout << "Presione una tecla para continuar";
            cin.ignore();
            cin.ignore();
            break;

        case 11:
            cout << "Estudiantes del sexo femenino:" << endl;
            multilista.mostrarEstudiantesFemeninos();
            cout << "Presione una tecla para continuar";
            cin.ignore();
            cin.ignore();
            break;

        case 12:
            exit(0);
            break;
        }

    } while (opc != 12);

    return 0;
}
