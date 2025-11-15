#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<int> leerArchivo(string nombre);
void clasificarNumeros(string archivoEntrada, string archivoPares, string archivoImpares);
void ordenarArchivo(string nombreArchivo);
void mostrarArchivo(string nombreArchivo);
void burbuja(vector<int> &arr);


vector<int> leerArchivo(string nombre) {
    ifstream archivo(nombre);
    vector<int> numeros;
    int n;

    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo: " << nombre << endl;
        return numeros;
    }

    while (archivo >> n) {
        numeros.push_back(n);
    }

    archivo.close();
    return numeros;
}

// Clasificar números en pares.txt e impares.txt

void clasificarNumeros(string archivoEntrada, string archivoPares, string archivoImpares) {
    vector<int> numeros = leerArchivo(archivoEntrada);

    ofstream pares(archivoPares);
    ofstream impares(archivoImpares);

    for (int n : numeros) {
        if (n % 2 == 0)
            pares << n << endl;
        else
            impares << n << endl;
    }

    pares.close();
    impares.close();
}

// Ordenando el contenido de un archivo usando burbuja
void ordenarArchivo(string nombreArchivo) {
    vector<int> numeros = leerArchivo(nombreArchivo);

    burbuja(numeros);

    ofstream archivo(nombreArchivo);
    for (int n : numeros)
        archivo << n << endl;

    archivo.close();
}

// Ordenamiento de burbuja
void burbuja(vector<int> &arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Muestra el contenido de un archivo
void mostrarArchivo(string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    int n;

    if (!archivo.is_open()) {
        cout << "No se pudo abrir " << nombreArchivo << endl;
        return;
    }

    cout << "\nContenido de " << nombreArchivo << ":\n";

    while (archivo >> n) {
        cout << n << " ";
    }

    cout << endl;
    archivo.close();
}

int main() {
    string archivoDatos = "datos.txt";
    string archivoPares = "pares.txt";
    string archivoImpares = "impares.txt";

    cout << "=== CLASIFICADOR Y ORDENADOR DE NUMEROS ===\n";

    cout << "\n--- Contenido original ---\n";
    mostrarArchivo(archivoDatos);

    // Clasificando pares e impares
    clasificarNumeros(archivoDatos, archivoPares, archivoImpares);

    cout << "\n--- Pares antes de ordenar ---\n";
    mostrarArchivo(archivoPares);

    cout << "\n--- Impares antes de ordenar ---\n";
    mostrarArchivo(archivoImpares);

    // Ordenar archivos
    ordenarArchivo(archivoPares);
    ordenarArchivo(archivoImpares);

    cout << "\n--- Pares después de ordenar ---\n";
    mostrarArchivo(archivoPares);

    cout << "\n--- Impares después de ordenar ---\n";
    mostrarArchivo(archivoImpares);

    cout << "\nProceso completado." << endl;

    return 0;
}
