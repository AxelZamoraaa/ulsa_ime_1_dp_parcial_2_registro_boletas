//dar el promedio por materia del salon materia mas alta en calis el promedio y materia mas baja

#pragma once
#include <iostream>
#include <string>
#include "registro.h"

const std::string TITULO_ESTADISTICAS = "--- ESTADISTICAS POR MATERIA ---";

void mostrarEstadisticas(std::string nombres[], double espanol[],
                         double matematicas[], double programas[], int total) {

    if (total == 0) {
        std::cout << "No hay alumnos registrados.\n";
        return;
    }

    // Sumar las calificaciones de cada materia
    double sumaEspanol = 0;
    double sumaMatematicas = 0;
    double sumaProgramas = 0;

    for (int i = 0; i < total; i++) {
        sumaEspanol = sumaEspanol + espanol[i];
        sumaMatematicas = sumaMatematicas + matematicas[i];
        sumaProgramas = sumaProgramas + programas[i];
    }

    // Calcular los promedios
    double promEspanol = sumaEspanol / total;
    double promMatematicas = sumaMatematicas / total;
    double promProgramas = sumaProgramas / total;

    // Encontrar la materia con el promedio mas alto
    std::string masAlta = "Espanol";
    double mayor = promEspanol;

    if (promMatematicas > mayor) {
        mayor = promMatematicas;
        masAlta = "Matematicas";
    }

    if (promProgramas > mayor) {
        mayor = promProgramas;
        masAlta = "Diseno de Programas";
    }

    // Encontrar la materia con el promedio mas bajo
    std::string masBaja = "Espanol";
    double menor = promEspanol;

    if (promMatematicas < menor) {
        menor = promMatematicas;
        masBaja = "Matematicas";
    }

    if (promProgramas < menor) {
        menor = promProgramas;
        masBaja = "Diseno de Programas";
    }

    // Mostrar los resultados
    std::cout << TITULO_ESTADISTICAS << "\n";
    std::cout << "Espanol: " << promEspanol << "\n";
    std::cout << "Matematicas: " << promMatematicas << "\n";
    std::cout << "Diseno de Programas: " << promProgramas << "\n";
    std::cout << "Mas alta: " << masAlta << "\n";
    std::cout << "Mas baja: " << masBaja << "\n";
}