#include <iostream>     // Para entrada y salida est�ndar
#include <fstream>      // Para manejo de archivos
#include <stdexcept>    // Para lanzar y manejar excepciones
#include <numeric>      // Se incluye seg�n el requerimiento (aunque en este ejemplo no se utiliza directamente)
#include <string>       // Para trabajar con cadenas

int main() {
    try {
        // 1. Abrir (o crear) el archivo "numeros.txt" en modo escritura.
        // Se abre en modo "truncado" para que cada ejecuci�n del programa inicie con un archivo vac�o.
        std::ofstream archivoNumeros("numeros.txt");
        if (!archivoNumeros.is_open()) {
            throw std::runtime_error("Error: no se pudo abrir el archivo 'numeros.txt' para escribir.");
        }

        // 2. Solicitar n�meros al usuario y almacenarlos en "numeros.txt".
        // Se utilizar� un ciclo en el que el usuario ingresa un n�mero o la palabra "fin" para terminar.
        std::string entrada;  // Variable para almacenar la entrada del usuario
        std::cout << "Ingrese un n�mero o 'fin' para terminar: ";
        while (std::cin >> entrada) {
            // Si se ingresa "fin", se sale del ciclo.
            if (entrada == "fin") {
                break;
            }

            // Intentar convertir la entrada a n�mero entero.
            try {
                int num = std::stoi(entrada);  // Convertir cadena a entero
                // Escribir el n�mero en el archivo, cada uno en una nueva l�nea.
                archivoNumeros << num << "\n";
            }
            catch (const std::invalid_argument& e) {
                // En caso de que la conversi�n falle (por ejemplo, se ingresa una cadena no num�rica)
                std::cerr << "Entrada inv�lida. Se esperaba un n�mero entero o 'fin'." << std::endl;
                // Se contin�a con el siguiente ciclo para pedir otra entrada
                continue;
            }

            // Pedir la siguiente entrada al usuario
            std::cout << "Ingrese otro n�mero o 'fin' para terminar: ";
        }
        // Cerrar el archivo donde se almacenaron los n�meros
        archivoNumeros.close();

        // 3. Abrir el archivo "numeros.txt" en modo lectura para procesar los n�meros.
        std::ifstream in("numeros.txt");
        if (!in.is_open()) {
            throw std::runtime_error("Error: no se pudo abrir el archivo 'numeros.txt' para leer.");
        }

        // Variables para almacenar la suma y la cantidad de n�meros le�dos.
        int suma = 0;
        int cantidad = 0;
        int numero;

        // Leer cada n�mero almacenado en el archivo y acumular la suma y el contador.
        while (in >> numero) {
            suma += numero;
            cantidad++;
        }
        in.close();  // Cerrar el archivo despu�s de la lectura

        // Verificar que se haya ingresado al menos un n�mero.
        if (cantidad == 0) {
            std::cout << "No se ingres� ning�n n�mero." << std::endl;
            return 0;
        }

        // Calcular el promedio como un valor de punto flotante.
        double promedio = static_cast<double>(suma) / cantidad;

        // 4. Escribir los resultados en el archivo "resultados.txt".
        std::ofstream out("resultados.txt");
        if (!out.is_open()) {
            throw std::runtime_error("Error: no se pudo abrir el archivo 'resultados.txt' para escribir.");
        }
        // Escribimos la suma, la cantidad y el promedio en el formato solicitado.
        out << "Suma: " << suma << std::endl;
        out << "cantidad: " << cantidad << std::endl;
        out << "promedio: " << promedio << std::endl;
        out.close(); // Cerrar el archivo de salida

        std::cout << "\nProceso completado. Los resultados se han escrito en 'resultados.txt'." << std::endl;

        // 5. Volver a abrir "resultados.txt" en modo lectura para mostrar su contenido en la consola.
        std::ifstream resultados("resultados.txt");
        if (!resultados.is_open()) {
            throw std::runtime_error("Error: no se pudo abrir el archivo 'resultados.txt' para lectura.");
        }
        std::cout << "\nContenido de resultados.txt:" << std::endl;
        std::string linea;
        while (std::getline(resultados, linea)) {
            std::cout << linea << std::endl;
        }
        resultados.close();  // Cerrar el archivo despu�s de la lectura

    }
    catch (const std::exception& e) {
        // Capturar cualquier excepci�n producida durante la ejecuci�n del programa
        std::cerr << "Se produjo una excepci�n: " << e.what() << std::endl;
        return 1;
    }

    return 0;  // Finaliza el programa correctamente
}
