#include <iostream>
#include <string>
using namespace std;
struct Nodo {
    string nombre;
    string apellido;
    string codigo;
    Nodo* siguiente;
};

Nodo* frente = NULL;
Nodo* final = NULL;

void registrar() {
    Nodo* nuevo = new Nodo();
    
    cout << "Nombre: ";
    cin >> nuevo->nombre;
    cout << "Apellido: ";
    cin >> nuevo -> apellido;
    cout << "Codigo: ";
    cin >> nuevo->codigo;

    nuevo->siguiente = NULL;

    if (frente == NULL) {
        frente = nuevo;
        final = nuevo;
    } else {
        final->siguiente = nuevo;
        final = nuevo;
    }

    cout << "Estudiante registrado.\n";
}

void atender() {
    if (frente == NULL) {
        cout << "No hay estudiantes en espera.\n";
        return;
    }

    Nodo* temp = frente;

    cout << "Atendiendo a: " << temp->nombre << temp -> apellido 
         << " | Codigo: " << temp->codigo << endl;

    frente = frente->siguiente;

    delete temp;

    if (frente == NULL) {
        final = NULL;
    }
}


void mostrar() {
    if (frente == NULL) {
        cout << "No hay estudiantes en espera.\n";
        return;
    }

    Nodo* aux = frente;
    int pos = 1;

    cout << "\nLista de espera:\n";

    while (aux != NULL) {
        cout << pos << ". " << aux->nombre << aux-> apellido
             << " | " << aux->codigo << endl;
        aux = aux->siguiente;
        pos++;
    }
}

void buscar() {
    if (frente == NULL) {
        cout << "Lista vacia.\n";
        return;
    }

    string nombre;
    cout << "Ingrese nombre a buscar: ";
    cin >> nombre;

    Nodo* aux = frente;
    int pos = 1;

    while (aux != NULL) {
        if (aux->nombre == nombre) {
            cout << "Encontrado en posicion: " << pos << endl;
            return;
        }
        aux = aux->siguiente;
        pos++;
    }

    cout << "No encontrado.\n";
}


int main() {
    int opcion;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Registrar estudiante\n";
        cout << "2. Atender estudiante\n";
        cout << "3. Mostrar estudiantes\n";
        cout << "4. Buscar estudiante\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: registrar(); break;
            case 2: atender(); break;
            case 3: mostrar(); break;
            case 4: buscar(); break;
            case 5: cout << "Saliendo...\n"; break;
            default: cout << "Opcion invalida\n";
        }

    } while (opcion != 5);

    return 0;
}