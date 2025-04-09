# PRIMERA SERIE

## ✅ ¿Qué son los operadores lógicos?

Los operadores lógicos permiten combinar condiciones booleanas (`true` o `false`).

- `&&` (AND): Verdadero si **ambas** condiciones lo son.
- `||` (OR): Verdadero si **al menos una** lo es.
- `!` (NOT): Invierte el valor lógico.

### Ejemplo:
```cpp
int edad = 20;
bool tieneLicencia = true;

if (edad >= 18 && tieneLicencia) {
    cout << "Puedes conducir.";
}
```

---

## ✅ Diferencia entre `for` y `while`

- `for`: Se usa cuando **se conoce el número de repeticiones**.
- `while`: Se usa cuando **la repetición depende de una condición**.

### Ejemplo de `for`:
```cpp
for (int i = 1; i <= 5; i++) {
    cout << i << " ";
}
```

### Ejemplo de `while`:
```cpp
int i = 1;
while (i <= 5) {
    cout << i << " ";
    i++;
}
```

---

## ✅ ¿Qué es la recursividad?

La recursividad es una técnica donde una función **se llama a sí misma** para resolver un problema dividiéndolo en subproblemas más pequeños.

### Ejemplo: Factorial
```cpp
int factorial(int n) {
    if (n == 0) return 1;
    else return n * factorial(n - 1);
}
```

Llamar a `factorial(5)` devuelve `120`.

---

## ✅ Archivos secuenciales vs archivos de acceso aleatorio

- **Archivos secuenciales:** Se leen o escriben desde el inicio hasta el final, en orden.
- **Archivos de acceso aleatorio:** Permiten saltar directamente a cualquier parte del archivo.

### Ejemplo de lectura de archivo secuencial:
```cpp
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ifstream archivo("datos.txt");
    string linea;

    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();
    return 0;
}
```

---

## ✅ ¿Cómo se maneja una excepción en C++?

Se usan los bloques `try` y `catch` para **capturar y manejar errores** que ocurren durante la ejecución.

### Ejemplo con `std::out_of_range` (sin vectores):
```cpp
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

int main() {
    string texto = "Hola";

    try {
        char letra = texto.at(10); // posición inválida
        cout << letra << endl;
    } catch (const out_of_range& e) {
        cout << "Excepción capturada: " << e.what() << endl;
    }

    return 0;
}
```

---

# SEGUNDA SERIE


---

### 1. ¿Cuál de las siguientes es un operador lógico?
✅ b) &&

---

### 2. ¿Cuál es la principal diferencia entre el operador de asignación (=) y el operador de igualdad (==) en C++?
✅ b) == se usa para comparar y = se usa para asignar un valor

---

### 3. ¿Cuál de las siguientes estructuras de control permite ejecutar un bloque de código un número determinado de veces?
✅ a) for

---

### 4. ¿En C++, qué hace la instrucción continue dentro de un bucle?
✅ b) salta a la siguiente iteración del bucle sin ejecutar el código restante

---

### 5. ¿Qué tipo de bucle es más adecuado cuando no sabemos cuántas veces necesitaremos ejecutar un bloque de código?
✅ b) while

---

### 6. ¿Cuál de las siguientes se utiliza para capturar una excepción en C++?
✅ a) try-catch

---

### 7. ¿Qué hace la sentencia break dentro de una estructura switch?
✅ c) finaliza la ejecución del switch y sale del bloque

---

### 8. ¿Cuál es la característica principal de una función recursiva?
✅ d) llama a sí misma para resolver un subproblema

---

### 9. ¿Cómo se maneja una excepción en C++?
✅ a) usando la palabra clave try-catch

---

### 10. ¿Qué tipo de archivo es el más adecuado para almacenar datos que deben ser accedidos de manera secuencial?
✅ c) archivo secuencial
