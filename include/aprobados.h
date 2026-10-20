#pragma once
#include <iostream>
#include <string>
#include "registro.h"
 

const std::string TITULO_APROBADOS = "--- APROBADOS Y REPROBADOS ---";
 

int contarAprobados(double calificaciones[], int total) {
    int aprobados = 0;
    for (int i = 0; i < total; i++) {
        if (calificaciones[i] >= CALIFICACION_APROBATORIA) {
            aprobados++;
        }
    }
    return aprobados;
}
 

std::string conNumero(int n, std::string palabra) {
    if (n == 1) {
        return palabra;
    }
    return palabra + "s";
}

void mostrarAprobados(std::string nombres[], double espanol[], double matematicas[],
                      double programas[], int total) {
    (void)nombres;  
    if (total == 0) {
        std::cout << "No hay alumnos registrados.\n";
        return;
    }
 
    int apEspanol = contarAprobados(espanol, total);
    int apMatematicas = contarAprobados(matematicas, total);
    int apProgramas = contarAprobados(programas, total);
 
    int repEspanol = total - apEspanol;
    int repMatematicas = total - apMatematicas;
    int repProgramas = total - apProgramas;
 
    std::cout << TITULO_APROBADOS << "\n";
    std::cout << "Espanol: " << apEspanol << " " << conNumero(apEspanol, "aprobado")
              << ", " << repEspanol << " " << conNumero(repEspanol, "reprobado") << "\n";
    std::cout << "Matematicas: " << apMatematicas << " " << conNumero(apMatematicas, "aprobado")
              << ", " << repMatematicas << " " << conNumero(repMatematicas, "reprobado") << "\n";
    std::cout << "Diseno de Programas: " << apProgramas << " " << conNumero(apProgramas, "aprobado")
              << ", " << repProgramas << " " << conNumero(repProgramas, "reprobado") << "\n";
 
    
    if (repEspanol >= repMatematicas && repEspanol >= repProgramas) {
        std::cout << "Materia con mas reprobados: Espanol\n";
    } else if (repMatematicas >= repProgramas) {
        std::cout << "Materia con mas reprobados: Matematicas\n";
    } else {
        std::cout << "Materia con mas reprobados: Diseno de Programas\n";
    }
}