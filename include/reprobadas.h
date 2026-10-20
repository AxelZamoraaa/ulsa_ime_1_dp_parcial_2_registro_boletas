#pragma once
#include <iostream>
#include <string>
#include "registro.h"
 

const std::string TITULO_REPROBADAS = "--- MATERIAS REPROBADAS POR ALUMNO ---";
 

void mostrarReprobadas(std::string nombres[], double espanol[], double matematicas[],
                       double programas[], int total) {
    if (total == 0) {
        std::cout << "No hay alumnos registrados.\n";
        return;
    }
 
    std::cout << TITULO_REPROBADAS << "\n";
    int alumnosConReprobadas = 0;  
 
    for (int i = 0; i < total; i++) {
        int reprobadas = 0;
        if (espanol[i] < CALIFICACION_APROBATORIA) {
            reprobadas++;
        }
        if (matematicas[i] < CALIFICACION_APROBATORIA) {
            reprobadas++;
        }
        if (programas[i] < CALIFICACION_APROBATORIA) {
            reprobadas++;
        }
        if (reprobadas > 0) {
            std::cout << nombres[i] << " " << reprobadas << "\n";
            alumnosConReprobadas++;
        }
    }
 
    
    if (alumnosConReprobadas == 0) {
        std::cout << "Ningun alumno reprobo materias.\n";
    } else if (alumnosConReprobadas == total) {
        std::cout << "Todos los alumnos reprobaron al menos una materia: "
                  << alumnosConReprobadas << "\n";
    } else {
        std::cout << "Alumnos con materias reprobadas: " << alumnosConReprobadas << "\n";
    }
}