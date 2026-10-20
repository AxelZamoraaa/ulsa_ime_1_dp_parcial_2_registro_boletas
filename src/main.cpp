// Proyecto Parcial 2: Sistema de Registro y Boletas de un Grupo Escolar
// Programa principal (bloque de integracion, de todo el equipo).
//
// Compilar (desde la carpeta del proyecto):
//   g++ -Wall -Wextra -std=c++17 -Iinclude src/main.cpp -o boletas
// Ejecutar:
//   ./boletas
//
// Lean PROYECTO.md antes de escribir codigo.


#include <iostream>
#include <iomanip>
 
#include "utilerias.h"
#include "registro.h"
 
// Un include por bloque individual
#include "captura.h"        // Bloque 1 - Persona 1
#include "estadisticas.h"   // Bloque 2 - Persona 2
#include "aprobados.h"      // Bloque 3 - Persona 3
#include "boleta.h"         // Bloque 4 - Persona 4
#include "reprobadas.h"     // Bloque 5 - Persona 5
 
int main() {
    // Cuatro arreglos paralelos y el total (sin variables globales)
    std::string nombres[MAX_ALUMNOS];
    double espanol[MAX_ALUMNOS] = {0};
    double matematicas[MAX_ALUMNOS] = {0};
    double programas[MAX_ALUMNOS] = {0};
    int total = 0;
 
    int opcion;
 
    // Muestra los decimales con un solo digito (9.0, 7.5, ...)
    std::cout << std::fixed << std::setprecision(1);
 
    do {
        std::cout << "\n1. Capturar alumno\n";
        std::cout << "2. Mostrar lista\n";
        std::cout << "3. Estadisticas por materia\n";
        std::cout << "4. Aprobados y reprobados\n";
        std::cout << "5. Boleta individual\n";
        std::cout << "6. Materias reprobadas por alumno\n";
        std::cout << "7. Salir\n";
        opcion = leerEntero("Opcion: ");
 
        switch (opcion) {
            case 1:
                total = capturarAlumno(nombres, espanol, matematicas, programas, total);
                break;
            case 2:
                mostrarLista(nombres, espanol, matematicas, programas, total);
                break;
            case 3:
                mostrarEstadisticas(nombres, espanol, matematicas, programas, total);
                break;
            case 4:
                mostrarAprobados(nombres, espanol, matematicas, programas, total);
                break;
            case 5:
                mostrarBoleta(nombres, espanol, matematicas, programas, total);
                break;
            case 6:
                mostrarReprobadas(nombres, espanol, matematicas, programas, total);
                break;
            case 7:
                std::cout << "Hasta luego.\n";
                break;
            default:
                std::cout << "Opcion invalida.\n";
        }
    } while (opcion != 7);
 
    return 0;
}
