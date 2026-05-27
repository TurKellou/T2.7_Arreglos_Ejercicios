#include <iostream>
#include <vector>
using namespace std;

// Estructura del estudiante
struct Estudiante {
    string nombre;
    float nota;
};

int main() {
    vector<Estudiante> estudiantes;
    int opcion;
    
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Registrar calificaciones\n";
        cout << "2. Mostrar reporte estadistico\n";
        cout << "3. Buscar estudiante\n";
        cout << "4. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion) {
            
            case 1: {
                int n;
                cout << "Cuantos estudiantes desea registrar: ";
                cin >> n;

                for(int i = 0; i < n; i++) {
                    Estudiante e;
                    cout << "\nNombre del estudiante: ";
                    cin >> e.nombre;
                    cout << "Nota: ";
                    cin >> e.nota;

                    estudiantes.push_back(e);
                }
                break;
            }

            case 2: {
                if(estudiantes.empty()) {
                    cout << "No hay datos registrados.\n";
                    break;
                }

                float suma = 0;
                int aprobados = 0, reprobados = 0;

                for(int i = 0; i < estudiantes.size(); i++) {
                    suma += estudiantes[i].nota;

                    if(estudiantes[i].nota >= 7)
                        aprobados++;
                    else
                        reprobados++;
                }

                float promedio = suma / estudiantes.size();

                cout << "\n===== REPORTE =====\n";
                cout << "Promedio general: " << promedio << endl;
                cout << "Aprobados: " << aprobados << endl;
                cout << "Reprobados: " << reprobados << endl;

                break;
            }

            case 3: {
                if(estudiantes.empty()) {
                    cout << "No hay datos registrados.\n";
                    break;
                }

                string nombreBuscar;
                bool encontrado = false;

                cout << "Ingrese el nombre a buscar: ";
                cin >> nombreBuscar;

                for(int i = 0; i < estudiantes.size(); i++) {
                    if(estudiantes[i].nombre == nombreBuscar) {
                        cout << "\nEstudiante encontrado:\n";
                        cout << "Nombre: " << estudiantes[i].nombre << endl;
                        cout << "Nota: " << estudiantes[i].nota << endl;

                        if(estudiantes[i].nota >= 7)
                            cout << "Estado: Aprobado\n";
                        else
                            cout << "Estado: Reprobado\n";

                        encontrado = true;
                        break;
                    }
                }

                if(!encontrado) {
                    cout << "El estudiante no se encuentra registrado.\n";
                }

                break;
            }

            case 4:
                cout << "Saliendo del sistema...\n";
                break;

            default:
                cout << "Opcion invalida.\n";
        }

    } while(opcion != 4);

    return 0;
}