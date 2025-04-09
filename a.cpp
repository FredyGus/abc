#include <iostream>     // Para entrada y salida est�ndar
#include <fstream>      // Para manejo de archivos
#include <stdexcept>    // Para lanzar y manejar excepciones
#include <numeric>      // Se incluye seg�n el requerimiento, aunque no se usa en este ejemplo
#include <string>       // Para utilizar la clase std::string

using namespace std;

int main() {
    try {
        // Inicializaci�n de variables para acumular resultados
        int suma = 0;           // Variable para almacenar la suma de los n�meros ingresados
        int cantidad = 0;       // Variable para contar la cantidad de n�meros v�lidos ingresados
        string entrada;    // Cadena para almacenar la entrada del usuario (puede ser n�mero o "fin")

        // Bucle para la entrada de datos de forma interactiva
        // Se ejecuta indefinidamente hasta que el usuario escriba "fin"
        while (true) {
            // Solicitar al usuario que ingrese un n�mero o "fin" para finalizar la entrada
            cout << "Ingrese un numero o 'fin' para terminar: ";
            cin >> entrada;  // Leer la entrada desde el teclado y almacenarla en la variable "entrada"

            // Si el usuario escribe "fin", se sale del bucle
            if (entrada == "fin") {
                break;
            }

            // Intentar convertir la entrada de texto a un n�mero entero usando std::stoi
            try {
                int num = stoi(entrada);  // Convertir la cadena a entero
                suma += num;                   // Sumar el n�mero a la suma acumulada
                cantidad++;                    // Incrementar el contador de n�meros ingresados
            }
            catch (const invalid_argument& e) {
                // Si la conversi�n falla, se atrapa la excepci�n std::invalid_argument
                // Esto ocurre si la entrada no es un n�mero v�lido (y tampoco es "fin")
                cerr << "Entrada inv�lida. Se esperaba un n�mero entero o 'fin'." << std::endl;
                continue;    // Continuar con la siguiente iteraci�n del bucle para pedir otra entrada
            }
        }

        // Verificar si se ingres� al menos un n�mero
        if (cantidad == 0) {
            cout << "No se ingres� ning�n n�mero." << endl;
            return 0;  // Finaliza el programa ya que no hay datos para procesar
        }

        // Calcular el promedio de los n�meros ingresados
        // Se usa un cast a double para obtener un resultado de punto flotante
        double promedio = static_cast<double>(suma) / cantidad;

        // Abrir el archivo "resultados.txt" en modo escritura para guardar los resultados
        ofstream out("resultados.txt");
        // Verificar si el archivo se abri� correctamente
        if (!out.is_open()) {
            throw runtime_error("Error: no se pudo abrir el archivo 'resultados.txt' para escribir.");
        }
        // Escribir los resultados en el archivo con el formato solicitado
        out << "Suma: " << suma << endl;
        out << "cantidad: " << cantidad << endl;
        out << "promedio: " << promedio << endl;
        out.close(); // Cerrar el archivo despu�s de escribir

        // Informar al usuario que el proceso se complet� y el archivo se gener� correctamente
        cout << "\nProceso completado. Los resultados se han escrito en 'resultados.txt'." << endl;

        // Abrir el archivo "resultados.txt" en modo lectura para mostrar su contenido en la consola
        ifstream in("resultados.txt");
        // Verificar que se haya abierto correctamente el archivo para lectura
        if (!in.is_open()) {
            throw runtime_error("Error: no se pudo abrir el archivo 'resultados.txt' para lectura.");
        }
        cout << "\nContenido de resultados.txt:" << endl;
        string linea;  // Variable para almacenar cada l�nea le�da del archivo
        // Leer el archivo l�nea por l�nea y mostrar cada l�nea en la consola
        while (getline(in, linea)) {
            cout << linea << endl;
        }
        in.close();  // Cerrar el archivo de lectura

    }
    catch (const exception& e) {
        // Capturar cualquier excepci�n que se haya lanzado en el bloque try
        cerr << "Se produjo una excepci�n: " << e.what() << endl;
        return 1;   // Retornar 1 indica que ocurri� un error en la ejecuci�n
    }

    return 0; // Retornar 0 indica que el programa finaliz� exitosamente
}
