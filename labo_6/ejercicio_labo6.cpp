#include <iostream>
#include <string>
using namespace std;

// estructura
struct Direccion {
    string calle;
    int numero;
    string ciudad;
};

struct Estudiante {
    string nombre;
    int edad;
    float calificaciones[5];
    Direccion direccion;
};

void ingresarEstudiantes(Estudiante* estudiantes, int cantidad);
void mostrarEstudiantes(Estudiante* estudiantes, int cantidad);
void buscarEstudiante(Estudiante* estudiantes, int cantidad);
void modificarEstudiante(Estudiante* estudiantes, int cantidad);

//programa principal
int main() {
    int cantidad;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> cantidad;

    
    Estudiante* estudiantes = new Estudiante[cantidad];

    int opcion;
    do {
        cout << "\n========= MENU =========" << endl;
        cout << "1. Ingresar estudiantes" << endl;
        cout << "2. Mostrar estudiantes" << endl;
        cout << "3. Buscar estudiante" << endl;
        cout << "4. Modificar estudiante" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                ingresarEstudiantes(estudiantes, cantidad);
                break;
            case 2:
                mostrarEstudiantes(estudiantes, cantidad);
                break;
            case 3:
                buscarEstudiante(estudiantes, cantidad);
                break;
            case 4:
                modificarEstudiante(estudiantes, cantidad);
                break;
            case 5:
                cout << "\nSaliendo del programa..." << endl;
                break;
            default:
                cout << "\nOpcion invalida, intente de nuevo.\n";
        }
    } while (opcion != 5);

    delete[] estudiantes;
    return 0;
}


void ingresarEstudiantes(Estudiante* estudiantes, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << "\n--- Estudiante #" << i + 1 << " ---" << endl;
        cin.ignore();
        cout << "Nombre: ";
        getline(cin, estudiantes[i].nombre);

        cout << "Edad: ";
        cin >> estudiantes[i].edad;

        cout << "Ingrese 5 calificaciones:\n";
        for (int j = 0; j < 5; j++) {
            cout << "Calificacion " << j + 1 << ": ";
            cin >> estudiantes[i].calificaciones[j];
        }

        cin.ignore();
        cout << "Calle: ";
        getline(cin, estudiantes[i].direccion.calle);

        cout << "Numero: ";
        cin >> estudiantes[i].direccion.numero;
        cin.ignore();

        cout << "Ciudad: ";
        getline(cin, estudiantes[i].direccion.ciudad);
    }
}

void mostrarEstudiantes(Estudiante* estudiantes, int cantidad) {
    cout << "\n======= LISTA DE ESTUDIANTES =======\n";
    for (int i = 0; i < cantidad; i++) {
        cout << "\nEstudiante #" << i + 1 << endl;
        cout << "Nombre: " << estudiantes[i].nombre << endl;
        cout << "Edad: " << estudiantes[i].edad << endl;
        cout << "Calificaciones: ";
        for (int j = 0; j < 5; j++) {
            cout << estudiantes[i].calificaciones[j] << " ";
        }
        cout << endl;
        cout << "Direccion: " << estudiantes[i].direccion.calle
             << " #" << estudiantes[i].direccion.numero
             << ", " << estudiantes[i].direccion.ciudad << endl;
    }
}

void buscarEstudiante(Estudiante* estudiantes, int cantidad) {
    cin.ignore();
    string nombreBuscado;
    cout << "\nIngrese el nombre del estudiante a buscar: ";
    getline(cin, nombreBuscado);

    bool encontrado = false;
    for (int i = 0; i < cantidad; i++) {
        if (estudiantes[i].nombre == nombreBuscado) {
            cout << "\nEstudiante encontrado:\n";
            cout << "Nombre: " << estudiantes[i].nombre << endl;
            cout << "Edad: " << estudiantes[i].edad << endl;
            cout << "Calificaciones: ";
            for (int j = 0; j < 5; j++) {
                cout << estudiantes[i].calificaciones[j] << " ";
            }
            cout << endl;
            cout << "Direccion: " << estudiantes[i].direccion.calle
                 << " #" << estudiantes[i].direccion.numero
                 << ", " << estudiantes[i].direccion.ciudad << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "\nEstudiante no encontrado.\n";
    }
}

void modificarEstudiante(Estudiante* estudiantes, int cantidad) {
    cin.ignore();
    string nombreModificar;
    cout << "\nIngrese el nombre del estudiante a modificar: ";
    getline(cin, nombreModificar);

    bool encontrado = false;
    for (int i = 0; i < cantidad; i++) {
        if (estudiantes[i].nombre == nombreModificar) {
            cout << "\nModificando datos de " << estudiantes[i].nombre << "...\n";
            cout << "Nueva edad: ";
            cin >> estudiantes[i].edad;

            cout << "Nuevas calificaciones:\n";
            for (int j = 0; j < 5; j++) {
                cout << "Calificacion " << j + 1 << ": ";
                cin >> estudiantes[i].calificaciones[j];
            }

            cin.ignore();
            cout << "Nueva calle: ";
            getline(cin, estudiantes[i].direccion.calle);
            cout << "Nuevo numero: ";
            cin >> estudiantes[i].direccion.numero;
            cin.ignore();
            cout << "Nueva ciudad: ";
            getline(cin, estudiantes[i].direccion.ciudad);

            cout << "\nDatos actualizados correctamente.\n";
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "\nEstudiante no encontrado.\n";
    }
}