//dar el promedio por materia del salon materia mas alta en calis el promedio y materia mas baja

#pragma once
#include <iostream>
#include <string>
#include "registro.h"

const std::string TITULO_ESTADISTICAS = "--- ESTADISTICAS POR MATERIA ---";

// Promedio por materia, y materia mas alta y mas baja con su promedio.
void mostrarEstadisticas(std::string nombres[], double espanol[],
                         double matematicas[], double programas[], int total) {
    (void)nombres;  // este reporte no usa los nombres

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

    // Materia con el promedio mas alto
    std::string masAlta;
    double promAlta;

    if (promEspanol >= promMatematicas && promEspanol >= promProgramas) {
        masAlta = "Espanol";
        promAlta = promEspanol;
    } else if (promMatematicas >= promProgramas) {
        masAlta = "Matematicas";
        promAlta = promMatematicas;
    } else {
        masAlta = "Diseno de Programas";
        promAlta = promProgramas;
    }

    // Materia con el promedio mas bajo
    std::string masBaja;
    double promBaja;

    if (promEspanol <= promMatematicas && promEspanol <= promProgramas) {
        masBaja = "Espanol";
        promBaja = promEspanol;
    } else if (promMatematicas <= promProgramas) {
        masBaja = "Matematicas";
        promBaja = promMatematicas;
    } else {
        masBaja = "Diseno de Programas";
        promBaja = promProgramas;
    }

    // Mostrar los resultados
    std::cout << TITULO_ESTADISTICAS << "\n";
    std::cout << "Espanol: " << promEspanol << "\n";
    std::cout << "Matematicas: " << promMatematicas << "\n";
    std::cout << "Diseno de Programas: " << promProgramas << "\n";
    std::cout << "Mas alta: " << masAlta << " (" << promAlta << ")\n";
    std::cout << "Mas baja: " << masBaja << " (" << promBaja << ")\n";
}